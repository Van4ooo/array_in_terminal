#include "sorts_list.h"

void sorts::QuickSort::run(int *array, int size, int pause) {
    ait->set_name_alg("QUICK_SORT");
    init_ait(array, size, pause);

    quick_sort(array, 0, size-1);
    ait->_sorted();
}

void sorts::QuickSort::quick_sort(int *array, int low, int high) {
    if(low<high){
        int pi=partition(array, low, high);

        quick_sort(array,low,pi-1);
        quick_sort(array,pi+1,high);
    }
}

int sorts::QuickSort::partition(int *array, int low, int high) {
    int pivot=array[high];

    int i=(low-1);

    for(int j=low;j<=high;j++){
        if(array[j]<pivot){
            i++;
            ait->swap(&array[i], &array[j], i, j);
        }
    }
    ait->swap(&array[i+1], &array[high], i+1, high);
    return (i+1);
}