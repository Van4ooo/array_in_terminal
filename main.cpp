#include "src/sorts_list.h"

int main() {
    sorts::HeapSort{}.rand_run(50, 10);
    sorts::MergeSort{}.rand_run(50, 100);

    getchar();
    return 0;
}