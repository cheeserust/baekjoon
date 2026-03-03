#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    struct Node* head;
    struct Node* tail;
} Queue;

void enQ(Queue* q, int data){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    }
    else{
        q->tail->next = new_node;
        q->tail = new_node;
    }
}
int deQ(Queue* q){
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

    int n, k, i, j;
    scanf("%d %d", &n, &k);

    int* output = malloc(sizeof(int) *n);
    for (i = 0; i < n; i++) enQ(q, i + 1);

    int outputIdx = 0;
    while(outputIdx < n){
        for (i = 1; i < k; i++){
            enQ(q, deQ(q));
        }
        output[outputIdx++] = deQ(q);

        
    }
    printf("<");
    for (i = 0; i < n; i++){
        printf("%d", output[i]);
        if (i < n-1) printf(", ");
    }
    printf(">");
    free(q);
    return 0;
}

