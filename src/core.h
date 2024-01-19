#ifndef ARRAY_IN_TERMINAL_CORE_H
#define ARRAY_IN_TERMINAL_CORE_H

#include <iostream>
#include <windows.h>
#include <unistd.h>

#define GREEN "\033[32m"
#define BLUE "\033[38;2;207;236;242m"
#define ORANGE "\033[38;2;218;97;17m"
#define PINK "\033[38;2;250;83;161m"

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

struct ColorStyle{
    const char* REC = BLUE;
    const char* SWAP = ORANGE;
    const char* SET = PINK;
    const char* FIRST_DRAW = BLUE;
    const char* TABLE = GREEN;
    const char* SORTED = GREEN;
};

class ArrayInTerminal{
private:
    HANDLE setting{};
    COORD position{};
    SHORT height=46, weight=200;

    int wx{}, _min{}, right_shift{};
    float hx{};
    int *last{};
    int last_size{};

    int pause{};
    int swap_counter = 0;
    int set_counter = 0;

    std::string name_alg = "SHUFFLE";
    Rectangles l1{}, l2{};
    StyleRec style{};
    ColorStyle colors{};

    char table_border_chr = '~';
    int table_w = 20;
    int table_h = 2;

public:
    bool shuffle = false;
    bool _init = false;

    void init_array(int *, int, int);

    static int _max(int *, int);

    void swap(int*, int*, int, int);

    void set(int*, int, int);

    void first_print_array(const int *, int);

    void print_rectangles(int, int, int);

    void _write_rectangles(bool, int, int, int);

    void _write_border_rec(int, int, int);

    void _sorted();

    void print_table();

    void clear_table();

    void reset_color_rectangles(int, int);

    void reset_color_rectangles_set(int);

    [[nodiscard]] int height_rectangles(int) const;

    void print_head(int, int);

    void clear_rectangles(int, int, int);

    void write_symbol(int, int, char);

    void write_symbol_with_checking(int, int, char);

    void set_name_alg(std::string);

    [[maybe_unused]] void set_style_rec(const char *);
    [[maybe_unused]] void set_size_window(int, int);
};

class SortsVis{
public:
    ArrayInTerminal *ait{};

    explicit SortsVis(ArrayInTerminal *);

    void rand_array(int *, int &) const;
    static void init_array(int *, int);

    void init_ait(int *, int, int) const;
    static bool sorted(const int *, int);

    [[maybe_unused]] virtual void run(int *, int, int);

    [[maybe_unused]] virtual void rand_run(int, int);

    [[maybe_unused]] void set_style(const char *) const;
    [[maybe_unused]] void set_size_window(int, int) const;
};

#endif //ARRAY_IN_TERMINAL_CORE_H
