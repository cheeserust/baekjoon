#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int L;
    scanf("%d", &L);
    char *str = malloc(sizeof(char) * (L + 1));
    scanf("%s", str);
    int *num = malloc(sizeof(int) * (L + 1));
    int len = strlen(str);
    int M = 1234567891;
    int hash = 0;
    int r = 1;
    for (int i = 0; i < len; i++)
    {
        num[i] = str[i] - 96;
        hash += ((num[i])*r)%M;
        r = (r*31) % M;
    }

    printf("%d", hash%M);

    return 0;
}