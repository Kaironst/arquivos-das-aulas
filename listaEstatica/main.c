#include <stdio.h>

#include "biblioteca_estatica.c"


int main() {

Biblioteca b;

inicializarBiblioteca(&b);
printf("\nbiblioteca inicializada\n");

cadastrarLivro(&b, "Dom Quixote", "Cervantes", 1605, "1234567890123");
printf("\nlivro cadastrado\n");
cadastrarLivro(&b, "1984", "George Orwell", 1949, "9876543210123");
printf("\nlivro cadastrado\n");

listarTodosLivros(&b);
printf("\nlistando\n");

emprestarLivro(&b, "9876543210123", "Maria", "01/04/2025");
printf("\nemprestando\n");

listarTodosLivros(&b);
printf("\nlistando\n");

return 0;

}