#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, num;
    scanf("%d", &n);
    int top = 0, next = 1, count = 0;
    int* stack = malloc(sizeof(int) * n);
    char output[1000001];
    for (i = 0; i < n; i++){
        scanf("%d", &num);
        while (next <= num){
            stack[top] = next;
            top++;                            
            next++;                           
            output[count] = '+';
            //printf("+ ");  // 지울거
            count++;
        }
        if (stack[top - 1] != num) {
            printf("NO\n");
            free(stack);
            return 0;
        } 
    
        top--;
        output[count] = '-';
        //printf("- "); // 지울거
        count++;

        
    }
    for (i = 0; i < count;i++){
        printf("%c\n", output[i]);
    }
    free(stack);
    return 0;
}