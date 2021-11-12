#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

    struct stack{

    int top;
    unsigned capacity;
    int *array;


    };
   /* struct stack* createStack(unsigned capacity){

        struct stack *yeni = (struct stack*) malloc(sizeof(struct stack));
        if(yeni==NULL){

        return NULL;

        }
            yeni->top = -1;
            yeni->capacity = capacity;
            yeni->array = (int *)malloc(yeni->capacity * sizeof(int));
            if(yeni->array ==NULL){
            return NULL;
        }
        return yeni;


    }*/
    struct stack* createStack(unsigned capacity){

    struct stack  *yeni = (struct stack*)malloc(sizeof(struct stack));
    yeni->top = -1;
    yeni->capacity = capacity;
    yeni->array = (int*)malloc(yeni->capacity * sizeof(int));
    return yeni;
    }

    void push(struct stack *yigin,int item){
    if(isFull(yigin)){ //1 ise girer
    return;
    }
    yigin->array[++yigin->top] = item;
    printf("%d elemani yigina eklendi\n",item);



    }

    int isFull(struct stack *yigin){

    return yigin->top == yigin->capacity-1;

    }

    int isEmpty(struct stack *yigin){
    return yigin->top ==-1;

    }

    int pop(struct stack *yigin){

    if(isEmpty(yigin)){ // 1 ise içine girecek
    return INT_MIN;
    }
    return yigin->array[yigin->top--];

    }

int main(){

    struct stack *yeni = createStack(5);
    push(yeni,12);
    push(yeni,15);
    push(yeni,17);
    push(yeni,18);
    push(yeni,19);



    printf("Cikan eleman: %d\n",pop(yeni));
    printf("Cikan eleman: %d\n",pop(yeni));
    printf("Cikan eleman: %d\n",pop(yeni));
    printf("Cikan eleman: %d\n",pop(yeni));
    printf("Cikan eleman: %d\n",pop(yeni));
    printf("Cikan eleman: %d\n",pop(yeni));


return 0;
}
