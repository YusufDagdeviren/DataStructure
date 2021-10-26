#include<stdio.h>
#include<stdlib.h>


struct node{
    int deger;
    struct node *sonraki;
    struct node *onceki;
};
void yazdir(struct node *head,int ileriMiGeriMi){

    struct node *temp = head;
    /*
    eğer 1 ise ileri gitsin 2 ise geri gitsin
    */
    if(ileriMiGeriMi == 1){

    while(temp!=NULL){

    printf("\n %d",temp->deger);
    temp = temp->sonraki;

    }


    }else if(ileriMiGeriMi==2){

    while(temp->sonraki != NULL){

    temp = temp->sonraki;
    }

    while(temp !=NULL){

    printf("\n %d",temp->deger);
    temp = temp->onceki;


    }



    }




}




int main(){

    struct node *dugum1 = (struct node*)malloc(sizeof(struct node));
    struct node *dugum2 = (struct node*)malloc(sizeof(struct node));
    struct node *dugum3 = (struct node*)malloc(sizeof(struct node));

    dugum1->deger = 0;
    dugum2->deger = 1;
    dugum3->deger = 2;

    dugum1->onceki = NULL;
    dugum1->sonraki = dugum2;
    dugum2->onceki = dugum1;
    dugum2->sonraki = dugum3;
    dugum3->onceki = dugum2;
    dugum3->sonraki = NULL;

    yazdir(dugum1,1);
    printf("\n\n\n\n\n");
    yazdir(dugum1,2);













return 0;
}
