#include<stdio.h>
#include<stdlib.h>
#include<time.h>
    struct node{

    int deger;

    struct node *sonraki;


    };
    //
    struct node *olustur(int deger){
    /*
    recursive fonksiyonda tek yönlü listeyi ters çevirme
    */

    struct node *yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->deger = deger;
    yeniDugum->sonraki =NULL;
    return yeniDugum;
    }
   void printfList(struct node *dugum){


   struct node *temp = dugum;
   while(temp!=NULL){

    printf("%d\n",temp->deger);
    temp = temp->sonraki;

   }



   }
   void basaEkle(struct node **head,int sayi){
    struct node *basEleman =olustur(sayi);


    // **head baslangicin referans�
    struct node *temp = *head;

    *head = basEleman;

    basEleman->sonraki = temp;


    }
   void sonaEkle(struct node *head,int sayi){
    struct node *sonEleman =olustur(sayi);



    struct node *temp = head;

    while(temp->sonraki!=NULL){


        temp = temp->sonraki;


    }
    temp->sonraki = sonEleman;
    sonEleman->sonraki = NULL;

    }
   void arayaEkle(struct node *head,int sayi,int indis){
    struct node *yeni = olustur(sayi);

    struct node *temp = head;
    int counter = 0;
    while(temp!=NULL){

        if(counter== indis-1){
            break;
        }
        counter++;
        temp = temp->sonraki;


    }
    struct node *eskiSayi = temp->sonraki;
    temp->sonraki = yeni;
    yeni->sonraki = eskiSayi;


    }
   void sondanSil(struct node *head){

   struct node *temp = head;
   while(temp->sonraki->sonraki != NULL){


    temp = temp->sonraki;

   }
   free(temp->sonraki);
   temp->sonraki = NULL;


   }
   void bastanSil(struct node **head){

   struct node *temp =  *head;
   *head = temp->sonraki;



   }
   void reverse(struct node **head){

   struct node *temp = *head;
   struct node *next = NULL;
   struct node *prev = NULL;
   while(temp != NULL){

    next = temp->sonraki;
    temp->sonraki = prev;
    prev = temp;
    temp = next;
   }
    *head = prev;



   }
   void arayaEkleDegerIleOnce(struct node *head,int sayi,int eklenecekSayi){
   struct node *ekle = olustur(eklenecekSayi);

   struct node *temp = head;

   while(temp->sonraki->deger != sayi){
    temp = temp->sonraki;


   }
   struct node *gecici = temp->sonraki;
   temp->sonraki = ekle;
   ekle->sonraki = gecici;


   }
   void arayaEkleDegerIleSonra(struct node *head,int sayi,int eklenecekSayi){

   struct node *ekle = olustur(eklenecekSayi);

   struct node *temp = head;
   while(temp->deger!=sayi){

    temp = temp->sonraki;
   }
   struct node *gecici = temp->sonraki;
   temp->sonraki = ekle;
   ekle->sonraki = gecici;

   }
   void indisIleSil(struct node **head,int indis){

       struct node *temp = *head;
       int count = 0;
       if(indis==0){
        bastanSil(head);
        return;

       }
       while(temp != NULL){


        if(count == indis-1){
            break;
        }

        temp = temp->sonraki;
        count++;
       }



    struct node *gecici = temp->sonraki->sonraki;
    free(temp->sonraki);
    temp->sonraki = gecici;


   }
   void degerIleSil(struct node *head,int sayi){

   struct node *temp = head;
   while(temp->sonraki->deger != sayi){
   temp = temp->sonraki;
   }

   struct node *gecici = temp->sonraki->sonraki;
   free(temp->sonraki);
   temp->sonraki = gecici;


   }



        int main(){


    struct node *dugum1 = olustur(0);
    struct node *dugum2 = olustur(1);
    struct node *dugum3 = olustur(2);
    struct node *dugum4 = olustur(3);
    struct node *dugum5 = olustur(4);
    dugum1->sonraki = dugum2;
    dugum2->sonraki = dugum3;
    dugum3->sonraki = dugum4;
    dugum4->sonraki = dugum5;
    dugum5->sonraki = NULL;

    /*printfList(dugum1);
    printf("\n\n\n\n");*/
    degerIleSil(dugum1,2);
    printfList(dugum1);

    /*basaEkle(&dugum1,66);
    printfList(dugum1);*/
    /*sonaEkle(dugum1,66);
    printfList(dugum1);*/
    /*arayaEkle(dugum1,66,2);
    printfList(dugum1);*/
   /* sondanSil(dugum1);
    printfList(dugum1); */
    /*bastanSil(&dugum1);
    printfList(dugum1);*/
    /*reverse(&dugum1);
    printfList(dugum1);*/
   /* arayaEkleDegerIleOnce(dugum1,3,10);
    printfList(dugum1);*/
    //printf("\n\n\n");
   /* arayaEkleDegerIleSonra(dugum1,3,10);
    printfList(dugum1);*/
      /*indisIleSil(&dugum1,3);
      printfList(dugum1);*/





    /*int i = 0;
    clock_t bas = clock();


    while(i<2){

        dugum1 = dugum1->sonraki;
        i++;
    }
    printf("\n %d",dugum1->deger);

    clock_t son = clock();
    double zaman = 0.0;
    zaman = (double) (son-bas)/CLOCKS_PER_SEC;
    printf("\n gecen zaman sn=%f",zaman);
*/
        return 0;
        }

