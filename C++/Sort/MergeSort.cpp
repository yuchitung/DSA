#include <iostream>

using namespace std;

/**
 * Merge Sort
 *
 * averge-case complecity：O(nlogn)
 * best-case complcity：O(nlogn)
 * worst-case complecity：O(nlogn)
 * space complecity：O(n)
 */

/**
 * Compare the left sub and the right sub, and extract the bigger value to the
 * array until all the values from sub-arrays are extracted
 */
void merge(int arr[], int leftIndex, int middleIndex, int rightIndex) {
    int i, j, index;
    int lengthOfLeftSub = middleIndex - leftIndex + 1;
    int lengthOfRightSub = rightIndex - middleIndex;
    int leftSub[lengthOfLeftSub], rightSub[lengthOfRightSub];

    for (i = 0; i < lengthOfLeftSub; i++)
        leftSub[i] = arr[leftIndex + i];
    for (j = 0; j < lengthOfRightSub; j++)
        rightSub[j] = arr[middleIndex + 1 + j];

    i = 0;
    j = 0;
    index = leftIndex;

    while (i < lengthOfLeftSub && j < lengthOfRightSub) {
        if (leftSub[i] <= rightSub[j]) {
            arr[index] = leftSub[i];
            i++;
        } else {
            arr[index] = rightSub[j];
            j++;
        }
        index++;
    }

    while (i < lengthOfLeftSub) {
        arr[index] = leftSub[i];
        i++;
        index++;
    }
    while (j < lengthOfRightSub) {
        arr[index] = rightSub[j];
        j++;
        index++;
    }
}

/**
 * Split array into two parts recursively until it can not be split, and merge
 * them in each recursion
 */
void mergeSort(int arr[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        mergeSort(arr, leftIndex, middleIndex);
        mergeSort(arr, middleIndex + 1, rightIndex);
        merge(arr, leftIndex, middleIndex, rightIndex);
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {28, 54, 11, 3, 9, 6, 34};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    print(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << endl << "After sorting: ";
    print(arr, arr_size);
    return 0;
}