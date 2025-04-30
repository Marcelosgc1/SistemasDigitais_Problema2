.global escrever
.type escrever, %function

escrever: 
    @ Salvando registradores 
    push{r0 - r5, lr}
    @ r0 = n0
    @ r1 = n1
    @ r2 = id
    @ r3 = linha
    @ r4 = coluna
    @ r5 = address

    @ Endereço ponte HPS-FPGA
    ldr r6, =0xFF200000

    @ Deslocando os paramêtros para o formato da instrução do projeto
    lsl r0, r0, #20
    lsl r1, r1, #12
    lsl r2, r2, #10
    lsl r3, r3, #7
    lsl r4, r4, #4
    @ r11 = opcode
    ldr r11, =0x0010

    @ Utilizando porta lógica OR para todos os paramêtros ficar em um único registrador
    
    @ N0 or N1
    orr r7, r0, r1

    @ ID or Linha
    orr r8, r2, r3

    @ (N0 or N1) or (ID or Linha)
    orr r9, r7, r8

    @ Coluna or Opcode
    orr r12, r4, r11

    @ (N0 or N1) or (ID or Linha) or (Coluna or Opcode)
    orr r10, r9, r12

    @ Salvando a instrução no endereço da ponte + deslocamento
    str r10,[r6, r5] 

    pop {r0-r5, pc}        @ Restaura registradores e retorna
