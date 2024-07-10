#include <iostream>

struct no
{
    int info;
    struct no *prox;
};

typedef struct no *noPtr;

int inserir(noPtr *, int *);
void retirar(noPtr *, int *);
void listar(noPtr, int);

using namespace std;

main() // LIFO
{
    noPtr topo = NULL;
    int op, qtde = 0;
    do
    { // assert op is int
        cout << endl
             << "Select the following: " << endl
             << "1 for enqueue" << endl
             << "2 for dequeue" << endl
             << "3 to list" << endl
             << "0 to end" << endl;
        cin >> op;
        switch (op)
        {

        case 1:
            qtde = inserir(&topo, &qtde);
            cout << "\nA lista posssui " << qtde << " nos" << endl;
            break;

        case 2:
            retirar(&topo, &qtde);
            break;
        case 3:
            listar(topo, qtde);
            break;
        }
    } while (op != 0);
    return 0;
}
int inserir(noPtr *i, int *q)
{
    noPtr aux, p = new no;
    cout << "\nInsira novo no\n";
    cin >> p->info;

    if (*i == NULL)
    {
        *i = p;
        p->prox = *i; // o ultimo colocado apontará pra ele mesmo;
    }
    else
    { // formato PILHA
        p->prox = *i;
        *i = p; // topo atualizado para o novo nó
        aux = *i;
        for (int i = 0; i < *q; i++)
        {
            aux = aux->prox;
        } // aux aponta pro último da fila
        aux->prox = *i; // ultimo elemento -> prox recebe o topo atualizado
    }
    return *q + 1;
}
void retirar(noPtr *i, int *q)
{
    noPtr p = *i;
    if (*i == NULL)
        cout << "\nLista vazia!\n";
    else
    {
        if(*q == 1) (*i) == NULL;
        else{
            (*i) = p->prox;
        }
        delete (p);
        *q = *q - 1;
    }
}


void listar(noPtr topo, int q)
{
    noPtr aux = topo;
    if (topo == NULL)
        cout << "\nLista vazia!\n";
    else
    {
        for (int i = 0; i < q; i++)
        {
            cout << "| " << aux->info << " |";
            aux = aux->prox;
        }
    }
}