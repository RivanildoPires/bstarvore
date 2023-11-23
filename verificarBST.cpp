#include <iostream>

using namespace std;

struct NoArvore{
    int key;
    NoArvore* esquerda;
    NoArvore* direita;
};
NoArvore* insercaoBST(NoArvore *&raiz,int key){
   

   if(raiz == NULL){
    
    NoArvore* novoNo = new NoArvore;
    novoNo->key = key;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    raiz = novoNo;
    return novoNo;
}
    if(key > raiz -> key){
        raiz -> direita = insercaoBST(raiz -> direita, key);
    }

    if(key < raiz -> key){
        raiz -> esquerda = insercaoBST(raiz -> esquerda, key);
    }

    return raiz;
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

        listar(raiz->esquerda);
        cout <<"Numero da chave: "<< raiz -> key  << " \n";
        listar(raiz->direita);
    }
}

int main(){
    
    NoArvore* raiz = NULL;
    
    insercaoBST(raiz,20);
    insercaoBST(raiz,10);
    insercaoBST(raiz,23);
    insercaoBST(raiz,18);
    insercaoBST(raiz,22);
    listar(raiz);

    if(verificarBST(raiz)){
        cout << "E BST";
    }else{
        cout << "Nao e";
    }

    return 0;
}