#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int firstRow = 0, firstCol = 0;

    for (int j = 0; j < n; j++)
        if (a[0][j] == 0)
            firstRow = 1;

    for (int i = 0; i < m; i++)
        if (a[i][0] == 0)
            firstCol = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] == 0) {
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][0] == 0 || a[0][j] == 0)
                a[i][j] = 0;
        }
    }

    if (firstRow) {
        for (int j = 0; j < n; j++)
            a[0][j] = 0;
    }

    if (firstCol) {
        for (int i = 0; i < m; i++)
            a[i][0] = 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}