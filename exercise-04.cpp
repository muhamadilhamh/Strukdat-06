/*
Program		: Exercise-04
Nama		: Sitti Ufairoh Azzahra
NPM			: 140810180002
Deskripsi	: Program ini berfungsi untuk membuat phonebook dengan multi linked list
Tanggal		: 15 April 2019
*/

#include<iostream>
#include<string.h>

using namespace std;

struct Kontak{
 char nama[15];
 char nomor[12];
 Kontak* nextKontak;
};
struct Index{
 char index[1];
 Kontak* FirstKontak;
 Index* next;
};

typedef Index* pointerIndex;
typedef Kontak* pointerKontak;
typedef pointerIndex list;

void createList(list& First){
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

void traversalIndex(list First){
    pointerIndex pBantu;
    pBantu=First;
    cout<<"Index :"<<endl;
    while(pBantu!=NULL){
        cout<<"|- "<<pBantu->index<<endl;
        pBantu=pBantu->next;
    }
}

void linearSearch(list First,char key[20],int& status,pointerIndex& pCari){
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

void insertFirstIndex(list& First,pointerIndex pBaru){
    if(First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void delFirstIndex(list& First,pointerIndex pHapus){
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

void insertFirstKontak(list& First,char key[20],pointerKontak pBaru){
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

void delFirstKontak(list& First,char key[20],pointerKontak& pHapus ){
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

void traversal(list First){
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
    list a;
    int jindex,jnama;
    int pil;
    char key [20];
    pointerIndex pd,pc,phd;
    pointerKontak pk,phk;
    createList(a);
    do{
        system("CLS");
		cout << "--------------MENU--------------" <<endl;
		cout << "1.  Insert Index Phonebook" <<endl;
		cout << "2.  Insert Nomor" <<endl;
		cout << "3.  Delete Index" <<endl;
		cout << "4.  Delete Kontak" <<endl;
		cout << "5.  Tampilkan Phonebook" <<endl;
		cout << "6.  Exit" <<endl;	
		cout << "--------------------------------" <<endl;
		cout << "Pilih : "; cin >> pil;
        switch(pil){
        case 1 :
            cout<<"Masukkan banyak Index : "; cin>>jindex;
            for(int i=0;i<jindex;i++){
                createIndex(pd);
                insertFirstIndex(a,pd);
            }
            break;
        case 2 :cout<<"Masukan banyak Nama :";
            cin>>jnama;
            traversalIndex(a);
            for(int i=0;i<jnama;i++){
                createKontak(pk);
                insertFirstKontak(a,key,pk);
            }
            break;
        case 3 :
            delFirstIndex(a,phd);
            traversalIndex(a);
            break;
        case 4:
            delFirstKontak(a,key,phk);
            traversal(a);
            break;
        case 5 :
            traversal(a);
            break;
        default :
            exit(0);
        }
        system("pause");
    }while(pil!=6);


}


