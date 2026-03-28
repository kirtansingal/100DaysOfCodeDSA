#include <stdio.h>

int main() {
    int n1, n2;

    scanf("%d", &n1);
    int nums1[n1];
    for (int i = 0; i < n1; i++)
        scanf("%d", &nums1[i]);

    scanf("%d", &n2);
    int nums2[n2];
    for (int i = 0; i < n2; i++)
        scanf("%d", &nums2[i]);

    int visited[1000] = {0};
    int result[1000], k = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (!visited[j] && nums1[i] == nums2[j]) {
                result[k++] = nums1[i];
                visited[j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < k; i++)
        printf("%d ", result[i]);

    return 0;
}