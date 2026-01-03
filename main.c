/*
 * Proje: Palindrom Sayi Kontrolü
 Kullanicidan alinan bir sayinin palindrom (tersten okunusu kendisiyle ayni)
 olup olmadigini matematiksel yöntemlerle (logaritma ve modül aritmetigi) kontrol eder.
 */

#include <stdio.h>
#include <math.h>

int main()
{
    // Degisken tanimlamalari
    int sayi, j, basamak_sayisi, i, son_basamak, eskiSayi;
    int yeniSayi = 0; // Ters çevrilen sayiyi tutacak degisken (0 ile baslatildi)

    printf("Lutfen bir sayi giriniz: ");
    scanf("%d", &sayi);
    
    // Islem sonunda karsilastirma yapabilmek için sayinin ilk halini sakliyoruz
    eskiSayi = sayi;
    
    basamak_sayisi = (int)log10(sayi) + 1;
    j = basamak_sayisi; // Döngü kontrolü için basamak sayisini sabit bir degiskende tutuyoruz
    
    // Sayiyi tersine çevirme döngüsü
    for(i = 0; i < j; i++){
        son_basamak = sayi % 10; // Sayinin son basamagini al (Modül alma)
        sayi = sayi / 10;        // Sayinin son basamagini at (Bölme islemi)
        
        // Alinan basamagi, basamak degerine göre (birler, onlar, yüzler...) yeni sayiya ekle
        yeniSayi = yeniSayi + son_basamak * pow(10, basamak_sayisi - 1);
        
        basamak_sayisi--; // Bir sonraki basamagin 10'un kuvvetini düsürmek için azaltiyoruz
    }
    
    printf("Sayinin Tersi: %d\n", yeniSayi);
    
    // Palindrom kontrolü: Sayinin ilk hali ile ters hali esit mi?
    if(yeniSayi == eskiSayi){
        printf("Palindrom Bir Sayidir\n");
    }
    else{
        printf("Palindrom Bir Sayi Degildir\n");
    }
    
    return 0;
}
