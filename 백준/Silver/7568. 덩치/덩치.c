#include <stdio.h>
#include <stdlib.h>

typedef struct Spec {
    int x;
    int y;
}Spec;

int main(){
    int n;
    scanf("%d", &n);

    Spec* input = malloc(sizeof(Spec) * n);

    for (int i = 0; i < n;i++){
        scanf("%d %d", &input[i].x, &input[i].y);
    }
    
    for (int i = 0; i < n; i++){
        int count = 0;
        for (int j = 0; j < n; j++){
            if (input[i].x < input[j].x && input[i].y < input[j].y) count++;
        }
        printf("%d ", count+1);
    }
    free(input);
    return 0;
}

