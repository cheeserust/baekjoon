#include <stdio.h>
#include <stdlib.h>

int compare(const void*a, const void*b){
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int bin_search(int arr[], int start, int end, int target){

    while (start <= end){
        int mid = (start + end) / 2;
        if (arr[mid] == target) return 1;
        if (arr[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return 0;
}

int main() {
    int n, m, i;

    scanf("%d", &n);
    int* arrN = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++){
        scanf("%d", &arrN[i]);
    }

    scanf("%d", &m);
    int* arrM = malloc(sizeof(int) * m);
    for (i = 0; i < m; i++){
        scanf("%d", &arrM[i]);
    }

    qsort(arrN, n, sizeof(int), compare);
    
    int start = 0;
    int end = n - 1;

    
    for (i = 0; i < m; i++){
        printf("%d\n", bin_search(arrN, start, end, arrM[i]));
    }
    printf("\n");
    free(arrN);
    free(arrM);

    return 0;
}