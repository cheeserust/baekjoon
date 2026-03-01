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
            // input[i] 를 기준으로 input[j] (즉 다른 사람들) 하고 비교해서 다른사람이 더 크면 count++ (순위가 낮아짐)
            if (input[i].x < input[j].x && input[i].y < input[j].y) count++;
        }
        // 1위를 기준으로 가장 높은 count는 0 (자기 자신보다 덩치가 클순 없으므로)
        // 그래서 +1 해줌
        printf("%d ", count+1);
    }
    free(input);
    return 0;
}


