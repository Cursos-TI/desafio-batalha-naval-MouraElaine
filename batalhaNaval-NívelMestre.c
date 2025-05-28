#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

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

void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posicoes[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int x = posicoes[i][0];
        int y = posicoes[i][1];
        tabuleiro[x][y] = 3;
    }
}

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

void habilidadeCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void habilidadeCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == 2 || j == 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void habilidadeOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemX, int origemY) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int tabX = origemX + i - offset;
            int tabY = origemY + j - offset;

            if (tabX >= 0 && tabX < TAMANHO_TABULEIRO && tabY >= 0 && tabY < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[tabX][tabY] != 3) {
                    tabuleiro[tabX][tabY] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posições dos navios
    int navio1[TAMANHO_NAVIO][2] = { {0, 0}, {0, 1}, {0, 2} };
    int navio2[TAMANHO_NAVIO][2] = { {5, 5}, {6, 5}, {7, 5} };
    int navio3[TAMANHO_NAVIO][2] = { {2, 2}, {3, 2}, {4, 2} };
    int navio4[TAMANHO_NAVIO][2] = { {6, 0}, {7, 1}, {8, 2} };

    if (validarPosicoes(tabuleiro, navio1, TAMANHO_NAVIO)) posicionarNavio(tabuleiro, navio1, TAMANHO_NAVIO);
    if (validarPosicoes(tabuleiro, navio2, TAMANHO_NAVIO)) posicionarNavio(tabuleiro, navio2, TAMANHO_NAVIO);
    if (validarPosicoes(tabuleiro, navio3, TAMANHO_NAVIO)) posicionarNavio(tabuleiro, navio3, TAMANHO_NAVIO);
    if (validarPosicoes(tabuleiro, navio4, TAMANHO_NAVIO)) posicionarNavio(tabuleiro, navio4, TAMANHO_NAVIO);

    // Matriz de habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    habilidadeCone(cone);
    habilidadeCruz(cruz);
    habilidadeOctaedro(octaedro);

    // Aplicar habilidades
    aplicarHabilidade(tabuleiro, cone, 1, 7);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);

    // Exibir resultado
    exibirTabuleiro(tabuleiro);

    return 0;
}
