/* Author 		: Rhio Adjie Fabian / 181511064 / Kresna Bayu Sanyoto / 181511051
   File			: driver5164.cpp
   Deskripsi	: Driver untuk menjalankan setiap perintah yang ada di linked5164.cpp
   				  Program ini dapat menjalankan beberapa perintah seperti :
   				  - entry data (banyak kota yang dapat dientry dan nama kota)
   				  - searching data (dapat mencari sebuah data string dan akan memberitahukan di kota apa posisi data string tersebut)
   				  - menampilkan data (menampilkan seluruh data di sebuah kota yang telah dipilih sebelumnya)
   Date			: 24 - 3 - 2019
*/
#include "linked5164.h"
bool cekkota(city C[], int jum, infotype* nilai);
void masukandata(city C[], int jum);
void searching(city C[], int jum);
void deletemhs(city C[], int jum);
void tampilsemua(city C[], int jum);
void tampilhasil(city C[], int jum);
void showkota(city C[], int kota);
void isiKota(city C[], int kota);
int pilihkota(city C[],int kota);
void bankota(int *kota);

bool cekkota(city C[], int jum, infotype* nilai)
{
    for (int a = 1; a <= jum; a++){
        if (strcmp(C[a].kota, nilai) == 0){
            return true;
        }
    }
    return false;
}
void masukandata(city C[],int jum)	// Modul mengentrykan data
{
    address Pnew;
    infotype datanama[20];
    char ulang= 'T';
    if (C[jum].next1==NULL){
            printf("Masukan nama ke kota %s\n", C[jum].kota);
            printf("Masukkan nama : ");fflush(stdin);
            scanf("%[^\n]s", datanama);
            Create_Node(&(C[jum].next1));
            Isi_Node(&(C[jum].next1), datanama);
			printf("\nApakah anda ingin entry data lagi? (Y/T) : ");
        	ulang = toupper(_getch());
		}
        //ulang
    while(ulang == 'Y'){
        system("cls");
        //input nama
        if (C[jum].next1!=NULL){
            printf("Masukan nama ke kota %s\n", C[jum].kota);
            printf("Masukkan nama : ");fflush(stdin);
            scanf("%[^\n]s", datanama);
            //pembuatan elemen list baru
            Create_Node(&Pnew);
            Isi_Node(&Pnew, datanama);
            Ins_Akhir(&(C[jum].next1), Pnew);
        }
        //ulang
        printf("\nIngin mengulangi input? (Y/T) : ");
        ulang = toupper(_getch());
    }
}
 void searching(city C[], int jum)		// Modul mencari nama mahasiswa
 {
  	address google;
  	char search1[20];
  	// User menginput nama yang akan dicari
  	system("cls");
  	printf("Masukkan nama yang anda ingin cari : ");
  	fflush(stdin);
  	scanf("%[^\n]s", search1);
  	printf("\n");
 		for (int z = 1; z <= jum; z++){
   		google = Search(C[z].next1, search1);
   			if (!isEmpty(google)){
    			printf("%s telah ketemu di data kota %s\n",search1, C[z].kota);
    			printf("\n");
    			break;
   				}
   			}
   	if (isEmpty(google)){
     			printf("\n%s tidak ditemukan\n",search1);
    }
    printf("Tekan anything..."); _getch();
}
void deletemhs(city C[], int jum)
{
    char datanama[20];
    address xSearch;
    char repeat = 'Y';

    while(repeat == 'Y'){
        system("cls");
        tampilhasil(C,jum);
        printf("Masukkan nama yang akan dihapus : ");
        scanf("%s", datanama);

        xSearch = Search2((C[jum].next1), datanama);
        if (isEmpty(xSearch)){
            printf("\n%s ga ada", datanama);
        } else if (xSearch == C[jum].next1){
            Del_Awal(&(C[jum].next1));
            printf("\n%s berhasil dihapus\n", datanama);
        } else{
            Del_After(&xSearch);
            printf("\n%s berhasil dihapus\n", datanama);
        }
        printf("Apakah anda ingin menghapus lagi ? (Y/T) ");
        repeat = toupper(_getch());
    }
}
void tampilsemua(city C[],int jum)
{
	for(int x=1;x<=jum;x++){
		tampilhasil(C,x);
	}
}
void tampilhasil(city C[], int jum){		// Menampilkan data
    address head;
    head = C[jum].next1;
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("\tKota : %s\n", C[jum].kota);
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    if (head!=NULL){
    	Tampil_List(head);
	}
	if (head==NULL){
		printf("\tNode Kosong");
	}
	printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	if (head!=NULL){
    printf("\t\nJumlah Mahasiswa : %d\n",NbElmt(C[jum].next1));
	}
	if (head==NULL){
		printf("\tNode Kosong\n");
	}
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n\n");
}
void showkota(city C[], int kota)
{
	for (int i = 1; i <= kota; i++){
        printf("%d. %s\n",i, C[i].kota);
    }
}
void isiKota(city C[], int kota)		// User memasukkan kota yang akan digunakan
{
    char pubgm[20];
	printf("-->Daftar Kota<--\n");
	for(int i = 1; i <= kota ;i++){
        printf("Nama kota %d = ", i);
        fflush(stdin);
        scanf("%[^\n]s", pubgm);
        if (cekkota(C,kota,pubgm)){
                printf("\nKota %s sudah ada dalam array\n",pubgm);
                i--;
            } else{
                strcpy(C[i].kota,pubgm);
                 C[i].next1 = Nil;
            }
        }
}
void KeeptoFileMhs(ElmtList M[] , int num)
{
    FILE *sda;
    if ((sda=fopen("Data Mahasiswa","a+"))==Nil){
        printf("\nAlokasi gagal");
        exit(1);
    } else{
        system("cls");
        for (int i = 0; i < num; i++){
            fprintf(sda,"%d". "%s\n",i);
        }
    }
}
int pilihkota(city C[],int kota)		// User memilih kota untuk kebutuhan tertentu
{
    int pilih;
    	showkota(C,kota);
        printf("Tentukan kota (berdasarkan angka) : ");
        scanf("%d",&pilih);
        /* if (pilih > kota){
        	printf("\nAnda memasukkan angka yang tidak ada dalam list kota\n");
        	exit(1);
		}
		*/
        return pilih;
}
void bankota(int *kota)		// User mengentry jumlah kota
{
	printf("\nMasukkan jumlah kota yang anda inginkan : ");
	scanf("%d", kota);
}
int main()
{
	int menu;
	char menu2;
    int x, y;
 	bankota(&x);
    city C[x];
    isiKota(C,x);
    do{
		printf("\n*********************************************\n");
    	printf("*		    MENU		    *\n");
    	printf("*********************************************\n");
    	printf("1. Entry Data\n");
    	printf("2. Looking For Data\n");
    	printf("3. Show Data\n");
    	printf("4. Show All Data\n");
    	printf("5. Delete Data\n");
    	printf("6. Exit\n");
    	printf("Masukkan pilihan anda : ");
    	scanf("%d",&menu);
    	switch (menu)
    	{
    		case 1	: system("cls");
					  y = pilihkota(C,x);
    				  masukandata(C,y);
    				  break;
    		case 2	: searching(C,y);
    				  break;
    		case 3	: y = pilihkota(C,x);
					  tampilhasil(C,y);
    				  break;
    		case 4	: tampilsemua(C,x);
    				  break;
            case 5  : system("cls");
                      deletemhs(C,x);
                      break;
    		case 6	: system("cls"); printf("Bye Bye...."); exit(1); break;
    		default	: printf("\nTidak ada opsi di menu\n"); _getch();
		}
		printf("\nApakah anda ingin kembali ke menu : Y/T ");
		menu2 = toupper(_getch());
	} while (menu2 == 'Y');
	return 0;
}
