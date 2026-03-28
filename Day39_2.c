#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

int cmp(const void *a, const void *b) {
    return ((Pair*)b)->freq - ((Pair*)a)->freq;
}

int main() {
    int n, k;
    scanf("%d", &n);

    int *nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);

    Pair *arr = (Pair*)malloc(n * sizeof(Pair));
    int size = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j].num == nums[i]) {
                arr[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            arr[size].num = nums[i];
            arr[size].freq = 1;
            size++;
        }
    }

    qsort(arr, size, sizeof(Pair), cmp);

    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i].num);
    }

    free(nums);
    free(arr);

    return 0;
}