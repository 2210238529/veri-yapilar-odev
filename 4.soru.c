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

void ogrenciAraVeYazdir(struct Ogrenci* head, char arananIsim[]) {
    int bulundu = 0;
    while (head != NULL) {
        if (strcmp(head->isim, arananIsim) == 0) {
            printf("Numara: %d, Isim: %s, Yas: %d\n", head->numara, head->isim, head->yas);
            bulundu = 1;
            break;
        }
        head = head->next;
    }

    if (!bulundu) {
        printf("Aradiginiz isimde bir ogrenci bulunamadi.\n");
    }
}

int main() {
    struct Ogrenci* ogrenciListesi = NULL;

    // Örnek ögrenci bilgileri ekleniyor
    ogrenciEkle(&ogrenciListesi, 101, "Ali", 20);
    ogrenciEkle(&ogrenciListesi, 102, "Ayse", 21);
    ogrenciEkle(&ogrenciListesi, 103, "Mehmet", 22);

    char arananIsim[50];
    printf("Aranacak ogrenci adini girin: ");
    scanf("%s", arananIsim);

    // Ögrenci adina göre arama yapilip sonuçlar yazdiriliyor
    ogrenciAraVeYazdir(ogrenciListesi, arananIsim);

    // Bellegi temizle
    while (ogrenciListesi != NULL) {
        struct Ogrenci* temp = ogrenciListesi;
        ogrenciListesi = ogrenciListesi->next;
        free(temp);
    }

    return 0;
}
