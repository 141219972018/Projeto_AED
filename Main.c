#include <stdio.h>
#include <stdlib.h>
#include "Clientes.c"
//#include "Livros.c"

/*
//--------------------------------------------LIVROS----------------------------------------
//estrutura que define os dados dos Livros
typedef struct{
  int  ISBN; //-> Forma de identificar o livro
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

//----------------------------------------------CLIENTES------------------------------------
//estrutura que define os dados do Cliente
typedef struct{
    int NIF; //-> Forma de identificar o cliente
    char nome[40];
    char morada[40];
    int contacto;
}CLIENTE;

struct Nodo{
	CLIENTE c;
	struct Nodo *Prox;
	struct Nodo *Ant;
};

typedef struct Nodo *PNodo;

//define Head and Tail from list
PNodo Head, Tail;
*/
//---------------------------------------------ENCOMENDA----------------------------------
//estrutura que define a data da encomenda
typedef struct{
    int dia;
    int mes;
    int ano;
}DATA;

//estrutura que define os dados dos precos -> irá ser usado na encomenda
typedef struct{
    double p_produto; //get preço do produto através do preco no struct livro
    double custo_transporte;
}PRECO;

//estrutura que define os dados das Encomendas
typedef struct{
    int id; //-> forma de identificar a encomenda
    DATA encomenda;
    PRECO preco;
    int NIF_cliente;
    int ISBN_livro; // adicionar livro e alterar a quantidade nas proproedades do livro
}ENCOMENDA;

typedef struct{
		ENCOMENDA e;
		struct Nodo *Prox;
}Nodo;

typedef struct Nodo *PNodoE;


//-------------------------------AUXILIAR FUNTIONS----------------------------------------

//criar novas estruturas de dados
PNodo make_new_struct(){
    //criar nova estrutura de dados cliente

    //criar nova estrutura de dados livro

    //criar nova estrutura dados encomenda
	PNodoE P;
	P = NULL;

}

/*
//abrir os dados dos ficheiros para a estrutura de dados
void open_files_to_struct(CLIENTE *C, ENCOMENDA *E){
    
    open_files_tostruct(C);

    FILE *file_Client = fopen("encomenda.txt","r");
    int size = 0;
    if(file_Client == NULL){
        printf("Erro na abertura do ficheiro\n");
    }else{
        E = (ENCOMENDA*)malloc(sizeof(ENCOMENDA)); 
        while(fscanf(file_Client,"%d %d %d %d %f %f %d %d", &E->id, &E->encomenda.dia, &E->encomenda.mes, &E->encomenda.ano, &E->preco.p_produto, &E->preco.custo_transporte, &E->NIF_cliente, &E->ISBN_livro) == 1) { 
            size = size + 1;
            fscanf(file_Client,"%d %d %d %d %f %f %d %d", &E->id, &E->encomenda.dia, &E->encomenda.mes, &E->encomenda.ano, &E->preco.p_produto, &E->preco.custo_transporte, &E->NIF_cliente, &E->ISBN_livro);
            E = (ENCOMENDA*)realloc(E, size * sizeof(ENCOMENDA)); 
            //fscanf(file_Client,"%d %s %s %d", C->NIF, &C[size-1]->nome, &C[size-1]->morada, &C[size-1]->contacto);
        }
    }
    fclose(file_Client);
}

*/

//atualizar os dados das estruturas de dados -> ficheiros
void update_files(ENCOMENDA *E){

    FILE *file_Client = fopen("encomenda.txt","w");
    int size = 0;
    if(file_Client == NULL){
        printf("Erro na abertura do ficheiro\n");
    }else{
        E = (ENCOMENDA*)malloc(sizeof(ENCOMENDA)); 
        while(fscanf(file_Client,"%d %d %d %d %f %f %d %d", &E->id, &E->encomenda.dia, &E->encomenda.mes, &E->encomenda.ano, &E->preco.p_produto, &E->preco.custo_transporte, &E->NIF_cliente, &E->ISBN_livro) == 1) { 
            size = size + 1;
            fprintf(file_Client,"%d %d %d %d %f %f %d %d", &E->id, &E->encomenda.dia, &E->encomenda.mes, &E->encomenda.ano, &E->preco.p_produto, &E->preco.custo_transporte, &E->NIF_cliente, &E->ISBN_livro);
            E = (ENCOMENDA*)realloc(E, size * sizeof(ENCOMENDA)); 
            //fscanf(file_Client,"%d %s %s %d", C->NIF, &C[size-1]->nome, &C[size-1]->morada, &C[size-1]->contacto);
        }
    }
    fclose(file_Client);
}

//registar encomenda
void register_encomenda(){
    //registar id!!! -> mostrar os dados existentes para ser feita a introdução correta

}

//mostrar todas as encomendas realizadas
void show_encomendas(){

}

//remover dade encomenda dado o id da mesma
void remove_encomenda(){

}


//-------------------------------MENU FICHEIROS--------------------------------------------
void Menu_Ficheiros(){
    int choise_files = -1;
    do{
        printf("\n - MENU - FICHEIRO - \n\n");
        printf("1 - Novo - Criar uma nova Estrutura de Dados -> vazia\n");
        printf("2 - Abrir - Passar os dados de um ficheiro para a Estrutura de Dados\n");
        printf("3 - Guardar - Passar da Estrutura de Dados para ficheiro corrente\n");
        printf("0 - Sair\n-> ");
        scanf("%d",&choise_files);
        switch(choise_files){
            case 1: //criar uma nova Estrutura de Dados
                break;
            case 2: //abrir um ficheiro e passar os dados para uma estrutura de dados
                break;
            case 3: //passar os dados de uma estrutura de dados para ficheiro
                break;
            case 0:
                break;
        }
    }while(choise_files != 0);
}

//--------------------------MENU ENCOMENDAS-----------------------------------------------
void Menu_Encomendas(){
    int choise_enc = -1;
    do{
        printf("\n - MENU ENCOMENDAS - \n\n");
        printf("1 - Inserir Encomenda\n");
        printf("2 - Remover Encomenda\n");
        printf("0 - Sair\n->");
        scanf("%d",&choise_enc);
        switch(choise_enc){
            case 1: //Inserir encomenda/realizar compra/venda
                break;
            case 2: //Remover encomenda/anular venda
                break;
            case 0:
                break;
        }
    }while(choise_enc != 0);
}

//---------------------------------MAIN MENU-------------------------------------------
void Main_Menu(int escolha){
    do{
        printf("\n|/|------------BEM VINDO A NOSSA LIVRARIA---------------|/|\n");
        printf("|/|------------------NUNO & JUNIOR----------------------|/|\n");
        printf("|/|----------UNIVERSIDADE DA BEIRA INTERIOR-------------|/|\n");
        printf("|/|_____________________________________________________|/|\n");
        printf("1 - Ficheiros\n");
        printf("2 - Livros\n");
        printf("3 - Clientes\n");
        printf("4 - Encomendas\n");
        printf("0 - Sair\n-> ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1: //ficheiro
                Menu_Ficheiros();
                //terminar
                break;
            case 2: //livros
                //Menu_Livros();
                break;
            case 3: //clientes
                Menu_Cliente();
                break;
            case 4: //encomendas
                //Menu_Encomendas();
                break;
            case 5:
                break;
            case 0: //break!!
                break;
        }
    }while(escolha != 0);
}

//BEGIN
int main(){
    int escolha = -1;
    Main_Menu(escolha);
}