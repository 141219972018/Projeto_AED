#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Aleatorio.h"

typedef struct{
  int  ISBN;
  char Titulo[30];
  char Idioma[30];
  char PAutor[30];
  char SAutor[30];
  char Editora[30];
  int  AnoPubl; 
  char AreaCientifica[30]; 
  float Preco;
  int Quantidade;
}LIVRO;

struct NodoAB {	
	LIVRO Elemento ;
	struct NodoAB *Esquerda;
	struct NodoAB *Direita;
};
typedef struct NodoAB *PNodoAB;

// Operações sobre o Nodo
PNodoAB CriarAB(){ 
	PNodoAB T;
	T = NULL;
	return T;
}
PNodoAB CriarNodoAB(LIVRO X){
	PNodoAB P = (PNodoAB) malloc(sizeof(struct NodoAB));
	if (P == NULL)
	   return  NULL;
	P->Elemento = X;
	P->Esquerda = NULL;
	P->Direita = NULL;
	return P;
}
LIVRO CriarElemento (){        
  LIVRO X;
   
        printf("Introduza O ISBN do Elemento do Livro:\n");
        scanf("%d",&X.ISBN);

        printf("Introduza o Titulo:\n");      
		    scanf("%s",X.Titulo);
       
        printf("Introduza o Idioma:\n");
        scanf("%s",X.Idioma);

        printf("Introduza o Primeiro Autor:\n");
        scanf("%s",X.PAutor);
  
        printf("Introduza o Segundo Autor:\n");
        scanf("%s",X.SAutor);
        
        printf("Introduza o Editor:\n");
        scanf("%s",X.Editora);

        printf("Introduza O Ano do Lancamento:\n");
        scanf("%d",&X.AnoPubl); 

        printf("Introduza Area cientifica:\n");
        scanf("%s",X.AreaCientifica);

        printf("Introduza o Preco:\n");
        scanf("%f",&X.Preco);
  
        printf("Introduza A Quantidade:\n");
        scanf("%d",&X.Quantidade);
return X;

}

int CompararElementos (LIVRO X,LIVRO Y){
  if (X.ISBN > Y.ISBN)
    return 1;
  if (X.ISBN < Y.ISBN)
    return -1;
  return 0;
}

PNodoAB InserirABP (PNodoAB T, LIVRO X){
  if (T == NULL) {
    T = CriarNodoAB(X);
    return T;
  }
  if (CompararElementos(X, T->Elemento) == -1)   // X.NIF < (T->Elemento).NIF)
    T->Esquerda = InserirABP(T->Esquerda, X);
  else
    T->Direita = InserirABP(T->Direita, X);
  return T;
}
PNodoAB construiABPAleatorio(){
 int N,k=1;
 PNodoAB T;
 LIVRO X; 

 N=3;
 //gerarNumeroInteiro(1,3);

 T=CriarAB();
 while(k<=N){
     X=CriarElemento();
     //if(PesquisarAB(T,X)==0){
         T=InserirABP(T,X);
         k++;
     //}
 }
 return T;
 }

void MostrarElemento (LIVRO X){
  printf("enTREI Mostrando\n");
  printf("%d\n", X.ISBN);
  printf("%s\n", X.Titulo);
  printf("%s\n", X.Idioma);
  printf("%s\n", X.PAutor);
  printf("%s\n", X.SAutor);
  printf("%s\n", X.Editora);
  printf("%d\n", X.AnoPubl);
  printf("%s\n", X.AreaCientifica);
  printf("%f\n", X.Preco);
  printf("%d\n", X.Quantidade);
 
}
void ListarElementos(PNodoAB T ){
    if(T!=NULL){
        MostrarElemento(T->Elemento);
        ListarElementos(T->Esquerda);
        ListarElementos(T->Direita);
    }
}
///////////////////////////////////////FUNCOES DE REMOCAO//////////

PNodoAB LibertarNodoAB(PNodoAB P){
	P->Esquerda = NULL;
	P->Direita = NULL;
	free(P);
	P = NULL;
	return P;
}
PNodoAB SubstituirNodoDireita (PNodoAB T, LIVRO *X){
  PNodoAB  PAux;
  if (T->Esquerda == NULL) {
    *X = T->Elemento;
    PAux = T;
    T = T->Direita;
    PAux = LibertarNodoAB(PAux);
    return T;
  }
  T->Esquerda = SubstituirNodoDireita(T->Esquerda, X);
  return T;
}
int ABVazia(PNodoAB T){
	if (T == NULL)
		return 1;
	return 0;
}
//versao interativa
//encotrar o elemento correspondente ao ISBN dado
LIVRO ElementoIgual(int k,PNodoAB T){
 PNodoAB P=T;
  LIVRO X;

while (P!=NULL){
    if(P->Elemento.ISBN==k)
    return P->Elemento;
    if(P->Elemento.ISBN > k)
    P=P->Esquerda;
    else
    P=P->Direita;
}
X.ISBN=-1;
return X;
}
//funcao que faz a pesquisa do titulo
LIVRO ElementoIgualTitulo(char s[30],PNodoAB T){
 PNodoAB PA=T;
 LIVRO X;

 if(ABVazia(T)){
      return X;
    }
 
   if(strcmp(s,PA->Elemento.Titulo)==0){//Faz a comparação de strings
     printf("Livro encotrado\n");
     return PA->Elemento;//retorna ponteiro se encotrar
}
else{
  if(strcmp(s,PA->Elemento.Titulo)>0)
      return  ElementoIgualTitulo(s,PA->Direita);
    else
      return ElementoIgualTitulo(s,PA->Esquerda);
}}

LIVRO PesquisaAutor(char ss[30],int ano,PNodoAB T){
 PNodoAB PE=T;
 LIVRO X;
 
 if(ABVazia(T)){
      return X;
    }
 
   if(strcmp(ss,PE->Elemento.PAutor)==0 && (ano==PE->Elemento.AnoPubl)){//Faz a comparação de strings
     printf("Livro encotrado\n");
     return PE->Elemento;//retorna ponteiro se encotrar
}
else{
  if(strcmp(ss,PE->Elemento.Titulo)>0 && ano==PE->Elemento.AnoPubl)
      return  PesquisaAutor(ss,ano,PE->Direita);
    else
      return PesquisaAutor(ss,ano,PE->Esquerda);
}}

LIVRO PesquisaEDitor(char edit[30],char area[30],PNodoAB T){
 PNodoAB PA=T;
 LIVRO X;

  while(PA!=NULL){

if(strcmp(edit,PA->Elemento.Editora)==0 && strcmp(area,PA->Elemento.AreaCientifica)==0){
     printf("Livro encotrado\n");
     return PA->Elemento;
}
//else{
  if(strcmp(edit,PA->Elemento.Editora)<0 && strcmp(area,PA->Elemento.AreaCientifica)<0)
     //return PesquisaEDitor(edit,area,PA->Esquerda);
      PA= PA->Esquerda;
    else
      PA=PA->Direita;
      // return  PesquisaEDitor(edit,area,PA->Direita);
}
}

PNodoAB RemoverNodoABP (PNodoAB T){
  PNodoAB  R;
  LIVRO  X;
  if (T->Esquerda == NULL && T->Direita == NULL) {   // T é uma folha
    T = LibertarNodoAB(T);
    return T;
  }
  if (T->Esquerda == NULL) {   //  só um filho direito 
    R = T;
    T = T->Direita;
    R = LibertarNodoAB(R);
    return T;
  }
  if (T->Direita == NULL) {     // só um filho esquerdo
    R = T;
    T = T->Esquerda;
    R = LibertarNodoAB(R);
    return T;
  }
  // 2 filhos (1º caso): remover o nodo sucessor (nodo mais à esquerda da subárvore direita) e copiar a sua informação
  T->Direita = SubstituirNodoDireita(T->Direita, &X);
  // 2 filhos (2º caso): remover o nodo antecessor (nodo mais à direita da subárvore esquerda) e copiar a sua informação
  //  T->Esquerda = SubstituirNodoEsquerda(T->Esquerda, &X);  // 2º caso
  T->Elemento = X;
  return T;
}
PNodoAB RemoverABP (PNodoAB T, LIVRO X) {
  if (CompararElementos(X, T->Elemento) == 0) {
       T = RemoverNodoABP(T);
    return T;
  }    
  if (CompararElementos(X, T->Elemento) == -1)
    T->Esquerda = RemoverABP(T->Esquerda, X);
  else
    T->Direita = RemoverABP(T->Direita, X);
  return T;
}

/* Funcao que Altera informacoes do Nodo dada o valor do ISBN*/
void AlterarNodo(PNodoAB T,LIVRO cria,int k){
  PNodoAB A=T;
 
 while(A!=NULL){
    if(A->Elemento.ISBN==k)
    A->Elemento.ISBN=cria.ISBN;
    strcpy(A->Elemento.Titulo,cria.Titulo);
    strcpy(A->Elemento.Idioma,cria.Idioma); 
    strcpy(A->Elemento.PAutor,cria.PAutor);
    strcpy(A->Elemento.SAutor,cria.SAutor);
    strcpy(A->Elemento.Editora,cria.Editora);
    A->Elemento.AnoPubl=cria.AnoPubl;
    strcpy(A->Elemento.AreaCientifica,cria.AreaCientifica);
    A->Elemento.Preco=cria.Preco;
    A->Elemento.Quantidade=cria.Quantidade; 
    if(A->Elemento.ISBN > k)
    A=A->Esquerda;
    else
    A=A->Direita; 
  }
}
//Funcao main dos Livros 
int main(){
  PNodoAB T,P;
  LIVRO X,LI;
   int Num,cont,i;
   char stri[30];
   //A11 

   int operador,consult;
printf("|/|------------BEM VINDO A NOSSA LIVRARIA---------------|/|\n");
printf("|/|------------------NUNO & JUNIOR----------------------|/|\n");
printf("|/|----------UNIVERSIDADE DA BEIRA INTERIOR-------------|/|\n");
printf("|/|_____________________________________________________|/|\n");

while(true){
  printf("ESCOLHA A OPCAO\n");
  printf("1.Inserir Elemento\n");
  printf("2.Remover Por ISBN\n");
  printf("3.Alterar Por ISBN\n");
  printf("4.Consultar\n");
  printf("5.Sair\n");

  scanf("%d", &operador);

  switch(operador){
      case 1:
           printf(" ESCOLHESTE A OPCAO DE INSERIR\n");
           T=construiABPAleatorio(); 
           ListarElementos(T);
           break;
       case 2:
          printf(" ESCOLHESTE A OPCAO DE REMOVER\n");
          printf("Introduza O ISBN do Elemento\n");
              scanf("%d",&X.ISBN); 
                  Num=X.ISBN;
                      LI=ElementoIgual(Num,T);
              P=RemoverABP (T,LI);
              ListarElementos(P);
           break;
       case 3:
          printf(" ESCOLHESTE A OPCAO DE ALTERAR\n");
          printf("Introduza O ISBN do Livro A Alterar\n");
          scanf("%d",&X.ISBN);
          i=X.ISBN;
          printf("Pretende Alterar Para Quais Valores\n");
          LIVRO cria=CriarElemento();
          AlterarNodo(T,cria,i);
          //}

           break;
       case 4:
       while(true){
           printf("CONSULTAR POR\n");
           printf("1.ISBN\n");
           printf("2.Titulo\n");
           printf("3.Autor\n");
           printf("4.Editor\n");

           scanf("%d", &consult);
           
            switch(consult){
                case 1:
                
                 printf(" ESCOLHESTE A OPCAO DE CONSULTAR \n");
                 printf("INTRODUZ O ISBN\n");
                 scanf("%d",&X.ISBN); 
                  Num=X.ISBN;
                  LI=ElementoIgual(Num,T); //funcao que pesquisa por ISBN
                  //ListarElementos(P);
                  MostrarElemento(LI); //mostra o elemento que esta ser procurado
                 break;

                 case 2:
                
                 printf(" ESCOLHESTE A OPCAO DE CONSULTAR \n");
                 printf("INTRODUZ O TITULO\n");
                 scanf("%s",X.Titulo); 
                 //stri=X.Titulo;
                 LI=ElementoIgualTitulo(X.Titulo,T); //funcao que pesquisa por ISBN
                 //ListarElementos(LI);
                  MostrarElemento(LI); //mostra o elemento que esta ser procurado
                 break;

                 case 3:
                 
                 printf(" ESCOLHESTE A OPCAO DE CONSULTAR \n");
                 printf("INTRODUZ O NOME AUTOR \n");
                 scanf("%s",X.PAutor);
                 printf("INTRODUZ A DATA DO LANCAMENTO \n");
                 scanf("%d",&X.AnoPubl);

               //  LI=PesquisaAutor(X.PAutor,X.AnoPubl,T);

                 MostrarElemento(LI);
                 
                 break;
                 case 4:
                 
                 printf(" ESCOLHESTE A OPCAO DE CONSULTAR \n");
                 printf("INTRODUZ O EDITOR\n");
                 scanf("%s",X.Editora); 
                 printf("INTRODUZ O AREA CIENTIFICA\n");
                 scanf("%s",X.AreaCientifica); 
                 //stri=X.Titulo;
                 LI=  PesquisaEDitor(X.Editora,X.AreaCientifica,T); //funcao que pesquisa por ISBN
                 //ListarElementos(LI);
                 MostrarElemento(LI); //mostra o elemento que esta ser procurado
                
               
                 break;
                 default:
                 printf("Opcao Invalida\n"); 

            }
           break;
          }
        case 5:
              exit(0);
              break;
                  default:
                  printf("Opcao Invalida\n"); 
                     break;
                
                        
  }}
}
