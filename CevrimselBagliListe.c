#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;


};

void makeCircular(struct node *head){
/*
this method makes singly linked list to circular list
*/

    struct node *temp = head;
    while(temp->next != NULL){
    temp = temp->next;
    }
    temp->next = head;

}
void printCircularList(struct node *head){

struct node *temp = head;

    do{

    printf("%d\n",temp->data);
    temp = temp->next;
    }while(temp != head);


}
void pushOver(struct node **head,int newData){

    struct node *temp = *head;
    struct node *yeni = (struct node *)malloc(sizeof(struct node));
    yeni->data = newData;
    yeni->next = *head; //1. adım

    if(*head != NULL){

    while(temp->next ==*head){
    temp = temp->next; //2.Adım
    temp->next = yeni;
    }

    }
    *head = yeni; // 3.Adım

}
void addFirst(struct node **head,int newData){

struct node *temp = *head;
struct node *yeni = (struct node *)malloc(sizeof(struct node));
yeni->data = newData;

while(temp->next != *head){

temp = temp->next;


}
temp->next = yeni;// 1
yeni->next = *head; // 2
*head = yeni; // 3
}
void addLast(struct node *head,int newData){
struct node *temp = head;
struct node *yeni = (struct node *)malloc(sizeof(struct node));
yeni->data = newData;

while(temp->next != head){

temp = temp->next;


}
temp->next = yeni;
yeni->next = head;






}

int main(){

 /*struct node *dugum1 = (struct node *)malloc(sizeof(struct node));
 struct node *dugum2 = (struct node *)malloc(sizeof(struct node));
 struct node *dugum3 = (struct node *)malloc(sizeof(struct node));

dugum1->data = 1;
dugum2->data = 2;
dugum3->data = 3;

dugum1->next = dugum2;
dugum2->next = dugum3;

makeCircular(dugum1);
addFirst(&dugum1,55);
addLast(dugum1,33);
printCircularList(dugum1);
*/
struct node *dugum1 = NULL;
pushOver(&dugum1,1);
pushOver(&dugum1,2);
pushOver(&dugum1,3);
pushOver(&dugum1,4);
printCircularList(dugum1);

return 0;
}
