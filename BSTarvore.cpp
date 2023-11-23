#include <iostream>

using namespace std;


struct Aluno{
    string nome;
    string cpf;
    int idade;
    
    
    void imprimir() {
		cout << "Nome: " << nome << endl;
        cout << "CPF: " << cpf << endl;
		cout << "Idade: " << idade << endl;
        
        }
};

struct NoArvore{
    Aluno aluno;
    NoArvore* esquerda;
    NoArvore* direita;
    int key;
};

NoArvore* insercaoBST(NoArvore *&raiz,int key,string nome,string cpf,int idade){
   

   if(raiz == NULL){
    
    NoArvore* novoNo = new NoArvore;
    novoNo->key = key;
    novoNo->aluno.nome = nome;
    novoNo->aluno.cpf = cpf;
    novoNo->aluno.idade = idade;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    raiz = novoNo;
    return novoNo;
}
    if(key > raiz -> key){
        raiz -> direita = insercaoBST(raiz -> direita, key, nome, cpf, idade);
    }

    if(key < raiz -> key){
        raiz -> esquerda = insercaoBST(raiz -> esquerda, key, nome, cpf, idade);
    }

    return raiz;
}

NoArvore* removerBST(NoArvore *&raiz,int key){
    if(raiz == NULL){
        return raiz;
    }
    if(raiz -> key > key){
        raiz->esquerda = removerBST(raiz->esquerda,key);
        return raiz;
    }
    else if(raiz -> key < key){
        raiz->direita = removerBST(raiz->direita,key);
        return raiz;
    }

    if(raiz -> esquerda == NULL && raiz -> direita == NULL){
        delete raiz;
        raiz = NULL;
        return raiz;
    }
    
    else if(raiz -> esquerda == NULL){
        NoArvore* aux = raiz;
        raiz  = raiz -> direita;

        delete aux;

        return raiz;
    }
    else if(raiz -> direita == NULL){
        NoArvore* aux = raiz;
        raiz  = raiz -> esquerda;

        delete aux;

        return raiz;
    }
    else{
        NoArvore* aux = raiz -> esquerda;
        
        while(aux -> direita != NULL){
            aux = aux->direita;
        }
    
    raiz -> key = aux -> key;
    raiz -> esquerda = removerBST(raiz -> esquerda, raiz -> key);
        
        }
    }

NoArvore* buscaBST(NoArvore *&raiz, int key) {
	if( raiz == NULL || raiz -> key == key) {
		return raiz;
	}
	
	if(key < raiz -> key) {
		return buscaBST(raiz -> esquerda, key);
	} else {
		return buscaBST(raiz -> direita, key);
	}
	
}

void listar(NoArvore* raiz){

    if(raiz != NULL){

        listar(raiz->esquerda);
        cout <<"Numero da chave: "<< raiz -> key  << " \n";
        raiz -> aluno.imprimir();
        listar(raiz->direita);
    }
}
void listarN(NoArvore *raiz){

    if(raiz != NULL){
        cout << "Arvore nao ordenada: ";
        cout << raiz->key << " " ;
        listarN(raiz->esquerda);
        listarN(raiz->direita);
        }
}
int main(){
    
    NoArvore* raiz = NULL;
    
    insercaoBST (raiz,20,"Rivanildo","3232",120);
    insercaoBST (raiz,10,"Saemy","323322",121);
    insercaoBST (raiz,23,"Riane","3232",124);
    insercaoBST (raiz,18,"Claudia","3232",122);
    insercaoBST(raiz,22,"Rivinha","323244141",14422);
    //buscaBST (raiz,21);
    //listarN(raiz);
    //cout << "\nArvore ordenada: ";
    listar(raiz);
    raiz = removerBST(raiz,23);
    listar(raiz);
    
   
    if(buscaBST(raiz, 10)==NULL){
        cout << "Chave nao encontrada" << endl;
    }else{
        cout << "Chave encontrada" << endl;
    }

    return 0;
}