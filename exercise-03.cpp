/*
Nama    = Muhamad Ilham Habib
Kelas   = B
NPM     = 140810180018
Tahun   = 2019
Deskripsi = Represent below data in circular doubly linked list
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Elemtlist{
    char data;
    Elemtlist* next;
    Elemtlist* prev;
};
void createList(Elemtlist* &pBaru){
    pBaru = new Elemtlist;
    cout<<"Masukan data =";cin>>pBaru->data;
    pBaru->next=NULL;
    pBaru->prev=NULL;
}
void insertFirst(Elemtlist* &First, Elemtlist* &pBaru){
    if(First==NULL){
		First=pBaru;
		First->next=First;
		First->prev=First;
	}else{
		pBaru->next=First;
		pBaru->prev=First->prev;
		First->prev->next=pBaru;
		First->prev=pBaru;
		First=pBaru;
	}
	cout<<endl<<"Data berhasil "<<endl;
}
void insertLast(Elemtlist* &First, Elemtlist* pBaru){
	if(First==NULL){
		First=pBaru;
		pBaru->next=First;
		pBaru->prev=First;
	}else{
		Elemtlist *last=First;
		while(last->next!=First){
			last=last->next;
		}
		last->next=pBaru;
		pBaru->prev=last;
		pBaru->next=First;
		First->prev=pBaru;
	}
	cout<<endl<<"Data Berhasil"<<endl;
}
void deleteFirst(Elemtlist* &First, Elemtlist* &pHapus){
	pHapus=First;
	if(First==NULL){
		pHapus=NULL;
		cout<<"Data tidak terhapus"<<endl;
	}else if(First->next==First){
		First->next=NULL;
		First->prev=NULL;
		First=NULL;
		cout<<"Data berhasil dihapus"<<endl;
	}else{
		First->next->prev=First->prev;
		First->prev->next=First->next;
		First=First->next;
		pHapus->next=NULL;
		pHapus->prev=NULL;
		pHapus=NULL;
		cout<<endl<<"Data berhasil dihapus"<<endl;
	}
}
void deleteLast(Elemtlist* &First, Elemtlist* &pHapus){
	pHapus=First;
	if(pHapus==NULL){
		pHapus=NULL;
		cout<<"Data Tidak Terhapus"<<endl;
	}else if(First->next==First){
		First->next=NULL;
		First->prev=NULL;
		First=NULL;
		cout<<"Data berhasil dihapus"<<endl;
	}else{
		Elemtlist *prevLast;
		while(pHapus->next!=First){
			prevLast=pHapus;
			pHapus=pHapus->next;
		}
		prevLast->next=First;
		pHapus->prev=NULL;
		pHapus->next=NULL;
		pHapus=NULL;
		cout<<"Data berhasil dihapus"<<endl;
	}
}
void traversal(Elemtlist* First){
	if(First!=NULL){
		Elemtlist *trav=First;
		cout<<"...<-->";
		do{
			cout<<"'"<<trav->data<<"'";
			if(trav->next!=First){
				cout<<"<-->";
			}
			trav=trav->next;
		}while(trav!=First);
		cout<<"<-->...";
	}else{
		cout<<"List Tidak Ada!"<<endl;
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

