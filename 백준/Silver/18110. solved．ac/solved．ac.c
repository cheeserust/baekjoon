#include <stdio.h>
#include <math.h>

int main() {
    int n, i, data, edge = 0;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    int arr[31] = {0,};
    
    for (i = 0; i < n; i++){
        scanf("%d", &data);
        arr[data]++;
        edge += data;
    }
    
    int low15 = (int)round(n * 0.15);
    int high15 = (int)round(n * 0.85);
    
    int count = 0, sum = 0, sumCount = 0;
    for (i = 1; i <= 30; i++){
        for (int j = 0; j < arr[i]; j++){
            count++;
            if (count > low15 && count <= (n - low15)){
                sum += i;
                sumCount++;
            }
        }
    }

    int average = (int)round((double)sum / sumCount);
    printf("%d\n", average);

    return 0;
}