#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, num;
    int count[10001] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &num);
        count[num]++;
    }
    for (i = 1; i <= 10000; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d\n", i);
        }
    }
    return 0;
}