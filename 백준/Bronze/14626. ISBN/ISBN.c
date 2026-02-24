#include <stdio.h>

int main(){
    char arr[14];
    scanf("%s", arr);
    int sum = 0;
    int idx = -1;
    for (int i = 0; i < 13; i++){
        if (arr[i] == '*') {
            idx = i;
            continue;
        }
        int num = arr[i] - '0';
        sum += (i % 2 == 1) ? (num * 3) : num;
    }
    
    
    if (idx != -1){
        int ans2 = (10 - sum % 10) % 10;
        for (int j = 0; j <= 9; j++){
            int x = (idx % 2 == 1) ? (j * 3) : j;
            if (x % 10 == ans2){
                printf("%d", j);
                break;
            }
        }
    } 
    return 0;
}