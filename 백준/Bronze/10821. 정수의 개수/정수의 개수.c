#include <stdio.h>

int main() {
    char arr[101];
    scanf("%s", arr);
    int count = 0, i = 0;
    while(arr[i]!='\0'){
        if (arr[i] == ',') count++;
        i++;
    }
    printf("%d", count+1);

    return 0;
}