#include "src/sorts/sorts_list.h"

int main() {
    sorts::MergeSort{}.rand_run(50, 70);
    sorts::HeapSort{}.rand_run(200, 0);
    sorts::SelectionSort{}.rand_run(200, 20);

    getchar();
    return 0;
}