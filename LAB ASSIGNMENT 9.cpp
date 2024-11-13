#include <iostream>
using namespace std;

void Maxheap(int Arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && Arr[l] > Arr[largest]) {
        largest = l;
    }
    if (r < n && Arr[r] > Arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(Arr[i], Arr[largest]);
        Maxheap(Arr, n, largest);
    }
}

void Maxheapsort(int Arr[], int n) {
    // Build the heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        Maxheap(Arr, n, i);
    }
    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(Arr[0], Arr[i]);
        Maxheap(Arr, i, 0);
    }
}

void Display(int Arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "How many elements do you want to sort: ";
    cin >> n;

    int Arr[n]; // Declare array after n is read

    cout << "Enter " << n << " Elements: ";
    for (int i = 0; i < n; i++) {
        cin >> Arr[i];
    }

    Maxheapsort(Arr, n);

    cout << "This is the sorted array: \n";
    Display(Arr, n);

    return 0;
}

