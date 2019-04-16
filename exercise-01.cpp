/*
Nama    = Muhamad Ilham Habib
Kelas   = B
NPM     = 140810180018
Tahun   = 2019
Deskripsi = Represent below data in singly linked list.
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Elemtlist{
    char data;
    Elemtlist* next;
};
void createList(Elemtlist* &pBaru){
    pBaru = new Elemtlist;
    cout<<" Masukan data =";cin>>pBaru->data;
    pBaru->next = NULL;
}
void insertFirst(Elemtlist* &First, Elemtlist* pBaru){
    if(First==NULL){
        First=pBaru;
    }else{
        pBaru->next=First;
        First=pBaru;
    }
    cout<<"Data sukses"<<endl;
}
void insertLast(Elemtlist* &First, Elemtlist* pBaru){
    if(First==NULL){
        First=pBaru;
    }else{
        Elemtlist*last=First;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
    }
    cout<<"Data sukses"<<endl;
}
void deleteFirst(Elemtlist* &First, Elemtlist* &pHapus){
	pHapus=First;
	if(First==NULL){
		pHapus=NULL;
	}else{
		First=First->next;
		pHapus->next=NULL;
		pHapus=NULL;
		cout<<endl<<"Berhasil Dihapus!"<<endl;
	}
}
void deleteLast(Elemtlist* &First, Elemtlist* &pHapus){
	pHapus=First;
	if(First==NULL){
		pHapus=NULL;
	}else{
		Elemtlist *prevLast;
		while(pHapus->next!=NULL){
			prevLast=pHapus;
			pHapus=pHapus->next;
		}
		prevLast->next=NULL;
		pHapus=NULL;
		cout<<endl<<"Berhasil Dihapus!"<<endl;
	}
}
void traversal(Elemtlist* First){
    if(First!=NULL){
        Elemtlist*trav=First;
        while(trav!=NULL){
            cout<<"'"<<trav->data<<"'";
            if(trav->next!=NULL){
                cout<<"->";
            }
            trav=trav->next;
        }
    }else{
        cout<<"List Tidak Ditemukan"<<endl;
    }
}
int main(){
    Elemtlist *list=NULL,*p;
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
