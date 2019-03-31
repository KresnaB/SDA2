//nama : kresna bayu sanyoto (181511051)
//nama file : linked51.cpp
//tgl:17-3-2019
//deskripsi : module linked list

#include "linked5164.h"


boolean isEmpty(address p)
//Tujuan : memeriksa apakah linked masih kosong
//Linked list kosong , jika Head == NULL
{
	if (p == NULL) {
    	return true;
	}else{
		return false;

    }
}

void Create_Node (address *p)
//Tujuan : memesan memory dengan alokasi dinamis
//Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
//Parameter : P (parameter Output)
{
    *p = (address) malloc(sizeof(ElmtList));
}

void Isi_Node (address *p , infotype *nilai)

//Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
//Periksa keberadaan P, Nilai diisi jika P tidak NULL
//	*p.next2 diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
{
    if(!isEmpty(*p)){
        strcpy((*p)->nama, nilai);
        (*p)->next2 = NULL;
    }
}

void Tampil_List (address p)
//Tujuan : Menampilkan seluruh isi Linked List
//Parameter : p (parameter input)
{ElmtList * current = p;
    printf("\nNode :{");
    while (current != NULL) {
        printf("%s ", current->nama);
        current = current->next2;
    }
    printf("}");
}
void Ins_Awal (address *p, address PNew)
//Tujuan : Insert 1 node baru (PNew) di awal Linked List
//Parameter : P (input-output)
//	PNew (input)
{
    (PNew)->next2=*p;
    *p=PNew;

}
void Ins_Akhir (address *p, address PNew)
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */
{
    ElmtList *current = *p;
    while (current->next2 != NULL){
        current = current->next2;
    }
    current->next2=PNew;
}

address Search(address p, infotype *nilai)

/* Mencari apakah ada elemen list dengan nama(P) = nilai */ /* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
    ElmtList * current = p;
	bool ketemu;
	ketemu = false;
	if (current->nama==nilai){
        ketemu = true;
	}
	while (ketemu==false && current->next2!=NULL){
        current=current->next2;
        if (current->nama==nilai){
        ketemu = true;
	}
	}
	return current;
}

address Search2(address p , infotype *nilai)
{
    bool ketemu = false;
    address akm = Nil;
    if (strcmp(nama(p),nilai) == 0){
        akm = p;
        ketemu = true;
    } else {
            while(!ketemu && !isEmpty(next2(p)) == 0){
                if (strcmp(nama(next2(p)),nilai) == 0){

                akm = p;
                ketemu = true;
                }
                p = next2(p);
            }
        }
   return akm;
}

void InsertAfter (address * pBef, address PNew)

/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */
{
    (PNew)->next2=(*pBef)->next2;
    (*pBef)->next2=PNew;

}
void Del_Awal (address *p)
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */ /* dan alamat elemen pertama di dealokasi */
{
    address f;
	f = *p;
	*p = next2(*p);
	next2(f) = Nil;
	DeAlokasi(&f);
}

void Del_After (address * pBef)

/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/*	nilai info node yang dihapus disimpan pada X */
/*	dan alamat elemen setelah pBef di dealokasi */
{
    address PDel,PNext;
    PDel = (*pBef)->next2;
    PNext = (PDel)->next2;
    (*pBef)->next2 = PNext;
    (PDel)->next2 = NULL;
    DeAlokasi(&PDel);

}

void DeAlokasi (address *p)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
    (*p)->next2=NULL;
    free(*p);
}

int NbElmt (address p)
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */ // Recursif Mode
{
    ElmtList * current = p;
    int i=1;
    while (current->next2 != NULL){
        i++;
        current = current->next2;
    }
    if (i!=0){
        return i;
    }else{
        return 0;
    }
}


address BalikList (address p)
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */
{
    address awal;
    if ((p)->next2!=NULL){
        awal=BalikList((p)->next2);
        ((p)->next2)->next2=p;
        (p)->next2=NULL;
        return awal;
    }
    return p;

}
