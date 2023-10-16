#include <bits/stdc++.h>
#include <SDL2/SDL.h>
using namespace std;

const int WIDTH = 1260, HEIGHT = 720;
const int NUM_BARS = 500;
const int BAR_WIDTH = 5;


// Function to render bars on the SDL window with flashing effect
void renderBars(SDL_Renderer* renderer, vector<int>& bars, int size) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < size; ++i) {
        int barX = i * (BAR_WIDTH + 1);
        SDL_Rect barRect = { barX, HEIGHT - bars[i], BAR_WIDTH, bars[i] };

        // Calculate hue based on the height of the bar
        float hue = (static_cast<float>(bars[i]) / static_cast<float>(HEIGHT)) * 360.0f;

        // Convert HSV to RGB color with flashing effect
        float c = 1.0f;
        float x = c * (1 - abs(fmod(hue / 60.0f, 2.0f) - 1));
        float m = 1.0f - c;


        float r, g, b;
        if (hue >= 0 && hue < 60) {
            r = c ;
            g = x ;
            b = 0;
        } else if (hue >= 60 && hue < 120) {
            r = x ;
            g = c ;
            b = 0;
        } else if (hue >= 120 && hue < 180) {
            r = 0;
            g = c ;
            b = x ;
        } else if (hue >= 180 && hue < 240) {
            r = 0;
            g = x ;
            b = c ;
        } else if (hue >= 240 && hue < 300) {
            r = x ;
            g = 0;
            b = c ;
        } else { // hue >= 300 && hue < 360
            r = c ;
            g = 0;
            b = x ;
        }

        // Scale RGB values to 0-255 range
        Uint8 red = static_cast<Uint8>((r + m) * 255);
        Uint8 green = static_cast<Uint8>((g + m) * 255);
        Uint8 blue = static_cast<Uint8>((b + m) * 255);

        // Set the render draw color using the calculated RGB values
        SDL_SetRenderDrawColor(renderer, red, green, blue, 255);

        // Fill the current bar's rectangle with the current render draw color
        SDL_RenderFillRect(renderer, &barRect);
    }

    SDL_RenderPresent(renderer);
}


// Bubble Sort algorithm
void bubbleSort(vector<int> &arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap the bars
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Render the updated bars at each step
                renderBars(SDL_GetRenderer(SDL_GetWindowFromID(1)), arr, size);

                // Add a delay to visualize the sorting process (optional)
                SDL_Delay(0);
            }
        }
    }
}

//Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    renderBars(SDL_GetRenderer(SDL_GetWindowFromID(1)), arr, right);
    SDL_Delay(70); // in miliseconds

    int mid = left + (right - left) / 2;

    // Sort the first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

// //int getSortingOption() {
//     int option = 1;

//     cout << "Select the sorting algorithm to apply:" << endl;
//     cout << "1. Bubble Sort" << endl;
//     cout << "2. Merge Sort" << endl;
//     cin >> option;

//     return option;
// }


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Bubble Sort Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if (NULL == window) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        return 1;
    }

    // Create SDL renderer to draw on the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (NULL == renderer) {
        cout << "Could not create renderer: " << SDL_GetError() << endl;
        return 1;
    }

    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(0)));

    // int bars[NUM_BARS];
    vector<int> bars(NUM_BARS);

    // Generate random bar heights
    for (int i = 0; i < NUM_BARS; ++i) {
        bars[i] = rand() % HEIGHT;
    }

    // Render the initial state of bars
    renderBars(renderer, bars, NUM_BARS);
    SDL_Delay(1000);
    SDL_Event windowEvent;

    // int sortingSelection = getSortingOption();

    // if(sortingSelection == 1){
    //     bubbleSort(bars, NUM_BARS);
    // } else {
    //     mergeSort(bars, 0, NUM_BARS);
    // }
     bubbleSort(bars, NUM_BARS);

    // Wait for the user to close the window
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
    
    //Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}