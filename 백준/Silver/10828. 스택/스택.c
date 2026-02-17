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
        printf("%d\n", -1);
        return;
    }
    else {
        temp = s->top;
        int data = temp->data;
        s->top = s->top->next;
        free(temp);
        printf("%d\n", data);
        return;
    }
}

void size(Stack* s){
    int i = 0;
    Node* current = s->top;
    while(current != NULL) {
        i++;
        current = current->next;
    }
    printf("%d\n", i);
}

void empty(Stack* s){
    printf("%d\n", (s->top == NULL) ? 1 : 0);
}

void top(Stack * s){ // peak
    printf("%d\n", (s->top == NULL) ? -1 : s->top->data);

}

int main() {
    Stack s;
    s.top = NULL;
    int n;
    scanf("%d", &n);
    char arr[6];
    for (int i = 0; i < n; i++){
        scanf("%s", arr);
        if(strcmp(arr, "push") == 0) {
            int num;
            scanf("%d", &num);
            push(&s, num);
        }
        else if (strcmp(arr, "pop") == 0) {
            pop(&s);
        } 
        else if (strcmp(arr, "size") == 0) {
            size(&s);
        } 
        else if (strcmp(arr, "empty") == 0) {
            empty(&s);
        } 
        else if (strcmp(arr, "top") == 0) {
            top(&s);
        }
    }

        return 0;
}