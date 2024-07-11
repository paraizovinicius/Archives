#include <iostream>

using namespace std;

struct no
{
    int info;
    struct no *ant;
    struct no *prox;
};
typedef struct no *noPtr;

void push(noPtr *);
void pop(noPtr *);
void list(noPtr *);
bool listaVazia(noPtr);

main() // FIFO mode
{

    int input;
    noPtr topo = NULL;
    do
    {
        cout << endl
             << "Select the following: " << endl
             << "1 for enqueue" << endl
             << "2 for dequeue" << endl
             << "3 to list" << endl
             << "0 to end" << endl;
        cin >> input;
        switch (input)
        {
        case 1: // enqueue
            push(&topo);
            break;
        case 2: // dequeue
            pop(&topo);
            break;
        case 3: // list
            list(&topo);
            break;
        }
    } while (input != 0);

    return 0;
}

void push(noPtr *i)
{
    noPtr aux, auxant, p = new no;
    cout << endl
         << "Insert the new value:" << endl;
    cin >> p->info;
    p->prox = NULL;
    p->ant = NULL; // lembrar de inicializar as variáveis pois elas podem ser inicializadas com valores aleatórios e pode dar erro depois

    if (listaVazia(*i))
    {
        *i = p; // primeiro elemento
    }
    else
    {
        aux = *i;
        while (aux->prox != NULL && p->info > aux->info)
        {   
            aux = aux->prox;
        }
        if (p->info < aux->info) // ficará no meio
        {
            auxant = aux->ant;
            cout << "\naux: " << aux->info << "\nauxant: " << auxant->info;
            p->prox = aux;
            p->ant = auxant;
            auxant->prox = p;
            aux->ant = p;
        }
        else // último elemento
        {
            p->ant = aux;
            aux->prox = p;
        }
    }
    
}

void pop(noPtr *i)
{
    noPtr p = *i;

    if (listaVazia(*i))
        cout << endl
             << "Empty list!" << endl;
    else
    {
        if (p->prox == NULL) // somente um elemento
            *i = NULL;
        else
        {
            while (p->prox != NULL)
            {
                p = p->prox;
            }
            p->ant->prox = NULL; // penultimo elem -> prox
            p->ant = NULL;       // ultimo elem -> ant
        }
        delete (p);
        cout << endl
             << "Item removed from the list!" << endl;
    }
}

void list(noPtr *i)
{
    if (listaVazia(*i))
    {
        cout << endl
             << "Empty list!" << endl;
    }
    else
    {
        noPtr p = *i;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        while (p->ant != NULL){
            cout << "| " << p->info << " |";
            p = p->ant;
        }cout << "| " << p->info << " |";
    
        cout << endl;
    }
}

bool listaVazia(noPtr topo)
{
    if (topo == NULL)
    {
        return true;
    }
    else
        return false;
}