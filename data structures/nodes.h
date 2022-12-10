#ifndef NODES_H_INCLUDED
#define NODES_H_INCLUDED



struct node {
    struct node* prev;
    struct node* next;
    long int ogrenciNo;
    char ad[20], soyad[20], bolum[20];
    int sinif;
} * h, *temp, *temp1, *temp2, *temp4;


void createNode()
{
    long int ogrenciNo;
    char ad[20], soyad[20], bolum[20];
    int sinif;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nOgrencinin bilgilerini giriniz(Ogrenci no, Ad, Soyad, Bolum, Sinif):\n");
    scanf("%ld %s %s %s %d",&ogrenciNo, ad, soyad, bolum,&sinif);
    temp->ogrenciNo = ogrenciNo;
    strcpy(temp->ad, ad);
    strcpy(temp->soyad, soyad);
    strcpy(temp->bolum, bolum);
    temp->sinif = sinif;
}

void createList()
{
    if (h == NULL) {
        createNode();
        h = temp;
        temp1 = h;
    }
    else {
        createNode();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

void destroyList(){
    while(h != NULL) {
        temp = h;
        h = h->next;
        free(temp);
      }
      printf("Listedeki bilgiler basariyla silindi!");
}



void addNode()
{
    if (h == NULL) {
        printf("Liste bos...\n");
        return 0;
    }
    else {
        createNode();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

int deleteBas()
{
    struct node* temp;
    temp = h;
    if (temp == NULL) {
        printf("Liste bos...\n");
        return 0;
    }
    if (temp->next == NULL) {
        printf("%ld %s ogrenci numarasina sahip ogrenci silindi.\n",temp->ogrenciNo);
        free(temp);
        h = NULL;
    }
    else {
        h = h->next;
        h->prev = NULL;
        printf("%ld %s ogrenci numarasina sahip ogrenci silindi.\n",temp->ogrenciNo);
        free(temp);
        return 0;
    }
    return 0;
}

int deleteSon()
{
    struct node* temp;
    temp = h;
    if (temp == NULL) {
        printf("Liste bos...\n");
        return 0;
    }
    if (temp->next == NULL) {
        printf("%ld %s ogrenci numarasina sahip ogrenci silindi.\n",temp->ogrenciNo);
        free(temp);
        h = NULL;
    }
    else {
        temp = temp1;
        temp2 = temp1->prev;
        temp2->next = NULL;
        printf("%ld %s ogrenci numarasina sahip ogrenci silindi.\n",temp->ogrenciNo);
        free(temp);
        temp1 = temp2;
    }
    return 0;
}

int deleteNode(){
    long int aranacakOgrenciNo;
    temp = h;
    if (temp == NULL) {
        printf("\n Liste bos...\n");
        return;
    }
    printf("Silinecek olan ogrencinin ogrenci numarasi: ");
    scanf("%ld",&aranacakOgrenciNo);
    while (temp->ogrenciNo != aranacakOgrenciNo) {
        temp = temp->next;
    }
    if(temp == h){
        deleteSon();
    }
    else if(temp->next == NULL){
        deleteBas();
    }
    else{
        temp1 = temp;
        temp2 = temp->prev;
        temp2->next = temp->next;
        printf("%ld %s ogrenci numarasina sahip ogrenci silindi.\n",temp->ogrenciNo);
        free(temp1);
        temp = temp2;
        return 0;
    }

}

void searchNode()
{
    long int aranacakOgrenciNo;
    temp2 = h;
    if (temp2 == NULL) {
        printf("\n Liste bos...\n");
        return;
    }
    printf("Aranacak olan ogrencinin ogrenci numarasi: ");
    scanf("%ld",&aranacakOgrenciNo);
    while (temp2->ogrenciNo != aranacakOgrenciNo) {
        temp2 = temp2->next;
    }
    printf("%ld %s %s %s %d\n",temp2->ogrenciNo,temp2->ad,temp2->soyad,temp2->bolum,temp2->sinif);

}

void displayList()
{
    temp2 = h;
    if (temp2 == NULL) {
        printf("\n Liste bos...\n");
        return;
    }
    printf("\n Okulda bulunan ogrenciler:\n");
    while (temp2 != NULL) {
        printf("%ld %s %s %s %d\n",temp2->ogrenciNo, temp2->ad,temp2->soyad, temp2->bolum,temp2->sinif);
        temp2 = temp2->next;
    }
}


#endif // NODES_H_INCLUDED
