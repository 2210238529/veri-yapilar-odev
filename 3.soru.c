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

void ogrenciBilgileriniYazdir(struct Ogrenci* head) {
    int sayac = 0;
    printf("Ogrenci Bilgileri:\n");
    while (head != NULL) {
        printf("Numara: %d, Isim: %s, Yas: %d\n", head->numara, head->isim, head->yas);
        head = head->next;
        sayac++;
    }
    printf("Toplam Ogrenci Sayisi: %d\n", sayac);
}

int main() {
    struct Ogrenci* ogrenciListesi = NULL;

    
    ogrenciEkle(&ogrenciListesi, 101, "Ali", 20);
    ogrenciEkle(&ogrenciListesi, 102, "Ayse", 21);
    ogrenciEkle(&ogrenciListesi, 103, "Mehmet", 22);

    ogrenciBilgileriniYazdir(ogrenciListesi);

    while (ogrenciListesi != NULL) {
        struct Ogrenci* temp = ogrenciListesi;
        ogrenciListesi = ogrenciListesi->next;
        free(temp);
    }

    return 0;
}
