#include <stdio.h>

#define MAX 100000

int deque[MAX];
int front = 0, rear = -1;

void push_back(int val) {
    deque[++rear] = val;
}

void pop_back() {
    if (rear >= front) rear--;
}

void pop_front() {
    if (front <= rear) front++;
}

int front_val() {
    return deque[front];
}

int back_val() {
    return deque[rear];
}

int is_empty() {
    return front > rear;
}

int main() {
    int n, k;
    scanf("%d", &n);

    int nums[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);

    int dq[MAX];
    int f = 0, r = -1;

    int result[MAX];
    int resSize = 0;

    for (int i = 0; i < n; i++) {

        while (f <= r && dq[f] <= i - k) {
            f++;
        }

        while (f <= r && nums[dq[r]] <= nums[i]) {
            r--;
        }

        dq[++r] = i;

        if (i >= k - 1) {
            result[resSize++] = nums[dq[f]];
        }
    }

    for (int i = 0; i < resSize; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}