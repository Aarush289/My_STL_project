#include <stdio.h>
#include <stdlib.h>

#define debug 1

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int l = 0; l < cases; l++) {
        int n, x;
        scanf("%d %d", &n, &x);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        if (x >= n) {
            int max = arr[0];
            for (int i = 1; i < n; i++) {
                if (max < arr[i]) { max = arr[i]; }
            }
            printf("%d\n", max);
        } else {
            qsort(arr, n, sizeof(int), compare);
            int answer = 0;
            int count = 0;
            int count1 = 0;
            while (arr[n-1] > 0) {
                if (count1 <= n - x) {
                    answer += arr[n - x];
                    for (int i = n - 1; i >= n - x; i--) {
                        arr[i] -= arr[n - x];
                        if (arr[i] == 0) { count++; }
                    }
                    qsort(arr, n, sizeof(int), compare);
                } else {
                    answer += arr[count1];
                    for (int i = n - 1; i >= count1; i--) {
                        arr[i] -= arr[count1];
                        if (arr[i] == 0) { count++; }
                    }
                    qsort(arr, n, sizeof(int), compare);
                }
                count1 = count;
            }
            printf("%d\n", answer);
        }
    }
    return 0;
}
