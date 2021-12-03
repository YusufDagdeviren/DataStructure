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

    struct Queue createQueue(unsigned capacity){

        struct Queue *yeni = (struct Queue*)malloc(sizeof (struct Queue));
        yeni->capacity = capacity;
        yeni->front = 0;
        yeni->size = 0;
        yeni->rear = capacity-1;
        yeni->array = (int*) malloc(yeni->capacity*sizeof(int ));
        return yeni;

    }




int main(){


    return 0;
}
