#include <iostream>

using namespace std;

struct no {
    int info;
    struct no *prox;
};

typedef struct no * noPtr;
noPtr topo = NULL;
noPtr ultimo = NULL;

void enqueue();
void dequeue();
bool emptyList();
void list();

main(){ // LAST IN FIRST OUT -- LIFO

    ultimo = new no;
    ultimo->info = 0;
    ultimo->prox = NULL;
    int input;
    do{
        cout <<  endl << "Select the following: " << endl << "1 for enqueue" << endl << "2 for dequeue" << endl << "3 to list" << endl << "0 to end" <<endl;
        cin >> input;
        switch(input){
            case 1: // enqueue
                enqueue();
                break;
            case 2: // dequeue
                dequeue();
                break;
            case 3: // list
                list();
                break;
        }
    } while (input != 0);

return 0;
}

void enqueue(){
    noPtr aux, p = new no;
    cout << endl << "Type the value of the noeud:" << endl;
    cin >> p->info;

    if(emptyList()){
        cout << endl << "Empty list, item added." << endl;
        topo = p;
        p->prox = ultimo;
    }
    else{
        aux = topo;
        while(aux->prox != ultimo){
            aux = aux->prox;
        }
        aux->prox = p;
        p->prox = ultimo;
    }
}

void dequeue(){
    if(emptyList()) cout << endl << "Empty list!" << endl;
    else topo = topo->prox;
}

bool emptyList(){
    if(topo == NULL) return true;
    else return false;
}

void list(){
    if(emptyList()) cout << endl << "Empty list!" << endl;
    else {
        noPtr a = topo;
        while(a->prox != NULL){
            cout << "| " << a->info << " |";
            a = a->prox;
        }
        cout << endl;
    }
}