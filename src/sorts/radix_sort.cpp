#include "sorts_list.h"

void sorts::RadixSort::run(int *array, int size, int pause) {
    ait->set_name_alg("RADIX_SORT");
    init_ait(array, size, pause);

    int m = _max(array, size);

    for (int exp = 1; m / exp > 0; exp *= 10)
        count_sort(array, size, exp);

    ait->_sorted();
}

int sorts::RadixSort::_max(int *array, int size) {
    int max_now = array[0];

    for(int i=1;i<size;i++)
        max_now = std::max(max_now, array[i]);

    return max_now;
}

void sorts::RadixSort::count_sort(int *array, int size, int exp) {
    int output[size];
    int i, count[10] = { 0 };

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        ait->set(&array[i], output[i], i);
}