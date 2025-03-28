#include <stdio.h>
#include <stdlib.h>

// Tamanho do tabuleiro
#define TAMANHO 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicializa o tabuleiro
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // **Nível Novato** - Posicionamento inicial de dois navios
    // Navio 1: Posicionado verticalmente
    int x1 = 0, y1 = 1; // Coordenada inicial
    for (int i = 0; i < 3; i++) { // Navio de 3 partes
        tabuleiro[x1 + i][y1] = 3;
    }

    // Navio 2: Posicionado horizontalmente
    int x2 = 3, y2 = 0; // Coordenada inicial
    for (int j = 0; j < 4; j++) { // Navio de 4 partes
        tabuleiro[x2][y2 + j] = 3;
    }

    printf("Tabuleiro após posicionamento inicial dos navios:\n");
    exibirTabuleiro(tabuleiro);

    // **Nível Aventureiro** - Expansão do tabuleiro e adição de navios diagonais
    // Navio 3: Posicionado na diagonal principal
    int x3 = 5, y3 = 5; // Coordenada inicial
    for (int i = 0; i < 4; i++) { // Navio de 4 partes
        tabuleiro[x3 + i][y3 + i] = 3;
    }

    // Navio 4: Posicionado na diagonal secundária
    int x4 = 8, y4 = 2; // Coordenada inicial
    for (int i = 0; i < 3; i++) { // Navio de 3 partes
        tabuleiro[x4 - i][y4 + i] = 3;
    }

    printf("\nTabuleiro após adicionar navios diagonais:\n");
    exibirTabuleiro(tabuleiro);

    // **Nível Mestre** - Implementação de habilidades especiais
    // Habilidade "Cruz"
    printf("\nHabilidade Especial - Cruz:\n");
    int cruz[TAMANHO][TAMANHO] = {0};
    int centroX = 4, centroY = 4; // Centro da cruz
    for (int i = -2; i <= 2; i++) {
        cruz[centroX][centroY + i] = 1; // Linha horizontal
        cruz[centroX + i][centroY] = 1; // Linha vertical
    }
    exibirTabuleiro(cruz);

    // Habilidade "Cone"
    printf("\nHabilidade Especial - Cone:\n");
    int cone[5][5] = {0};
    cone[2][2] = 1;
    for (int i = 1; i <= 2; i++) {
        cone[2 + i][2 - i] = 1;
        cone[2 + i][2 + i] = 1;
        for (int j = -i; j <= i; j++) {
            cone[2 + i][2 + j] = 1;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    // Habilidade "Octaedro"
    printf("\nHabilidade Especial - Octaedro:\n");
    int octaedro[5][5] = {0};
    octaedro[2][2] = 1;
    for (int i = 1; i <= 2; i++) {
        octaedro[2 - i][2] = 1;
        octaedro[2 + i][2] = 1;
        octaedro[2][2 - i] = 1;
        octaedro[2][2 + i] = 1;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
