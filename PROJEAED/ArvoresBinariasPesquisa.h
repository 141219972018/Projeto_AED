
// Operações sobre ABP cuja chave é o campo "NIF"

int PesquisarABP (PNodoAB T, INFO X){   // 0 = nao existe; 1 = existe
  PNodoAB P;
  if (T == NULL)
    return 0;
  if (CompararElementos(X, T->Elemento) == 0)
    return 1;
  if (CompararElementos(X, T->Elemento) == -1)   // X.NIF < (T->Elemento).NIF)
    return PesquisarABP(T->Esquerda, X);
  else
    return PesquisarABP(T->Direita, X);
}

PNodoAB NodoMaiorElementoABP (PNodoAB T){
  if (T == NULL)
    return NULL;
  if (T->Direita == NULL)
    return T;
  return NodoMaiorElementoABP(T->Direita);
}

PNodoAB NodoMenorElementoABP (PNodoAB T){
  if (T == NULL)
    return NULL;
  if (T->Esquerda == NULL)
    return T;
  return NodoMenorElementoABP(T->Esquerda);
}

PNodoAB InserirABP (PNodoAB T, INFO X){
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


PNodoAB SubstituirNodoDireita (PNodoAB T, INFO *X){
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

PNodoAB SubstituirNodoEsquerda (PNodoAB T, INFO *X){
  PNodoAB  PAux;
  if (T->Direita == NULL) {
    *X = T->Elemento;
    PAux = T;
    T = T->Esquerda;
    PAux = LibertarNodoAB(PAux);
    return  T;
  }
  T->Direita = SubstituirNodoEsquerda(T->Direita, X);
  return T;
}

PNodoAB RemoverNodoABP (PNodoAB T){
  PNodoAB  R;
  INFO  X;
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

PNodoAB RemoverABP (PNodoAB T, INFO X) {
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


