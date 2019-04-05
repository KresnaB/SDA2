#include "linked.h"

int main(){
    address head1,head2;
    address PNew;
    int nilai,jumlahsamping=0;
    //membuat node baru
    createnote(&head1);
    nilai = rand() % 10;
    isinode(&head1,nilai);
    //menambahkan
    createnote(&PNew);
    nilai = rand() % 10;
    isinode(&PNew,nilai);
    insakhir(&head1,PNew);
    //menambah ke bawah
    createnote(&PNew);
    nilai = rand() % 10;
    isinode(&PNew,nilai);
    insbawah(&head1,PNew);
    cekjumlahsamping(head1,&jumlahsamping);
    printf("%d",jumlahsamping);
    //menambah ke samping baris ke 2
    createnote(&PNew);
    nilai = rand() % 10;
    isinode(&PNew,nilai);
    penunjuk(head1,&head2);
    insakhir(&head2,PNew);
    //menghubungkan
    menghubungkan(&head1,head2,jumlahsamping);
    tampil(head1);
    tampil2(head1);
}
