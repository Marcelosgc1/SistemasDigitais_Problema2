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



void operacoes(){
    int m[5][5];
    soma();
    getchar();
    leMatriz(m,5,2);
    printf("SOMA\n");
    printMatriz(m, 5);

    subtracao();
    getchar();
    leMatriz(m,5,2);
    printf("SUBTRACAO\n");
    printMatriz(m, 5);
    
    transposicao();
    getchar();
    leMatriz(m,5,2);
    printf("TRANSPOSICAO\n");
    printMatriz(m, 5);
    
    oposta();
    getchar();
    leMatriz(m,5,2);
    printf("OPOSTA\n");
    printMatriz(m, 5);
    
    multiEscalar(4);
    getchar();
    leMatriz(m,5,2);
    printf("MUL ESCALAR\n");
    printMatriz(m, 5);
    
    multiplicacao();
    getchar();
    leMatriz(m,5,2);
    printf("MULTIPLICACAO\n");
    printMatriz(m, 5);
    
    determinante2x2();
    getchar();
    leMatriz(m,5,2);
    printf("DETERMINANTE 2X2\n");
    printMatriz(m, 5);
    
    determinante3x3();
    getchar();
    leMatriz(m,5,2);
    printf("DETERMINANTE 3X3\n");
    printMatriz(m, 5);

    determinante4x4();
    getchar();
    leMatriz(m,5,2);
    printf("DETERMINANTE 4X4\n");
    printMatriz(m, 5);

    determinante5x5();
    getchar();
    leMatriz(m,5,2);
    printf("DETERMINANTE 5X5\n");
    printMatriz(m, 5);

}

void escrever2x2ASM(){
    __uint8_t temp;
    signed char n0, n1;

    endereco *adrs = malloc(sizeof(signed char) * 3);
    *adrs = (endereco) {0,0,0};
    
    printf("Escreva [0][0]: ");
    scanf("%d", &temp);
    n0 = temp;
    printf("Escreva [0][1]: ");
    scanf("%d", &temp);
    n1 = temp;

    escreverASM(n0, n1, adrs);
    adrs->coluna = 4;
    
    printf("Escreva [1][0]: ");
    scanf("%d", &temp);
    n1 = temp;

    escreverASM(0, n1, adrs);
    adrs->coluna = 1;
    adrs->linha = 1;

    printf("Escreva [1][1]: ");
    scanf("%d", &temp);
    n0 = temp;

    escreverASM(n0, 0, adrs);

}

void ler2x2ASM(int matriz[2][5]){
    endereco *adrs = malloc(sizeof(signed char) * 3);
    *adrs = (endereco) {0,0,0};
    int temp;
    
    temp = lerASM(adrs);
    matriz[0][0] = temp & 255;
    matriz[0][1] = temp >> 8;

    adrs->coluna = 4;
    temp = lerASM(adrs);
    matriz[1][0] = temp >> 8;

    adrs->linha = 1;
    adrs->coluna = 1;
    temp = lerASM(adrs);
    matriz[1][1] = temp & 255;

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

    printf("Matriz esperada 2x2: \n");
    printMatriz(a, 2);
    escreveMatriz(a, 2, 0);
    leMatriz(b, 2, 0);
    printMatriz(b, 2);
}

void exemplo2(){
    int a[3][5]= {
        {2, 3, -1},
        {7,-4, -1},
        {20, 1, -9}
    };

    int b[3][5]= {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    printf("Matriz esperada 3x3: \n");
    printMatriz(a, 3);
    escreveMatriz(a, 3, 0);
    leMatriz(b, 3, 0);
    printMatriz(b, 3);
}

void exemplo3(){
    int a[4][5]= {
        {2, 3, -1, 11},
        {7,-4, -1, 20},
        {20, 1, -9, 6},
        {0, 54, -32, 7}

    };

    int b[4][5]= {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    printf("Matriz esperada 4x4: \n");
    printMatriz(a, 4);
    escreveMatriz(a, 4, 0);
    leMatriz(b, 4, 0);
    printMatriz(b, 4);
}

void exemplo4(){
    int a[5][5]= {
        {2, 3, -1, 11, 22},
        {7,-4, -1, 20, 1},
        {20, 1, -9, 6, 0},
        {0, 54, -32, 7, 8},
        {-3, 5, 1, 27, -1}

    };

    int b[5][5]= {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    printf("Matriz esperada 5x5: \n");
    printMatriz(a, 5);
    escreveMatriz(a, 5, 0);
    leMatriz(b, 5, 0);
    printMatriz(b, 5);
}

void exemplo5(){
    int matriz[2][5];
    escrever2x2ASM();
    ler2x2ASM(matriz);
    printMatriz(matriz, 2);

}

void exemplo6(){
    int a[5][5]= {
        {2, 3, -1, 11, 22},
        {7,-4, -1, 20, 1},
        {20, 1, -9, 6, 0},
        {0, 54, -32, 7, 8},
        {-3, 5, 1, 27, -1}
    };

    int b[5][5]= {
        {12, 4, -5, 7, 3},
        {7,-4, 11, 0, -20},
        {2, 13, 2, 6, 12},
        {0, 21, 12, 7, 5},
        {-6, 2, 2, 7, -1}
    };

    printf("matriz A:\n");
    escreveMatriz(a,5,0);
    printMatriz(a,5);
    printf("matriz B:\n");
    escreveMatriz(b,5,1);
    printMatriz(b,5);
    getchar();
    operacoes();
}

void exemplo7(){
    ler(1,0,1);
}

int main(){
	iniciarDafema();
    int opcao = 1, delay;

    while(opcao != 0){
        printf("[1] Matrizes pre-setadas\n");
        printf("[2] Escrever Matriz pelo terminal\n");
        printf("[3] Exit call p/ erro\n");
        printf("[5] Testar Operações\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            getchar();
            exemplo1();
            getchar();
            exemplo2();
            getchar();
            exemplo3();
            getchar();
            exemplo4();
            break;

        case 2:
            exemplo5();
            break;
            
        case 3:
            exemplo7();
            break;
        case 5:
            exemplo6();
            break;
        default:
            break;
        }
    }
    
    encerrarDafema();
	return 0;
};

