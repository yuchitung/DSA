#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Partition
 * pick the last element as pivot,then compare all the other elements with the
 * pivot. If the elemnt is smaller then the pivot, make the element on the left
 * side of the pivot. If the elemnt is greater then the pivot, make the element
 * on the right side of the pivot
 */
int partition(int *arr, int low, int high) {
    int i = low - 1;
    int j;
    int pivot = arr[high];

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

/**
 * Quick Sort
 * pick an element as pivot, then sort both the left partition and right
 * partition recursively
 */
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {9, 56, 23, 11, 6, 34, 28, 17};
    cout << "Array:" << endl;
    print(arr, 8);
    cout << endl;
    cout << "After sorting:" << endl;
    quickSort(arr, 0, 7);
    print(arr, 8);

    return 0;
}
