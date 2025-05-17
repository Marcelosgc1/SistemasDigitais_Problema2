#include <stdio.h>
#include <stdlib.h>
#include "dafema.h"
#include "txt.h"

void new5(endereco *adrs);
void escrever5x5(endereco *adrs);
void escrever4x4(endereco *adrs);
void escrever3x3(endereco *adrs);
void escrever2x2(endereco *adrs);
int iniciarPrograma(int seletor, signed char n0, signed char n1);

int main(){
	printf("a\n");
	mapeiaMemoria();
	printf("b\n");
	//soma();
	printf("c\n");

	signed char n0 = 0;
	signed char n1 = 1;
	int seletor = 0;
	int x = 1;
	while (x != 0) {
		x = iniciarPrograma(seletor, n0, n1);
	}

	return 0;
};


int iniciarPrograma(int seletor, signed char n0, signed char n1) {
    printf("\nDIGITE A OPERAÇÃO DESEJADA: ");
    printf("\n[1] LEITURA: ");
    printf("\n[2] ESCRITA: ");
    printf("\n[3] SOMA: ");
    printf("\n[4] SUBTRAÇÃO: ");
    printf("\n[5] MULTIPLICAÇÃO: ");
    printf("\n[6] TRANSPOSTA: ");
    printf("\n[7] OPOSTA: ");
    printf("\n[8] MULTIPLICAÇÃO ESCALAR: ");
    printf("\n[9] DETER2X2: ");
    printf("\n[10] DETER3X3: ");
    printf("\n[11] DETER4X4: ");
    printf("\n[12] DETER5X5: ");
    printf("\n[13] LER RESULT: ");
    printf("\n[14] DIGITE O TAMANHO DA MATRIZ: ");
    printf("\n OPÇÃO: ");
    int temporario, size;
    signed char temp1, temp2, temp3;
    scanf("%d", &seletor);
    endereco *meuEndereco = malloc(sizeof(endereco));
    // meuEndereco->matriz_id = 1;
    // meuEndereco->linha = 0;
    // meuEndereco->coluna = 2;


    switch (seletor) {
        case 1:
            *meuEndereco = (endereco) {0,0,0};
            temp1 = ler(meuEndereco);
	    //printf("aaa\n")
            temp2 = lerIndice(meuEndereco);
            meuEndereco->coluna = 1;
            temp3 = lerIndice(meuEndereco);

            printf("pacote de dados: %d\n", temp1);
            printf("valor n0: %d\n", temp2);
            printf("valor n1: %d\n", temp3);
	    break;
        case 2:
            printf("valor n0: ");
            scanf("%d", &temp1); 
            printf("valor n1: ");
            scanf("%d", &temporario);
            temp2 = (signed char) temporario;

            *meuEndereco = (endereco) {0,0,2};
            escrever(temp1, temp2, meuEndereco);

            *meuEndereco = (endereco) {1,0,2};
            escrever(temp1, temp2, meuEndereco);
            //enviarMatriz(n0, n1, 0, addressA, 2); // Escrevendo números na matriz A
            //enviarMatriz(n0, n1, 1, addressB, 2); // Escrevendo números na matriz B
            break;
        case 3:
            soma();     
            break;
        case 4:
            subtracao(); 
            break;
        case 5:
            multiplicacao(); 
            break;
        case 6:
            transposicao();    
            break;
        case 7:
            oposta();
            break;
        case 8:
            multiEscalar(5); 
            break;
        case 9:
            determinante2x2();     
            break;
        case 10:
            determinante3x3();     
            break;
        case 11:
            determinante4x4();     
            break;
        case 12:
            determinante5x5();    
            break;
        case 13:
            *meuEndereco = (endereco) {2,0,0};
            temp1 = ler(meuEndereco);

            temp2 = lerIndice(meuEndereco);
            
            *meuEndereco = (endereco) {2,0,1};
            temp3 = lerIndice(meuEndereco);

            printf("pacote de dados: %d\n", temp1);
            printf("valor n0: %d\n", temp2);
            printf(">linha < 5 && adrs->coluna < 5valor n1: %d\n", temp3);
	        break;
        case 14:
            scanf("%d", &size);
            switch(size){
                case 5:
                    *meuEndereco = (endereco) {0,0,0};
                    escrever5x5(meuEndereco);
                    *meuEndereco = (endereco) {1,0,0};
                    escrever5x5(meuEndereco);
                    break;
                case 4:
                    *meuEndereco = (endereco) {0,0,0};
                    escrever4x4(meuEndereco);
                    meuEndereco->matriz_id = 1;
                    escrever4x4(meuEndereco);
                    break;
                case 3:
                    *meuEndereco = (endereco) {0,0,0};
                    escrever3x3(meuEndereco);
                    meuEndereco->matriz_id = 1;
                    escrever3x3(meuEndereco);
                    break;
                case 2:
                    *meuEndereco = (endereco) {0,0,0};
                    escrever4x4(meuEndereco);
                    meuEndereco->matriz_id = 1;
                    escrever4x4(meuEndereco);
                    break;
                default:
                    printf("Só tamanho 2, 3, 4 ou 5");
                    break;
            }
            break;
	    case 15:
            new5(meuEndereco);
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
    return seletor;
}


void escrever5x5(endereco *adrs){
    signed char *dados = ler_arquivo_txt("teste.txt");

    int n = 0;
    do{
        escrever(dados[n], dados[n+1], adrs);
        printf("%d\n\n",dados[n]);
        n = n + 2;
        adrs->coluna = adrs->coluna + 2;
        if (adrs->coluna > 4){
            adrs->coluna = adrs->coluna % 5;
            adrs->linha = adrs->linha + 1;
        }
        printf("%d/%d\n", adrs->linha, adrs->coluna);
    }while (adrs->linha < 5 && adrs->coluna < 5);
    adrs->coluna = 0;
    adrs->linha = 0;  

    liberar_lista(dados);
}

void escrever4x4(endereco *adrs){
    signed char *dados = ler_arquivo_txt("teste.txt");

    int n = 0;
    do{
        escrever(dados[n], dados[n+1], adrs);
        printf("%d\n\n",dados[n]);
        n = n + 2;
        adrs->coluna = adrs->coluna + 2;
        if (adrs->coluna > 3){
            adrs->coluna = adrs->coluna % 5;
            adrs->linha = adrs->linha + 1;
        }
        printf("%d/%d\n", adrs->linha, adrs->coluna);
    }while (adrs->linha < 4 && adrs->coluna < 4);
    adrs->coluna = 0;
    adrs->linha = 0;  

    liberar_lista(dados);
}

void escrever3x3(endereco *adrs){
    signed char *dados = ler_arquivo_txt("teste.txt");

    int n = 0;
    do{
        escrever(dados[n], dados[n+1], adrs);
        printf("%d\n\n",dados[n]);
        n = n + 2;
        adrs->coluna = adrs->coluna + 2;
        if (adrs->coluna > 2){
            adrs->coluna = adrs->coluna % 5;
            adrs->linha = adrs->linha + 1;
        }
        printf("%d/%d\n", adrs->linha, adrs->coluna);
    }while (adrs->linha < 3 && adrs->coluna < 3);
    adrs->coluna = 0;
    adrs->linha = 0;  

    liberar_lista(dados);
}

void escrever2x2(endereco *adrs){
    signed char *dados = ler_arquivo_txt("teste.txt");

    int n = 0;
    do{
        escrever(dados[n], dados[n+1], adrs);
        printf("%d\n\n",dados[n]);
        n = n + 2;
        adrs->coluna = adrs->coluna + 2;
        if (adrs->coluna > 1){
            adrs->coluna = adrs->coluna % 5;
            adrs->linha = adrs->linha + 1;
        }
        printf("%d/%d\n", adrs->linha, adrs->coluna);
    }while (adrs->linha < 2 && adrs->coluna < 2);
    adrs->coluna = 0;
    adrs->linha = 0;  

    liberar_lista(dados);
}

void new5(endereco *adrs){
    *adrs = (endereco) {1,0,0};
    int temp;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            scanf("%d", &temp);
	        signed char x = (signed char) temp;
            *adrs = (endereco) {1,i,j};
            escreverIndice(x, adrs);
        }
    }
    *adrs = (endereco) {0,0,0};
    return;
}

