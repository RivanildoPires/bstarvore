#include <iostream>

using namespace std;

struct NoArvore{
    int key;
    NoArvore* esquerda;
    NoArvore* direita;
};

NoArvore* inserirNo(int value) {
    NoArvore* novoNo = new NoArvore;
    novoNo->key = value;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}
bool verificarBST(NoArvore *&raiz, NoArvore* minVal = NULL, NoArvore* maxVal = NULL){
    if(raiz == NULL){
        return true;
    }
    if ((minVal != NULL && raiz->key <= minVal->key) || (maxVal != NULL && raiz->key  >= maxVal->key )) {
        return false;
    }

    return verificarBST(raiz->esquerda, minVal, raiz) && verificarBST(raiz->direita, raiz, maxVal);
}

void listar(NoArvore* raiz){

    if(raiz != NULL){

        cout << raiz->key << " " ;
        listar(raiz->esquerda);
        listar(raiz->direita);
        
    }
}

int main(){
	
	NoArvore* raiz = inserirNo (1);
    raiz->esquerda = inserirNo(2);
    raiz->direita = inserirNo(4);
    raiz->esquerda->esquerda = inserirNo(6);
    //raiz->direita->direita = inserirNo(7);
    //raiz->esquerda->esquerda->esquerda = inserirNo(4);
    //raiz->direita->direita->direita = inserirNo(20);
    //raiz->esquerda->esquerda->esquerda->esquerda = inserirNo(9);
    //raiz->direita->direita->direita->direita = inserirNo(11);
    //raiz->esquerda->esquerda->esquerda->esquerda->esquerda = inserirNo(10);
    listar(raiz);

      if(verificarBST(raiz)){
        cout << "E BST";
    }else{
        cout << "Nao e";
    }
}