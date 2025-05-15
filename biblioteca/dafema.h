#ifndef DAFEMA_H
#define DAFEMA_H

/*
 * matriz_id: Indica qual matriz você vai escrever,
 * 0 => matriz A
 * 1 => matriz B
 * 2 => matriz C
 * linha: Linha que os valores serão escritos
 * coluna: Coluna que os valores serão escritos
*/
typedef struct {
    unsigned char matriz_id;
    unsigned char linha;
    unsigned char coluna;
} endereco;

/* Mapeia a memória para o endereço base do AXI Bridge*/
void mapeiaMemoria();

/* Escreve dois números no endereço indicado
 * n0: Valor escrito da linha e coluna indicadas
 * n1: Valor escrito no próximo espaço da matriz
 * endereco: ponteiro p/ struct cujo dados serão escritos
 * 
 * retorno: -1 se mal sucedido, 0 se bem sucedido
 */
int escrever(signed char n0, signed char n1, endereco *endereco);

/* Lê dois números no endereço indicado
 * endereco: ponteiro p/ struct cujo dados serão lido
 * 
 * retorno: -1 se mal sucedido, se não, valor correto lido
 */
unsigned int ler(endereco *endereco);

/* Lê um valor da matriz 
 * endereco: ponteiro p/ struct cujo dados serão lido
 * 
 * retorno: -1 se mal sucedido, se não, valor correto lido
 */
signed char lerIndice(endereco *endereco);

/* Multiplica matriz A por char */
void multiEscalar(char multi);

/* Multiplica matrizes A e B*/
void multiplicacao();

/* soma matrizes A e B */
void soma();

/* subtrai matriz A por matriz B */
void subtracao();

/* gera matriz A transposta*/
void transposicao();

/* gera matriz A oposta */
void oposta();

/* calcula de determinante da matriz A 2x2 */
void determinante2x2();

/* calcula de determinante da matriz A 3x3 */
void determinante3x3();

/* calcula de determinante da matriz A 4x4 */
void determinante4x4();

/* calcula de determinante da matriz A 5x5 */
void determinante5x5();


#endif