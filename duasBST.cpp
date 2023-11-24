#include <iostream>

using namespace std;

struct NoArvore{
    int key;
    NoArvore* esquerda;
    NoArvore* direita;
};

void listar(NoArvore* raiz){

    if(raiz != NULL){

        listar(raiz->esquerda);
        cout <<"Numero da chave: "<< raiz-> key  << " \n";
        listar(raiz->direita);
    }
}

NoArvore* insercaoBST(NoArvore *&raiz, int key){

    if(raiz == NULL){

        NoArvore* novoNo = new NoArvore;
        novoNo -> key = key;
        novoNo -> esquerda = NULL;
        novoNo -> direita = NULL;

        raiz = novoNo;
        return novoNo;
    }

        if(key > raiz -> key){
            raiz -> direita = insercaoBST(raiz->direita,key);
        }
        if(key < raiz -> key){
            raiz -> esquerda = insercaoBST(raiz->esquerda,key);
        }
        return raiz;
    }

int bstIdentica(NoArvore* raiz1, NoArvore* raiz2){
    if(raiz1 == NULL && raiz2 == NULL){
        return 1;
    }
    if(raiz1 == NULL || raiz2 == NULL){
        return 0;
    }
    else{
        if(raiz1 -> key == raiz2 -> key && bstIdentica(raiz1 -> esquerda, raiz2 -> esquerda) && bstIdentica(raiz1 -> direita, raiz2 -> direita)){
            return 1;
        }
    }
}

int main(){
    
    NoArvore* raiz1 = NULL;
    NoArvore* raiz2 = NULL;
    
    insercaoBST (raiz1,20);
    insercaoBST (raiz1,10);
    insercaoBST (raiz1,30);
    insercaoBST (raiz2,20);
    insercaoBST (raiz2,10);
    insercaoBST (raiz2,30);
    //insercaoBST (raiz2,45);

   listar(raiz1);
   listar(raiz2);

   if(bstIdentica(raiz1,raiz2)){
    cout << "E identico";
   }
   else{
    cout << "Nao e identica";
   }

   return 0;
}
