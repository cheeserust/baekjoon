#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node* next;
} Node;

typedef struct Stack {
    struct Node* top;
} Stack;

int is_empty(Stack *s){
    return (s->top == NULL) ? 1 : 0;
    // 1 --> 비어있음
}

void push(Stack *s, char data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

void pop(Stack* s){
    if (is_empty(s)) return;
    Node* current = s->top;
    s->top = s->top->next;
    free(current);
    
}

char peak(Stack*s){
    return is_empty(s) ? 0 : s->top->data;
}

void empty(Stack *s){
    while (!is_empty(s)) pop(s);
}

int main(){
    Stack s;
    s.top = NULL;
    char str[102];
    while(1){
        int valid = 1;
        fgets(str, 102, stdin);
        if (strcmp(str, ".\n") == 0) {
            break;  // 입력으로 . 만 들어오면 break
        }

        for (int i = 0; i < strlen(str); i++){
            if (str[i] == '(' || str[i] == '[') push(&s, str[i]);
            else if (str[i] == ')' && peak(&s) == '(')
                pop(&s);
            else if (str[i] == ']' && peak(&s) == '[')
                pop(&s);
            else if (str[i] == ')' || str[i] == ']') { // 괄호 외에 다른 글자일때도 valid 를 0으로 만드는거 방지
                valid = 0;
                break;
            }
        }
        // printf("valid=%d empty=%d\n", valid, is_empty(&s));
        if (valid && is_empty(&s)) printf("yes\n");
        else printf("no\n");
        empty(&s);
    }
    return 0;
}
