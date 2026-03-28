#include <stdio.h>
#include <stdlib.h>

#define MAX 26

int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int leastInterval(char tasks[], int tasksSize, int n) {
    int freq[MAX] = {0};

    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    qsort(freq, MAX, sizeof(int), cmp);

    int maxFreq = freq[0];
    int maxCount = 0;

    for (int i = 0; i < MAX; i++) {
        if (freq[i] == maxFreq) {
            maxCount++;
        }
    }

    int partCount = maxFreq - 1;
    int partLength = n - (maxCount - 1);
    int emptySlots = partCount * partLength;
    int availableTasks = tasksSize - (maxFreq * maxCount);
    int idles = (emptySlots > availableTasks) ? (emptySlots - availableTasks) : 0;

    return tasksSize + idles;
}

int main() {
    int n;
    scanf("%d", &n);

    char tasks[1000];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &tasks[i]);
    }

    int gap;
    scanf("%d", &gap);

    int result = leastInterval(tasks, n, gap);
    printf("%d", result);

    return 0;
}