//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//    struct node{
//
//    int deger;
//
//    struct node *sonraki;
//
//
//    };
//    //
//    struct node *olustur(int deger){
//    /*
//    recursive fonksiyonda tek yönlü listeyi ters çevirme
//    */
//
//    struct node *yenidugum = (struct node*)malloc(sizeof(struct node));
//    yenidugum->deger = deger;
//    yenidugum->sonraki =null;
//    return yenidugum;
//    }
//   void printflist(struct node *dugum){
//
//
//   struct node *temp = dugum;
//   while(temp!=null){
//
//    printf("%d\n",temp->deger);
//    temp = temp->sonraki;
//
//   }
//
//
//
//   }
//   void basaekle(struct node **head,int sayi){
//    struct node *baseleman =olustur(sayi);
//
//
//    // **head baslangicin referans�
//    struct node *temp = *head;
//
//    *head = baseleman;
//
//    baseleman->sonraki = temp;
//
//
//    }
//   void sonaekle(struct node *head,int sayi){
//    struct node *soneleman =olustur(sayi);
//
//
//
//    struct node *temp = head;
//
//    while(temp->sonraki!=null){
//
//
//        temp = temp->sonraki;
//
//
//    }
//    temp->sonraki = soneleman;
//    soneleman->sonraki = null;
//
//    }
//   void arayaekle(struct node *head,int sayi,int indis){
//    struct node *yeni = olustur(sayi);
//
//    struct node *temp = head;
//    int counter = 0;
//    while(temp!=null){
//
//        if(counter== indis-1){
//            break;
//        }
//        counter++;
//        temp = temp->sonraki;
//
//
//    }
//    struct node *eskisayi = temp->sonraki;
//    temp->sonraki = yeni;
//    yeni->sonraki = eskisayi;
//
//
//    }
//   void sondansil(struct node *head){
//
//   struct node *temp = head;
//   while(temp->sonraki->sonraki != null){
//
//
//    temp = temp->sonraki;
//
//   }
//   free(temp->sonraki);
//   temp->sonraki = null;
//
//
//   }
//   void bastansil(struct node **head){
//
//   struct node *temp =  *head;
//   struct node* yeni = temp->sonraki;
//   free(temp);
//   *head = yeni;
//
//
//
//   }
//   void reverse(struct node **head){
//
//   struct node *temp = *head;
//   struct node *next = null;
//   struct node *prev = null;
//   while(temp != null){
//
//    next = temp->sonraki;
//    temp->sonraki = prev;
//    prev = temp;
//    temp = next;
//   }
//    *head = prev;
//
//
//
//   }
//   void arayaekledegerıleonce(struct node *head,int sayi,int ekleneceksayi){
//   struct node *ekle = olustur(ekleneceksayi);
//
//   struct node *temp = head;
//
//   while(temp->sonraki->deger != sayi){
//    temp = temp->sonraki;
//
//
//   }
//   struct node *gecici = temp->sonraki;
//   temp->sonraki = ekle;
//   ekle->sonraki = gecici;
//
//
//   }
//   void arayaekledegerılesonra(struct node *head,int sayi,int ekleneceksayi){
//
//   struct node *ekle = olustur(ekleneceksayi);
//
//   struct node *temp = head;
//   while(temp->deger!=sayi){
//
//    temp = temp->sonraki;
//   }
//   struct node *gecici = temp->sonraki;
//   temp->sonraki = ekle;
//   ekle->sonraki = gecici;
//
//   }
//   void indisılesil(struct node **head,int indis){
//
//       struct node *temp = *head;
//       int count = 0;
//       if(indis==0){
//        bastansil(head);
//        return;
//
//       }
//       while(temp != null){
//
//
//        if(count == indis-1){
//            break;
//        }
//
//        temp = temp->sonraki;
//        count++;
//       }
//
//
//
//    struct node *gecici = temp->sonraki->sonraki;
//    free(temp->sonraki);
//    temp->sonraki = gecici;
//
//
//   }
//   void degerılesil(struct node *head,int sayi){
//
//   struct node *temp = head;
//   while(temp->sonraki->deger != sayi){
//   temp = temp->sonraki;
//   }
//
//   struct node *gecici = temp->sonraki->sonraki;
//   free(temp->sonraki);
//   temp->sonraki = gecici;
//
//
//   }
//
//
//
//        int main(){
//
//
//    struct node *dugum1 = olustur(0);
//    struct node *dugum2 = olustur(1);
//    struct node *dugum3 = olustur(2);
//    struct node *dugum4 = olustur(3);
//    struct node *dugum5 = olustur(4);
//    dugum1->sonraki = dugum2;
//    dugum2->sonraki = dugum3;
//    dugum3->sonraki = dugum4;
//    dugum4->sonraki = dugum5;
//    dugum5->sonraki = null;
//
//    bastansil(&dugum1);
//    printflist(dugum1);
//
//
//
//
//        }
//
