#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){
  int operador,consult;
 //bool b=true;

while (true)
{
  

  printf("ESCOLHA A OPCAO\n");
  printf("1.Inserir Elemento\n");
  printf("2.Remover Por ISBN\n");
  printf("3.Alterar Por ISBN\n"); 
  printf("4.Consultar\n");
  printf("5.Sair\n");

  scanf("%d", &operador);

  switch(operador){
      case 1:
           printf(" Inseri O Livro\n");
           break;
       case 2:
           printf(" Remove O Livro\n");
           break;
       case 3:
           printf(" Aterar O Livro\n");
           break;
       case 4:
           printf("CONSULTAR POR\n");
           printf("1.ISBN\n");
           printf("2.Titulo\n");
           printf("3.Autor\n");
           printf("4.Editor\n");

           scanf("%d\n", &consult);
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
        default:
             printf("Opcao Invalida\n");           
                        
  }}

}