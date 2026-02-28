#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    char str[21];
    for (int i = 0; i < n; i++){
        scanf("%s", str);
        if (strlen(str) >= 6 && strlen(str) <= 9) printf("yes\n");
        else printf("no\n");
    }
    
    return 0;
}