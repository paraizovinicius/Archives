#include <iostream>

using namespace std;

struct no
{
    int info;
    struct no *ant;
    struct no *prox;
};
typedef struct no *noPtr;

noPtr topo = NULL;

void push(noPtr *);
void pop(noPtr *);
void list(noPtr);

main() // LIFO mode
{

    int input;
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
            list(topo);
            break;
        }
    } while (input != 0);

    return 0;
}

void push(noPtr *i)
{
    noPtr p = new no;
    cout << endl
         << "Insert the new value:" << endl;
    cin >> p->info;

    p->ant = NULL;
    if (*i == NULL)
    {
        p->prox = NULL;
    }
    else
    {
        p->prox = *i;
        (*i)->ant = p; // formato PILHA
    }
    *i = p;
}

void pop(noPtr *i)
{
    noPtr p = *i; // qual a necessidade de fazer isso?

    if (topo == NULL)
        cout << endl
             << "Empty list!" << endl;
    else
    {
        if (p->prox == NULL)
            *i = NULL; // somente um elemento
        else
        {
            *i = p->prox;
            (*i)->ant = NULL;
        }
        delete (p);
        cout << endl
             << "Item removed from the list!" << endl;
    }
}

void list(noPtr p)
{
    if (topo == NULL)
        cout << endl
             << "Empty list!" << endl;
    else
    {
        noPtr a = topo;
        while (a != NULL)
        {
            cout << "| " << a->info << " |";
            a = a->prox;
        }
        cout << endl;
    }
}
