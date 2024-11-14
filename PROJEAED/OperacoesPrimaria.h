
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
 /*
void MostrarElemento (LIVRO X){
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
 /*
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
     fclose(f2);

  return X;
}*/