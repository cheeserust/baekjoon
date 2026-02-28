#include <stdio.h>

int main() {
    int w, h;
    scanf("%d %d", &w, &h);
    float ans = (float)w * (float)h * 0.5;
    printf("%.1f", ans);

    return 0;
}