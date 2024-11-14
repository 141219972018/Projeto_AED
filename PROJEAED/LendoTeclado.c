#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "OperacoesPrimaria.h"

LIVRO CriarElemento (){
  LIVRO X;
  
        printf("Introduza O ISBN do Elemento a compra:\n");
        scanf("%d",&X.ISBN);

        printf("Introduza o Titulo:\n");
        scanf("%s",X.Titulo);
        
        printf("Introduza o Idioma:\n");
        scanf("%s",X.Idioma);

        printf("Introduza o Primeiro Autor:\n");
        scanf("%s",X.PAutor);
  
        printf("Introduza o Segundo Autor:\n");
        scanf("%s",X.SAutor);

        printf("Introduza O Ano do Lancamento:\n");
        scanf("%s",X.datahora);

        printf("Introduza Area cientifica:\n");
        scanf("%s",X.AreaCientifica);

        printf("Introduza o Preco:\n");
        scanf("%f",&X.Preco);
  
        printf("Introduza A Quantidade:\n");
        scanf("%d",&X.Quantidade);
         
      FILE *f2;
 
      f2 = fopen("tabela2.txt", "ab");

       if (f2 == NULL){
         printf("Nao foi possivel abrir arquivo:");
         getchar();
         exit(0);
    }
     fwrite(&X,sizeof(LIVRO),1,f2);
     //fclose(f2);

  return X;
  }
int main()

{
    FILE *f2;
    LIVRO Y;

    Y=CriarElemento();
 
    f2 = fopen("tabela2.txt", "ab");

    if (f2 == NULL){
         printf("Nao foi possivel abrir arquivo:");
         getchar();
         exit(0);
    }
/*
    f2 = fopen("tabela2.txt", "rb");

    if (f2 == NULL)
    {
         printf("Nao foi possivel ler ficheiro:");
         getchar();
         exit(1);
    }
    while (freed(&X,sizeof(LIVRO),1,f2))
    {
        printf("%d\n - ", X.ISBN);
        printf("%c\n - ", X.Titulo);
        printf("%c\n- ", X.Idioma);
        printf("%c\n",  X.PAutor);
        printf("%c\n",  X.SAutor);
        printf("%c\n",  X.datahora);
        printf("%c\n",  X.AreaCientifica);
        printf("%f\n",  X.Preco);
        printf("%d\n",  X.Quantidade);
    }
    fclose(f2);

//LIVRO CriarElemento(){
   //LIVRO X;

        //tem que escrever esses elementos dentro de um ficheiro
    
        printf("Introduza O ISBN do Elemento a compra:\n");
        scanf("%d",&X.ISBN);

        printf("Introduza o Titulo:\n");
        scanf("%s",X.Titulo);
      

        printf("Introduza o Idioma:\n");
        scanf("%s",X.Idioma);

        printf("Introduza o Primeiro Autor:\n");
        scanf("%s",X.PAutor);
  
        printf("Introduza o Segundo Autor:\n");
        scanf("%s",X.SAutor);

        printf("Introduza O Ano do Lancamento:\n");
        scanf("%s",X.datahora);

        printf("Introduza Area cientifica:\n");
        scanf("%s",X.AreaCientifica);

        printf("Introduza o Preco:\n");
        scanf("%f",&X.Preco);
  
        printf("Introduza A Quantidade:\n");
        scanf("%d",&X.Quantidade);*/

        fwrite(&X,sizeof(LIVRO),1,f2);
      
        
        
/* */

    fclose(f2);

    return 0;
}