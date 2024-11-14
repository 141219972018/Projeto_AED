
#include "EADFilaAB.h"
void ListarPorNiveis (PNodoAB T){
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
  printf("Nivel %2d: %4d\n", k, T->Elemento.NIF);
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
        printf("%4d [%4d] ## ", P->Esquerda->Elemento.NIF, P->Elemento.NIF);  // [pai]
      else
        printf("     [%4d] ## ", P->Elemento.NIF);
      if (P->Direita != NULL)
        printf("%4d [%4d] ## ", P->Direita->Elemento.NIF, P->Elemento.NIF);
      else
        printf("     [%4d] ## ", P->Elemento.NIF);
      if (P->Esquerda != NULL)
        Fila = Juntar(P->Esquerda, Fila);
      if (P->Direita != NULL)
        Fila = Juntar(P->Direita, Fila);
    }
  }

}

