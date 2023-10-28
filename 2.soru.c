#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return ((int)b - (int)a);
}

int main() {
    int numbers[100];
    int count = 0;
    int num;

   
    for (int i = 0; i < 100; i++) {
        numbers[i] = rand() % 1000; 
        count++;
    }

 
    while (1) {
        printf("Bir sayi girin (cikis icin -1 giriniz): ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        } else {
            numbers[count] = num;
            count++;
        }
    }

   
    qsort(numbers, count, sizeof(int), compare);

  
    printf("Siralanmis Liste (Büyükten Küçüge):\n");
    for (int i = 0; i < count; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
