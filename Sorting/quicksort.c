#include <stdio.h>
#include <stdlib.h>
#define n 10

void quick(int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void quickSort(int v[], int inicio, int fim) {

    int i, j, chave;
    if (fim - inicio < 2) 
    {
        if ((fim - inicio) == 1) {
            if (v[inicio] > v[fim])
              quick(&v[inicio], &v[fim]);
            }
    } 
    
    else 
    {
        i = inicio;
        j = fim;
        chave = v[inicio];
        while (j > i) 
        {
                i++;
            while (v[i] < chave) {
                i++;
            }
            while (v[j] > chave) {
                j--;
            }
            if (j > i) {
                quick(&v[i], &v[j]);
            }
        }
        quick(&v[inicio], &v[fim]);
        quickSort(v, inicio, j - 1);
        quickSort(v, j + 1, fim);
    } //else
} // quicksort



int main() {
    int v[n], i, resultado, j;
    printf("Sequencia sorteada: ");
    for (i = 0; i < n; i++)
    {
    printf("|%d|", v[i] = rand()%100);
    }
    quickSort(v, n-n, n - 1);
    printf("\n\nSequencia ordenada: ");
    for (i = 0; i < n; i++)
    printf("|%d|", v[i]);
}