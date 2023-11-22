#include <iostream>

using namespace std;


struct Aluno{
    string nome;
    string cpf;
    int idade;
};

struct NoArvore{
    Aluno aluno;
    int dados;
    NoArvore* esquerda;
    NoArvore* direita;
    int key;
};

NoArvore* buscaBST(NoArvore *&raiz,int key){
   

   if(raiz == NULL){
    
    NoArvore* novoNo = new NoArvore;
    novoNo->dados = key;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    raiz = novoNo;
    return novoNo;
}
    if(key > raiz -> dados){
        raiz -> direita = buscaBST(raiz -> direita, key);
    }

    if(key < raiz -> dados){
        raiz -> esquerda = buscaBST(raiz -> esquerda, key);
    }

    return raiz;
}

void listar(NoArvore* raiz){

    if(raiz != NULL){

        listar(raiz->esquerda);
        cout << raiz -> dados  << " ";
        listar(raiz->direita);
    }
}

int main(){
    
    NoArvore* raiz = NULL;
    
    raiz = buscaBST (raiz,7);
    buscaBST (raiz,4);
    buscaBST (raiz,2);
    listar(raiz);

    
    return 0;
}