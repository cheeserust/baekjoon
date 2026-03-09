#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    char** arrN = malloc(sizeof(char*) * n);
    for (i = 0; i < n; i++){
        arrN[i] = malloc(sizeof(char) * (m + 1));
        scanf("%s", arrN[i]);
    }
    int max_cost = 64; 
    // 최대 64개 칠할수있음
    
    // count2 = [0][0] == 'W  일때 칠하는 칸 개수
    int i8, j8; // 8*8 짜리 반복용 변수
    for (i8 = 0; i8 <= n - 8; i8++){
        for (j8 = 0; j8 <= m - 8; j8++) {
            // count1 = [0][0] == 'B' 일때 칠하는 칸 개수
            int count1 = 0;
            for (i = i8; i < i8 + 8;i++){
                for (j = j8; j < j8 + 8; j++){
                    if ((i + j) % 2 == 0 && arrN[i][j] != 'W')
                        count1++;
                    else if ((i+j) % 2 == 1 && arrN[i][j] != 'B')
                        count1++;
                }
            }
            int count2 = 64 - count1;
            int cost = count1 < count2 ? count1 : count2;
            if (cost < max_cost) max_cost = cost;
        }
    }
        
    printf("%d", max_cost);
    return 0;
}

