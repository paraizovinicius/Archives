#include <stdio.h>


int main(int argc, char** argv)
{
	FILE *entrada1, *entrada2, *saida;

	entrada1 = fopen("aula1a.txt","rb");
	entrada2 = fopen("aula1b.txt","rb");
    saida = fopen("resultado.txt","wb");

	int c1 = fgetc(entrada1);
	while(c1 != EOF)
	{
		fputc(c1, saida);
		c1 = fgetc(entrada1); 
	}

    int c2 = fgetc(entrada2);
	while(c2 != EOF)
	{
		fputc(c2, saida);
		c2 = fgetc(entrada2); 
	}

	fclose(entrada1);
    fclose(entrada2);
	fclose(saida);
	return 0;
}