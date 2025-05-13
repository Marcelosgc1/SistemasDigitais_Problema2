#ifndef DAFEMA_H
#define DAFEMA_H

/* Mapeia a memória para o endereço base do AXI Bridge*/
void mapeiaMemoria();

/* Escreve dois números no endereço indicado
 * n0: Valor escrito da linha e coluna indicadas
 * n1: Valor escrito no próximo espaço da matriz
 * matriz: Indica qual matriz você vai escrever,
 * 0 => matriz A
 * 1 => matriz B
 * 2 => matriz C
 * lin: Linha que os valores serão escritos
 * col: Coluna que os valores serão escritos
 * 
 * retorno: -1 se mal sucedido, 0 se bem sucedido
 */
int escrever(signed char n0, signed char n1, unsigned char matriz, unsigned char lin, unsigned char col);

/* Lê dois números do endereço indicado 
 * matriz: Indica qual matriz você vai escrever,
 * 0 => matriz A
 * 1 => matriz B
 * 2 => matriz C
 * lin: Linha que os valores serão escritos
 * col: Coluna que os valores serão escritos
 * 
 * retorno: -1 se mal sucedido, se bem sucedido um pacote de 16 bits contendo 2 chars
 */
unsigned int ler(unsigned char matriz, unsigned char lin, unsigned char col);

/* Lê dois números do endereço indicado 
 * matriz: Indica qual matriz você vai escrever,
 * 0 => matriz A
 * 1 => matriz B
 * 2 => matriz C
 * lin: Linha que os valores serão escritos
 * col: Coluna que os valores serão escritos
 * 
 * retorno: -1 se mal sucedido, se bem sucedido o char desejado
 */
unsigned int lerChar(unsigned char matriz, unsigned char lin, unsigned char col);

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