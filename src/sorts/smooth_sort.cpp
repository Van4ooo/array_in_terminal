#include "sorts_list.h"

void sorts::SmoothSort::run(int *arr, int size, int pause) {
    ait->set_name_alg("SMOOTH_SORT");
    init_ait(arr, size, pause);

    ait->_sorted();
}

int sorts::SmoothSort::leonardo(int k) {
    return ((k < 2) ? 1 : leonardo(k - 1) + leonardo(k - 2) + 1);
}

void sorts::SmoothSort::heapify(int *arr, int start, int end) {
}