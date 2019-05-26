#include <iostream>

using namespace std;

void print(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Bubble Sort
 *
 * 概念：兩兩比較，把最大或最小值換到邊界，完成每一回合的排序
 * 平均時間複雜度：O(n^2)
 * 最佳時間複雜度：O(n^2)
 * 最壞時間複雜度：O(n^2)
 * 空間複雜度：O(n)
 */
void bubbleSort(int array[], int size) {
    int round = size - 1;
    for (int i = 0; i < round; i++) {
        for (int j = 0; j < round - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

/**
 * 加上 flag ，若有一回合都沒有任何一次的交換，則結束排序
 * 平均時間複雜度：O(n^2)
 * 最佳時間複雜度O(n)
 * 最壞時間複雜度：O(n^2)
 * 額外空間複雜度：O(1)
 */
void bubbleSortWithFlag(int array[], int size) {
    int round = size - 1;
    for (int i = 0; i < round; i++) {
        int flag = 0;
        for (int j = 0; j < round - i; j++) {

            if (array[j] > array[j + 1]) {
                flag = 1;
                swap(&array[j], &array[j + 1]);
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    cout << "=== Bubble sort ===" << endl;
    int array[] = {36, 28, 11, 19, 40, 58, 73, 61};
    int size = sizeof(array) / sizeof(array[0]);
    print(array, size);
    cout << endl;
    bubbleSort(array, size);
    cout << "After sorting:" << endl;
    print(array, size);
    cout << endl << endl;

    cout << "=== Bubble sort with flag ===" << endl;
    int arrayB[] = {56, 24, 91, 11, 9, 72, 48, 19};
    size = sizeof(arrayB) / sizeof(arrayB[0]);
    print(arrayB, size);
    cout << endl;
    bubbleSortWithFlag(arrayB, size);
    cout << "After sorting:" << endl;
    print(arrayB, size);
    return 0;
}