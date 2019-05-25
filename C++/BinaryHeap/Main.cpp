#include <iostream>
#include <climits>
using namespace std;

class MinHeap {
    int *heap;
    int capacity;
    int heapSize;

  public:
    MinHeap(int capacity);
    void MinHeapify(int);
    int getParentIndex(int index) { return (index - 1) / 2; }
    int getLeftIndex(int index) { return (2 * index + 1); }
    int getRightIndex(int index) { return (2 * index + 2); }
    int extractMin();
    void decreaseNode(int index, int newValue);
    int getMin() { return heap[0]; }
    void deleteNode(int index);
    void insertNode(int value);
    void swap(int *x, int *y);
    void print();
};

MinHeap::MinHeap(int size) {
    heapSize = 0;
    capacity = size;
    heap = new int[size];
}

void MinHeap::insertNode(int value) {
    if (heapSize == capacity) {
        cout << "Heap is full. Can not insert a new element";
        return;
    }

    heapSize++;
    int index = heapSize - 1;
    heap[index] = value;

    // Fix the min heap if needed
    while (index != 0 && heap[getParentIndex(index)] > heap[index]) {
        swap(&heap[index], &heap[getParentIndex(index)]);
        index = getParentIndex(index);
    }
}

/**
 * Delete node : reduce the value to minus then extract the minimum
 */
void MinHeap::deleteNode(int index) {
    decreaseNode(index, INT_MIN);
    extractMin();
}

/**
 * Decrease node by change the value to the new value.
 * If the value of the node is less then new value, nothing is changed.
 */
void MinHeap::decreaseNode(int index, int newValue) {
    if (heap[index] <= newValue) {
        cout << "The value of target node is less than the new value" << endl;
        return;
    }

    heap[index] = newValue;
    while (index != 0 && heap[getParentIndex(index)] > heap[index]) {
        swap(&heap[index], &heap[getParentIndex(index)]);
        index = getParentIndex(index);
    }
}

/**
 *  Remove minimum node
 */
int MinHeap::extractMin() {
    if (heapSize <= 0) {
        return INT_MAX;
    }

    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }

    int minimum = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    MinHeapify(0);

    return minimum;
}

/**
 * Heapify tree recursively from root
 */
void MinHeap::MinHeapify(int index) {
    int left = getLeftIndex(index);
    int right = getRightIndex(index);
    int smallest = index;
    if (left < heapSize && heap[left] < heap[index])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MinHeap::print() {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i] << " ";
    }
}

int main() {
    MinHeap heap(15);
    heap.insertNode(6);
    heap.insertNode(4);
    heap.insertNode(11);
    heap.insertNode(12);
    heap.insertNode(7);
    heap.deleteNode(3);
    heap.insertNode(52);
    heap.insertNode(38);
    heap.insertNode(79);

    cout << "Minimum:" << heap.getMin() << endl;
    cout << "Extract minimum:" << heap.extractMin() << endl;
    cout << "Reduce the value of node2 to 5..." << endl;
    heap.decreaseNode(2, 5);
    cout << "Minimum:" << heap.getMin() << endl;
    cout << "Nodes of heap tree:";
    heap.print();

    return 0;
}