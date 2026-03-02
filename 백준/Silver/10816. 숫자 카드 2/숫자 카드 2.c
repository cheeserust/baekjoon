#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b){
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int bin_low(int arr[], int start, int end, int target){
    int result = -1;  // 0번째 index 에 요소가 있을경우 오류 방지
    while (start <= end){
        int mid = (start + end) / 2;
        if (arr[mid] == target){
            result = mid;
            end = mid - 1;
            }
        else if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return result;
}
int bin_high(int arr[], int start, int end, int target){
    int result = -1;  // 0번째 index 에 요소가 있을경우 오류 방지
    while (start <= end){
        int mid = (start + end) / 2;
        if (arr[mid] == target){
            result = mid;
            start = mid + 1;
                }
        else if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return result;
}
int main(){
    int n, m, i, j;

    scanf("%d", &n);
    int* arrN = malloc(sizeof(int) * n);
    for (i = 0; i < n;i++){
        scanf("%d ", &arrN[i]);
    }

    scanf("%d", &m);
    int* arrM = malloc(sizeof(int) * m);
    for (i = 0; i < m;i++){
        scanf("%d ", &arrM[i]);
    }

    qsort(arrN, n, sizeof(int), compare);
    int start = 0;
    int end = n - 1;
    for (i = 0; i < m; i++){
        int low = bin_low(arrN, 0, n - 1, arrM[i]);
        int high = bin_high(arrN, 0, n - 1, arrM[i]);
        int count = (low == -1) ? 0 : high - low + 1;
        printf("%d ", count);
    }
    free(arrN);
    free(arrM);

    return 0;
}
