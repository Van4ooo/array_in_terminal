#ifndef ARRAY_IN_TERMINAL_CORE_H
#define ARRAY_IN_TERMINAL_CORE_H

#include <iostream>
#include <windows.h>
#include <unistd.h>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

struct Rectangles{
    int value;
    int index;
};

struct StyleRec{
    char body = '#';
    char border = '|';
    char head = '_';
    char lf_corner = '.';
    char rh_corner = '.';
};

class ArrayInTerminal{
public:
    HANDLE setting{};
    COORD position{};
    SHORT height=46, weight=200;

    int wx{}, _min{}, right_shift{};
    float hx{};
    int *last{};

    int pause{};
    int swap_counter{};
    int set_counter{};

    char *name_alg{};
    Rectangles l1{}, l2{};
    StyleRec style{};

    void init_array(int *, int, int);

    static int _max(int *, int);

    void swap(int*, int*, int, int);

    void set(int*, int, int);

    void first_print_array(const int *, int);

    void print_rectangles(int, int, int);

    void _write_rectangles(bool, int, int, int);

    void _write_border_rec(int, int, int);

    void print_table();

    void reset_color_rectangles(int, int);

    void reset_color_rectangles_set(int);

    [[nodiscard]] int height_rectangles(int) const;

    void print_head(int, int);

    void clear_rectangles(int, int, int);

    void write_symbol(int, int, char);

    void set_name_alg(char *);

    [[maybe_unused]] void set_style_rec(const char *);
    [[maybe_unused]] void set_size_window(const int*, const int*);
};

class SortsVis{
public:
    ArrayInTerminal ait;

    static void rand_array(int *, int &);

    [[maybe_unused]] virtual void run(int *, int, int);
    [[maybe_unused]] virtual void rand_run(int, int);

    [[maybe_unused]] void set_style(const char *);
    [[maybe_unused]] void set_size_window(int, int);
};

#endif //ARRAY_IN_TERMINAL_CORE_H
