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

    // 1254

    int n = 0;
    for(int i=0; i<8; i++) {
        n = n * 10 + (cep[i] - '0');
    }
    return n % hashSize; //essa função vai retornar a posição em que aquele CEP está no arquivo índice
}

int main(int argc, char**argv)
{
	FILE *file, *index;
	Endereco e;
    Registro r;

    index = fopen("cep-hash.dat","rb");
    file = fopen("cep.dat", "rb");

    int p = h(argv[1]);
    int offset = p*sizeof(Registro);

    int qt = fread(&r,sizeof(Registro),1,file);
    while(qt > 0){
    
        fseek(index, offset, SEEK_SET); //posiciona para o lugar certo no arquivo do indice
        fread(&r,sizeof(Registro),1,index); //lê o dado que está na localização já posicionada
        fseek(index,offset, SEEK_SET); //recoloca na posição, pois a função fread avança 01 posição

        if(strncmp(argv[1],r.cep,8)==0){
            printf("\nCEP: %.8s",r.cep);
            fclose(file);
            fclose(index);
            return 0; 
        }
        if(offset == 0){
            return 0;
        }

        fread(&r,sizeof(Registro),1,file);
    }
    fclose(file);
    fclose(index);
}