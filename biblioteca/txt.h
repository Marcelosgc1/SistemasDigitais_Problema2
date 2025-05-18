#ifndef TXT_H
#define TXT_H

#include <stdio.h>
#include <stdlib.h>

signed char* ler_arquivo_txt(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    int capacidade = 25;
    int tamanho = 0;
    signed char *lista = (signed char *) malloc(capacidade * sizeof(signed char));
    if (lista == NULL) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return NULL;
    }

    int num;
    while (fscanf(arquivo, "%d", &num) == 1 && tamanho < capacidade) {
        lista[tamanho++] = (signed char)num;
    }

    fclose(arquivo);
    return lista; 
}

void liberar_lista(signed char *lista) {
    free(lista);
}

#endif
