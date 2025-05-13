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
	int x = 0;
	while (x != 14) {
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
    int sla;
    scanf("%d", &seletor);  

    switch (seletor) {
        case 1:
            seletor = ler(0,0,0);
            printf("valor lido: %d\n", seletor);
	    break;
        case 2:
            printf("wip escreva valor ai :");
            scanf("%d", &sla); 
            escrever(1,sla,0,0,0);
            escrever(1,sla,1,0,0);
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
            seletor = ler(2,0,0);  
            printf("valor lido: %d\n", seletor);
	    break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
    return seletor;
}
