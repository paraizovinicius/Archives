# Arquivos
Matéria de Organização de Estrutura de Arquivos do curso Bacharel Ciência da Computação do CEFET/RJ. Códigos feitos por Vinicius Paraizo. 

Você pode pegar as bases de dados teste em [dropbox link](https://www.dropbox.com/sh/8i46wy3q0rmasu7/AADIUy2iVsoWWwcbnxbPGrzya?dl=0)

Lá, você vai encontrar o cep.dat, cepordenado.dat e cep-hash.dat.

## MergeSort

Este código vai realizar a ordenação por meio do merge sort do arquivo "cep.dat".

### Como os usuários podem utilizá-lo
      Para o código funcionar, é preciso ter não somente o código "mergesort.c" como também o arquivo "cep.dat".
      Por fim, coloque os dois arquivos necessários em uma pasta dentro do seu computador. Abra o VS code com essa pasta. Compile o arquivo utilizando o seguinte código no terminal: "gcc -o mergesort mergesort.c". Obs: é preciso ter o compilador GCC instalado no seu computador.
      Com o código mergesort compilado, agora você pode realizar o teste no código. Para isso digite no terminal "./mergesort".


## Buscabinaria

Este código vai realizar uma busca binária à partir do arquivo cep_ordenado.dat
    
### Como os usuários podem utilizá-lo
      Para o código funcionar, é preciso ter não somente o código "buscabinária.c" como também o arquivo "cep_ordenado.dat". 
      Compile o arquivo utilizando o seguinte código no terminal: "gcc -o buscabinaria buscabinaria.c". Obs: é preciso ter o compilador GCC instalado no seu computador.
      Com o código buscabinária compilado, agora você pode realizar o teste no código. 
      Para isso digite no terminal "./buscabinaria [CEP desejado]"


## Copia1

Este código vai copiar um arquivo e gerar uma cópia. 

### Como os usuários podem utilizá-lo
      No terminal, esteja na pasta onde está o copia1.c e também o arquivo a ser copiado
      comando: gcc -o copia1 copia1.c
      comando: ./copia1 [arquivo origem] [arquivo destino]
      ex: ./copia1 teste.jpg imagem.jpg


## Ordena1

Este código vai ordenar um arquivo e gerar esse novo arquivo ordenado. 

### Como os usuários podem utilizá-lo
      No terminal, esteja na pasta onde está o ordena1.c e também o arquivo a ser copiado
      comando: gcc -o ordena1 ordena1.c
      comando: ./ordena1 [arquivo]
      ex: ./ordena1 cep.dat

## Quicksort
Estrutura de dados básica do quicksort implementado em C

### Como os usuários podem utilizá-lo
      No terminal, esteja na pasta onde está o arquivo
      comando: gcc -o quicksort quicksort.c
      comando: ./quicksort 

## Concatenar

Este código vai concatenar dois arquivos e gerar um terceiro concatenado

### Como os usuários podem utilizá-lo
      No terminal, esteja na pasta onde está o concatenar.c e também os arquivos a serem concatenados. De preferência, faça dois arquivos texto (de final .txt).
      comando: gcc -o concatenar concatenar.c
      comando: ./concatenar
      
      
## HashMap

HashMap é uma estrutura de dados que armazena e recupera elementos por meio de chaves. O acesso aos elementos é feito por meio de uma função hash, que mapeia a chave a um valor correspondente. Isso permite a busca rápida de elementos sem percorrer toda a estrutura de dados. O HashMap é amplamente utilizado em linguagens de programação para implementar dicionários, tabelas de símbolos e outras estruturas de dados que requerem acesso rápido aos elementos por meio de chaves.


### Como os usuários podem utilizá-lo
      No terminal, esteja na pasta onde está o concatenar.c e também os arquivos a serem concatenados. Você precisará [baixar](https://www.dropbox.com/sh/8i46wy3q0rmasu7/AAAr9PoWwJvRbsfpiafDurr1a/hash/data?dl=0&subfolder_nav_tracking=1)  o cep.dat e cep-hash.dat
      comando: gcc -o CriaIndice CriaIndice.c
      comando: ./CriaIndice


