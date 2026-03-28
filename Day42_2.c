#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int maxHeap[MAX];
int minHeap[MAX];
int maxSize = 0;
int minSize = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (maxHeap[parent] < maxHeap[i]) {
            swap(&maxHeap[parent], &maxHeap[i]);
            i = parent;
        } else break;
    }
}

void minHeapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (minHeap[parent] > minHeap[i]) {
            swap(&minHeap[parent], &minHeap[i]);
            i = parent;
        } else break;
    }
}

void maxHeapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < maxSize && maxHeap[left] > maxHeap[largest]) largest = left;
    if (right < maxSize && maxHeap[right] > maxHeap[largest]) largest = right;

    if (largest != i) {
        swap(&maxHeap[i], &maxHeap[largest]);
        maxHeapifyDown(largest);
    }
}

void minHeapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < minSize && minHeap[left] < minHeap[smallest]) smallest = left;
    if (right < minSize && minHeap[right] < minHeap[smallest]) smallest = right;

    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        minHeapifyDown(smallest);
    }
}

void insertMaxHeap(int val) {
    maxHeap[maxSize] = val;
    maxHeapifyUp(maxSize);
    maxSize++;
}

void insertMinHeap(int val) {
    minHeap[minSize] = val;
    minHeapifyUp(minSize);
    minSize++;
}

int extractMax() {
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapifyDown(0);
    return root;
}

int extractMin() {
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    minHeapifyDown(0);
    return root;
}

void addNum(int num) {
    if (maxSize == 0 || num <= maxHeap[0]) {
        insertMaxHeap(num);
    } else {
        insertMinHeap(num);
    }

    if (maxSize > minSize + 1) {
        insertMinHeap(extractMax());
    } else if (minSize > maxSize) {
        insertMaxHeap(extractMin());
    }
}

double findMedian() {
    if (maxSize > minSize) {
        return maxHeap[0];
    }
    return (maxHeap[0] + minHeap[0]) / 2.0;
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int num;
            scanf("%d", &num);
            addNum(num);
        } else if (type == 2) {
            printf("%.5f\n", findMedian());
        }
    }

    return 0;
}