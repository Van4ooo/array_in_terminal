#include "src/sorts/sorts_list.h"

using namespace sorts;

int main() {
    RadixSort{}.rand_run(200, 20);
    QuickSort{}.rand_run(200, 20);
    CocktailSort{}.rand_run(200, 0);

    BogoSort t = BogoSort{};
    t.set_size_window(46, 49);
    t.rand_run(7, 0);

    getchar();
    return 0;
}