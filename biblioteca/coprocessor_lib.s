.section .text
.global mapeiaMemoria
.type mapeiaMemoria, %function

.global escrever
.type escrever, %function

.global ler
.type ler, %function

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

        //abrindo dev/mem para acessar a func mmap2
        LDR R0, =DEV_MEM
        MOV R1, #2
        MOV R2, #0
        MOV R7, #5

        SVC 0

        MOV R4, R0
        
        //chamando mmap
        MOV R0, #0
        LDR R1, =FPGA_SPAM
        LDR R1, [R1, #0]
        MOV R2, #3
        MOV R3, #1
        LDR R5, =FPGA_BRIDGE
        LDR R5, [R5, #0]
        MOV R7, #192

        SVC 0

        //salva endereço virtual
        LDR R1, =FPGA_ADRS
        STR R0, [R1, #0]

        //MOV R2, #7              //Valor arbitrário p/ teste
        //STR R2, [R0, #0]


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
        //-----Verifica erro nos valores da matriz, linha e coluna-----
        CMP R2, #2
        BHI wrong_call_error

        CMP R3, #4
        BHI wrong_call_error

        CMP R4, #4
        BHI wrong_call_error

        EOR R3, R3, R4
        ANDS R3, R3, #1
        BNE wrong_call_error
        
        //-----Escrevendo parametros na instrução-----
        LSL R0, R0, #20

        LSL R1, R1, #12
        ORR R0, R0, R1

        LSL R2, R2, #10
        ORR R0, R0, R2
        
        LSL R3, R3, #7
        ORR R0, R0, R3
        
        LSL R4, R4, #4
        ORR R0, R0, R4

        //-----Opcode da instrução-----
        ORR R0, R0, #1

        SUB SP, SP, #4
        STR LR, [SP, #0]
        
        BL write_instruction
        
        LDR LR, [SP, #0]
        ADD SP, SP, #4

        BX LR

ler:
        //-----Verifica erro nos valores da matriz, linha e coluna-----
        CMP R0, #2
        BHI wrong_call_error

        CMP R1, #4
        BHI wrong_call_error

        CMP R2, #4
        BHI wrong_call_error

        EOR R1, R1, R2
        ANDS R1, R1, #1
        BNE wrong_call_error
        
        //-----Escrevendo parametros na instrução-----
        LSL R0, R0, #10

        LSL R1, R1, #7
        ORR R0, R0, R1
        
        LSL R2, R2, #4
        ORR R0, R0, R2

        //-----Opcode da instrução-----
        ORR R0, R0, #2

        SUB SP, SP, #4
        STR LR, [SP, #0]

        BL write_instruction
        
        LDR R1, =FPGA_ADRS
        LDR R1, [R1, #0]
        LDR R0, [R1, #0x10]
        
        LDR LR, [SP, #0]
        ADD SP, SP, #4

        BX LR


wrong_call_error:
        MOV R0, #-1
        
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
        STR R0, [R1, #0x30] //deslocamento p/ sinal de "activate_instruction"
activate_loop:
        LDR R0, [R1, #0x20] //deslocmento p/ sinal de "wait_signal"
        CMP R0, #0
        BEQ activate_loop
        
        STR R0, [R1, #0x30] //deslocamento p/ sinal de "activate_instruction"
wait_loop:
        LDR R0, [R1, #0x20] //deslocmento p/ sinal de "wait_signal"
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

