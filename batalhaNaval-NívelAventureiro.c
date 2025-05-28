#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Inicializa o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Verifica se posições são válidas
bool validarPosicoes(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posicoes[][2], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        int x = posicoes[i][0];
        int y = posicoes[i][1];
        if (x < 0 || x >= TAMANHO_TABULEIRO || y < 0 || y >= TAMANHO_TABULEIRO || tabuleiro[x][y] == 3) {
            return false;
        }
    }
    return true;
}

// Marca as posições do navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posicoes[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int x = posicoes[i][0];
        int y = posicoes[i][1];
        tabuleiro[x][y] = 3;
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Navio 1 - Horizontal
    int navio1[TAMANHO_NAVIO][2] = { {0, 0}, {0, 1}, {0, 2} };
    // Navio 2 - Vertical
    int navio2[TAMANHO_NAVIO][2] = { {5, 5}, {6, 5}, {7, 5} };
    // Navio 3 - Vertical
    int navio3[TAMANHO_NAVIO][2] = { {2, 2}, {3, 2}, {4, 2} };
    // Navio 4 - Diagonal (exemplo: de (1,1) até (3,3))
    int navio4[TAMANHO_NAVIO][2] = { {6, 0}, {7, 1}, {8, 2} };

    if (validarPosicoes(tabuleiro, navio1, TAMANHO_NAVIO)) {
        posicionarNavio(tabuleiro, navio1, TAMANHO_NAVIO);
    } else {
        printf("Posição inválida para o navio 1.\n");
    }

    if (validarPosicoes(tabuleiro, navio2, TAMANHO_NAVIO)) {
        posicionarNavio(tabuleiro, navio2, TAMANHO_NAVIO);
    } else {
        printf("Posição inválida para o navio 2.\n");
    }

    if (validarPosicoes(tabuleiro, navio3, TAMANHO_NAVIO)) {
        posicionarNavio(tabuleiro, navio3, TAMANHO_NAVIO);
    } else {
        printf("Posição inválida para o navio 3.\n");
    }

    if (validarPosicoes(tabuleiro, navio4, TAMANHO_NAVIO)) {
        posicionarNavio(tabuleiro, navio4, TAMANHO_NAVIO);
    } else {
        printf("Posição inválida para o navio 4 (diagonal).\n");
    }

    // Exibe o tabuleiro com todos os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
