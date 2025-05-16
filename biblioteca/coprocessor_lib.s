.section .text
.global mapeiaMemoria
.type mapeiaMemoria, %function

.global escrever
.type escrever, %function

.global escreverIndice
.type escreverIndice, %function

.global ler
.type ler, %function

.global lerIndice
.type lerIndice, %function

.global soma
.type soma, %function

.global subtracao
.type subtracao, %function

.global multiplicacao
.type multiplicacao, %function

.global transposicao
.type transposicao, %function

.global oposta
.type oposta, %function

.global multiEscalar
.type multiEscalar, %function

.global determinante2x2
.type determinante2x2, %function

.global determinante3x3
.type determinante3x3, %function

.global determinante4x4
.type determinante4x4, %function

.global determinante5x5
.type determinante5x5, %function

.global write_instruction

mapeiaMemoria:
        SUB SP, SP, #28
        STR R0, [SP, #0]
        STR R1, [SP, #4]
        STR R2, [SP, #8]
        STR R3, [SP, #12]
        STR R4, [SP, #16]
        STR R5, [SP, #20]
        STR R7, [SP, #24]

        @abrindo dev/mem para acessar a func mmap2
        LDR R0, =DEV_MEM
        MOV R1, #2
        MOV R2, #0
        MOV R7, #5

        SVC 0

        MOV R4, R0
        
        @chamando mmap
        MOV R0, #0
        LDR R1, =FPGA_SPAM
        LDR R1, [R1, #0]
        MOV R2, #3
        MOV R3, #1
        LDR R5, =FPGA_BRIDGE
        LDR R5, [R5, #0]
        MOV R7, #192

        SVC 0

        @salva endereço virtual
        LDR R1, =FPGA_ADRS
        STR R0, [R1, #0]


        LDR R0, [SP, #0]
        LDR R1, [SP, #4]
        LDR R2, [SP, #8]
        LDR R3, [SP, #12]
        LDR R4, [SP, #16]
        LDR R5, [SP, #20]
        LDR R7, [SP, #24]
        ADD SP, SP, #28

	BX LR
        
escrever:
        SUB SP, SP, #12
        STR R3, [SP, #0]
        STR R4, [SP, #4]
        STR R5, [SP, #8]

        LDR R4, [R2, #2]
        AND R4, R4, #255

        LDR R3, [R2, #1]
        AND R3, R3, #255

        LDR R2, [R2, #0]
        AND R2, R2, #255

        @-----Verifica erro nos valores da matriz, linha e coluna-----
        CMP R2, #2
        BHI wrong_call_error

        CMP R3, #4
        BHI wrong_call_error

        CMP R4, #4
        BHI wrong_call_error

        EOR R5, R3, R4
        ANDS R5, R5, #1
        BNE wrong_call_error
        
        @-----Escrevendo parametros na instrução-----
        LSL R0, R0, #20

        AND R1, R1, #255
        LSL R1, R1, #12
        ORR R0, R0, R1

        LSL R2, R2, #10
        ORR R0, R0, R2
        
        LSL R3, R3, #7
        ORR R0, R0, R3
        
        LSL R4, R4, #4
        ORR R0, R0, R4

        @-----Opcode da instrução-----
        ORR R0, R0, #2

        SUB SP, SP, #4
        STR LR, [SP, #0]
        
        BL write_instruction
        
        LDR LR, [SP, #0]
        LDR R3, [SP, #4]
        LDR R4, [SP, #8]
        LDR R5, [SP, #12]
        ADD SP, SP, #16

        BX LR

escreverIndice:
        SUB SP, SP, #16
        STR R3, [SP, #0]
        STR R4, [SP, #4]
        STR R5, [SP, #8]
        STR LR, [SP, #12]

        MOV R5, R0
        MOV R0, R1

        BL ler

        SUB SP, SP, #8
        STR R6, [SP, #0]
        STR R2, [SP, #4]

        LDR R3, [R1, #1]
        LDR R4, [R1, #2]

        @R5: numero p/ escrever
        @R1: endereco struct
        @R0: numero presente na fpga
        @R3: linha
        @R4: coluna

        MOV R2, R1 @R2 = struct

        EOR R6, R3, R4
        ANDS R6, R6, #1

        
        BNE odd_instruction       
        @se R6 == 0; par
        
        
        
        LSR R0, R0, #8 @R0 = n1
        MOV R1, R0     @R1 = n1
        MOV R0, R5     @R0 = n0
        B continue_to_write

      
odd_instruction:
        @se R6 == 0; impar
        AND R6, R4, #7
        CMP R6, #0

        BNE sub_col
        SUB R3, R3, #1
        LSR R4, R4, #3
        LSL R4, R4, #3

        ORR R4, R4, #5
        

sub_col:
        SUB R4, R4, #1

        AND R0, R0, #255
        MOV R1, R5

        STR R3, [R2, #1]
        STR R4, [R2, #2]


continue_to_write:

        BL escrever
        
        LDR R6, [SP, #0]
        LDR R2, [SP, #4]
        ADD SP, SP, #8

        LDR R3, [SP, #0]
        LDR R4, [SP, #4]
        LDR R5, [SP, #8]
        LDR LR, [SP, #12]
        ADD SP, SP, #16
        
        BX LR

ler:
        SUB SP, SP, #12
        STR R3, [SP, #0]
        STR R4, [SP, #4]
        STR R5, [SP, #8]

        LDR R4, [R0, #2]
        AND R4, R4, #255

        LDR R3, [R0, #1]
        AND R3, R3, #255

        LDR R0, [R0, #0]
        AND R0, R0, #255

        @-----Verifica erro nos valores da matriz, linha e coluna-----
        CMP R0, #2
        BHI wrong_call_error

        CMP R3, #4
        BHI wrong_call_error

        CMP R4, #4
        BHI wrong_call_error

        EOR R5, R4, R3
        ANDS R5, R5, #1
        BNE wrong_call_error
        
        @-----Escrevendo parametros na instrução-----
        LSL R0, R0, #10

        LSL R3, R3, #7
        ORR R0, R0, R3
        
        LSL R4, R4, #4
        ORR R0, R0, R4

        @-----Opcode da instrução-----
        ORR R0, R0, #1

        SUB SP, SP, #4
        STR LR, [SP, #0]

        BL write_instruction
        
        LDR R3, =FPGA_ADRS
        LDR R3, [R3, #0]
        LDR R0, [R3, #0x10]
        
        LDR LR, [SP, #0]
        LDR R3, [SP, #4]
        LDR R4, [SP, #8]
        LDR R5, [SP, #12]
        ADD SP, SP, #16

        BX LR


wrong_call_error:
        MOV R0, #-1
        
        LDR R3, [SP, #0]
        LDR R4, [SP, #4]
        LDR R5, [SP, #8]
        ADD SP, SP, #12

        BX LR

lerIndice:
        SUB SP, SP, #12
        STR R3, [SP, #0]
        STR R4, [SP, #4]
        STR R5, [SP, #8]

        LDR R4, [R0, #2]
        AND R4, R4, #255

        LDR R3, [R0, #1]
        AND R3, R3, #255

        LDR R0, [R0, #0]
        AND R0, R0, #255

        @-----Verifica erro nos valores da matriz, linha e coluna-----
        CMP R0, #2
        BHI wrong_call_error

        CMP R3, #4
        BHI wrong_call_error

        CMP R4, #4
        BHI wrong_call_error

        SUB SP, SP, #4
        STR R5, [SP, #0]

        @R3 é linha
        @R4 é coluna

        EOR R5, R3, R4 @Xor salvo em R5
        ANDS R5, R5, #1  

        BEQ correct_instruction
        CMP R4, #0
        BNE sub_adrs
        SUB R3, R3, #1
        MOV R4, #5
sub_adrs:
        SUB R4, R4, #1

        @-----Escrevendo parametros na instrução-----
correct_instruction:
        LSL R0, R0, #10

        LSL R3, R3, #7
        ORR R0, R0, R3
        
        LSL R4, R4, #4
        ORR R0, R0, R4

        @-----Opcode da instrução-----
        ORR R0, R0, #1

        SUB SP, SP, #4
        STR LR, [SP, #0]

        BL write_instruction
        
        LDR R3, =FPGA_ADRS
        LDR R3, [R3, #0]
        LDR R0, [R3, #0x10]

        @se r5 == 0: pega n0
        @se r5 == 1: pega n1
        
        CMP R5, #0
        BEQ else_n0
        LSR R0, R0, #8
else_n0:
        AND R0, R0, #255

        LDR LR, [SP, #0]
        LDR R3, [SP, #4]
        LDR R4, [SP, #8]
        LDR R5, [SP, #12]
        ADD SP, SP, #16

        BX LR


soma:
        SUB SP, SP, #8
        STR R0, [SP, #0]
        STR LR, [SP, #4]

        MOV R0, #3

        BL write_instruction
        
        LDR R0, [SP, #0]
        LDR LR, [SP, #4]
        ADD SP, SP, #8

        BX LR

subtracao:
        SUB SP, SP, #8
        STR R0, [SP, #0]
        STR LR, [SP, #4]

        MOV R0, #4

        BL write_instruction
        
        LDR R0, [SP, #0]
        LDR LR, [SP, #4]
        ADD SP, SP, #8

        BX LR

multiplicacao:
        SUB SP, SP, #8
        STR R0, [SP, #0]
        STR LR, [SP, #4]

        MOV R0, #5

        BL write_instruction
        
        LDR R0, [SP, #0]
        LDR LR, [SP, #4]
        ADD SP, SP, #8

        BX LR

transposicao:
        SUB SP, SP, #8
        STR R0, [SP, #0]
        STR LR, [SP, #4]

        MOV R0, #6

        BL write_instruction
        
        LDR R0, [SP, #0]
        LDR LR, [SP, #4]
        ADD SP, SP, #8

        BX LR

oposta:
        SUB SP, SP, #8
        STR R0, [SP, #0]
        STR LR, [SP, #4]

        MOV R0, #7

        BL write_instruction
        
        LDR R0, [SP, #0]
        LDR LR, [SP, #4]
        ADD SP, SP, #8

        BX LR

multiEscalar:
        SUB SP, SP, #4
        STR LR, [SP, #0]

        LSL R0, R0, #4
        ORR R0, R0, #8

        BL write_instruction
        
        LDR LR, [SP, #0]
        ADD SP, SP, #4

        BX LR

determinante2x2:
        SUB SP, SP, #8
        STR R0, [SP, #0]
        STR LR, [SP, #4]

        MOV R0, #9

        BL write_instruction
        
        LDR R0, [SP, #0]
        LDR LR, [SP, #4]
        ADD SP, SP, #8

        BX LR

determinante3x3:
        SUB SP, SP, #8
        STR R0, [SP, #0]
        STR LR, [SP, #4]

        MOV R0, #10

        BL write_instruction
        
        LDR R0, [SP, #0]
        LDR LR, [SP, #4]
        ADD SP, SP, #8

        BX LR

determinante4x4:
        SUB SP, SP, #8
        STR R0, [SP, #0]
        STR LR, [SP, #4]

        MOV R0, #11

        BL write_instruction
        
        LDR R0, [SP, #0]
        LDR LR, [SP, #4]
        ADD SP, SP, #8

        BX LR

determinante5x5:
        SUB SP, SP, #8
        STR R0, [SP, #0]
        STR LR, [SP, #4]

        MOV R0, #12

        BL write_instruction
        
        LDR R0, [SP, #0]
        LDR LR, [SP, #4]
        ADD SP, SP, #8

        BX LR

write_instruction:
        SUB SP, SP, #4
        STR R1, [SP, #0]

        LDR R1, =FPGA_ADRS
        LDR R1, [R1, #0]
        STR R0, [R1, #0] 
        MOV R0, #1
        STR R0, [R1, #0x20] @deslocamento p/ sinal de "activate_instruction"
activate_loop:
        @Fica no loop até o wait_signal for 1
        
        LDR R0, [R1, #0x30] @deslocmento p/ sinal de "wait_signal"
        CMP R0, #0
        BEQ activate_loop

	MOV R0, #0

        STR R0, [R1, #0x20] @deslocamento p/ sinal de "activate_instruction"
wait_loop:
        LDR R0, [R1, #0x30] @deslocmento p/ sinal de "wait_signal"
        CMP R0, #1
        BEQ wait_loop
        

        LDR R1, [SP, #0]
        ADD SP, SP, #4

        BX LR


.section .data

DEV_MEM:
        .asciz "/dev/mem"

FPGA_SPAM:
        .word 0x1000

FPGA_ADRS:
        .space 4;

FPGA_BRIDGE:
        .word 0xff200

