#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyDown(int *heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int *heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void init(KthLargest *obj, int k, int *nums, int numsSize) {
    obj->heap = (int*)malloc(sizeof(int) * (k + 1));
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (obj->size < k) {
            obj->heap[obj->size++] = val;
            heapifyUp(obj->heap, obj->size - 1);
        } else if (val > obj->heap[0]) {
            obj->heap[0] = val;
            heapifyDown(obj->heap, obj->size, 0);
        }
    }
}

int add(KthLargest *obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj->heap, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj->heap, obj->size, 0);
    }
    return obj->heap[0];
}

int main() {
    int k = 3;
    int nums[] = {4, 5, 8, 2};
    int numsSize = 4;

    KthLargest obj;
    init(&obj, k, nums, numsSize);

    printf("%d\n", add(&obj, 3));
    printf("%d\n", add(&obj, 5));
    printf("%d\n", add(&obj, 10));
    printf("%d\n", add(&obj, 9));
    printf("%d\n", add(&obj, 4));

    return 0;
}