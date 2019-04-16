/*
Nama    = Muhamad Ilham Habib
Kelas   = B
NPM     = 140810180018
Tahun   = 2019
Deskripsi = Represent below data in circular doubly linked list
*/
#include <iostream>
#include <stdlib.h>
#include<string.h>
using namespace std;
struct Kontak{
    char nama[10];
    char nomor[12];
    Kontak* nextKontak;
};
struct Index{
    char index[1];
    Kontak* FirstKontak;
    Index*  next;
};

typedef Index* pointerIndex;
typedef Kontak* pointerKontak;
typedef pointerIndex Elm;

void createList(Elm& First){
    First=NULL;
}
void createIndex(pointerIndex& pBaru){
    pBaru= new Index;
    cout<<"Masukan Index :"; cin>>pBaru->index;
    pBaru->next=NULL;
	pBaru->FirstKontak=NULL;
}

void createKontak(pointerKontak& pBaru){
    pBaru= new Kontak;
    cout<<"Masukan Nama   :"; cin>>pBaru->nama;
    cout<<"Masukan Nomor  :"; cin>>pBaru->nomor;
    pBaru->nextKontak=NULL;
}

void traversalIndex(Elm First){
    pointerIndex pBantu;
    pBantu=First;
    cout<<"Index :"<<endl;
    while(pBantu!=NULL){
        cout<<"|- "<<pBantu->index<<endl;
        pBantu=pBantu->next;
    }
}

void linearSearch(Elm First,char key[20],int& status,pointerIndex& pCari){
    status=0;
    pCari=First;
    while(status==0 && pCari!=NULL){
        if(strcmp(pCari->index,key)==0){
            status=1;
        }
        else{
            pCari=pCari->next;
        }
    }
}

void insertFirstIndex(Elm& First,pointerIndex pBaru){
    if(First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void delFirstIndex(Elm& First,pointerIndex pHapus){
	if(First==NULL){
  		cout<<"List kosong"<<endl;
 	}
 	else if(First->next==NULL){
  		pHapus=First;
  		First=NULL;
 	}
 	else{
 		pHapus=First;
  		First=pHapus->next;
  		First->next=NULL;
 	}
}

void insertFirstKontak(Elm& First,char key[20],pointerKontak pBaru){
 	pointerIndex pIndex;
 	int ketemu;
 	cout<<"Masukan huruf pertama yang dicari: "; cin>>key;
 	linearSearch(First,key,ketemu,pIndex);

 	if(ketemu){
  		cout<<"Ditemukan Index :"<<pIndex->index<<endl;
  	if(pIndex->FirstKontak==NULL){
   		pIndex->FirstKontak=pBaru;
  	}
  	else{
  		pBaru->nextKontak=pIndex->FirstKontak;
  		pIndex->FirstKontak=pBaru;
  		}
 	}
 	else{
  		cout<<"idak ditemukan pada index"<<endl;
 	}
}

void delFirstKontak(Elm& First,char key[20],pointerKontak& pHapus ){
 	int ketemu;
 	pointerIndex pIndex;
 	cout<<"Masukan huruf pertama yang dicari: "; cin>>key;
 	linearSearch(First,key,ketemu,pIndex);

 	if(ketemu){
  		cout<<"Ditemukan Index :"<<pIndex->index;
  	if(pIndex->FirstKontak==NULL){
   		cout<<"Index Tidak di hapus"<<endl;
  	}
  	else if(pIndex->FirstKontak->nextKontak==NULL){
  		pHapus=pIndex->FirstKontak;
   		pIndex->FirstKontak=NULL;
  	}
  	else{
   		pHapus=pIndex->FirstKontak;
   		pIndex->FirstKontak=pIndex->FirstKontak->nextKontak;
   		pHapus->nextKontak=NULL;
		}
 	}
 	else{
  		cout<<"Index tidak di temukan"<<endl;
 	}
}

void traversal(Elm First){
    pointerIndex pBantuIndex;
    pointerKontak pBantuKontak;
    cout<<"Traversal Index Kontak"<<endl;
    pBantuIndex=First;

    while (pBantuIndex!=NULL){
        cout<<"|- "<<pBantuIndex->index<<endl;
        pBantuKontak=pBantuIndex->FirstKontak;
        while (pBantuKontak!=NULL) {
        	cout<<"\t|- "<<pBantuKontak->nama<< " / "<<pBantuKontak->nomor<<endl;
        	pBantuKontak=pBantuKontak->nextKontak;
        }
        pBantuIndex=pBantuIndex->next;
    }
}

int main(){
    Elm Elmt;
    int index,nama;
    int pil;
    char key [20];
    pointerIndex pd,pc,phd;
    pointerKontak pk,phk;
    createList(Elmt);
    do{
        system("CLS");
		cout << "--------------MENU--------------" <<endl;
		cout << " | 1.  Insert Index Phonebook" <<endl;
		cout << " | 2.  Insert Nomor" <<endl;
		cout << " | 3.  Delete Index" <<endl;
		cout << " | 4.  Delete Kontak" <<endl;
		cout << " | 5.  Tampilkan Phonebook" <<endl;
		cout << " | 6.  Exit" <<endl;
		cout << "Pilih : "; cin >> pil;
        switch(pil){
        case 1 :
            cout<<"Masukkan banyak Index : "; cin>>index;
            for(int i=0;i<index;i++){
                createIndex(pd);
                insertFirstIndex(Elmt,pd);
            }
            break;
        case 2 :cout<<"Masukan banyak Nama :";
            cin>>nama;
            traversalIndex(Elmt);
            for(int i=0;i<nama;i++){
                createKontak(pk);
                insertFirstKontak(Elmt,key,pk);
            }
            break;
        case 3 :
            delFirstIndex(Elmt,phd);
            traversalIndex(Elmt);
            break;
        case 4:
            delFirstKontak(Elmt,key,phk);
            traversal(Elmt);
            break;
        case 5 :
            traversal(Elmt);
            break;
        default :
            exit(0);
        }
        system("pause");
    }while(pil!=6);


}
