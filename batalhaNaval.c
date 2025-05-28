#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0


#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10, inicializado com zeros (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Vetores representando os navios
    // Cada navio é um array de posições, aqui apenas para facilitar a visualização
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3}; // Navio na horizontal
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};   // Navio na vertical

    // Coordenadas iniciais do navio horizontal (linha e coluna)
    int linhaHorizontal = 2; // exemplo: linha 2
    int colunaHorizontal = 4; // exemplo: coluna 4

    // Coordenadas iniciais do navio vertical
    int linhaVertical = 5; // exemplo: linha 5
    int colunaVertical = 7; // exemplo: coluna 7

    // Validação das coordenadas do navio horizontal
    if (linhaHorizontal < 0 || linhaHorizontal >= TAMANHO_TABULEIRO ||
        colunaHorizontal < 0 || colunaHorizontal + TAMANHO_NAVIO - 1 >= TAMANHO_TABULEIRO) {
        printf("Coordenadas do navio horizontal inválidas.\n");
        return 1; // Encerra o programa se inválido
    }

    // Validação das coordenadas do navio vertical
    if (linhaVertical < 0 || linhaVertical + TAMANHO_NAVIO - 1 >= TAMANHO_TABULEIRO ||
        colunaVertical < 0 || colunaVertical >= TAMANHO_TABULEIRO) {
        printf("Coordenadas do navio vertical inválidas.\n");
        return 1; // Encerra o programa se inválido
    }

    // Posicionando o navio horizontal na matriz
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3; // Marca as posições com 3
    }

    // Posicionando o navio vertical na matriz
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3; // Marca as posições com 3
    }

    // Exibindo o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
    
