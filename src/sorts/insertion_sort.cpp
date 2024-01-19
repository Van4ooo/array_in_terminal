#include "sorts_list.h"


void sorts::InsertionSort::run(int *array, int size, int pause) {
    ait->set_name_alg("INSERTION_SORT");
    init_ait(array, size, pause);

    int i, key, j;

    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            ait->set(&array[j + 1], array[j], j+1);
            j--;
        }
        ait->set(&array[j + 1], key, j+1);
    }

    ait->_sorted();
}