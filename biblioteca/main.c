#include <stdio.h>
#include <stdlib.h>
#include "dafema.h"
#include "txt.h"


void escreveMatriz(int matriz[][5], int tamanho, int matrizId){

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            escreverIndice(matriz[i][j], matrizId, i, j);
        }
    }
}

void leMatriz(int matriz[][5], int tamanho, int matrizId){

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            matriz[i][j] = lerIndice(matrizId, i, j);
            
        }
    }
}

void printMatriz(int matriz[][5], int tamanho){
    printf("Imprimindo matriz %dx%d:\n",tamanho,tamanho);
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}


void exemplo1(){
    int a[2][5]= {
        {2, 3},
        {7,-4}
    };

    int b[2][5]= {
        {0, 0},
        {0, 0}
    };

    escreveMatriz(a, 2, 0);
    leMatriz(b, 2, 0);
    printMatriz(b, 2);
    
}


int main(){
	iniciarDafema();



    exemplo1();



    encerrarDafema();
	return 0;
};

