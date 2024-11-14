#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

//------------------------------------------------ NODE + STRUCT ----------------------------------------------------------------------
//struct that defines the Client
typedef struct{
    int NIF; //-> Forma de identificar o cliente
    char nome[40];
    char morada[40];
    int contacto;
}CLIENTE;

//define the nodes client
struct Nodo{
	CLIENTE c;
	struct Nodo *Prox;
	struct Nodo *Ant;
};
typedef struct Nodo *PNodo;
//define Head and Tail from list
PNodo Head, Tail;

//--------------------------------------AUXILIAR FUNCTIONS NODO-----------------------------------------

//criar um nodo
    /*
           +---+   
      Head | x-|->  NULL
           +---+           +---+
                    NULL <-|-x |
                           +---+
    */

void *Make(PNodo *Head, PNodo *Tail){
	Head = NULL;
    //aloca espaço 
    Head = (PNodo*)malloc(sizeof(PNodo));
	Tail = NULL;
    //aloca espaço
    Tail = (PNodo*)malloc(sizeof(PNodo));
}

int Empty(PNodo Head){
	if(Head == NULL){
		return 1;
	}
    return 0;
}

//make a isolated node
PNodo MakeNode(PNodo *Head, PNodo *Tail, CLIENTE *new){

    //make a single node that Head and Tail point to
    PNodo P;
    P = (PNodo)malloc(sizeof(struct Nodo)); 

    //if P equals to NULL return NULL
    //if not alocated space to P -> return NULL

    if(P == NULL){ //tenho duvidas acerca disto
        return NULL;
    }

    //P INFO is going to be equal to the new client formed
    /*
        +---+   +---------+
      P | x-|-> |  | X |x | -> NULL
        +---+   | x|   |  |
        NULL <- +---------+

    Head = P;
    Tail = P;

    */

    P->c = *new;

    //That node points PROX to NULL
    P->Prox = NULL;

    //And points ANT to NULL as well
    P->Ant = NULL;
    return P;
}

//find the previews 
PNodo find_big(PNodo Head, CLIENTE *new){
    PNodo P = Head;
    //if P is empty return NULL
    if(Empty(P) == 1){ 
        return Head;
    }else if(P->Prox == NULL){
        if(P->c.NIF >= (*new).NIF){
            return Head;
        }
    }
    while(P->Prox != NULL){
        if(P->c.NIF >= (*new).NIF){
            return P->Ant;
        }
        P = P->Prox;
    }
    return P;
    //se for maior que todos os anteriores devolve o atual e por isso é necessário comparar/verificar se o seu seguinte é NULL
}

//find client for change and remove certain cliente
PNodo find_Client(int aux){
    PNodo P = Head;
    //if P is NULL -> return false
    if(P == NULL){
        return NULL;
    }
    //if P is not NULL -> search
    while(P->Prox != NULL){
        //if NIF P equals aux -> return P
        if(P->c.NIF == aux){
            return P;
            free(P);
        }
        P = P->Prox;
    }
    //NIF P does not equal aux -> NULL
    return NULL;
    free(P);
}

//search if client exists
bool search_Client(PNodo Head, CLIENTE *aux){
	PNodo P = Head;
    //if P is NULL -> return false
    if(Empty(Head) == 1){
        free(P);
        return false; 
    }
    //if P is not NULL -> search
    while(P != NULL){
        //if P equals a client -> return true
        if(strcmp(P->c.nome,(*aux).nome) == 0 && strcmp(P->c.morada,(*aux).morada) == 0 && P->c.NIF == (*aux).NIF && P->c.contacto == (*aux).contacto){
            free(P);
            return true;
        }
        P = P->Prox;
    }
    //P does not equal a client -> false
    free(P);
    return false; 
}

//insert new client/Node to List
PNodo Add_Client(PNodo *Head, PNodo *Tail, CLIENTE *new){
    //find
    PNodo P = find_big(Head, new);
    //make node
    PNodo Q = MakeNode(Head, Tail, new);
    
    //if empty
    if(Empty(Head) == 1){
        printf("Vazia\n");
        Head = Q;
        Tail = Q;
        
        free(Q);
        return Head;
        
    //if last and only one
    }else if(P->Prox == NULL && Empty(P) == 0){

        printf("Last\n");
        (*Tail)->Prox = Q; 
	    Q->Ant = (*Tail);  
	    (*Tail) = Q;
        free(Q);
        free(P); 
        return Tail;  
    }
    printf("Geral\n");
    //general case
    Q->Prox = P->Prox; 
    Q->Ant = P;        
    P->Prox->Ant = Q;  
    P->Prox = Q; 
    free(Q);
    free(P);       
    return Head;   
}

//Remove Client
PNodo Remove(PNodo *Head, PNodo *Tail, PNodo *aux){
    PNodo P = Head;
    //if empty
    if(Empty(P) == 1){
        return NULL;
    //if 1st
    }else if((*aux)->Ant == NULL && Empty(P) == 0){
        (*Head)->Prox->Ant = NULL; 
	    (*Head) = (*aux)->Prox; 
        free(aux);
        return Head;        
    //if last 
    }else if((*aux)->Prox == NULL && Empty(P) == 0){
        (*Tail)->Ant->Prox = NULL;
        (*Tail) = (*aux)->Ant;
        free(*aux);
        return Tail;
    }
    //general case
    (*aux)->Ant->Prox = (*aux)->Prox;
    (*aux)->Prox->Ant = (*aux)->Ant;
    free(*aux);
    return Head;
}

//change client info
PNodo change_client(PNodo Head, PNodo Tail, PNodo *aux){
    //1 - retrieve client Info
    CLIENTE c = (*aux)->c;
    //2 - remove the node that previous contained aux
    PNodo P = Remove(Head, Tail, aux);
    //insert in the new position if changed the NIF
    P = Add_Client(Head, Tail, &c);
    free(P);
    return Head;
    
}

//------------------------------------------------ AUXILIAR FUNCTIONS --------------------------------------------------------
/*
//abrir os dados dos ficheiros para a estrutura de dados
void open_files_tostruct(CLIENTE *C){
    
    FILE *file_Client = fopen("clients.txt","r");
    int size = 0;
    if(file_Client == NULL){
        printf("Erro na abertura do ficheiro\n");
    }else{
        C = (PNodo)malloc(sizeof(PNodo)); 
        while(fscanf(file_Client,"%d %s %s %d", C->NIF, C->nome, C->morada, C->contacto) == 1) { 
            size = size + 1;
            fscanf(file_Client,"%d %s %s %d", C->NIF, C->nome, C->morada, C->contacto);
            C = (CLIENTE*)realloc(C, size * sizeof(CLIENTE)); 
        }
    }
    fclose(file_Client);
}

*/
void Menu_change(){
    int escolha = -1;
    int number;
    char letters[40];
    do{
        printf("\n - ALTERAR CLIENTES -\n\n");
        printf("1 - Alterar NIF\n");
        printf("2 - Alterar nome\n");
        printf("3 - Alterar morada\n");
        printf("4 - Alterar contacto\n");
        printf("0 - Sair\n-> ");
        switch (escolha){
        case 1: //NIF
            printf("Introduza o novo NIF:\n");
            scanf("%d",&number);
            break;
        case 2: //nome
            printf("Introduza o novo nome:\n");
            scanf("%s",letters);
            break;
        case 3: //morada
            printf("Introduza a nova morada:\n");
            scanf("%s",letters);
            break;
        case 4: //contacto
            printf("Introduza o novo contacto:\n");
            scanf("%d",&number);
            break;
        case 0:
            break;
        default:
            break;
        }
    }while(escolha != 0);
}

PNodo Insert(PNodo Head, PNodo Tail){
    bool point = true; 
    CLIENTE aux;
    do{
        printf("\n - INSERIR CLIENTE -\n\n");
        printf("Inserir NIF\n");
        scanf("%d",&aux.NIF);
        printf("Inserir nome\n");
        scanf("%s",aux.nome);
        printf("Inserir morada\n");
        scanf("%s",aux.morada);
        printf("Inserir contacto\n");
        scanf("%d",&aux.contacto);

        if(search_Client(Head, &aux) == true){
            pritnf("Já existe\n");
            point = true;
        }else{
            printf("Encontrado\n");
            point = false;
            Head = Add_Client(Head, Tail, &aux);
            return Head;
        }
    }while(point == true);
    return NULL;
}

void show_Clients(PNodo *Head){
    PNodo P = Head;
    printf("\n - CLIENTES - \n\n");
    printf("|  Nome        |  NIF        |  Morada          |  Contacto      |\n");
    if(Empty(P) == 1){
        printf("\nNÃO EXISTE NENHUM CLIENTE!\n");
        free(P);
    }else{
        while(P->Prox != NULL){
            printf("%s  | %d  |  %s  |  %d   |\n",P->c.nome, P->c.NIF, P->c.morada, P->c.contacto);
        }
    }
}

void int_Clients_by(int aux_int, int type){
    PNodo P = Head;
    //if P is NULL -> return false
    if(Empty(P) == 1){
        printf("Lista Vazia\n");
    }
    //NIF
    if(type == 1){
        //if P is not NULL -> search
        while(P->Prox != NULL){
            //if NIF P equals aux -> return true
            if(P->c.NIF == aux_int){
                printf("%s  | %d  |  %s  |  %d   |\n",P->c.nome, P->c.NIF, P->c.morada, P->c.contacto);
            }
            P = P->Prox;
        }
        free(P);

    //Contacto
    }else if(type == 4){
        //if P is not NULL -> search
        while(P->Prox != NULL){
            //if contacto P equals aux -> return true
            if(P->c.contacto == aux_int){
                printf("%s  | %d  |  %s  |  %d   |\n",P->c.nome, P->c.NIF, P->c.morada, P->c.contacto);
            }
            P = P->Prox;
        }
        free(P);
    }
    free(P);
}

void string_Clients_by(char aux_char[40], int type){
    PNodo P = Head;
    //if P is NULL -> return false
    if(Empty(Head) == 1){
        printf("Lista Vazia\n");
    }
    //nome
    if(type == 2){
        //if P is not NULL -> search
        while(P->Prox != NULL){
            //if nome P equals aux -> return true
            if(strstr(P->c.nome,aux_char) != NULL){
                printf("%s  | %d  |  %s  |  %d   |\n",P->c.nome, P->c.NIF, P->c.morada, P->c.contacto);
            }
            P = P->Prox;
        }
        free(P);
    //morada
    }else if(type == 3){
        //if P is not NULL -> search
        while(P->Prox != NULL){
            //if morada P equals aux -> return true
            if(strstr(P->c.morada,aux_char) != NULL){
                printf("%s  | %d  |  %s  |  %d   |\n",P->c.nome, P->c.NIF, P->c.morada, P->c.contacto);
            }
            P = P->Prox;
        }
        free(P);
    }else{
        printf("Not found\n");
    }
    free(P);
}

//----------------------------------------- MAIN MENU ------------------------------------------------------

void Menu_Cliente(){
    (Head) = NULL, (Tail) = NULL;
    //*Make(Head,Tail);

    int escolha = -1;
    int NIF = -1;  
    int search_by = -1;

    PNodo find;

    int inteiro;
    char carater[40];
    do{

        printf("\n - MENU CLIENTES -\n\n");
        printf("1 - Inserir Cliente\n");
        printf("2 - Remover Cliente - dado NIF\n");
        printf("3 - Alterar Cliente - dado NIF\n");
        printf("4 - Consultar Cliente\n");
        printf("5 - Mostrar todos os Clientes\n");
        printf("0 - Sair\n-> ");
        scanf("%d",&escolha);
        switch (escolha){
        case 1: //inserir
            Head = Insert(Head, Tail);   
            break;
        case 2: //remover
            printf("Introduza NIF do Cliente que pretende remover\n");
            scanf("%d",&NIF);

            find = find_Client(NIF);
            if(find != NULL){
                printf("Found\n");
                Remove(Head, Tail, &find);
            }
            break;
        case 3: //alterar  
            printf("Introduza NIF do Cliente que pretende alterar\n");
            scanf("%d",&NIF);
            find = find_Client(NIF);

            if(find != NULL){
                printf("Found\n");
                change_client(Head,Tail,&find);
            }
            break;
        case 4: //consultar
            do{
                printf("\n - Consultar Cliente por: - \n\n");
                printf("1 - NIF\n");
                printf("2 - Nome\n");
                printf("3 - Morada\n");
                printf("4 - Contacto\n");
                printf("0 - Sair\n-> ");
                scanf("%d",&search_by);
                switch(search_by){
                    case 1:
                        printf("Introduza o NIF do Cliente a consultar:\n");
                        scanf("%d",&inteiro);
                        int_Clients_by(inteiro,1);
                        break;
                    case 2:
                        printf("Introduza o nome do Cliente a consultar:\n");
                        scanf("%s",carater);
                        string_Clients_by(carater,2);
                        break;
                    case 3:
                        printf("Introduza a morada do Cliente a consultar:\n");
                        scanf("%s",carater);
                        string_Clients_by(carater,3);
                        break;
                    case 4:
                        printf("Introduza o contacto do Cliente a consultar:\n");
                        scanf("%d",&inteiro);
                        int_Clients_by(inteiro,4);
                        break;
                    case 0: 
                        break;
                }
            }while(search_by != 0);
            break;
        case 5:
            show_Clients(Head);
            break;
        case 0:
            break;
        default:
            break;
        }
    }while(escolha != 0);
}
