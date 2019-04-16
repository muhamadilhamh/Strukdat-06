/*
Program		: Exercise-02
Nama		: Sitti Ufairoh Azzahra
NPM			: 140810180002
Deskripsi	: Program ini berfungsi untuk merepresentasikan data dalam doubly linked list
Tanggal		: 14 April 2019
*/
#include<iostream>
using namespace std;

struct Doubly{
	char data;
	Doubly* next;
	Doubly* prev;
};

void createDoubly(Doubly* &pBaru){
	pBaru = new Doubly;
	cout<<"\nMasukkan data : ";cin>>pBaru->data;
	pBaru->next=NULL;
	pBaru->prev=NULL;
}
void insertFirst(Doubly* &first, Doubly* pBaru){
	if(first==NULL){
		first=pBaru;
	}else{
		pBaru->next=first;
		first->prev=pBaru;
		first=pBaru;
	}
	cout<<endl<<"Yeayy Berhasil!"<<endl;
}
void insertLast(Doubly* &first, Doubly* pBaru){
	if(first==NULL){
		first=pBaru;
	}else{
		Doubly *last=pBaru;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
		pBaru->prev=last;
	}
	cout<<endl<<"Yeayyy Berhasil!"<<endl;
}
void deleteFirst(Doubly* &first, Doubly* &pHapus){
	pHapus=first;
	if(first==NULL){
		pHapus=NULL;
	}else{
		first=first->next;
		pHapus->next=NULL;
		pHapus=NULL;
		cout<<endl<<"Berhasil Dihapus!"<<endl;
	}
}
void deleteLast(Doubly* &first, Doubly* &pHapus){
	pHapus=first;
	if(first==NULL){
		pHapus=NULL;
	}else{
		Doubly *prevLast;
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
void traversal(Doubly* first){
	if(first!=NULL){
		Doubly *trav=first;
		while(trav!=NULL){
			cout<<"'"<<trav->data<<"'";
			if(trav->next!=NULL){
				cout<<"<-->";
			}
			trav=trav->next;
		}
	}else{
		cout<<"List tidak ditemukan!"<<endl;
	}
}

int main(){
	Doubly *list=NULL,*d;
	int pil;char loop;
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
				createDoubly(d);
				insertFirst(list,d);
				break;
			case 2:
				createDoubly(d);
				insertLast(list,d);
				break;
			case 3:
				deleteFirst(list,d);
				break;
			case 4:
				deleteLast(list,d);
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
