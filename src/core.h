#ifndef SORT_VISUALIZATION_CORE_H
#define SORT_VISUALIZATION_CORE_H

#include <iostream>
#include <windows.h>
#include <unistd.h>

#define RESET "\033[0m"
#define GREEN "\033[32m"

struct Rectangles{
    int value;
    int index;
};

class ArrayInTerminal{

public:
    HANDLE setting{};
    COORD position{};
    SHORT height=46, weight=200;

    int wx{}, _min{};
    float hx{};
    int *last{};

    char *name_alg{};

    int pause{};
    int swap_counter{};
    int set_counter{};

    Rectangles l1{}, l2{};

public:
    void init_array(int *, int, int);

    static int _max(int *, int);

    void swap(int*, int*, int, int);

    void set(int*, int, int);

    void first_print_array(const int *, int);

    void print_rectangles(int, int, int);

    void print_table();

    void reset_color_rectangles(int, int);

    void reset_color_rectangles_set(int);

    [[nodiscard]] int height_rectangles(int) const;

    void print_head(int, int);

    void clear_rectangles(int, int, int);

    void write_symbol(int, int, char);

    void set_name_alg(char *);
};

class SortsVis{
public:
    ArrayInTerminal ait;

    static void rand_array(int *, int &);

    [[maybe_unused]] virtual void run(int *, int, int);
    [[maybe_unused]] virtual void rand_run(int, int);

};

#endif //SORT_VISUALIZATION_CORE_H
