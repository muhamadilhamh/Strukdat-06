/*
Program		: Exercise-01
Nama		: Sitti Ufairoh Azzahra
NPM			: 140810180002
Deskripsi	: Program ini berfungsi untuk merepresentasikan data dalam singly linked list
Tanggal		: 14 April 2019
*/
#include<iostream>
using namespace std;

struct Singly{
	char data;
	Singly* next;
};

void createSingly(Singly* &pBaru){
	pBaru = new Singly;
	cout<<"Masukkan data : ";cin>>pBaru->data;
	pBaru->next=NULL;
}
void insertFirst(Singly* &first, Singly* pBaru){
	if(first==NULL){
		first=pBaru;
	}else{
		pBaru->next=first;
		first=pBaru;
	}
	cout<<endl<<"Yeayyy Berhasil!"<<endl;
}
void insertLast(Singly* &first, Singly* pBaru){
	if(first==NULL){
		first=pBaru;
	}else{
		Singly *last=first;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
	cout<<endl<<"Yeayyy Berhasil!"<<endl;
}
void deleteFirst(Singly* &first, Singly* &pHapus){
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
void deleteLast(Singly* &first, Singly* &pHapus){
	pHapus=first;
	if(first==NULL){
		pHapus=NULL;
	}else{
		Singly *prevLast;
		while(pHapus->next!=NULL){
			prevLast=pHapus;
			pHapus=pHapus->next;
		}
		prevLast->next=NULL;
		pHapus=NULL;
		cout<<endl<<"Berhasil Dihapus!"<<endl;
	}
}
void traversal(Singly* first){
	if(first!=NULL){
		Singly *trav=first;
		while(trav!=NULL){
			cout<<"'"<<trav->data<<"'";
			if(trav->next!=NULL){
				cout<<"->";
			}
			trav=trav->next;
		}
	}else{
		cout<<"List Tidak Ditemukan!"<<endl;
	}
}

int main(){
	Singly *list=NULL,*p;
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
				createSingly(p);
				insertFirst(list,p);
				break;
			case 2:
				createSingly(p);
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
