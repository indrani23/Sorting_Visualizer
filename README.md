# Sorting Visualizer with SDL

This is a C++ program that visualizes two sorting algorithms - Bubble Sort and Merge Sort - using the Simple DirectMedia Layer (SDL) library. The program generates a set of bars with random heights, and then it sorts these bars using the selected sorting algorithm while displaying the sorting process in real-time.

## Prerequisites

Before running the program, ensure that you have the following installed:

- C++ Compiler (e.g., g++)
- SDL2 library (Simple DirectMedia Layer) - [Installation Guide](https://wiki.libsdl.org/Installation) (Don't worry about downloading and installing separately. It is included in the source code)

## How to Use

1. Clone the repository or download the source code.

2. Compile the code using your C++ compiler. Make sure to link the SDL2 library properly. I have included the SDL2 library in the src folder so you do not have to worry about installing SDL2 separately.

    For example, using g++:
    ```bash
    g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2
    ```

3. Run the compiled executable.

    ```bash
    ./main
    ```

4. A window titled "Bubble Sort Visualizer" will appear, displaying a set of bars. The height of the bars represents the values to be sorted.

5. The bars will be sorted using Merge Sort algorithm. The sorting process will be visualized in real-time with flashing colors indicating the sorting progress.

6. Once the sorting is complete, the window will remain open. You can close it manually to exit the program.

## Known Problems

1. I have not yet figured out how to take input from the user to select the sorting algorithm of their choice. If you want to use different algorithms, you can simply change line 204 and call the sorting function of your choice.

2. Unable to add flashing of bars while sorting. The current implementation of rendering bars only updates the display after each step of sorting, without any flashing effect.

3. While merge sorting, you cannot see the unsorted bars, but you can see the sorting process. This is because the bars are only rendered once the sorting process starts, and not before.

## About the Sorting Algorithms

### Bubble Sort

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

### Merge Sort

Merge Sort is an efficient, comparison-based sorting algorithm that follows the Divide and Conquer approach. It divides the input array into two halves, recursively sorts each half, and then merges the sorted halves to obtain a fully sorted array.

## Code Explanation

- The `renderBars` function renders the bars on the SDL window and updates the display with the current state of the bars. It also applies a flashing color effect based on the height of the bars.

- The `bubbleSort` function implements the Bubble Sort algorithm. It swaps elements when necessary and calls `renderBars` at each step to visualize the sorting process.

- The `merge` function is a helper function for Merge Sort. It merges two sub-arrays into a single sorted array.

- The `mergeSort` function implements the Merge Sort algorithm. It recursively divides the array into smaller sub-arrays and calls `merge` to merge them back together while visualizing the sorting process using `renderBars`.

- The `main` function initializes SDL, creates a window and renderer, generates random bar heights, and calls the `mergeSort` function to sort the bars. The program waits for the user to close the window before exiting.

## License

This code is provided under the [MIT License](https://opensource.org/licenses/MIT).

Feel free to use and modify the code according to your needs.

## Acknowledgments

- The sorting algorithms used in this visualizer are classic algorithms taught in computer science courses.
- The Simple DirectMedia Layer (SDL) library is used for graphics rendering in this program.
