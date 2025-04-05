#include "biblioteca_encadeada.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void inicializarBiblioteca(Biblioteca* b) {
    b->primeiro = NULL;
    b->totalLivros = 0;
}

int cadastrarLivro(Biblioteca* b, char* titulo, char* autor, int ano, char* isbn) {
    if (consultarLivroPorISBN(b,isbn)!=NULL) return 0;

    NoLivro * novo=malloc(sizeof(NoLivro));
    Livro novolivro;

    strcpy(novolivro.titulo,titulo);
    strcpy(novolivro.autor,autor);
    novolivro.ano=ano;
    strcpy(novolivro.isbn,isbn);
    novolivro.status=DISPONIVEL;

    novo->livro=novolivro;
    novo->proximo=b->primeiro;
    b->primeiro=novo;

    b->totalLivros++;
    return 1;

    // Verificar se ISBN já existe
    // Criar novo nó e preencher dados
    // Inserir no início da lista
}

void listarTodosLivros(Biblioteca* b) {
    NoLivro *aux=b->primeiro;
    while (aux!=NULL) {
        printf("%s, %s, %d, %s, %d, %s, %s \n",aux->livro.titulo, aux->livro.autor, aux->livro.ano, aux->livro.isbn, aux->livro.status, aux->livro.usuario, aux->livro.dataEmprestimo);
        aux=aux->proximo;
    }
    // Percorrer a lista com um ponteiro e imprimir dados
}

int emprestarLivro(Biblioteca* b, char* isbn, char* usuario, char* data) {
    NoLivro *aux=consultarLivroPorISBN(b,isbn);
    if (aux==NULL) return 0;
    aux->livro.status=EMPRESTADO;
    strcpy(aux->livro.usuario, usuario);
    strcpy(aux->livro.dataEmprestimo, data);
    return 1;
    
    // Percorrer lista e alterar status se encontrar
}

int devolverLivro(Biblioteca* b, char* isbn) {
    NoLivro *aux=consultarLivroPorISBN(b,isbn);
    if (aux==NULL) return 0;
    aux->livro.status=DISPONIVEL;
    strcpy(aux->livro.usuario, "\0");
    return 1;

    // Percorrer lista e alterar status
}

NoLivro* consultarLivroPorISBN(Biblioteca* b, char* isbn) {
    NoLivro* aux=b->primeiro;
    while (aux!=NULL) {
        if (strcmp(aux->livro.isbn, isbn) == 0) return aux;
        aux=aux->proximo;
    }
    return NULL;
}

void destruirBiblioteca(Biblioteca* b) {
    NoLivro *aux=b->primeiro;
    while(aux!=NULL) {
        b->primeiro=b->primeiro->proximo;
        free(aux);
        aux=b->primeiro;
    }
    // Liberar todos os nós da lista com free

}