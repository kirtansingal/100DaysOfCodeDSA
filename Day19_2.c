#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int total = nums[0];
    int max_ending = nums[0], max_sum = nums[0];
    int min_ending = nums[0], min_sum = nums[0];

    for (int i = 1; i < n; i++) {
        int x = nums[i];
        total += x;

        max_ending = max(x, max_ending + x);
        max_sum = max(max_sum, max_ending);

        min_ending = min(x, min_ending + x);
        min_sum = min(min_sum, min_ending);
    }

    if (max_sum < 0) {
        printf("%d", max_sum);
    } else {
        int result = max(max_sum, total - min_sum);
        printf("%d", result);
    }

    return 0;
}