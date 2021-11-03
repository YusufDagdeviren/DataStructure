#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define BOYUT 10

int dizi[BOYUT];
int last = -1;

bool isFull(){
    if(last == BOYUT - 1)
        return true;
    else
        return false;

    }
bool isEmpty(){

    if(last == -1)
        return true;
    else
        return false;


}
void push(int sayi){

    bool isThisFull = isFull();
    if(isThisFull == true){
        printf("StackOverFlow");
        return;
    }
    last = last + 1;
    dizi[last] = sayi;

}
int pop(){

    bool isThisEmpty = isEmpty();
    if(isThisEmpty==true){
    printf("StackUnderFlow");
    return;

    }
    int oldLast = dizi[last];
    last = last - 1;
    return oldLast;

}
int peek(){

return dizi[last];


}
void yazdir(){

    for(int i = last; i >= 0; i--)
    {
        printf(" %d\n", dizi[i]);
    }
}

int main(){
/*
Stack nedir ?
*Soyut bir veri yapısıdır
*En son giren eleman ilk olarak çıkar(Last in First Out)
*En çok kullanılan veri yapılarındandır
*Yapılan işlemler daha sonradan tekrar lazım olacağı durumlarda kullanılması tercih edilir
*Stack için hafızadan belli bir alan ayrılır
*Alan aşımı olduğunda --> StackOverflow hatası alınır
*Dizi veri yapısı ile ya da bağlı liste  ile kullanılabilir
-------------STACK İLE YAPILAN İŞLEMLER-------------
                        PUSH (EKLEME)
                        POP(LIFO İLE ÇIKARMA AYNI ZAMANDA GERİ DÖNDERME)
                        PEEK(EN ÜSTTEKİ ELEMANI GERİ DÖNDERİR)
----------------------------------------------------

*/
int secim, sayi, Cikartilan, MevcutTop;
    while(1)
    {
        printf("\n 1- Push");
        printf("\n 2- Pop");

        printf("\n Yapmak istediginiz islem ? ...");
        scanf("%d", &secim);

        switch(secim)
        {
            case 1:
                printf("\n Hangi sayiyi eklemek istiyorsunuz? ...");
                scanf("%d", &sayi);
                push(sayi);
                printf("Yeni Dizi\n");
                yazdir();
                break;
            case 2:
                Cikartilan = pop();
                MevcutTop = peek();
                printf("\n %d Elemani cikartildi. Yeni Top Elemani: %d\n", Cikartilan, MevcutTop);
                printf("Yeni Dizi\n");
                yazdir();
                break;
        }
    }



return 0;
}
