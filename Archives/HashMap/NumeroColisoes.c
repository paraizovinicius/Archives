#include <stdio.h>
#include <string.h>


typedef struct _Endereco Endereco;

struct _Endereco
{
	
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2]; // Ao Espaço no final da linha + quebra de linha
};

typedef struct _Registro Registro;

struct _Registro
{
	
    char cep[8];
	long Valor;
    long Prox;
};

int hashSize = 900001;

int h (char cep[8]) {

    int n = 0;
    for(int i=0; i<8; i++) {
        n = n * 10 + (cep[i] - '0');
    }
    return n % hashSize; //essa função vai retornar a posição em que aquele CEP está no arquivo índice
}

int main(int argc, char**argv) {

    int colisoes = 0;
    int tamanhoMaiorLista = 0;
    int recordCount = 0;

    int counts [900001];
    for(int i = 0; i < 900001; i++){
        counts[i] = 0;
    }

	FILE *file, *index;
	Endereco e;
    Registro r;

    file = fopen("cep.dat", "rb");

    int qt = fread(&r,sizeof(Registro),1,file);
    while(qt > 0){
        if (EOF){
            break;
        }
        int p = h(e.cep);
        counts[p] += 1;

        if (counts[p] > 1){
            colisoes += 1;
        }
        if (counts[p] > tamanhoMaiorLista){
            tamanhoMaiorLista = counts[p];
        }
        recordCount += 1;
        qt = fread(&r,sizeof(Registro),1,file);
    }
fclose(file);
// 
printf("\nNumero Colisoes: %i\n", colisoes);
printf("\nTamanho Maior Lista:%i\n", tamanhoMaiorLista);
return 0;
}