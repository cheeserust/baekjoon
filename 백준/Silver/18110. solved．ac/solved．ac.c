#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, data;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int cntArr[31] = {0,};
    int* sorted = malloc(sizeof(int) * n);
    int index = 0;

    for (i = 0; i < n; i++){
        scanf("%d", &data);
        cntArr[data]++;
    }

    for (i = 1; i <= 30; i++){
        for (int j = 0; j < cntArr[i]; j++){
            sorted[index] = i;
            index++;
        }
    }
    int low15 = (int)round(n * 0.15);
    int sum = 0;
    int count = 0;
    for (i = low15; i < n - low15; i++){
        sum += sorted[i];
        count++;
    }
    int avg = (int)round((double)sum / count);
    printf("%d\n", avg);
    free(sorted);
    return 0;
}