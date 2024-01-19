#include "sorts_list.h"

void sorts::BubbleSort::run(int * array, int size, int pause) {
    ait->set_name_alg("BUBBLE_SORT");
    init_ait(array, size, pause);

    int i, j;
    bool swapped;

    for (i = 0; i < size - 1; i++) {
        swapped = false;

        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                ait->swap(&array[j], &array[j + 1], j, j+1);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    ait->_sorted();
}
