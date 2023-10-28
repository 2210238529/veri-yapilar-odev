#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci* next;
};

void ogrenciEkle(struct Ogrenci** head, int numara, char isim[], int yas) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->numara = numara;
    strcpy(yeniOgrenci->isim, isim);
    yeniOgrenci->yas = yas;
    yeniOgrenci->next = *head;
    *head = yeniOgrenci;
}

void ogrenciSil(struct Ogrenci* head, char arananIsim[]) {
    struct Ogrenci* temp = head;
    struct Ogrenci* silinecek;

    if (temp != NULL && strcmp(temp->isim, arananIsim) == 0) {
        silinecek = temp->next;
        free(temp);
        head = silinecek;
        return;
    }

    while (temp != NULL && temp->next != NULL) {
        if (strcmp(temp->next->isim, arananIsim) == 0) {
            silinecek = temp->next;
            temp->next = silinecek->next;
            free(silinecek);
            return;
        }
        temp = temp->next;
    }
}

void ogrenciBilgileriniYazdir(struct Ogrenci* head) {
    printf("Ogrenci Bilgileri:\n");
    while (head != NULL) {
        printf("Numara: %d, Isim: %s, Yas: %d\n", head->numara, head->isim, head->yas);
        head = head->next;
    }
}

int main() {
    struct Ogrenci* ogrenciListesi = NULL;
    ogrenciEkle(&ogrenciListesi, 101, "Ali", 20);
    ogrenciEkle(&ogrenciListesi, 102, "Ayse", 21);
    ogrenciEkle(&ogrenciListesi, 103, "Mehmet", 22);

    char arananIsim[50];
    printf("Silinecek ogrenci adini girin: ");
    scanf("%s", arananIsim);

    ogrenciSil(ogrenciListesi, arananIsim);

    ogrenciBilgileriniYazdir(ogrenciListesi);

    while (ogrenciListesi != NULL) {
        struct Ogrenci* temp = ogrenciListesi;
        ogrenciListesi = ogrenciListesi->next;
        free(temp);
    }

    return 0;
}
