#include<stdio.h>
#include<stdlib.h>

struct node{
    int deger;
    struct node *sonraki;


};






void printList(struct node* head){

struct node *temp = head;
do{
printf("%d\n",temp->deger);
temp = temp->sonraki;

}while(temp!=head);




}

void push(struct node **head,int data){
    struct node *temp = *head;
    struct node* yeni = (struct node*)malloc(sizeof(struct node));
    yeni->deger = data;
    yeni->sonraki = *head;
    if(*head!=NULL){
    while(temp->sonraki==*head){
    temp = temp->sonraki;
    temp->sonraki = yeni;
    }
    }
    else{
    yeni->sonraki = temp;

    }
    *head = yeni;

    }



int main(){
struct node* dugum1 = NULL;

push(&dugum1,1);
push(&dugum1,2);
push(&dugum1,3);
printList(dugum1);




return 0;
}
