#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    struct Node* head;
    struct Node* tail;
}Queue;

void push(Queue* q, int data){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    }
    else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

void pop(Queue* q){
    Node* current;
    if (q->head == NULL) {
        printf("%d\n", -1);
    } else {
        current = q->head;
        int data = current->data;
        q->head = current->next;
        printf("%d\n", current->data);
        free(current);
    }
}

void size(Queue *q){
    int count = 0;
    Node* current = q->head;
    while(current != NULL){
        current = current->next;
        count++;
    }
    printf("%d\n", count);
}
void empty(Queue *q){
    printf("%d\n", q->head == NULL ? 1 : 0);
}
void front(Queue *q){
    printf("%d\n", q->head == NULL ? -1 : q->head->data);
}
void back(Queue *q){
    printf("%d\n", q->head == NULL ? -1 : q->tail->data);
}

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    int n;
    scanf("%d", &n);
    char str[6];
    for (int i = 0; i < n; i++){
        scanf("%s", str);
        if(strcmp(str, "push") == 0) {
            int num;
            scanf("%d", &num);
            push(q, num);
        }
        else if (strcmp(str, "pop") == 0){
            pop(q);
        }else if (strcmp(str, "size") == 0){
            size(q);
        }else if (strcmp(str, "empty") == 0){
            empty(q);
        }else if (strcmp(str, "front") == 0){
            front(q);
        }else if (strcmp(str, "back") == 0){
            back(q);
        }
    }

    free(q);
    return 0;
}