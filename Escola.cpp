#include <iostream>
#include <list>

using namespace std;

struct Aluno {
   string nome;
   int CPF;
   int idade;
   int matricula;
   string disciplina;
  
   void imprimir() {
        cout << "Fixa do aluno: " << endl; 
		cout << "Nome: " << nome << endl;
        cout << "CPF: " << CPF << endl;
		cout << "Idade: " << idade << endl;
        cout << "Matricula: " << matricula << endl;
        }

};

struct Disciplina {
   string nomeDisc;
   int qntdDeMateria;
   string conteudo;
   
   void imprimir() {
        cout << "Disciplinas cursadas: " << endl;
		cout << "Nome Disciplina: " << nomeDisc << endl;
        cout << "Materias: " << qntdDeMateria << endl;
		cout << "Conteudos: " << conteudo << endl;
        }
   
};
struct Fila {
   Aluno aluno;
   Disciplina disciplina;
   Fila *proximo;
};

void enqueue (Fila *&inicio, Fila *&fim, string nome, int CPF, int idade, int matricula, string nomeDisc, int qntdDeMateria, string conteudo){

    Fila *elemento = new Fila;
    elemento -> aluno.nome = nome;
    elemento -> aluno.CPF = CPF;
    elemento -> aluno.idade = idade;
    elemento -> aluno.matricula = matricula;
    elemento -> disciplina.nomeDisc = nomeDisc;
    elemento -> disciplina.qntdDeMateria = qntdDeMateria;
    elemento -> disciplina.conteudo = conteudo;
   
    elemento -> proximo = NULL;

    if(inicio == NULL){
        inicio = elemento;
        fim = elemento;
    }else {
        fim ->proximo = elemento;
        fim = elemento;
    }
    fim -> aluno.imprimir();
    fim -> disciplina.imprimir();
}

/*void dequeue(Fila *&inicio, Fila *&fim, string nome, int CPF, int idade, int matricula, string nomeDisc, int qntdDeMateria){
    if(inicio == NULL){
        cout << "Erro fatal";
        exit(1);
    }else if(inicio == fim){
        Fila *aux =inicio;

        inicio = NULL;
        fim = NULL;

        int alunoDeletado = aux -> aluno.nome = nome;

        delete aux;
        cout << alunoDeletado << endl;
    }else {
        Fila *&aux = inicio;
        inicio = inicio -> proximo;

        int alunoDeletado = aux -> aluno;
        delete aux;

        cout << alunoDeletado << endl;
        }
}
NÃO CONSEGUI FAZER PEGAR :(*/
bool isEmpty(Fila *&inicio, Fila *&fim) {
    if((inicio == NULL) && (fim == NULL)){
        cout << true << endl;
    }else {
        cout << false << endl;
    }
   
}
int front(Fila *&inicio){
    if(inicio == NULL){
        cout << "Não tem nada!" << endl;
        exit(1);
    }   
    inicio -> aluno.imprimir();

}


int size(Fila *&inicio, Fila *&fim){
    int total = 0;
    Fila *aux = new Fila;
    aux = inicio;

    if((inicio == NULL)&& (fim == NULL)){
        return 0;
    }
    while(aux != NULL){
        aux = aux -> proximo;
        total++;
    }
    cout << total << endl;
}


/*void listarDisciplinas(Fila *&inicio, Fila *&fim){
    inicio -> disciplina.imprimir();
    fim -> disciplina.imprimir();
}

void listarConteudos(Fila *&inicio, Fila *&fim){
    inicio -> disciplina.imprimir();
    fim -> disciplina.imprimir();
}*/
int main(){

    Fila *inicio = NULL;
    Fila *fim = NULL;

    isEmpty(inicio, fim);
    enqueue(inicio, fim, "oieee", 392929, 3232, 3232, "matematica, etica, religiao", 32, "Matematica aplicada");
    enqueue(inicio, fim, "oiee", 392929, 3232, 3232, "matematica", 32, "calculo");
    enqueue(inicio, fim, "oie", 392929, 3232, 3232, "m", 32, "algebra linear");
    isEmpty(inicio, fim);
    size(inicio, fim);
    front(inicio);
    //listarDisciplinas(inicio, fim);
    //listarConteudos(inicio, fim);
    

    return 0;
    
}