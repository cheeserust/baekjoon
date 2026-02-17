#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    struct Node* top;
} Stack;

void push(Stack* s, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

void pop(Stack* s){
    Node* temp;
    if (s->top == NULL) {
        return;
    }
    else {
        temp = s->top;
        int data = temp->data;
        s->top = s->top->next;
        free(temp);
        return;
    }
}

int empty(Stack* s){
    return (s->top == NULL) ? 1 : 0;
}

void check(Stack* s, char* arr){
    int is_valid = 1;
    
    for (int i = 0; i < strlen(arr); i++){
        if (arr[i] == '('){
            push(s, arr[i]);
        } else if (arr[i] == ')'){
            if(empty(s) == 1) {
                is_valid = 0;
                break;
            }
            pop(s);
        }
    }
    if (empty(s) == 0) is_valid = 0;
    printf("%s\n", (is_valid) ? "YES" : "NO");
    while(empty(s) == 0) pop(s);
}

int main() {
    Stack s;
    s.top = NULL;
    int t;
    scanf("%d", &t);
    char str[51] = {0};
    for (int i = 0; i < t; i++){
        scanf("%s", str);
        check(&s, str);
        }

        return 0;
}