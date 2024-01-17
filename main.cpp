#include "src/sorts/sorts_list.h"

using namespace sorts;

int main() {
    MergeSort{}.rand_run(200, 0);

    InsertionSort t = InsertionSort{};
    t.set_style("#|._.");
    t.set_size_window(46, 54);
    t.rand_run(48, 20);

    HeapSort{}.rand_run(200, 20);
    getchar();
    return 0;
}