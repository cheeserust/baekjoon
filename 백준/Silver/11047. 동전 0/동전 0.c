#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k, i, j = 1;
    scanf("%d %d", &n, &k);

    int* coin = malloc(sizeof(int) * n);
    for (i = 0; i < n;i++) {
        scanf("%d", &coin[i]);
    }

    int temp = k;
    int count = 0;
    while (1) {
        count += temp / coin[n - j];
        temp %= coin[n - j];
        
        j++;
        if (temp == 0) break;
    }
    printf("%d", count);
    free(coin);
    return 0;
}

