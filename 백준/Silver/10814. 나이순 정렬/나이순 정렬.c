#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 101
#define MAX_AGE 201

typedef struct {
    int age;
    char name[MAX_NAME];
} Person;

int main(){
    int n, i;
    scanf("%d", &n);

    Person* arr = malloc(sizeof(Person) * n);
    for (i = 0; i < n; i++){
        scanf("%d %s", &arr[i].age, arr[i].name);
    }
    int count[MAX_AGE] = {0};
    for (i = 0; i < n; i++) {
        count[arr[i].age]++;
    }
    for (i = 1; i < MAX_AGE; i++) {
        count[i] += count[i - 1];
    }

    Person* output = malloc(sizeof(Person) * n);
    for (i = n - 1; i >= 0; i--){
        output[--count[arr[i].age]] = arr[i];
    }
    for (i = 0; i < n; i++){
        printf("%d %s\n", output[i].age, output[i].name);
    }
    free(arr);
    free(output);
    return 0;
}
