#include <stdio.h>

unsigned int fact(unsigned int num) {
    if (num == 0 || num == 1) return 1;
    return num * fact(num - 1);
}

int main() {
    unsigned int n, k;
    scanf("%u %u", &n, &k);
    if (n == 0 || k == 0 || n == k) {
        printf("%d\n", 1);
        return 0;
    }
    
    unsigned int bt = (fact(n) / (fact(k)*fact(n-k)));
    printf("%u", bt);
    return 0;
}