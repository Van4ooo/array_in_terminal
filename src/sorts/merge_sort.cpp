#include "sorts_list.h"


[[maybe_unused]] void sorts::MergeSort::run(int *array, int size, int pause) {
    ait.set_name_alg("MERGE_SORT");
    ait.init_array(array, size, pause);

    merge_sort(array, 0, size-1);
}

[[maybe_unused]] void sorts::MergeSort::merge(
        int *array,const int left, const int mid, const int right){
    int const sub_one = mid - left + 1;
    int const sub_two = right - mid;

    auto *arr_left = new int[sub_one], *arr_right = new int[sub_two];

    for (auto i = 0; i < sub_one; i++)
        arr_left[i] = array[left + i];

    for (auto j = 0; j < sub_two; j++)
        arr_right[j] = array[mid + 1 + j];

    auto i_sub_one = 0, i_sub_two = 0;
    int index_merged = left;

    while (i_sub_one < sub_one && i_sub_two < sub_two) {
        if (arr_left[i_sub_one] <= arr_right[i_sub_two]) {
            ait.set(&array[index_merged], arr_left[i_sub_one], index_merged);
            i_sub_one++;
        } else {
            ait.set(&array[index_merged], arr_right[i_sub_two], index_merged);
            i_sub_two++;
        }
        index_merged++;
    }

    while (i_sub_one < sub_one) {
        ait.set(&array[index_merged], arr_left[i_sub_one], index_merged);

        i_sub_one++;
        index_merged++;
    }

    while (i_sub_two < sub_two) {
        ait.set(&array[index_merged], arr_right[i_sub_two], index_merged);

        i_sub_two++;
        index_merged++;
    }
    delete[] arr_left;
    delete[] arr_right;
}

[[maybe_unused]] void sorts::MergeSort::merge_sort(int *array, const int begin, const int end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}