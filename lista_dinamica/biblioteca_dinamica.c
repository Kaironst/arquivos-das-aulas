#include "biblioteca_dinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INICIAL 10

void inicializarBiblioteca(Biblioteca* b) {
b->livros = (Livro*) malloc(INICIAL * sizeof(Livro));
b->capacidade = INICIAL;
b->totalLivros = 0;
}

// Esta função realoca o vetor de livros com nova capacidade
void redimensionarBiblioteca(Biblioteca* b, int novaCapacidade) {
    b->livros=(Livro*)realloc(b->livros,novaCapacidade * sizeof(Livro));
    b->capacidade=novaCapacidade;
    // Completar: usar realloc para redimensionar e atualizar b->capacidade
}

// Cadastrar livro (com verificação de ISBN e redimensionamento automático)
int cadastrarLivro(Biblioteca* b, char* titulo, char* autor, int ano, char* isbn) {
    if (consultarLivroPorISBN(b,isbn)!=NULL) return 0;
    
    b->totalLivros++;
    if (b->capacidade<b->totalLivros) {b->livros=(Livro*)realloc(b->livros, 2*b->capacidade*(sizeof(Livro))); b->capacidade=b->capacidade*2;}
    
    Livro *aux = b->livros;
    aux = aux+b->totalLivros-1;
    strcpy(aux->titulo,titulo);
    strcpy(aux->autor,autor);
    aux->ano=ano;
    strcpy(aux->isbn,isbn);
    aux->status=DISPONIVEL;

    return 1;
    // Completar: verificar se já existe o ISBN
    // Se capacidade esgotada, dobrar o tamanho
    // Inserir novo livro no final
}

// Listar todos os livros
void listarTodosLivros(Biblioteca* b) {
    Livro *aux = b->livros;
    for (int i=0; i<b->totalLivros; i++) {
        aux = aux+i;
        printf("%s, %s, %d, %s, %d, %s, %s \n",aux->titulo, aux->autor, aux->ano, aux->isbn, aux->status, aux->usuario, aux->dataEmprestimo);
    }
    // Completar: percorrer de 0 até totalLivros e imprimir os dados
}

// Emprestar livro
int emprestarLivro(Biblioteca* b, char* isbn, char* usuario, char* data) {
    Livro *aux = consultarLivroPorISBN(b,isbn);
    if (aux==NULL) return 0;
    aux->status=EMPRESTADO;
    strcpy(aux->usuario, usuario);
    strcpy(aux->dataEmprestimo, data);
    return 1;
    // Completar: buscar pelo ISBN e alterar status
}

// Devolver livro
int devolverLivro(Biblioteca* b, char* isbn) {
    Livro *aux = consultarLivroPorISBN(b,isbn);
    if (aux==NULL) return 0;
    aux->status=DISPONIVEL;
    strcpy(aux->usuario, "\0");
    strcpy(aux->dataEmprestimo, "\0");
    return 1;
    // Completar: buscar pelo ISBN e alterar status
}

// Buscar livro pelo ISBN
Livro* consultarLivroPorISBN(Biblioteca* b, char* isbn) {
    Livro *aux=b->livros;
    for (int i=0; i<b->totalLivros; i++) {
        if (strcmp(aux->isbn, isbn) == 0) return aux;
        aux++;
    }
    return NULL;
    // Completar: percorrer o vetor e comparar com strcmp
}

// Liberar memória
void destruirBiblioteca(Biblioteca* b) {
free(b->livros);
b->livros = NULL;
b->capacidade = 0;
b->totalLivros = 0;
}