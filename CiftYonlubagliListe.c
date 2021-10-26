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
struct node* olustur(int deger){

struct node *yeniDugum =(struct node*)malloc(sizeof(struct node));
yeniDugum->deger = deger;
yeniDugum->sonraki = NULL;
yeniDugum->onceki = NULL;
return yeniDugum;

}
void sonaEkle(struct node* head,int sayi){
struct node *yeniEleman = olustur(sayi);
struct node *temp = head;

while(temp->sonraki != NULL){

    temp = temp->sonraki;


}

   temp->sonraki = yeniEleman;
   yeniEleman->onceki = temp;




}


int main(){

    struct node *dugum1 = olustur(0);
    struct node *dugum2 = olustur(1);
    struct node *dugum3 = olustur(2);



    dugum1->onceki = NULL;
    dugum1->sonraki = dugum2;
    dugum2->onceki = dugum1;
    dugum2->sonraki = dugum3;
    dugum3->onceki = dugum2;
    dugum3->sonraki = NULL;

    yazdir(dugum1,1);
    printf("\n\n\n\n\n");
    yazdir(dugum1,2);
    printf("\n\n\n\n\n");
    sonaEkle(dugum1,55);
    yazdir(dugum1,1);
    printf("\n\n\n\n\n");
    yazdir(dugum1,2);










return 0;
}
