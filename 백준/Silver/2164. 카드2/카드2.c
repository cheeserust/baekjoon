#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct queue{
    struct Node* head;
    struct Node* tail;
} Queue;

void enQ(Queue* q, int data){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->head == NULL){
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int deQ(Queue *q) {
    Node* current;
    current = q->head;
    int data = current->data;
    q->head = current->next;
    free(current);
    return data;
}

int main(){
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        enQ(q, i);
    }
    while(q->head != q->tail){
        deQ(q);
        enQ(q, deQ(q));
    }
    printf("%d", q->head->data);
    free(q);
    return 0;
}

