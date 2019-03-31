/* File			: linked5164.h*/
/* Deskripsi	: ADT linked list dengan representasi fisik pointer */
/* 				  Representasi address dengan pointer */
/* infoType adalah character */
/* Dibuat oleh : Kresna Bayu Sanyoto / 181511051 / Rhio Adjie Fabian / 181511064 */

#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include "boolean.h"
#define nama(P) (P)->nama
#define next1(P) (P)->next1
#define next2(P) (P)->next2
#define Nil NULL

typedef char infotype;
typedef struct tElmtList *address;
typedef struct{
	infotype kota[20];
	address next1;
}city;
typedef struct tElmtList{
	infotype nama[20];
	address next2;
}ElmtList;

boolean isEmpty(address p);
//Tujuan : memeriksa apakah linked masih kosong
//Linked list kosong , jika Head == NULL

void Create_Node (address *p) ;
//Tujuan : memesan memory dengan alokasi dinamis
//Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
//Parameter : P (parameter Output)

void Isi_Node (address *p , infotype* name);

//Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
//Periksa keberadaan P, Nilai diisi jika P tidak NULL
//	*p.next2 diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)

void Tampil_List (address p);
//Tujuan : Menampilkan seluruh isi Linked List
//Parameter : p (parameter input)

void Ins_Awal (address *p, address PNew);
//Tujuan : Insert 1 node baru (PNew) di awal Linked List
//Parameter : P (input-output)
//	PNew (input)

void Ins_Akhir (address *p, address PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

address Search (address p, infotype* nilai);
/* Mencari apakah ada elemen list dengan nama(P) = nilai */ /* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
address Search2(address p , infotype *nilai);
/* Buat membantu fungsi delete */

void InsertAfter (address * pBef, address PNew);

/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */

void Del_Awal (address *p);
/* untuk menghapus intinya */

void Del_After (address * pBef);
/* untuk menghapus intinya */

void DeAlokasi (address *p);
/* membebaskan intinya */

int NbElmt (address p);
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */ // Recursif Mode

address BalikList (address p);
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */

#endif

