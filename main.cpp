#include "src/sorts/sorts_list.h"

using namespace sorts;

int main() {
    HeapSort{}.rand_run(50, 50);
    MergeSort{}.rand_run(200, 10);

    InsertionSort t = InsertionSort{};
    t.set_style("#|o_O");
    t.set_size_window(46, 180);
    t.rand_run(60, 20);

    getchar();
    return 0;
}