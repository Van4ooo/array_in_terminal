#include "src/sorts/sorts_list.h"

using namespace sorts;

int main() {
    // Cool sorting algorithms O(n*log(n))
    int n1=200, arr1[n1];
    SortsVis::init_array(arr1, n1);
    ArrayInTerminal ait = ArrayInTerminal();

    MergeSort{&ait}.run(arr1, n1, 0);
    QuickSort{&ait}.run(arr1, n1, 0);
    HeapSort{&ait}.run(arr1, n1, 0);
    RadixSort{&ait}.run(arr1, n1, 5);

    // Poor sorting algorithms O(n^2)
    int n2=50, arr2[n2];
    SortsVis::init_array(arr2, n2);

    InsertionSort{&ait}.run(arr2, n2, 10);
    CocktailSort{&ait}.run(arr2, n2, 0);
    SelectionSort{&ait}.run(arr2, n2, 100);
    BubbleSort{&ait}.run(arr2, n2, 0);

    // Stupid sort O(n*n!)
    auto t = BogoSort{&ait};
    t.set_size_window(46, 49);
    t.rand_run(7, 0);

    getchar();
    return 0;
}