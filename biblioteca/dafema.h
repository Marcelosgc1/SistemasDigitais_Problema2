#ifndef DAFEMA_H
#define DAFEMA_H

/* Escreve dois números no endereço indicado */
void escrever(signed char n0, signed char n1, char address);

/* Lê dois números do endereço indicado */
char ler(char address);

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