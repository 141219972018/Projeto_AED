struct NodoAB {
	
	LIVRO  Elemento;
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

int ABVazia(PNodoAB T){
	if (T == NULL)
		return 1;
	return 0;
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

PNodoAB LibertarNodoAB(PNodoAB P){
	P->Esquerda = NULL;
	P->Direita = NULL;
	free(P);
	P = NULL;
	return P;
}

PNodoAB DestruirAB(PNodoAB T){
	if (T == NULL) 
		return NULL;
	T->Esquerda = DestruirAB(T->Esquerda);
	T->Direita = DestruirAB(T->Direita);
	return LibertarNodoAB(T);
}

PNodoAB CopiarAB (PNodoAB T) {
	PNodoAB E, D, R;		// R é a nova árvore, que é uma cópia de T
	R = CriarAB();
	if (T == NULL)
		return R;
	E = CopiarAB(T->Esquerda);
	D = CopiarAB(T->Direita);
	R = CriarNodoAB(T->Elemento);
	R->Esquerda = E;
	R->Direita = D;
	return R;
}

int ABIguais (PNodoAB T, PNodoAB R) {
	int  ig;
	if (T == NULL && R == NULL)	// se são ambas nulas, então são iguais
		return 1;
	if (T == NULL || R == NULL)	// se uma delas é nula, então são diferentes
		return 0;
	if (CompararElementos(T->Elemento, R->Elemento) != 0)  // raízes diferentes, árvores diferentes
		return 0;
	if (ABIguais(T->Esquerda, R->Esquerda) == 0) // subárvores esq. diferentes
		return 0;
	if (ABIguais(T->Direita, R->Direita) == 0)	// subárvores direitas diferentes
		return 0;
	return 1;		// caso contrário, são iguais
}

int NumeroNodosAB (PNodoAB T) {
	int  e, d;
	if (T == NULL)
		return 0;
	e = NumeroNodosAB(T->Esquerda);
	d = NumeroNodosAB(T->Direita);
	return (e + d + 1);
}

int AlturaAB (PNodoAB T) {
	int  e, d;
	if (T == NULL)
		return -1;
	e = AlturaAB(T->Esquerda);
	d = AlturaAB(T->Direita);
	if (e > d)
		return (e + 1);	// e (altura da esquerda), 1 a raiz
	else
		return (d + 1);	// d (altura da direita), 1 a raiz
}

void ListarPreOrdemAB (PNodoAB T) {
	if (T != NULL) {
		MostrarElemento(T->Elemento);
		ListarPreOrdemAB(T->Esquerda);
		ListarPreOrdemAB(T->Direita);
	}
}

void ListarEmOrdemAB (PNodoAB T) {
	if (T != NULL) {
		ListarEmOrdemAB(T->Esquerda);
		MostrarElemento(T->Elemento);
		ListarEmOrdemAB(T->Direita);
	}
}

void ListarPosOrdemAB (PNodoAB T) {
	if (T != NULL) {
		ListarPosOrdemAB(T->Esquerda);
		ListarPosOrdemAB(T->Direita);
		MostrarElemento(T->Elemento);
	}
}

PNodoAB PesquisarAB (LIVRO X, PNodoAB T) {
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

PNodoAB InserirPorAlturaAB (PNodoAB T, LIVRO X) {
	if (T == NULL) {
		T = CriarNodoAB(X);
		return T;
	}
	if (AlturaAB(T->Esquerda) > AlturaAB(T->Direita))
		T->Direita = InserirPorAlturaAB(T->Direita, X);
	else
		T->Esquerda = InserirPorAlturaAB(T->Esquerda, X);
	return T;
}
		
PNodoAB ProcurarFolhaAB (PNodoAB T, LIVRO *X) {
	PNodoAB P;
	if (T->Esquerda == NULL  &&  T->Direita == NULL) {
		*X = T->Elemento;
		return T;
	}
	if (AlturaAB(T->Esquerda) > AlturaAB(T->Direita))
		return ProcurarFolhaAB(T->Esquerda, X);
	else
		return ProcurarFolhaAB(T->Direita, X);
}

PNodoAB RemoverNodoAB (PNodoAB T) {
	PNodoAB P, R;
	INFO  X;
	if (T->Esquerda == NULL && T->Direita == NULL) { 	// T é uma folha
		T = LibertarNodoAB(T);
		return T;
	}
	if (T->Esquerda == NULL) { 	//  só um filho direito 
		R = T;
		T = T->Direita;
		R = LibertarNodoAB(R);
		return T;
	}
	if (T->Direita == NULL) { 		// só um filho esquerdo
		R = T;
		T = T->Esquerda;
		R = LibertarNodoAB(R);
		return T;
	}
	// 2 filhos: remover a folha escolhida e copiar a sua informação
	P = ProcurarFolhaAB(T, &X);
	P = LibertarNodoAB(P);
	T->Elemento = X;
	return T;
}


PNodoAB RemoverAB (PNodoAB T, LIVRO X) {
	PNodoAB P;
	if (T == NULL)
		return NULL;
	if (CompararElementos(T->Elemento, X) == 0) {
		T = RemoverNodoAB(T);
		return T;
	}
	P = PesquisarAB(X, T->Esquerda);
	if (P != NULL)
		T->Esquerda = RemoverAB(T->Esquerda, X);
	else
		T->Direita = RemoverAB(T->Direita, X);
	return T;
}