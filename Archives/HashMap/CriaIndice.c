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
    return n % hashSize;
}

int main(int argc, char**argv)
{
	FILE *file, *index;
	Endereco e;
    Registro r;

    index = fopen("cep-hash.dat","wb");
    strncpy(r.cep,"        ",8);
    r.Valor = 0;
    r.Prox = 0;

    for(int i=0; i<hashSize ; i++){

        fwrite(&r,sizeof(Registro),1,index);
    }

    fclose(index); //o arquivo index agora está resetado

	file = fopen("cep.dat","rb");
    index = fopen("cep-hash.dat","r+b"); //lê e escreve mas não sobrescreve.

    fseek(index,0,SEEK_END);
    long fileIndexSize = ftell(index);
    int contador = 0;

    int qt = fread(&e,sizeof(Endereco),1,file);
    while(qt > 0){
        int p = h(e.cep); //transforma o cep em inteiro e retorna a posição onde ele deve ficar no arquivo de indice
        fseek(index,p*sizeof(Registro), SEEK_SET); //posiciona para o lugar certo no arquivo do indice
        fread(&r,sizeof(Registro),1,index); //lê o negócio que tá na posição posicionada
        fseek(index,p*sizeof(Registro), SEEK_SET); //recoloca na posição, pois o fread avança na posição
        if(strncmp(r.cep,"        ",8) == 0){ //se estiver zerado
            strncpy(r.cep, e.cep, 8);
            r.Valor = contador;
            r.Prox = 0;
            fwrite(&r,sizeof(Registro),1,index); //colocar o cep no arquivo de indice
        } else { //Em caso de colisão..
            long prox = r.Prox; 
            r.Prox = fileIndexSize; // o ponteiro Prox da célula já existente do arquivo indice vai apontar pro fim da lista
            fwrite(&r,sizeof(Registro),1,index); //escreve a posição do ultimo arquivo no Prox do arquivo colidido
            fseek(index,0,SEEK_END); //vamos colocar o novo item colidido no fim do arquivo
            strncpy(r.cep, e.cep, 8);
            r.Valor = contador;
            r.Prox = prox;
            fwrite(&r,sizeof(Registro),1,index); //copia e cola a célula no arquivo novo (na ultima posição do arquivo índice) que colidiu com o arquivo colidido
            fileIndexSize = ftell(index); //já que aumentou de tamanho, incrementar o tamanho
        }
        contador++;
        fread(&e,sizeof(Endereco),1,file);
    }

    
    fclose(file);
    fclose(index);
}

	