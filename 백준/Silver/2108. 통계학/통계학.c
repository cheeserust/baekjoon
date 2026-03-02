#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){
    int n; scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    int sum = 0, max = -4000, min = 4000;
    int count[8001] = {0};

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
        count[arr[i]+4000]++;  // 음수 인덱스 방지
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }

    int* countSum = malloc(sizeof(int) * 8001);
    countSum[0] = count[0];
    for (int i = 1; i < 8001; i++){
        countSum[i] = countSum[i - 1] + count[i];
    }
    
    int* new_arr = malloc(sizeof(int) * n);
    for (int i = n-1; i >= 0; i--){
        int idx = arr[i] + 4000;
        new_arr[countSum[idx]-1] = arr[i];
        countSum[idx]--;
    }

    // mean
    int mean = (int)round((double)sum / n);
    printf("%d\n", mean);
    
    // middle
    qsort(arr, n, sizeof(int), compare);
    printf("%d\n", arr[n / 2]);
    
    // mode
    int mode = 0;
    for (int i = 0; i < 8001; i++){
        if (count[i] > mode) mode = count[i];
    }
    int modeList[8001], modeCount = 0;
    for (int i = 0; i < 8001; i++){
        if (count[i] == mode) modeList[modeCount++] = i - 4000;
    }
    mode = (modeCount == 1) ? modeList[0] : modeList[1];
    printf("%d\n", mode);

    // range
    printf("%d\n", max - min);

    free(arr);
    free(countSum);
    free(new_arr);
    return 0;
}
