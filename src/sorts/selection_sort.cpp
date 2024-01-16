#include "sorts_list.h"


[[maybe_unused]] void sorts::SelectionSort::run(int *array, int size, int pause) {
    ait.set_name_alg((char *)"SELECTION_SORT");
    ait.init_array(array, size, pause);

    int i, j, min_idx;

    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            ait.swap(&array[min_idx], &array[i], min_idx, i);
    }
}