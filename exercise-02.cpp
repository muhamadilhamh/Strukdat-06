/*
Nama    = Muhamad Ilham Habib
Kelas   = B
NPM     = 140810180018
Tahun   = 2019
Deskripsi = Represent below data in doubly linked list
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
struct ElemtList{
    char data;
    ElemtList* next;
    ElemtList* prev;
};
void createList(ElemtList* &pBaru){
    pBaru = new ElemtList;
    cout<<"Mausukan data =";cin>>pBaru->data;
    pBaru->next=NULL;
    pBaru->prev=NULL;
}
void insertFirst(ElemtList* &First, ElemtList* pBaru){
    if(First==NULL){
        First=pBaru;
    }else{
        pBaru->next=First;
        First->prev=pBaru;
        First=pBaru;
    }
    cout<<"Data Berhasil"<<endl;
}
void insertLast(ElemtList* &First, ElemtList* pBaru){
    if(First==NULL){
        First=pBaru;
    }else{
        ElemtList *last=pBaru;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
        pBaru->prev=last;
    }
    cout<<"Data Berhasil"<<endl;
}
void deleteFirst(ElemtList* &First, ElemtList* &pHapus){
    pHapus=First;
    if(First==NULL){
        pHapus=NULL;
    }else{
        First=First->next;
        pHapus->next=NULL;
        pHapus=NULL;
        cout<<"Berhasil dihapus"<<endl;
    }
}
void deleteLast(ElemtList* &First, ElemtList* &pHapus){
    pHapus=First;
	if(First==NULL){
		pHapus=NULL;
	}else{
		ElemtList *prevLast;
		while(pHapus->next!=NULL){
			prevLast=pHapus;
			pHapus=pHapus->next;
		}
		prevLast->next=NULL;
		pHapus->prev=NULL;
		pHapus=NULL;
		cout<<endl<<"Berhasil Dihapus!"<<endl;
	}
}
void traversal(ElemtList* First){
    if(First!=NULL){
        ElemtList *trav=First;
        while(trav!=NULL){
            cout<<"'"<<trav->data<<"'";
            if(trav->next!=NULL){
                cout<<"<-->";
            }
            trav=trav->next;
        }
    }else{
        cout<<"List Tidak Ditemukan"<<endl;
    }
}
int main(){
    ElemtList *list=NULL, *p;
    int pil;
    char loop;
    do{
        system("CLS");
		cout << "--------MENU--------" <<endl;
		cout << "1.  Insert First" <<endl;
		cout << "2.  Insert Last" <<endl;
		cout << "3.  Delete First" <<endl;
		cout << "4.  Delete Last" <<endl;
		cout << "5.  Traversal" <<endl;
		cout << "--------------------" <<endl;
		do{
			cout << "Pilih : "; cin >> pil;
		}while(pil<1||pil>5);
		switch(pil){
			case 1:
				createList(p);
				insertFirst(list,p);
				break;
			case 2:
				createList(p);
				insertLast(list,p);
				break;
			case 3:
				deleteFirst(list,p);
				break;
			case 4:
				deleteLast(list,p);
				break;
			case 5:
				traversal(list);
				break;
		}
		cout<<endl<<"Kembali ke menu? (Y/N) ";
		do{
			cin>>loop;
		}while(loop!='Y'&&loop!='y'&&loop!='N'&&loop!='n');
	}while(loop=='Y'||loop=='y');
}



