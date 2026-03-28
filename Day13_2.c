#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {

        for (int j = left; j <= right; j++)
            printf("%d ", matrix[top][j]);
        top++;

        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                printf("%d ", matrix[bottom][j]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}