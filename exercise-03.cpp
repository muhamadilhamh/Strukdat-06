/*
Program		: Exercise-02
Nama		: Sitti Ufairoh Azzahra
NPM			: 140810180002
Deskripsi	: Program ini berfungsi untuk merepresentasikan data dalam circular doubly linked list
Tanggal		: 14 April 2019
*/
#include<iostream>
using namespace std;

struct Circular{
	char data;
	Circular* next;
	Circular* prev;
};

void createCircular(Circular* &pBaru){
	pBaru = new Circular;
	cout<<"\nMasukkan data : ";cin>>pBaru->data;
	pBaru->next=NULL;
	pBaru->prev=NULL;
}
void insertFirst(Circular* &first, Circular* pBaru){
	if(first==NULL){
		first=pBaru;
		first->next=first;
		first->prev=first;
	}else{
		pBaru->next=first;
		pBaru->prev=first->prev;
		first->prev->next=pBaru;
		first->prev=pBaru;
		first=pBaru;
	}
	cout<<endl<<"Yeayyy Berhasil!"<<endl;
}
void insertLast(Circular* &first, Circular* pBaru){
	if(first==NULL){
		first=pBaru;
		pBaru->next=first;
		pBaru->prev=first;
	}else{
		Circular *last=first;
		while(last->next!=first){
			last=last->next;
		}
		last->next=pBaru;
		pBaru->prev=last;
		pBaru->next=first;
		first->prev=pBaru;
	}
	cout<<endl<<"Yeayyy Berhasil!"<<endl;
}
void deleteFirst(Circular* &first, Circular* &pHapus){
	pHapus=first;
	if(first==NULL){
		pHapus=NULL;
		cout<<endl<<"Tidak Terhapus"<<endl;
	}else if(first->next==first){
		first->next=NULL;
		first->prev=NULL;
		first=NULL;
		cout<<endl<<"Berhasil Delete Firstnya!"<<endl;
	}else{
		first->next->prev=first->prev;
		first->prev->next=first->next;
		first=first->next;
		pHapus->next=NULL;
		pHapus->prev=NULL;
		pHapus=NULL;
		cout<<endl<<"Berhasil Delete Firstnya!"<<endl;
	}
}
void deleteLast(Circular* &first, Circular* &pHapus){
	pHapus=first;
	if(pHapus==NULL){
		pHapus=NULL;
		cout<<endl<<"Tidak Terhapus"<<endl;
	}else if(first->next==first){
		first->next=NULL;
		first->prev=NULL;
		first=NULL;
		cout<<endl<<"Berhasil Delete Lastnya!"<<endl;
	}else{
		Circular *prevLast;
		while(pHapus->next!=first){
			prevLast=pHapus;
			pHapus=pHapus->next;
		}
		prevLast->next=first;
		pHapus->prev=NULL;
		pHapus->next=NULL;
		pHapus=NULL;
		cout<<endl<<"Berhasil Delete Lastnya!"<<endl;
	}
}
void traversal(Circular* first){
	if(first!=NULL){
		Circular *trav=first;
		cout<<"...<-->";
		do{
			cout<<"'"<<trav->data<<"'";
			if(trav->next!=first){
				cout<<"<-->";
			}
			trav=trav->next;
		}while(trav!=first);
		cout<<"<-->...";
	}else{
		cout<<"List Tidak Ada!"<<endl;
	}
}

int main(){
	Circular *list=NULL,*c;
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
				createCircular(c);
				insertFirst(list,c);
				break;
			case 2:
				createCircular(c);
				insertLast(list,c);
				break;
			case 3:
				deleteFirst(list,c);
				break;
			case 4:
				deleteLast(list,c);
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
