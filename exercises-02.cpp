/*
Nama = Muhamad Ilham Habib
NPM = 140810180018
Tahun = 2019
Deskripsi = program antrian huruf MARCEL dengan linklist
*/
#include <iostream>

using namespace std;


struct QueueList{
    char info;
    QueueList* next;
};
typedef QueueList* pointer;
typedef pointer List;

struct Queue{
    QueueList *head;
    QueueList *tail;
};
Queue S;

void createQueue(Queue& S){
    S.head=NULL;
    S.tail=NULL;
}
void createList(pointer &pBaru){
	pBaru=new QueueList;
	cout << "Masukkan huruf(Hrs huruf): "<<endl;
	cin>>pBaru->info;
	pBaru->next=NULL;
}

void push(Queue &S, pointer &pBaru){
	if(S.head==NULL){
		S.head=pBaru;
		S.tail=pBaru;
	}else{
		S.tail->next=pBaru;
		S.tail=pBaru;
	}
}

void pop(Queue &S, pointer pHapus){
	if(S.head==NULL){
		cout<<"Antrian Kosong-Kosong"<<endl;
	}else{
		pointer pHapus;
		pHapus=S.head;
		S.head=S.head->next;
		pHapus->next=NULL;
	}
}

void print(Queue S){
	if(S.head==NULL){
		cout<<"Antrian Kosong."<<endl;
	}else{
		pointer pBantu=S.head;
		cout<<endl<<"Q = [";
		while(pBantu!=NULL){
			cout<<pBantu->info;
			if(pBantu->next!=NULL){
				cout<<", ";
			}
			pBantu=pBantu->next;
		}
		cout<<"]"<<endl;
	}
}

int main(){
	Queue S;
	pointer p, pHapus;
	char pil;
	int opsi;

	createQueue(S);

	do{
		system("cls");
		cout << "\n|1. Push\n|2. Pop\n|3. Print\n\nMasukkan pilihan : ";
		cin >> opsi;
		switch(opsi)
		{
			case 1: createList(p);
					push(S,p);
					break;
			case 2: pop(S,pHapus);
					break;
			case 3: print(S);
					break;
			default: cout << "Pilihan salah.\n";
					 break;
		}
		cout << "Again? (Y/N) "; cin >> pil;
	} while (pil=='Y' || pil=='y');
}
