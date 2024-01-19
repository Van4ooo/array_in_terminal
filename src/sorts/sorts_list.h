#ifndef ARRAY_IN_TERMINAL_SORT_LIST_H
#define ARRAY_IN_TERMINAL_SORT_LIST_H

#include "../core.h"
#include <random>

namespace sorts{
    class [[maybe_unused]] HeapSort : public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
        [[maybe_unused]] void heapify(int *, int, int);
        explicit HeapSort(ArrayInTerminal *a) : SortsVis(a){};
    };

    class [[maybe_unused]] BubbleSort : public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
        explicit BubbleSort(ArrayInTerminal *a) : SortsVis(a){};
    };

    class [[maybe_unused]] SelectionSort: public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
        explicit SelectionSort(ArrayInTerminal *a) : SortsVis(a){};
    };

    class [[maybe_unused]] InsertionSort: public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
        explicit InsertionSort(ArrayInTerminal *a) : SortsVis(a){};
    };

    class [[maybe_unused]] MergeSort: public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
        explicit MergeSort(ArrayInTerminal *a) : SortsVis(a){};
    private:
        [[maybe_unused]] void merge_sort(int *, int , int );
        [[maybe_unused]] void merge(int *, int , int , int );
    };

    class [[maybe_unused]] CocktailSort: public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
        explicit CocktailSort(ArrayInTerminal *a) : SortsVis(a){};
    };

    class [[maybe_unused]] QuickSort: public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
        explicit QuickSort(ArrayInTerminal *a) : SortsVis(a){};
    private:
        [[maybe_unused]] void quick_sort(int *, int, int);
        [[maybe_unused]] int partition(int *, int, int);
    };

    class [[maybe_unused]] SmoothSort: public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
        explicit SmoothSort(ArrayInTerminal *a): SortsVis(a){};
    private:
        [[maybe_unused]] int leonardo(int);
        [[maybe_unused]] void heapify(int *, int, int);
    };

    class [[maybe_unused]] BogoSort: public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
        [[maybe_unused]] std::mt19937 _gen;
        explicit BogoSort(ArrayInTerminal *a) : SortsVis(a){};
    private:
        [[maybe_unused]] void shuffle(int *, int);
        [[maybe_unused]] static bool is_sorted(const int *, int);
    };

    class [[maybe_unused]] RadixSort: public SortsVis{
    public:
        explicit RadixSort(ArrayInTerminal *a) : SortsVis(a){};
        [[maybe_unused]] void run(int *, int, int) override;
    private:
        [[maybe_unused]] static int _max(int *, int);
        [[maybe_unused]] void count_sort(int *, int, int);
    };
}

#endif //ARRAY_IN_TERMINAL_SORT_LIST_H
