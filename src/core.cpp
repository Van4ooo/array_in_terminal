#include <random>
#include <utility>
#include "core.h"

void ArrayInTerminal::init_array(int *array, int size, int p){
    if (!_init) {
        set_size_window(height, width);
        setting = GetStdHandle(STD_OUTPUT_HANDLE);

        hide_cursor();
    } else if(last_size != size ) clear_window();

    wx = width/size;
    right_shift = width - wx*size;
    hx = (float)height/(float)_max(array, size);

    last = array;
    last_size = size;
    l1.index = -1;
    pause = p;

    set_counter = 0;
    swap_counter = 0;
    table_h = 2;

    if (!_init) first_print_array(array, size);

    _init = true;
}

int ArrayInTerminal::_max(int *array, int size){
    int max_el=array[0];

    for(int i=0;i<size;i++)
        max_el = std::max(max_el, array[i]);

    return max_el;
}

void ArrayInTerminal::swap(int* xp, int* yp, int i1, int i2){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

    reset_color_rectangles(i1, i2);

    std::cout << colors.SWAP;

    if (*xp > *yp){
        print_rectangles(i1, last[i1], full_draw ? 0 : last[i2]);
        clear_rectangles(i2, last[i1], last[i2]);
        print_rectangles(i2, last[i2], full_draw ? 0: last[i2]);
    } else{
        print_rectangles(i2, last[i2], full_draw ? 0: last[i1]);
        clear_rectangles(i1, last[i2], last[i1]);
        print_rectangles(i1, last[i1], full_draw ? 0 : last[i1]);
    }

    usleep(1000*pause);

    if(shuffle)
        return;

    if (swap_counter++ == 1)
        table_h++;

    print_table();
}

void ArrayInTerminal::set(int *xp, int yp, int i1) {
    reset_color_rectangles_set(i1);

    std::cout << colors.SET;

    if (*xp < yp)
        print_rectangles(i1, yp, 0);
    else {
        clear_rectangles(i1, *xp, yp);
        print_rectangles(i1, yp, 0);
    }

    *xp = yp;
    usleep(1000*pause);

    if(shuffle)
        return;

    if (set_counter++ == 1)
        table_h++;

    print_table();
}

void ArrayInTerminal::reset_color_rectangles(int i1, int i2) {
    std::cout << colors.REC;

    if (l1.index != -1){
        if (l1.index != i1) print_rectangles(l1.index, l1.value, 0);
        if (l2.index != i2) print_rectangles(l2.index, l2.value, 0);
    }

    l1 = {last[i1], i1};
    l2 = {last[i2], i2};
}

void ArrayInTerminal::reset_color_rectangles_set(int i1) {
    std::cout << colors.REC;

    if (l1.index == -1 && l2.index != i1)
        print_rectangles(l2.index, last[l2.index], 0);

    l2 = {last[i1], i1};
}

void ArrayInTerminal::first_print_array(const int *array, int size){
    std::cout << colors.FIRST_DRAW;

    for(int i=0;i<size;i++)
        print_rectangles(i, array[i], 0);
}

void ArrayInTerminal::_write_rectangles(bool mod, int index, int el, int last_el) {
    int y = height_rectangles(el);
    int last_y = height_rectangles(last_el);

    int x = index*wx + right_shift;

    for (int dy = y + mod; dy <= last_y; dy++)
        for (int dx = x + mod; dx < x + wx - mod; dx++) {
            if (mod)
                write_symbol_with_checking(dx, dy, style.body);
            else
                write_symbol_with_checking(dx, dy, ' ');
        }

    if (mod) {
        _write_border_rec(x, y, last_y);

        if(wx > 1) _write_border_rec(x+wx-1, y, last_y);
    }
    print_head(x, mod ? y : last_y);
}

void ArrayInTerminal::_write_border_rec(int x, int y, int last_y) {
    for (int dy = y+1; dy <= last_y; dy++) {
        write_symbol_with_checking(x, dy,(style.border == ' ' && wx == 1)? style.body : style.border);
    }
}

void ArrayInTerminal::print_rectangles(int index, int el, int last_el) {
    _write_rectangles(true, index, el, last_el);
}

void ArrayInTerminal::clear_rectangles(int index, int el, int last_el){
    _write_rectangles(false, index, el, last_el);
}

void ArrayInTerminal::print_table() {
    std::cout << colors.TABLE;

    write_symbol(0, 0, table_border_chr);
    int free_chr = table_w - (int)name_alg.size();

    for(int i=0; i<(free_chr/2 - 1);i++)
        std::cout << table_border_chr;

    std::cout << name_alg;
    for(int i=0; i<(free_chr/2 + free_chr%2);i++)
        std::cout << table_border_chr;

    std::cout << std::endl;

    if (swap_counter) printf(" SWAP_COUNTER: %i\n", swap_counter);
    if (set_counter) printf(" SET_COUNTER: %i\n", set_counter);

    for(int i=0;i<table_w;i++)
        std::cout << table_border_chr;
}

void ArrayInTerminal::clear_table() {
    for (int dy=0;dy<table_h;dy++)
        for(int dx=0;dx<table_w;dx++)
            write_symbol(dx, dy, ' ');
}

void ArrayInTerminal::clear_window() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void ArrayInTerminal::hide_cursor() {
#if defined _WIN32
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(setting, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(setting, &cursorInfo);

#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    std::cout << "\033[?25l";
#elif defined (__APPLE__)
    std::cout << "\033[?25l";
#endif
}

void ArrayInTerminal::print_head(int x, int y) {
    write_symbol_with_checking(x, y, style.lf_corner);

    for (int i = x+1; i < x + wx - 1; i++)
        write_symbol_with_checking(i, y, style.head);

    write_symbol_with_checking(x + wx - 1, y, style.rh_corner);
}

int ArrayInTerminal::height_rectangles(int el) const {
    return height - (el ? (int)((float)(el-_min)*hx-1) : 0) - 1;
}

void ArrayInTerminal::write_symbol(int x, int y, char ch){
    position.X = (SHORT)x;
    position.Y = (SHORT)y;

    SetConsoleCursorPosition(setting, position);
    std::cout << ch;
}

void ArrayInTerminal::write_symbol_with_checking(int x, int y, char ch) {
    if (y < table_h && x < table_w) return;

    write_symbol(x, y, ch);
}

void ArrayInTerminal::set_name_alg(std::string name) {
    name_alg = std::move(name);
}

void ArrayInTerminal::set_style_rec(const char *_style) {
    style.body = _style[0];
    style.border = _style[1];
    style.head = _style[3];
    style.lf_corner = _style[2];
    style.rh_corner = _style[4];
}

void ArrayInTerminal::set_size_window(int _height, int _width) {
    height = (SHORT)_height;
    width = (SHORT)_width;

    char form_string[15];
    std::sprintf(form_string, "mode %i, %i", width, height);

    system(form_string);
}

void ArrayInTerminal::_sorted() {
    std::cout << colors.SORTED;

    for(int i=0;i<last_size;i++) {
        print_rectangles(i, last[i], 0);
        usleep(900);
    }
}

[[maybe_unused]] void ArrayInTerminal::full_rec_draw(bool status) {
    full_draw = status;
}

SHORT ArrayInTerminal::w() const { return width; }
SHORT ArrayInTerminal::h() const { return height; }

SortsVis::SortsVis(ArrayInTerminal *a) : ait(a){
}

void SortsVis::rand_array(int *array, int &size) const {
    std::random_device rd;
    std::mt19937 gen(rd());

    ait->init_array(array, size, 0);
    ait->shuffle = true;

    for (int i = size - 1; i > 0; i--){
        std::uniform_int_distribution<> distribution(0, i+1);
        int j = distribution(gen);

        ait->swap(&array[i], &array[j], i, j);
    }
    ait->shuffle = false;
    ait->clear_table();
}

void SortsVis::init_array(int *array, int size) {
    for (int i=0;i<size;i++) array[i] = i;
}

void SortsVis::rand_run(int size, int pause) {
    int *array = new int[size];

    ait->_init = false;

    init_array(array, size);
    run(array, size, pause);

    delete[] array;
}

void SortsVis::init_ait(int *array, int size, int pause) const{
    if(sorted(array, size))
        rand_array(array, size);
    ait->init_array(array, size, pause);
}

bool SortsVis::sorted(const int *array, int size) {
    for(int i=1; i<size;i++)
        if(array[i-1] > array[i])
            return false;
    return true;
}

void SortsVis::run(int *, int, int){}

[[maybe_unused]] void SortsVis::set_style(const char * _style) const {
    ait->set_style_rec(_style);
}

[[maybe_unused]] void SortsVis::set_size_window(int _height, int _width) const {
    ait->set_size_window(_height, _width);
}

[[maybe_unused]] SHORT SortsVis::width() const{ return ait->w(); }
[[maybe_unused]] SHORT SortsVis::height() const{ return ait->h(); }