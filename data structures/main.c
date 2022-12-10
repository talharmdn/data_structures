#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

int main()
{
    int x=-1;
    int listesayisi;
    h = NULL;
    temp = temp1 = NULL;
    while (x != 0) {
        printf("\n-----------------------\n");
        printf("0-Stop\n1-Create linked list\n2-Destroy linked list\n3-Add node\n4-Delete node\n5-Search node\n6-Display list\n");
        printf("-----------------------\n");
        printf("Yapmak istediginiz islemi giriniz: ");
        scanf("%d",&x);

        switch (x) {
        case 0:
            exit(0);
            break;
        case 1:
            printf("\n Girilecek ogrenci sayisi: ");
            scanf("%d", &listesayisi);
            for (int i = 0; i < listesayisi; i++)
                createList();
            break;
        case 2:
            destroyList();
            break;
        case 3:
            addNode();
            break;
        case 4:
            deleteNode();
            break;
        case 5:
            searchNode();
            break;
        case 6:
            displayList();
            break;
        default:
            printf("\n-----------------------\n");
            printf("Yalnis secim\n");
            printf("-----------------------\n");
        }
    }

    return 0;
}
