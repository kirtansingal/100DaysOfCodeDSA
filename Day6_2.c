#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int j = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}