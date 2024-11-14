#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Aleatorio.h"

typedef struct{
  int  ISBN;
  char Titulo[30];
  char Idioma[30];
  char PAutor[30];
  char SAutor[30];
  char datahora[100];
  char AreaCientifica[100];
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
//char c;
// X.Titulo[30];
   
        printf("Introduza O ISBN do Elemento a compra:\n");
        scanf("%d",&X.ISBN);

        printf("Introduza o Titulo:\n");      
         //gets(X.Titulo);
        // X.Titulo[] = getchar();
         //X.Titulo[30] = getchar ();
         //getc(&X.Titulo);
         //strcat 
          //puts(&X.ISBN);
           //putchar(X.Titulo);
		     scanf("%s",X.Titulo);
        
         //X.Titulo="ju";
       
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
return X;
}
/*
PNodoAB PesquisarAB ( LIVRO X,PNodoAB T) {
	PNodoAB P;
	if (T == NULL)
		return NULL;
	if (CompararElementos(X, T->Elemento) == 0)
		return T;
	P = PesquisarAB(X, T->Esquerda);
	if (P != NULL)
		return P;
	return PesquisarAB(X, T->Direita);
}
*/

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

 N=gerarNumeroInteiro(1,3);
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
 /*void ListarPorNiveis (PNodoAB T){
  PNodoFila Fila;
  PNodoAB  P;
  int niveis, numNodos, k = 0;
  
  niveis = AlturaAB(T) + 1;
  numNodos = NumeroNodosAB(T);
  
  if (ABVazia(T))
    return;
  Fila = CriarFila();
  Fila = Juntar(T, Fila);
  Fila = Juntar(NULL, Fila);
  printf("Mostrar uma ABP com %d nodos.\n", numNodos);
  printf("Mostrar os valores do campo NIF por niveis e da esquerda para a direita.\n");
  printf("Legenda: nodo [pai]\n");
  printf("Nivel %2d: %4d\n", k, T->Elemento.ISBN);
  k++;
  printf("Nivel %2d: ", k);
  while (!FilaVazia(Fila)){
    P = Frente(Fila);
    Fila = Remover(Fila);
    if (P == NULL){
      k++;
      if (k == niveis){
        printf("\n");
        return;
      }
      printf("\nNivel %2d: ", k);
      if (!FilaVazia(Fila))
        Fila = Juntar(NULL, Fila);
    }
    else{
      //MostrarElemento(P->Elemento);
      if (P->Esquerda != NULL)
        printf("%4d [%4d] ## ", P->Esquerda->Elemento.ISBN, P->Elemento.ISBN);  // [pai]
      else
        printf("     [%4d] ## ", P->Elemento.ISBN);
      if (P->Direita != NULL)
        printf("%4d [%4d] ## ", P->Direita->Elemento.ISBN, P->Elemento.ISBN);
      else
        printf("     [%4d] ## ", P->Elemento.ISBN);
      if (P->Esquerda != NULL)
        Fila = Juntar(P->Esquerda, Fila);
      if (P->Direita != NULL)
        Fila = Juntar(P->Direita, Fila);
    }
  }

}*/
void MostrarElemento (LIVRO X){
  printf("%d\n", X.ISBN);
  printf("%s\n", X.Titulo);
  printf("%s\n", X.Idioma);
  printf("%s\n", X.PAutor);
  printf("%s\n", X.SAutor);
  printf("%s\n", X.datahora);
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

int main(){
  PNodoAB T,P;
  LIVRO S;
   int Num,cont;
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
              scanf("%d",&S.ISBN);           
              Num=S.ISBN;
               T->Elemento.ISBN=Num;
              //printf("O numero de el. maiores quer: %d ",Num);
              P=RemoverABP (T,T->Elemento);
              ListarElementos(P);
           break;
       case 3:
           printf(" Aterar O Livro\n");
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
                 printf(" consultando por ISBN\n");
                 break;
                 case 2:
                 printf(" consultando por Titulo\n");
                 break;
                 case 3:
                 printf(" consultando por Autor\n");
                 break;
                 case 4:
                 printf(" consultando por Editor\n");
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
