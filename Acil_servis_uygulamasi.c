#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sabit bir maksimum hasta kapasitesi tanımlanıyor.
#define MAX_PATIENTS 100

// Hasta bilgilerini tutmak için bir yapı (struct) tanımlanıyor.
typedef struct {
    int id; // Hastanın kimlik numarası.
    char name[50]; // Hastanın adı.
    int age; // Hastanın yaşı.
    char condition[100]; // Hastanın durumu.
    int priority; // Hastanın öncelik seviyesi (1-5 arası).
    int prescription_id; // Hastaya ait rastgele oluşturulan reçete numarası.
} Patient;

// Maksimum hasta sayısına kadar hasta bilgilerini saklayan dizi.
Patient patients[MAX_PATIENTS];
// Toplam kayıtlı hasta sayısını tutan sayaç.
int patient_count = 0;

// Yeni bir hasta kaydı eklemek için fonksiyon.
void add_patient() {
    // Eğer maksimum kapasite dolmuşsa, yeni kayıt eklenemez.
    if (patient_count >= MAX_PATIENTS) {
        printf("Hasta kapasitesi dolu!\n");
        return;
    }
    
    // Yeni hasta için bir yapı oluşturuluyor.
    Patient p;
    p.id = patient_count + 1; // Hasta ID'si, mevcut sayı + 1 olarak atanıyor.
    printf("Hasta adi: ");
    scanf("%s", p.name); // Hasta adı kullanıcıdan alınıyor.
    printf("Yas: ");
    scanf("%d", &p.age); // Hasta yaşı kullanıcıdan alınıyor.
    printf("Durumu: ");
    scanf("%s", p.condition); // Hastanın durumu kullanıcıdan alınıyor.
    printf("Oncelik (1-5): ");
    scanf("%d", &p.priority); // Hastanın öncelik seviyesi kullanıcıdan alınıyor.
    p.prescription_id = rand() % 10000; // Rastgele bir reçete numarası oluşturuluyor.
    
    // Yeni hasta, hastalar dizisine ekleniyor ve toplam sayaç artırılıyor.
    patients[patient_count++] = p;
    printf("Hasta basariyla kaydedildi. Recete No: %d\n", p.prescription_id);
}

// Hastaları ekrana öncelik sıralamasına göre listeleyen fonksiyon.
void list_patients() {
    printf("\nHasta Listesi:\n");
    int i;
    for (i = 0; i < patient_count; i++) {
        printf("ID: %d, Adi: %s, Yas: %d, Durum: %s, Oncelik: %d, Recete No: %d\n",
               patients[i].id, patients[i].name, patients[i].age, patients[i].condition,
               patients[i].priority, patients[i].prescription_id);
    }
}

// Programın ana fonksiyonu.
int main() {
    int choice; // Kullanıcıdan alınan menü seçimi.
    do {
        // Kullanıcıya menü seçenekleri gösteriliyor.
        printf("\n1. Yeni Hasta Ekle\n");
        printf("2. Hastalari Listele\n");
        printf("3. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice); // Kullanıcının seçimi alınıyor.
        
        // Kullanıcının seçimine göre işlem yapılması sağlanıyor.
        switch (choice) {
            case 1:
                add_patient(); // Yeni hasta ekleme işlemi.
                break;
            case 2:
                list_patients(); // Hasta listesini görüntüleme işlemi.
                break;
            case 3:
                printf("Sistemden cikiliyor...\n"); // Çıkış işlemi.
                break;
            default:
                printf("Gecersiz secim!\n"); // Geçersiz bir seçenek girildiğinde uyarı.
        }
    } while (choice != 3); // Kullanıcı çıkış yapana kadar döngü devam eder.
    
    return 0; // Program başarıyla sonlanıyor.
}
