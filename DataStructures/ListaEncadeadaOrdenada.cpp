#include <iostream>

using namespace std;

struct no {
    int info;
    struct no *prox;
};

typedef struct no * noPtr;
noPtr topo = NULL;

void push();
void pop();
bool emptyList();
void list();

main(){ // First In First Out -- FIFO

    int input;
    do{
        cout <<  endl << "Select the following: " << endl << "1 for push" << endl << "2 for pop" << endl << "3 to list" << endl << "0 to end" <<endl;
        cin >> input;
        switch(input){
            case 1: // enqueue
                push();
                break;
            case 2: // dequeue
                pop();
                break;
            case 3: // list
                list();
                break;
        }
    } while (input != 0);
    return 0;
}

void push(){
    noPtr aux, ant, p = new no;
    cout << endl << "Type the value of the noeud:" << endl;
    cin >> p->info;
    aux = topo;

    if(emptyList()){
        p->prox = topo; //recebe null
        topo = p; // topo atualizado
    } else{
        while(aux != NULL && p->info > aux->info){
                ant = aux;
                aux = aux->prox;
            }
        if(topo == aux){
            topo = p;
            p->prox = aux;
        } else{
            ant->prox = p;
            p->prox = aux;
        }
    }
}

void pop(){

    if(emptyList()) cout << endl << "Empty list!" << endl;
    else topo = topo->prox; // topo agora aponta pra onde o primeiro elemento apontava
}

void list(){
    if(emptyList()) cout << endl << "Empty list!" << endl;
    else {
        noPtr a = topo;
        while(a->prox != NULL){
            cout << "| " << a->info << " |";
            a = a->prox;
        }
        cout << "| " << a->info << " |";
        cout << endl;
    }
}

bool emptyList(){
    if(topo == NULL) return true;
    else return false;
}
