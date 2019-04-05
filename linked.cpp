#include "linked.h"
bool isEmpty(address p)
{
    if (p==NULL){
        return true;
    }else{
        return false;
    }
}
void createnote(address *p)
{
    *p = (address) malloc(sizeof(matriks));
}
void isinode(address *p,infotype nilai)
{
    if (!isEmpty(*p)){
        (*p)->data=nilai;
        (*p)->next=NULL;
        (*p)->prev=NULL;
    }

}
void insakhir(address *p,address PNew)
{
    address temp;
    temp=*p;
    while (temp->next!=NULL){
       temp=temp->next;
    }
    temp->next=PNew;
}
void insbawah(address *p,address PNew)
{
    address temp;
    temp=*p;
    while (temp->prev!=NULL){
       temp=temp->prev;
    }
    temp->prev=PNew;
}
void cekjumlahsamping(address p,infotype *X)
{
    address temp;
    temp=p;
    while (temp->next!=NULL){
       temp=temp->next;
       *X=*X+1;
    }
}
void cekjumlahbawah(address p,infotype *X)
{
    address temp;
    temp=p;
    while (temp->prev!=NULL){
       temp=temp->prev;
       *X=*X+1;
    }
}
void tampil(address p)
{
    address temp,temp1;
    temp=p;
    temp1=p;
    printf("\nNode :{");
    while (temp != NULL){
        while (temp1 != NULL) {
            printf("%d ", temp1->data);
            temp1 = temp1->next;
        }
        printf("\n");
        temp=temp->prev;
        temp1=temp;
    }
    printf("}");
}
void penunjuk(address p,address *q){
    while (p->prev!=NULL){
       p=p->prev;
    }
    *q=p;
}
void menghubungkan(address *p,address q, int jumlah){
    int x=0,y=0;
    address temp=*p;
    while (x!=jumlah){
       temp=temp->next;
       x++;
    }
    while (y!=jumlah){
        q=q->next;
        y++;
    }
    temp->prev=q;
}
void tampil2(address p)
{
    address temp,temp1;
    temp=p;
    temp1=p;
    printf("\nNode :{");
    while (temp1 != NULL){
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
        printf("\n");
        temp1=temp1->next;
        temp=temp1;
    }
    printf("}");
}
