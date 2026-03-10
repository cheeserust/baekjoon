#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int priority; // data
    struct Node* next;
} Node;

typedef struct Queue{
    struct Node* head;
    struct Node* tail;
} Queue;

// push pop scan

void enQ(Queue* q, int data){
    Node* new_node = malloc(sizeof(Node));
    new_node->priority = data;
    new_node->next = NULL;
    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int deQ(Queue * q){
    Node* current = q->head;
    int data = current->priority;
    q->head = current->next;
    free(current);
    return (data);
}

int find_max(Queue*q){
    Node* current = q->head;
    int max = 0;
    while(current!=NULL){
        if (current->priority > max) max = current->priority;
        current = current->next;
    }
    return max;
}

int print(Queue* q, int n, int m){
    int count = 0;
    while(1){
        int max = find_max(q);
        if (q->head->priority == max) {
            if (m == 0) return count + 1;
            deQ(q);
            count++;
            m--;
            n--;

        } else {
            enQ(q, deQ(q));
            if (m == 0) 
                m = n - 1;
            else
                m--;
        }
    }
}

int main(){
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;

    int t;
    scanf("%d", &t);
    int n, m, i, j, p;
    for (i = 0; i < t; i++){
        while (q->head != NULL) deQ(q);
        q->tail = NULL;

        scanf("%d %d", &n, &m);
        for (j = 0; j < n;j++){
            scanf("%d", &p);
            enQ(q, p);
        }
        int whereInLine = print(q, n, m);
        printf("%d\n", whereInLine);
    }

    free(q);
    return 0;
}

