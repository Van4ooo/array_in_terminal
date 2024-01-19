#include "sorts_list.h"

[[maybe_unused]] void sorts::HeapSort::run(int *array, int size, int pause){
    ait->set_name_alg("HEAP_SORT");
    init_ait(array, size, pause);

    for (int i = size/2 - 1; i>=0; i--)
        heapify(array, size, i);


    for (int i = size - 1; i>0; i--) {
        ait->swap(&array[0], &array[i], 0, i);

        heapify(array, i, 0);
    }

    ait->_sorted();
}

[[maybe_unused]] void sorts::HeapSort::heapify(int *array, int size, int i){
    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && array[l] > array[largest])
        largest = l;

    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i) {
        ait->swap(&array[i], &array[largest], i, largest);

        heapify(array, size, largest);
    }
}
