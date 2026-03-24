#include <stdio.h>

int main() {
    int n;
    scanf("%d\n", &n);

    for (int i = (n / 5); i >= 0; i--){
        int remainder = n - i * 5;
        if (remainder % 3 ==0) {
            printf("%d", i + remainder / 3);
            return 0;
        }
    }
    printf("%d", -1);

    return 0;
}