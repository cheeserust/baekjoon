#include <stdio.h>
#include <math.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    int a = sqrt(n);

    for (int i = m; i <= n; i++){
        if (i < 2) continue;
        int flag = 1;
        int a = (int)sqrt(i);
        for (int j = 2; j <= a; j++){
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) printf("%d\n", i);
    }
    
    return 0;
}

