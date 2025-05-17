#ifndef DAFEMA_H
#define DAFEMA_H

/*
 * Stuct que indica um indice de uma matriz
 *
 * matriz_id: unsig char
 * 0 => matriz A
 * 1 => matriz B
 * 2 => matriz C
 * 
 * linha: unsig char
 * coluna: unsig char
*/
typedef struct dafemaEndereco{
    unsigned char matriz_id;
    unsigned char linha;
    unsigned char coluna;
} endereco;

/* Mapeia a memória para o endereço base do AXI Bridge*/
void iniciarDafema();

/* Libera memória do endereço para o AXI Bridge*/
void encerrarDafema();

/* Escreve dois números no endereço indicado
 * n0: Valor escrito no endereço indicado
 * n1: Valor escrito no próximo espaço da matriz
 * endereco: ponteiro p/ struct cujo dados serão escritos
 * 
 * retorno: -1 se mal sucedido, 0 se bem sucedido
 */
int escrever(signed char n0, signed char n1, endereco *endereco);

/* Escreve dois números no endereço indicado
 * num: Valor escrito no endereço indicado
 * endereco: ponteiro p/ struct cujo dados serão escritos
 * 
 * retorno: -1 se mal sucedido, 0 se bem sucedido
 */
int escreverIndice(signed char num, endereco *endereco);

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