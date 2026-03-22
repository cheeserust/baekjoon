#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int s[], int x){
    if (s[x - 1] == 0) s[x - 1] = x;
    else
        return;
}

void rmv(int s[], int x){
    if (s[x - 1] == x) s[x - 1] = 0;
    else
        return;
}

void check(int s[], int x){
    printf("%d\n" , (s[x - 1] == x) ? 1 : 0);
}

void toggle(int s[], int x){
    if (s[x-1] == x) s[x-1] = 0;
    else s[x-1] = x;

}

void all(int s[]){
    for (int i = 0; i < 20;i++){
        s[i] = (i + 1);
    }
}

void empty(int s[]){
    for (int i = 0; i < 20;i++){
        s[i] = 0;
    } 
}


int main(){
    int s[20] = {0};
    char str[7];
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        int x;
        scanf("%s %d", str, &x);
        if (strcmp(str, "add") == 0){
            add(s, x);
        } else if (strcmp(str, "remove") == 0){
            rmv(s, x);
        } else if (strcmp(str, "check") == 0){
            check(s, x);
        } else if (strcmp(str, "toggle") == 0){
            toggle(s, x);
        } else if (strcmp(str, "all") == 0){
            all(s);
        } else if (strcmp(str, "empty") == 0){
            empty(s);
        }
    }
        return 0;
}

