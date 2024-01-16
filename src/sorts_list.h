#ifndef SORT_VISUALIZATION_SORTS_LIST_H
#define SORT_VISUALIZATION_SORTS_LIST_H

#include "core.h"

namespace sorts{

    class [[maybe_unused]] HeapSort : public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
        [[maybe_unused]] void heapify(int *, int, int);
    };

    class [[maybe_unused]] BubbleSort : public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
    };

    class [[maybe_unused]] SelectionSort: public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
    };

    class [[maybe_unused]] InsertionSort: public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
    };

    class [[maybe_unused]] MergeSort: public SortsVis{
    public:
        [[maybe_unused]] void run(int *, int, int) override;
    private:
        [[maybe_unused]] void merge_sort(int *, int , int );
        [[maybe_unused]] void merge(int *, int , int , int );
    };
}

#endif //SORT_VISUALIZATION_SORTS_LIST_H
