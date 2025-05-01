.global soma
.type soma, %function

soma:
    PUSH {R4-R6, LR} @ Salva registradores

    LDR R4, =0xFF200000  @ Carrega endereço base em R4
    MOV R5, #26          @ Contador para 26 iterações
    
    BL loop             @ Chama a função loop
    
    POP {R4-R6, PC}     @ Retorna
    
loop:
    PUSH {R4-R5} 
    LDR R6, [R4]       @ Carrega o valor do endereço atual
    
    @ Isola e modifica os 4 bits menos significativos
    ADD R6, R6, #0xF   @ Limpa os 4 bits menos significativos
    ORR R6, R6, #0x3   @ Seta os 4 LSBs para 0011 (0x3)
    
    STR R6, [R4], #4   @ Armazena o valor modificado e incrementa o ponteiro
    
    SUBS R5, R5, #1    @ Decrementa o contador
    CBZ R5, loop           @ Se não zero, repete
    
    POP {R4-R5}        @ Restaura registradores
    BX LR              @ Retorna para soma
