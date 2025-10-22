#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Inicializa o tabuleiro com agua
void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for(int i=0;i<TAM;i++)
        for(int j=0;j<TAM;j++)
            tabuleiro[i][j]='~';
}

// Imprime tabuleiro
void imprimirTabuleiro(char tabuleiro[TAM][TAM], int mostrarNavios) {
    printf("  ");
    for(int j=0;j<TAM;j++) printf("%d ", j);
    printf("\n");
    for(int i=0;i<TAM;i++){
        printf("%d ", i);
        for(int j=0;j<TAM;j++){
            if(tabuleiro[i][j]=='#' && !mostrarNavios)
                printf("~ ");
            else
                printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Coloca navio no tabuleiro horizontal ou vertical
int colocarNavio(char tabuleiro[TAM][TAM], int tamanho) {
    int linha, coluna, horizontal;
    horizontal = rand()%2; // 0 = vertical, 1 = horizontal

    if(horizontal){
        linha = rand() % TAM;
        coluna = rand() % (TAM-tamanho+1);
    } else {
        linha = rand() % (TAM-tamanho+1);
        coluna = rand() % TAM;
    }

    // Verifica se espaço livre
    for(int i=0;i<tamanho;i++){
        int x = linha + (horizontal?0:i);
        int y = coluna + (horizontal?i:0);
        if(tabuleiro[x][y] != '~') return 0;
    }

    // Coloca navio
    for(int i=0;i<tamanho;i++){
        int x = linha + (horizontal?0:i);
        int y = coluna + (horizontal?i:0);
        tabuleiro[x][y]='#';
    }
    return 1;
}

// Conta navios restantes
int contarNavios(char tabuleiro[TAM][TAM]) {
    int cont=0;
    for(int i=0;i<TAM;i++)
        for(int j=0;j<TAM;j++)
            if(tabuleiro[i][j]=='#') cont++;
    return cont;
}

int main() {
    srand(time(NULL));
    char jogador[TAM][TAM], computador[TAM][TAM];
    inicializarTabuleiro(jogador);
    inicializarTabuleiro(computador);

    int tamanhos[5] = {5,4,3,3,2};

    // Coloca navios jogador e computador
    for(int i=0;i<5;i++){
        while(!colocarNavio(jogador, tamanhos[i]));
        while(!colocarNavio(computador, tamanhos[i]));
    }

    int lin, col;
    int vezJogador=1;

    while(contarNavios(jogador)>0 && contarNavios(computador)>0){
        if(vezJogador){
            printf("\nSeu tabuleiro:\n");
            imprimirTabuleiro(jogador,1);
            printf("\nTabuleiro inimigo:\n");
            imprimirTabuleiro(computador,0);

            printf("\nDigite linha e coluna para atacar (0-9): ");
            scanf("%d %d",&lin,&col);

            if(computador[lin][col]=='#'){
                printf("Acertou!\n");
                computador[lin][col]='X';
            } else if(computador[lin][col]=='~'){
                printf("Agua!\n");
                computador[lin][col]='O';
            } else {
                printf("Ja tentou essa posicao!\n");
                continue;
            }
            vezJogador=0;
        } else {
            // Computador ataca aleatoriamente
            lin = rand()%TAM;
            col = rand()%TAM;
            printf("\nComputador ataca: %d %d\n", lin, col);

            if(jogador[lin][col]=='#'){
                printf("Computador acertou!\n");
                jogador[lin][col]='X';
            } else if(jogador[lin][col]=='~'){
                printf("Computador errou!\n");
                jogador[lin][col]='O';
            }
            vezJogador=1;
        }
    }

    if(contarNavios(computador)==0)
        printf("\nParabens! Voce afundou todos os navios inimigos!\n");
    else
        printf("\nGame Over! Todos os seus navios foram afundados.\n");

    return 0;
}
