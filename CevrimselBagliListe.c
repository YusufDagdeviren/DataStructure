#include<stdio.h>
#include<stdlib.h>

struct node{

    int deger;
    struct node *sonraki;


};
    void push(struct node **head,int data){
        struct node *yeni =(struct node*)malloc(sizeof(struct node));
        struct node *temp = *head;
        yeni->deger = data;
        yeni->sonraki = *head;

        if(*head != NULL){

            while(temp->sonraki != *head){
            temp = temp->sonraki;

            }

            temp->sonraki = yeni;

        }
        else{
            yeni->sonraki = yeni;

        }
          *head = yeni;
            /*
            uzun uğraşlar sonucu olmadan anlaşıldı
            */
    /*struct node *yeni = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
    yeni->deger = data;
    yeni->sonraki = *head;


    if (*head != NULL)
    {
        while (temp->sonraki != *head){
            temp = temp->sonraki;
        }

        temp->sonraki = yeni;
    }
    else{
        yeni->sonraki = yeni;
            }
    *head = yeni;


*/
    }

    void printCircularLinkedList(struct node *head){

    struct node *temp = head;
    int i = 1;
    do{
    printf("%d. eleman = %d\n",i,temp->deger);
    temp = temp->sonraki;
    i++;
    }while(temp != head);



    }


    int main(){

    struct node *head = NULL;


    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);


    printCircularLinkedList(head);



    return 0;
    }


