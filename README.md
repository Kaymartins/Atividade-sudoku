## Objetivo

Utilizar matrizes e funções para resolver um problema de programação

## Problema

”Sudoku1
, por vezes escrito Su Doku é um jogo baseado na colocação lógica de números. O
objetivo do jogo é a colocação de números de 1 a 9 em cada uma das células vazias numa grade de
9x9, constituída por 3x3 subgrades chamadas regiões. O quebra-cabeça contém algumas pistas
iniciais, que são números inseridos em algumas células, de maneira a permitir uma indução ou
dedução dos números em células que estejam vazias. Cada coluna, linha e região só pode ter
um número de cada um dos 1 a 9. Resolver o problema requer apenas raciocínio lógico e algum
tempo. Os problemas são normalmente classificados em relação à sua realização [...]. Foi criado
por Howard Garns, um projetista e arquiteto de 74 anos aposentado”.

  O seu trabalho é criar um programa que leia um valor n, n = {2, 3, 4}, que determina a
dimensão de uma matriz quadrada n^2 x n^2 e em seguida leia n^4 valores que preenchem uma
matriz quadrada que representa um jogo de sudoku resolvido. A matriz pode ser 4 x 4 (se n =
2), 9 x 9 (se n = 3) ou 16 x 16 (se n = 4). Com a matriz carregada na memória, o seu programa
deve avaliar se o preenchimento está correto ou não, indicando a primeira linha e coluna onde
foi encontrado o erro (se houver), ou a mensagem ”Sudoku Ok!”. Para o jogo de Sudoku 16 x
16, considere as letras A, B, C, D, E, F e G para representar os dígitos 10, 11, 12, 13, 14, 15 e
16, respectivamente.

Para entrada:

<img src = "https://raw.githubusercontent.com/Kaymartins/Atividade-sudoku/main/entrada.png"> </img>

O programa deverá apresentar o seguinte resultado:

<img src = "https://raw.githubusercontent.com/Kaymartins/Atividade-sudoku/main/saida.png"> </img>

## Nota 

Nessa atividade foi completada a função sudokuOk, além disso foi criada a função ArmazenaBloco. A nota atríbuida a essa atividade foi de 7,5.
