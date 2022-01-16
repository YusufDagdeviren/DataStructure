#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Queue{

    int front;
    int rear;
    int size;
    unsigned capacity;
    int *array;

};
int ortBul(struct Queue* queue) {
    int toplam = 0;
    int adet = 0;
    while (!isEmpty(queue)) {

        toplam += dequeue(queue);
        adet++;


    }
    return toplam / adet;



    }
    struct Queue* createQueue(unsigned capacity){

        struct Queue *yeni = (struct Queue*)malloc(sizeof (struct Queue));
        yeni->capacity = capacity;
        yeni->front = 0;
        yeni->size = 0;
        yeni->rear = capacity-1;
        yeni->array = (int*) malloc(yeni->capacity*sizeof(int ));
        return yeni;

    }
    int isFull(struct Queue *queue){
        return (queue->size == queue->capacity);
    }
    int isEmpty(struct Queue *queue){
        return (queue->size == 0);
    }
    void enqueue(struct Queue *queue,int item){

        if(isFull(queue))
            return;
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->size = queue->size + 1;
        queue->array[queue->rear] = item;
        printf("%d kuyruga eklendi:\n",queue->array[queue->rear]);
    }
    int dequeue(struct Queue *queue){

        if(isEmpty(queue)){
            return INT_MIN;
        }
        int item = queue->array[queue->front];
        queue->front = (queue->front +1) % queue->capacity;
        queue->size = queue->size -1;
        return item;


    }

int main(){
    struct Queue *newQueue = createQueue(5);
    enqueue(newQueue,0);
    enqueue(newQueue,1);
    enqueue(newQueue,2);
    //printf("%d kuyruktan cikarildi...\n", dequeue(newQueue));
    //printf("%d kuyruktan cikarildi...\n", dequeue(newQueue));
    //printf("%d kuyruktan cikarildi...\n", dequeue(newQueue));
    printf("Ortalama = %d", ortBul(newQueue));
    return 0;
}
