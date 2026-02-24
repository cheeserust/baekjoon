#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    struct Node* top;
} Stack;

void push(Stack* s, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

void pop(Stack* s) {
    Node* current = s->top;
    int data = current->data;
    s->top = current->next;
    free(current);
}

int sum(Stack *s){
    Node* current = s->top;
    int sum = 0;
    while (current != NULL){
        sum += current->data;
        current = current->next;
    }
    return sum;
}

int main(){
    Stack s;
    s.top = NULL;

    int k;
    scanf("%d", &k);
    int input;
    
    for (int i = 0; i < k; i++){
        int num;
        scanf("%d", &num);
        (num != 0) ? push(&s, num) : pop(&s);
    }

    printf("%d", sum(&s));

    return 0;
}