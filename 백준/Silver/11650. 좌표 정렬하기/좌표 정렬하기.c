#include <stdio.h>
#include <stdlib.h>

typedef struct _Coord {
    int x;
    int y;
}Coord;

int compare(const void * a, const void *b){
    // casting a and b into Coord* and store them into seperate var
    Coord* ca = (Coord*)a;  
    Coord* cb = (Coord*)b;
    if (ca->x < cb->x) return -1;
    if (ca->x > cb->x) return 1;
    // if xs are same then compare y
    if (ca->y < cb->y) return -1;
    if (ca->y > cb->y) return 1;
    return 0;
    }


int main(){
    
    int n, i, j;
    scanf("%d", &n);
    Coord* c = malloc(sizeof(Coord) * n);
    for (i = 0; i < n; i++){
        scanf("%d %d", &c[i].x, &c[i].y);
    }
    
    qsort(c, n, sizeof(Coord), compare);
    
    for (i = 0; i < n; i++){
        printf("%d %d\n", c[i].x, c[i].y);
    }
    free(c);
    return 0;
}

