#include<stdio.h>
#include<stdlib.h>

    struct node {

    int sayi;
    struct node *sonraki;




    };


    struct node* baslangic = NULL;

    struct node *olustur(int deger){


    struct node *yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->sayi = deger;
    yeniDugum->sonraki =NULL;
    return yeniDugum;
    }

    void listeYaz(){

    struct node *temp = baslangic;
    while(temp != NULL){

        printf("%d\n",temp->sayi);
        temp = temp->sonraki;


    }


    }
    void listeninSonunaEkle(int sayi){

    struct node *sonDugum = olustur(sayi);
    if(baslangic == NULL){

        baslangic = sonDugum;

    }else{

        struct node *temp = baslangic;
        while(temp->sonraki != NULL){ // traversal yapýsý

            temp = temp->sonraki;


        }
        temp->sonraki = sonDugum;

        }


    }
    void listeninBasinaEkle(int sayi){

    struct node *yeniEleman = olustur(sayi);
    if(baslangic == NULL){
        baslangic = yeniEleman;
        return;
    }
    struct node *eskiBirinci = baslangic;
    baslangic = yeniEleman;
    baslangic ->sonraki = eskiBirinci;




    }
    void listeninArasinaEkle(int sayi,int konum){


    if(konum == 0){

        listeninBasinaEkle(sayi);
        return;
    }
    struct node *arayaEklenecek = olustur(sayi);
    struct node *temp = baslangic;
    int counter = 0;
    while(temp != NULL){

        if(counter == konum -1){
            break;
        }
        temp = temp->sonraki;
        counter++;
    }
    if(counter+1 != konum){
        printf("Gecersiz indis no\n");
        return;
    }
    if(temp->sonraki == NULL){
        listeninSonunaEkle(sayi);
        return;
    }

    struct node *eskiSayi = temp->sonraki;
    temp->sonraki = arayaEklenecek;
    arayaEklenecek->sonraki = eskiSayi;



    }
    void sondanElemanSil(){


        struct node *temp = baslangic;

        while(temp->sonraki->sonraki != NULL){

            temp = temp->sonraki;



        }
        free(temp->sonraki);
        temp->sonraki = NULL;


    }
    void ilkElemanSil(){

    if(baslangic == NULL){

        printf("Baslangic bulunamadi\n");
        return;


    }

    if(baslangic->sonraki == NULL){

        baslangic = NULL;
        return;
    }
    struct node *temp = baslangic->sonraki;
    free(baslangic);
    baslangic = temp;


    }
    void aradanElemanSil(int konum){

    if(konum == 0){
        ilkElemanSil();
        return;
    }
    if(konum>elemanSayiBastir()){

        printf("Girdiginiz Konum listeyi asti...\n");
        return;


    }
    int count = 0;
    struct node *temp = baslangic;

    while(count != konum-1){

        temp = temp->sonraki;

        count++;
    }
    struct node *gecici = temp->sonraki->sonraki;
    free(temp->sonraki);
    temp->sonraki = gecici;



    }
    int elemanSayiBastir(){

    int elemanSayi=0;
    struct node *temp = baslangic;

    while(temp != NULL){

        temp = temp->sonraki;
        elemanSayi++;
    }

    return elemanSayi;

    }
    void aradanElemanSilDeger(int deger){


    int varMi = 0;

    if(baslangic == NULL){

        printf("Listede eleman bulunamıyor....\n");
        return;

    }

   if(baslangic->sayi == deger){
        ilkElemanSil();
        return;
   }
   struct node *temp = baslangic;

    while(temp->sonraki != NULL){

        if(temp->sonraki->sayi == deger){
            varMi = 1;
            break;
        }
        temp = temp->sonraki;

    }
    if(varMi==1){
       struct node *gecici = temp->sonraki->sonraki;
        free(temp->sonraki);
        temp->sonraki = gecici;
    }else{
        printf("deger bulunamadi....\n");
        return;
    }


    }






    int main(){

    int secim, sayi,konum;


    while(1){

        printf("\n\n\n********Menu********\n");
        printf("Lutfen Secim Yapiniz... \n");
        printf("1.Listenin Elemanlarini bastir\n");
        printf("2.Listenin Sonuna Eleman Ekle\n");
        printf("3.Listenin Basina Eleman Ekle\n");
        printf("4.Listenin Arasina Eleman Ekle\n");
        printf("5.Listenin Son Elemanini Sil\n");
        printf("6.Listenin Ilk Elemanini Sil\n");
        printf("7.Listenin Aradan Elemanini Sil\n");
        printf("8.Listenin Aradan Elemanini Sil(Deger ile)\n");
        scanf("%d",&secim);
        if(secim==1){

            printf("\nListe yaziliyor...\n");
            listeYaz();


        }else if(secim == 2){
            printf("Lutfen ekleyeceginiz sayiyi giriniz: \n");
            scanf("%d",&sayi);
            listeninSonunaEkle(sayi);

        }else if(secim==3){
            printf("Lutfen ekleyeceginiz sayiyi giriniz: \n");
            scanf("%d",&sayi);
            listeninBasinaEkle(sayi);


        }else if(secim==4){
            printf("Lutfen ekleyeceginiz sayiyi giriniz: \n");
            scanf("%d",&sayi);
            printf("Lutfen indis nuamrasý giriniz: \n");
            scanf("%d",&konum);
            listeninArasinaEkle(sayi,konum);

        }else if(secim==5){
            sondanElemanSil();

        }else if(secim==6){
            ilkElemanSil();
        }else if(secim==7){
            printf("Lutfen cikaracaginiz sayiyinin indisini giriniz: \n");
            scanf("%d",&sayi);
            aradanElemanSil(sayi);

        }else if(secim==8){
            printf("Lutfen cikaracaginiz sayiyinin degerini giriniz: \n");
            scanf("%d",&sayi);
            aradanElemanSilDeger(sayi);


        }

    }
    return 0;
    }
