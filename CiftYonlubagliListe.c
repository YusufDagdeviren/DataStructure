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

    while(temp->onceki !=NULL){

    temp = temp->onceki;
    }

    while(temp!=NULL){

    printf("\n %d",temp->deger);
    temp = temp->sonraki;

    }


    }
    else if(ileriMiGeriMi==2){

    while(temp->sonraki != NULL){

    temp = temp->sonraki;
    }

    while(temp != NULL){

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
void basaEkle(struct node *head,int sayi){

struct node *yeniDugum = olustur(sayi);

struct node *temp = head;
while(temp->onceki !=NULL){

    temp = temp->onceki;
    }


 temp->onceki = yeniDugum;
 yeniDugum->sonraki = temp;


}
int elemanBas(struct node *head){


int elemanSayi = 0;
struct node *temp = head;

while(temp->onceki != NULL){


temp = temp->onceki;

}
while(temp != NULL){


temp = temp->sonraki;
elemanSayi++;
}
return elemanSayi;
}
void arayaElemanEkle(struct node *head,int eklenecek,int indis){

struct node *yeni = olustur(eklenecek);
int cursor = 0;
struct node *temp = head;

while(temp->onceki != NULL){

temp = temp->onceki;
}


while(temp->sonraki != NULL){

if(cursor == indis -1){
break;
}


temp = temp->sonraki;
cursor++;
}
struct node *gecici = temp->sonraki;
temp->sonraki = yeni;
yeni->onceki = temp;
yeni->sonraki = gecici;
gecici->onceki = yeni;





}
void sonElemanSil(struct node *head){

struct node *temp = head;
while(temp->sonraki != NULL){



temp = temp->sonraki;



}
temp->onceki->sonraki = NULL;
free(temp);


}
void basElemanSil(struct node *head){
struct node *temp = head;
while(temp->onceki != NULL){


temp = temp->onceki;
}
temp->sonraki->onceki = NULL;
free(temp);

}
void aradanElemanSil(struct node *head,int indis){
struct node *temp = head;
int cursor = 0;
while(temp->onceki != NULL){
temp = temp->onceki;

}
while(temp->sonraki != NULL){

if(cursor == indis-1){
break;
}
temp = temp->sonraki;
cursor++;
}
struct node *gecici = temp->sonraki;
temp->sonraki = gecici->sonraki;
gecici->sonraki->onceki = temp;
free(gecici);


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

   /* yazdir(dugum1,1);
    printf("\n\n\n\n\n");
    yazdir(dugum1,2);
    printf("\n\n\n\n\n");
    sonaEkle(dugum1,55);
    yazdir(dugum1,1);
    printf("\n\n\n\n\n");
    yazdir(dugum1,2);
    printf("\n\n\n\n\n");*/
    basaEkle(dugum1,35);
    yazdir(dugum1,1);
    /*printf("\n\n\n\n\n");
    yazdir(dugum1,2);
    printf("\n\n\n\n\n");
    basaEkle(dugum1,41);
    yazdir(dugum1,1);*/
    printf("\n\n\n\n\n");
    arayaElemanEkle(dugum1,61,2);
    yazdir(dugum1,1);

    /*printf("\n\n\n\n\n");
    sonElemanSil(dugum1);
    yazdir(dugum1,1);
    printf("\n\n\n\n\n");
    yazdir(dugum1,2);*/
    printf("\n\n\n\n\n");
    aradanElemanSil(dugum1,2);
    yazdir(dugum1,1);
    printf("\n\n\n\n\n");
    printf("Eleman sayisi = %d",elemanBas(dugum1));

   /* basElemanSil(dugum1);
    yazdir(dugum1,1);
    printf("\n\n\n\n\n");
    printf("Eleman sayisi = %d",elemanBas(dugum1));*/




return 0;
}
