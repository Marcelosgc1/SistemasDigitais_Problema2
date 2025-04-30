#include <stdio.h>
#include <dafema.h>

void escrever(signed char n0, signed char n1, char id, char linha, char coluna, char address);
void soma();

int main() {

    signed char n0 = 0;
    signed char n1 = 1;
    char addressA = 0;
    char addressB = 14;
    int seletor = 0;

    // Enviando Matriz A  
    enviarMatriz(n0, n1, 0, addressA, 2);

    // Enviando Matriz B
    enviarMatriz(n0, n1, 1, addressB, 2);
    
    // Testando opcode de soma
    somar();


    return 0;   
}

// Encaminhamento de Matriz para teste
void enviarMatriz(signed char n0, signed char n1, char id, char address, char TAM){
 
    for(char i = 0; i < TAM; i++){
        for(char j = i % 2; i < TAM; j+=2){
            // i = Linha , j = Coluna
            escrever(n0 + i, n1 + i, id, i, j, address + 1);
        }
    }

}

int seletorDeOpcode(int seletor){

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


    switch (seletor)
    {
    case 1:
        /* code */
        break;
    
    default:
        break;
    }

}