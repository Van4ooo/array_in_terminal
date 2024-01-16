#include "src/sorts/sorts_list.h"

using namespace sorts;

int main() {
    MergeSort{}.rand_run(50, 10);

    InsertionSort t = InsertionSort{};
    t.set_style("# /_\\");
    t.rand_run(48, 20);

    SelectionSort{}.rand_run(200, 20);

    getchar();
    return 0;
}