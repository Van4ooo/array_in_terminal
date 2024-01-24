# Array in terminal

Simple and flexible CLI toolkit for visualization any sorting algorithms. You can see how it works in the video

In the video, you can see rectangles of different widths, because **ArrayInTerminal automatically sets** their width depending on the size of the input array.
Therefore, the size of the input array can be any, but **within 2 and windows.width**.
You can run the sorting algorithm in two ways:
```c++
auto ait = ArrayInTerminal();

// full draw rectangles, more beautiful, but more processor load
ait.full_rec_draw(true);

// I way - using the .rand_run(a, b) a - array size, b - pause time, which automatically generates an input array
QuickSort{&ait}.rand_run(ait.w(), 0);
MergeSort{&ait}.rand_run(100, 10);

// II way - using the .run(a, b, c) a - array, b - array size, b - pause time, which work with user array
int arr[ait.w()];
SortsVis::init_array(arr, ait.w()); // fill the array with values

HeapSort{&ait}.run(arr, ait.w(), 0);
RadixSort{&ait}.run(arr, ait.w(), 10);
```
The **rand_run** method is a wrapper for the **run** method, so it is automatically generated for each sorting algorithm. If the input array is sorted, it is automatically shuffled.

Change the windows shape it is possible using method *set_size_window*

```c++
int height=46, width=49;

ait.set_size_window(height, width);
// ait.w() - width window, ait.h() - height window

ait.set_size_window(ait.h(), 142); //changes width
ait.set_size_window(36, ait.w()); //changes height
```

Change the rectangles style it is possible using method *set_style_rec*
```c++
ait.set_style_rec("#|._."); // default style
// : '#' - body, '|' - border, '.' - left corner, '_' - head, '.' - right corner

ait.set_style_rec("$ <_>"); // custom style
// : '$' - body, ' ' - border, '<' - left corner, '_' - head, '>' - right corner
```

List of **all available sorting algorithms**
```c++
// Cool sorting algorithms O(n*log(n))
MergeSort{&ait};
QuickSort{&ait};
HeapSort{&ait};
RadixSort{&ait};

// Poor sorting algorithms O(n^2)
InsertionSort{&ait};
CocktailSort{&ait};
SelectionSort{&ait};
BubbleSort{&ait};

// Stupid sort O(n*n!)
BogoSort{&ait};
```