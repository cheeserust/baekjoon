#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    int t;
    scanf("%d", &t);
    int pCounter = 0;
    char str[51] = {0};
    for (int i = 0; i < t; i++){
        scanf("%s", str);
        int is_valid = 1;
        for (int j = 0; j < strlen(str); j++){
            
            if (str[j] == '('){
                pCounter++;
                //printf("%c, %d\n", str[j], pCounter);
            }
            else if (str[j] == ')'){
                pCounter--;
                if (pCounter < 0) {
                    is_valid = 0;
                    break;
                }
            }
        }
    if (pCounter != 0) is_valid = 0;
    printf("%s\n", (pCounter == 0) ? "YES" : "NO");
    pCounter = 0;
    }
    return 0;
}