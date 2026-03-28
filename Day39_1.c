#include <stdio.h>

#define MAX 100000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
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

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int val) {
    heap[size] = val;
    heapifyUp(size);
    size++;
}

int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int extractMin() {
    if (size == 0) return -1;

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if (op[0] == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'p' && op[1] == 'e') {
            printf("%d\n", peek());
        } else if (op[0] == 'e') {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}