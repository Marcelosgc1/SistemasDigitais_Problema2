<h1 align="center">Comunicação entre HPS e FPGA com o Coprocessador Dafema</h1>

<h2>Descrição do Projeto</h2>
<p>
  O segundo problema do projeto MI - Sistemas Digitais tem como foco a comunicação entre o processador HPS (Hard Processor System) e o FPGA (Field Programmable Gate Array) da placa DE1-SoC. A integração entre as duas unidades foi feita por meio do uso de PIOs (Parallel Input/Output) personalizados, configurados através do Platform Designer e mapeados via barramento AXI. A comunicação eficiente entre os dois blocos permite o envio de instruções, dados e comandos de controle para execução das operações matriciais.

A implementação do cooprocessador em verilog pode ser encontrada no [repositório do problema 1](https://github.com/Marcelosgc1/SistemasDigitais_Problema1/tree/HPS_communication), com as modificações necessárias descritas acima.

  <div align="center">
    <img src="images/fpga-hps.png"><br>
    <strong>Conexão HPS ↔ FPGA via PIOs AXI</strong><br><br>
  </div>

  O principal objetivo desta etapa do projeto é viabilizar um protocolo de comunicação simples, porém robusto, entre o software em C rodando no HPS (Linux embarcado) e a lógica do coprocessador implementada no FPGA, utilizando linguagem Assembly e Verilog.

</p>

Sumário
=================
<!--ts-->
   * [Visão Geral do Sistema](#visao)
   * [Plataform Designer e PIOs](#pio)
   * [Protocolo de Comunicação](#protocolo)
   * [Biblioteca em Assembly](#assembly)
   * [Testes Realizados](#testes)
   * [Referências](#referencias)
<!--te-->

<div id="visao">
  <h2>Visão Geral do Sistema</h2>
  <p>
    O sistema é composto por um coprocessador implementado no FPGA que realiza operações com matrizes e um software no HPS que envia instruções e dados. A comunicação ocorre via PIOs mapeados no barramento AXI, e o controle é realizado por sinais de escrita, leitura, ativação e espera.
  </p>
</div>

<div id="pio">
  <h2>Plataform Designer e Adição de PIOs</h2>
  <ul>
    <li>Foram adicionados 4 PIOs no Platform Designer:</li>
    <ul>
      <li><strong>Instrução:</strong> 28 bits (comando e parâmetros)</li>
      <li><strong>Dados:</strong> 16 bits (valores numéricos)</li>
      <li><strong>Wait:</strong> 1 bit (indica se o coprocessador ainda está processando)</li>
      <li><strong>Activate:</strong> 1 bit (sinal para iniciar a execução)</li>
    </ul>
    <li>Separar os sinais em diferentes PIOs oferece:</li>
    <ul>
      <li>Facilidade de debug</li>
      <li>Maior organização e clareza</li>
      <li>Escalabilidade para novos comandos</li>
    </ul>
  </ul>
</div>

<div id="protocolo">
  <h2>Protocolo de Comunicação</h2>
  <img src="imagens/protocolo.png"><br>
  <p>
    As instruções são enviadas do HPS para o FPGA pela memória mapeada em Assembly. <br><br>
    O protocolo exige que o campo "Activate" seja setado após o envio da instrução, então o HPS aguarda o sinal de "Wait" ser setado, para confirmar que a FPGA começou a processar a instrução, depois retira o sinal de "Activate" e verifica "Wait" até que a execução seja concluída.
  </p>
</div>

<div id="assembly">
  <h2>Biblioteca em Assembly</h2>
  <p>
    A comunicação e controle do coprocessador pelo HPS são implementados em Assembly ARMv7. A biblioteca oferece funções como:
  </p>
  <ul>
    <li><strong>Mapeamento de memória:</strong> usa `mmap()` para acessar os PIOs e `unmmap()` p/ liberar memória</li>
    <ul>
      <li>InciarDafema</li>
      <li>EncerrarDafema</li>
    </ul>
    <li><strong>Funções aritméticas:</strong> formatação de instrução com máscaras e shift</li>
    <ul>
      <li>Soma</li>
      <li>Subtração</li>
      <li>Transposta</li>
      <li>Oposta</li>
      <li>Multiplicação Escalar</li>
      <li>Multiplicação</li>
      <li>Determinantes 2x2, 3x3, 4x4 e 5x5</li>
    </ul>
    <li><strong>Funções de leitura/escrita:</strong><br>Essas funções devem receber, o ID da matriz, que deve ser menor que 3, linha e coluna menores que 5 e parametrizados, seguindo a regra de acessar os índices de 2 em 2, começando do índice [0][0], já que estas opreações o programador trabalha com 2 números por vez. Para as funções Ler Indice e Escrever Indice, não se aplica a regra da parametrização de linha e coluna, já que é trabalhado apenas um número por vez.</li>
    <ul>
      <li>Ler</li>
      <li>Escrever</li>
      <li>Ler Indice</li>
      <li>Escrever Indice</li>
    </ul>
  </ul>

  <p>As structs são utilizadas para encapsular parâmetros e facilitar o uso das funções, contornando a limitação de 4 registradores nos parâmetros de função em ARM.</p>
</div>

<div id="testes">
  <h2>Testes Realizados</h2>
  <ul>
    <li><strong>Matriz Pré-definida:</strong> Escrita e leitura de matriz A → B</li>
    <li><strong>Escrita via Terminal:</strong> Inserção manual dos elementos da matriz</li>
    <li><strong>Acesso Inválido:</strong> Teste com IDs, linhas e colunas fora do intervalo</li>
    <li><strong>Leitura via Arquivo:</strong> Leitura de matriz a partir de `.txt`</li>
    <li><strong>Operações Aritméticas:</strong> Teste completo das operações:</li>
    <ul>
      <li>Soma</li>
      <li>Subtração</li>
      <li>Transposta</li>
      <li>Oposta</li>
      <li>Multiplicação Escalar</li>
      <li>Multiplicação</li>
      <li>Determinantes 2x2, 3x3, 4x4 e 5x5</li>
    </ul>
  </ul>
</div>

<div id="referencias">
  <h2>Referências</h2>
  <ul>
    <li>DE1-SoC User Manual - Terasic</li>
    <li>ARM Architecture Reference Manual - ARMv7</li>
    <li>Quartus Prime Lite 23.1 Documentation</li>
    <li>Intel SoC FPGA Embedded Development Suite (EDS)</li>
  </ul>
</div>
