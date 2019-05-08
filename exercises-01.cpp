/*
Nama = Muhamad Ilham Habib
NPM = 140810180018
Tahun = 2019
Deskripsi = program antrian huruf MARCEL dengan array
*/
#include <iostream>

using namespace std;

const int maxE=5;
struct Queue{
    char data[maxE];
    int head;
    int tail;
};

void createQueue(Queue& S){
    S.head=-1;
    S.tail=-1;
}
void push(Queue &S){
    if(S.head==-1){
        S.head++;
        S.tail++;
        cin>>S.data[S.head];
    }else{
        if(S.tail<maxE-1){
            S.tail++;
            cin>>S.data[S.tail];
        }else{
            if(S.head==0){
                cout<<"Geus pinuh"<<endl;
            }else{
                S.tail=0;
                cin>>S.data[S.tail];
            }
        }
    }
}
void pop(Queue &S){
    if(S.tail==-1){
        cout<<"Kosong-kosong"<<endl;
    }else if(S.head==S.tail){
        S.head = -1;
        S.tail = -1;
    }else{
        if(S.head<maxE-1){
            S.head++;
        }else{
            S.head=0;
        }
    }
}
void print(Queue &S){
    if(S.head==-1){
        cout<<"Kosong-kosong"<<endl;
    }else{
        int i = S.head;
        cout<<"\n"<<"Antrian = [";
        if(S.head>S.tail){
            while(i<maxE){
                cout<<S.data[i];
                if(i!=S.tail){
                    cout<<",";
                }i++;
            }
            i=0;
            while(i<=S.tail){
                cout<<S.data[i];
                if(i!=S.tail){
                    cout<<",";
                }
                i++;
            }
        }else{
            while(i<=S.tail){
                cout<<S.data[i];
                if(i!=S.tail){
                    cout<<",";
                }
                i++;
            }
        }cout<<"]\n";
    }
}
int main(){
    Queue S;
    int pil,n;
    char opsi;

    cout<<"Masukan banyaknya data :"; cin>>n;
    cout<<"Input Nama (inisial) :"<<endl;
    for(int i=0;i<n;i++){
        push(S);
    }
    do{
        system("cls");
        cout<<"\n|1. Push\n|2. Pop\n|3. Print\n\nMasukkan pilihan :";cin>>pil;
        switch(pil){
        case 1:
            push(S);
            break;
        case 2:
            pop(S);
            break;
        case 3:
            print(S);

        }
        cout<<"Kembali ke Menu (Y/N) :";cin>>opsi;
    }while(opsi=='Y'||opsi=='y');

    return 0;
}
