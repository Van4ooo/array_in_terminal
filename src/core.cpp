#include <random>

#include "core.h"

void ArrayInTerminal::init_array(int *array, int size, int p){
    system("mode 200, 46");
    setting = GetStdHandle(STD_OUTPUT_HANDLE);

    wx = weight/size;
    hx = (float)height/(float)_max(array, size);

    last = array;
    pause = p;

    first_print_array(array, size);
}

int ArrayInTerminal::_max(int *array, int size){
    int max_el=array[0];

    for(int i=0;i<size;i++){
        max_el = std::max(max_el, array[i]);
    }

    return max_el;
}

void ArrayInTerminal::swap(int* xp, int* yp, int i1, int i2){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

    reset_color_rectangles(i1, i2);

    std::cout << GREEN;

    if (*xp > *yp){
        print_rectangles(i1, last[i1], last[i2]);
        clear_rectangles(i2, last[i1], last[i2]);
    } else{
        print_rectangles(i2, last[i2], last[i1]);
        clear_rectangles(i1, last[i2], last[i1]);
    }

    usleep(1000*pause);

    swap_counter++;
    print_table();
}

void ArrayInTerminal::set(int *xp, int yp, int i1) {
    reset_color_rectangles_set(i1);

    std::cout << GREEN;

    if (*xp < yp)
        print_rectangles(i1, yp, 0);
    else {
        clear_rectangles(i1, *xp, yp);
        print_rectangles(i1, yp, 0);
    }

    *xp = yp;
    usleep(1000*pause);

    set_counter++;
    print_table();
}

void ArrayInTerminal::reset_color_rectangles(int i1, int i2) {
    std::cout << RESET;

    if (l1.index != -1){
        if (l1.index != i1) print_rectangles(l1.index, l1.value, 0);
        if (l2.index != i2) print_rectangles(l2.index, l2.value, 0);
    }

    l1 = {last[i1], i1};
    l2 = {last[i2], i2};
}

void ArrayInTerminal::reset_color_rectangles_set(int i1) {
    std::cout << RESET;

    if (l1.index == -1 && l2.index != i1)
        print_rectangles(l2.index, last[l2.index], 0);

    l2 = {last[i1], i1};
}

void ArrayInTerminal::first_print_array(const int *array, int size){
    for(int i=0;i<size;i++)
        print_rectangles(i, array[i], 0);
}

void ArrayInTerminal::print_rectangles(int index, int el, int last_el) {
    int y = height_rectangles(el);
    int last_y = height_rectangles(last_el);

    int x = index*wx;

    for (int dy = y-1; dy >= last_y; dy--)
        for (int i = x; i < x + wx; i++)
                write_symbol(i, height - dy - 1,
                         (i == x || i == x + wx - 1 ? '|' : '#'));

    print_head(x, y);
}

void ArrayInTerminal::print_table() {
    position.X = 0;
    position.Y = 0;

    SetConsoleCursorPosition(setting, position);

    std::cout << "---------------------\n    ";
    std::cout << name_alg << std::endl;

    std::cout << "   SWAP_COUNTER: " << swap_counter;
    std::cout << "\n   SET_COUNTER: " << set_counter;
    std::cout << "\n---------------------\n";
}

void ArrayInTerminal::clear_rectangles(int index, int el, int last_el){
    int y = height_rectangles(el);
    int last_y = height_rectangles(last_el);

    int x = index*wx;

    for (int dy = y; dy >= last_y; dy--)
        for (int i = x; i < x + wx; i++)
            write_symbol(i, height - dy - 1, ' ');

    print_head(x, last_y);
}

void ArrayInTerminal::print_head(int x, int y) {
    for (int i = x; i < x + wx; i++)
        write_symbol(i, height - y - 1,
                     (i == x || i == x + wx - 1 ? '.' : '_'));
}

int ArrayInTerminal::height_rectangles(int el) const {
    return el ? (int)((float)(el-_min)*hx-1) : 0;
}

void ArrayInTerminal::write_symbol(int x, int y, char ch){
    position.X = (SHORT)x;
    position.Y = (SHORT)y;

    SetConsoleCursorPosition(setting, position);
    std::cout << ch;
}

void ArrayInTerminal::set_name_alg(char *name) {
    name_alg = name;

    swap_counter = 0;
    set_counter = 0;
    l1.index = -1;
}

void SortsVis::rand_array(int *array, int &size) {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i=0;i<size;i++)array[i] = i;

    for (int i = size - 1; i > 0; i--){
        std::uniform_int_distribution<> distribution(0, i+1);
        int j = distribution(gen);

        std::swap(array[i], array[j]);
    }
}

void SortsVis::rand_run(int size, int pause) {
    int *array = new int[size];

    rand_array(array, size);
    run(array, size, pause);

    delete[] array;
}

void SortsVis::run(int *, int, int){}