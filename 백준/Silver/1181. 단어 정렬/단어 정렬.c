#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void *a ,const void *b ) {
    const char *arr1 = (const char*)a;
    const char *arr2 = (const char*)b;

    if (strlen(arr1) < strlen(arr2)) return -1;
    if (strlen(arr1) > strlen(arr2)) return 1;
    return strcmp(arr1,arr2);
}

int main(){
    int n;
    scanf("%d", &n);
    char list[n][51];

    for (int i = 0; i < n; i++){
        scanf("%s", list[i]);
    }
    qsort(list, n, sizeof(list[0]), compare);

    for (int i = 0; i < n; i++){
        if (strcmp(list[i], list[i-1]) != 0)
        printf("%s\n", list[i]);
    }


    return 0;
}

