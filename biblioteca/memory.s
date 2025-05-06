.section .text
.global memory_map
.type memory_map, %function

memory_map:
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

        LDR R1, =FPGA_ADRS
        STR R0, [R1, #0]
        MOV R2, #7
        STR R2, [R0, #0]

@       LDR R1, [R1]
@       STR R0, [R1, #0]
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

