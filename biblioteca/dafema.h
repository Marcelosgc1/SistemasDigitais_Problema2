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
 * exceção: caso endereço não esteja parametrizado corretamente,
 * o programa é terminado e o código de erro 255 é emitido 
 */
void escrever(signed char n0, signed char n1, endereco *endereco);

/* Escreve dois números no endereço indicado
 * num: Valor escrito no endereço indicado
 * endereco: ponteiro p/ struct cujo dados serão escritos
 * 
 * exceção: caso endereço não esteja parametrizado corretamente,
 * o programa é terminado e o código de erro 255 é emitido 
 */
void escreverIndice(signed char num, endereco *endereco);

/* Lê dois números no endereço indicado
 * endereco: ponteiro p/ struct cujo dados serão lido
 * 
 * exceção: caso endereço não esteja parametrizado corretamente,
 * o programa é terminado e o código de erro 255 é emitido
 * 
 * retorno: pacote de 16 bits contendo n0 nos 8 bits menos
 * significativos e n1 nos 8 bits mais significativos
 */
unsigned int ler(endereco *endereco);

/* Lê um valor da matriz 
 * endereco: ponteiro p/ struct cujo dados serão lido
 * 
 * exceção: caso endereço não esteja parametrizado corretamente,
 * o programa é terminado e o código de erro 255 é emitido
 * 
 * retorno: valor de 8 bits lido do endereco indicado
 */
signed char lerIndice(endereco *endereco);

/* Multiplica matriz A (0) por char 
 * 
 * O resultado é escrito na matriz C (2)
 */
void multiEscalar(char multi);

/* Multiplica matrizes A e B 
 * 
 * O resultado é escrito na matriz C (2)
 */
void multiplicacao();

/* Soma matrizes A e B  
 * 
 * O resultado é escrito na matriz C (2)
 */
void soma();

/* Subtrai matriz A por matriz B  
 * 
 * O resultado é escrito na matriz C (2)
 */
void subtracao();

/* Gera matriz A transposta 
 * 
 * O resultado é escrito na matriz C (2)
 */
void transposicao();

/* Gera matriz A oposta  
 * 
 * O resultado é escrito na matriz C (2)
 */
void oposta();

/* Calcula de determinante da matriz A 2x2  
 * 
 * O resultado é escrito na matriz C (2), linha 0 e coluna 0
 */
void determinante2x2();

/* Calcula de determinante da matriz A 3x3   
 * 
 * O resultado é escrito na matriz C (2), linha 0 e coluna 0
 */
void determinante3x3();

/* Calcula de determinante da matriz A 4x4   
 * 
 * O resultado é escrito na matriz C (2), linha 0 e coluna 0
 */
void determinante4x4();

/* Calcula de determinante da matriz A 5x5   
 * 
 * O resultado é escrito na matriz C (2), linha 0 e coluna 0
 */
void determinante5x5();


#endif