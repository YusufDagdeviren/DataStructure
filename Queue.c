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
        printf("%d kuyruga eklendi: ",queue->array[queue->rear]);
    }

int main(){


    return 0;
}
