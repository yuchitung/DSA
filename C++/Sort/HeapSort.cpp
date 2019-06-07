#include <iostream>

using namespace std;

/**
 * Heap Sort
 *
 * averge-case complecity：O(nlogn)
 * best-case complcity：O(nlogn)
 * worst-case complecity：O(nlogn)
 * space complecity：O(n)
 */

/**
 * Max-heapify
 */
void heapify(int arr[], int size, int index) {

    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if (left<size & arr[left]> arr[largest]) {
        largest = left;
    }
    if (right<size & arr[right]> arr[largest]) {
        largest = right;
    }
    if (index != largest) {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    /**
     * Make a heap array
     */
    for (int index = size / 2 - 1; index >= 0; index--) {
        heapify(arr, size, index);
    }

    /**
     * Swap the root (max value) and the last value, then heapify 
     * In each iteration, the largest value will be moved to the final position
     */
    for (int length = size - 1; length >= 0; length--) {
        swap(arr[length], arr[0]);
        heapify(arr, length, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {3, 5, 52, 11, 2, 49, 5, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array:";
    printArray(arr, n);

    heapSort(arr, n);
    cout << "After sorting: ";
    printArray(arr, n);
}