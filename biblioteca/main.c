#include <stdio.h>
#include "dafema.h"


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
    int temp1, temp2, temp3;
    scanf("%d", &seletor);  

    switch (seletor) {
        case 1:
            temp1 = ler(0,0,0);
            temp2 = lerIndice(0,0,0);
            temp3 = lerIndice(0,0,1);
            printf("pacote de dados: %d\n", temp1);
            printf("valor n0: %d\n", temp2);
            printf("valor n1: %d\n", temp3);
	    break;
        case 2:
            printf("valor n0: ");
            scanf("%d", &temp1); 
            printf("valor n1: ");
            scanf("%d", &temp2); 
            escrever(temp1,temp2,0,0,0);
            escrever(temp1,temp2,1,0,0);
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
            temp1 = ler(2,0,0);
            temp2 = lerIndice(2,0,0);
            temp3 = lerIndice(2,0,1);
            printf("pacote de dados: %d\n", temp1);
            printf("valor n0: %d\n", temp2);
            printf("valor n1: %d\n", temp3);
	    break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
    return seletor;
}
