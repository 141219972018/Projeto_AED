#include <stdio.h>
#include <stdlib.h>


typedef struct{
  int   ISBN;
  char Titulo[30];
  char Idioma[30];
  char PAutor[30];
  char SAutor[30];
  char datahora[100];
  char AreaCientifica[100];
  float Preco;
  int Quantidade;
}LIVRO;

int main(){
    LIVRO X;

     printf("Introduza O ISBN do Elemento a compra:\n");
     scanf("%d",&X.ISBN);

     printf("Introduza o Titulo:\n");
     //fscanf("%s",X.Titulo);
     //fgets(X.Titulo,30,stdin);
     
     fflush(stdin);
     gets(X.Titulo);

    printf("Introduza o Idioma:\n");
    scanf("%s",X.Idioma);

return 0;
}