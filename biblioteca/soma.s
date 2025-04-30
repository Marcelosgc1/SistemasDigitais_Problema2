.global soma
.type soma, %function

soma:

    @ Endereço Ponte HPS-FPGA
    ldr r3, =0xFF200000

    @ ds
