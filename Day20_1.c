#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long count = 0, prefix = 0;

    int maxSize = 2 * n + 1;
    int *map = (int *)calloc(maxSize, sizeof(int));

    int offset = n;

    map[offset] = 1;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        int index = prefix + offset;

        if (index >= 0 && index < maxSize) {
            count += map[index];
            map[index]++;
        }
    }

    printf("%lld", count);

    free(map);
    return 0;
}