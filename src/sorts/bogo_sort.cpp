#include "sorts_list.h"


void sorts::BogoSort::run(int *array, int size, int pause) {
    ait->set_name_alg("BOGO_SORT");
    init_ait(array, size, pause);

    std::random_device rd;
    std::mt19937 gen(rd());
    _gen = gen;

    while (!is_sorted(array, size))
        shuffle(array, size);

    ait->_sorted();
}

bool sorts::BogoSort::is_sorted(const int *array, int size) {
    for(int i=0;i<size - 1;i++)
        if (array[i] > array[i+1])
            return false;

    return true;
}

void sorts::BogoSort::shuffle(int *array, int size) {
    std::uniform_int_distribution<> distribution(0, size-1);
    for(int i=0;i<size;i++) {
        int r = distribution(_gen);
        ait->swap(&array[i], &array[r], i, r);
    }
}