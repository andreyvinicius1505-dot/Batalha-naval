# Batalha Naval em C 🚢

Um jogo de **Batalha Naval** desenvolvido em **C**, onde o jogador compete contra o computador em um tabuleiro 10x10.

O jogador e o computador têm **navios posicionados aleatoriamente**, e o objetivo é **afundar todos os navios do adversário**. O programa atualiza o tabuleiro após cada jogada, indicando **acertos (`X`)** e **erros (`O`)**.

---

## Como jogar

1. Compile o programa usando o GCC (ou outro compilador C):


gcc batalha_naval.c -o batalha_naval.exe
Execute o programa:


./batalha_naval.exe   # no Linux/Mac
batalha_naval.exe     # no Windows
Durante o jogo:

Digite a linha e coluna (0-9) para atacar o tabuleiro inimigo.

X indica acerto em navio adversário.

O indica água (erro).

O tabuleiro é atualizado a cada jogada.

O jogo termina quando todos os navios de um lado forem afundados.

Funcionalidades
Tabuleiro 10x10 para jogador e computador.

Navios posicionados automaticamente (tamanhos: 5, 4, 3, 3, 2).

Turnos alternados: jogador e computador.

Acertos (X) e erros (O) indicados no tabuleiro.

Fim do jogo quando todos os navios de um lado são destruídos.

Tecnologias
Linguagem: C

Compilador recomendado: GCC

Autor
Andrey Araújo

Projeto desenvolvido como exercício de lógica, matrizes 2D e loops, simulando um clássico jogo de estratégia em C.













