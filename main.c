//SEFA ENES ERGİN-sefaenesergin@gmail.com
//Örnek dosya kullanımlarını gösteren C kodu


#include <stdio.h>

int ogrenciSayisi;

typedef struct ogrenci_data
{
    int No;
    char Ad[51];
    int Not;
} Ogrenci;
Ogrenci* ogr;

void dosyaYaz(){
    printf("LUTFEN OGRENCİ BİLGİLERİNİ GİRİNİZ.\n-----------------------\n");
    for (int i=0; i<ogrenciSayisi; i++) {
        
        printf("Lütfen %d.ogrenci numarasını giriniz...\n",i+1);
            scanf("%d",&ogr[i].No);
        printf("Lütfen %d.ogrenci adını giriniz...\n",i+1);
            scanf("%s",ogr[i].Ad);
        printf("Lütfen %d.ogrenci notunu giriniz...\n",i+1);
            scanf("%d",&ogr[i].Not);
        printf("\n");
        
    }
    
    FILE* fptr=fopen("ogrenci_Bilgi.txt","w");
    if (fptr==NULL)
        printf("Dosya açılamadı...");
    else
    {
        for (int i=0; i<ogrenciSayisi; i++) {
            
            fprintf(fptr,"%d\t%s\t%d\t\n",ogr[i].No,ogr[i].Ad,ogr[i].Not);
       
        }
        printf("Ogrenci bilgileri başarıyla kaydedildi!");
        fclose(fptr);
    }
        
}


void dosyaOku(){
    
    printf("OGRENCİ BİLGİLERİ DOSYADAN OKUNUYOR...\n\n");
    printf("OGRENCİ BİLGİLERİ\n----------------------\n");
    
    int no;
    int not;
    char ismi[51];
    
    FILE *fptr=fopen("ogrenci_Bilgi.txt", "r");
    
    if(fptr==NULL)
        printf("Dosya açılamadı...");
    else{
        for (int i=0; i<ogrenciSayisi; i++) {
             
            fscanf(fptr,"%d\t%s\t%d\t\n",&no,ismi,&not);
            printf(" OgrenciNo:%d\n Ogrenciİsim:%s\n OgrenciNotu:%d\n",no,ismi,not);
            printf("\n\n");
         }
        fclose(fptr);
    }
    
    
}

int main(int argc, const char * argv[]) {
    
    printf("Kaç öğrenci var?");
    scanf("%d",&ogrenciSayisi);
    
    ogr=(Ogrenci*)malloc(sizeof(int)*ogrenciSayisi);
    
    dosyaYaz();
    dosyaOku();
    
    return 0;
}

