#include <stdio.h>
#include <dafema.h>


int main() {

    signed char n0 = 0;
    signed char n1 = 1;
    char addressA = 0;
    char addressB = 14;
    int seletor = 0;

    iniciarPrograma(seletor, n0, n1, addressA, addressB);

    return 0;   
}

// Encaminhamento de Matriz para teste
void enviarMatriz(signed char n0, signed char n1, char id, char address, char TAM){
 
    for(char i = 0; i < TAM; i++){
        for(char j = i % 2; i < TAM; j+=2){
            // i = Linha , j = Coluna
            escrever(n0 + i, n1 + i, address + 1);
        }
    }

}

int iniciarPrograma(int seletor, signed char n0, signed char n1, char addressA, char addressB) {
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
    scanf("%d", &seletor);  

    switch (seletor) {
        case 1:
            ler(addressA);  
            break;
        case 2:
            enviarMatriz(n0, n1, 0, addressA, 2); // Escrevendo números na matriz A
            enviarMatriz(n0, n1, 1, addressB, 2); // Escrevendo números na matriz B
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
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
    return seletor;
}
