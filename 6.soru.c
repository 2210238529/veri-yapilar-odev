#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ISIM_UZUNLUGU 15

struct Ogrenci {
    int numara;
    char isim[MAX_ISIM_UZUNLUGU + 1]; // +1 bosluk karakteri için
    int yas;
    struct Ogrenci* next;
};

void ogrenciEkle(struct Ogrenci** head, int numara, char isim[], int yas) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->numara = numara;
    strncpy(yeniOgrenci->isim, isim, MAX_ISIM_UZUNLUGU);
    yeniOgrenci->yas = yas;
    yeniOgrenci->next = *head;
    *head = yeniOgrenci;
}

void enUzunIsimliOgrenciyiYazdir(struct Ogrenci* head) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }

    struct Ogrenci* enUzunIsimli = head;
    while (head != NULL) {
        if (strlen(head->isim) > strlen(enUzunIsimli->isim)) {
            enUzunIsimli = head;
        }
        head = head->next;
    }

    printf("En Uzun Isime Sahip Ogrenci:\n");
    printf("Numara: %d, Isim: %s, Yas: %d\n", enUzunIsimli->numara, enUzunIsimli->isim, enUzunIsimli->yas);
}

int main() {
    struct Ogrenci* ogrenciListesi = NULL;

    // Örnek ögrenci bilgileri ekleniyor
    ogrenciEkle(&ogrenciListesi, 101, "Ali", 20);
    ogrenciEkle(&ogrenciListesi, 102, "Ayse", 21);
    ogrenciEkle(&ogrenciListesi, 103, "Mehmet", 22);
    ogrenciEkle(&ogrenciListesi, 104, "Fatma", 23);
    ogrenciEkle(&ogrenciListesi, 105, "Ahmet", 24);

    // En uzun isimli ögrenciyi yazdirma
    enUzunIsimliOgrenciyiYazdir(ogrenciListesi);

    // Bellegi temizle
    while (ogrenciListesi != NULL) {
        struct Ogrenci* temp = ogrenciListesi;
        ogrenciListesi = ogrenciListesi->next;
        free(temp);
    }

    return 0;
}
