#include "sorts_list.h"

void sorts::CocktailSort::run(int * array, int size, int pause) {
    ait->set_name_alg("COCKTAIL_SORT");
    init_ait(array, size, pause);

    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; i++) {
            if (array[i] > array[i + 1]) {
                ait->swap(&array[i], &array[i + 1], i, i+1);
                swapped = true;
            }
        }

        if (!swapped) break;

        swapped = false;
        end--;

        for (int i = end - 1; i >= start; i--) {
            if (array[i] > array[i + 1]) {
                ait->swap(&array[i], &array[i + 1], i, i+1);
                swapped = true;
            }
        }
        start++;
    }

    ait->_sorted();
}