#include <stdio.h>

#define TAM 10

void inicializarTabuleiro(int tabuleiro[TAM][TAM])
{
  for (int i = 0; i < TAM; i++)
  {
    for (int j = 0; j < TAM; j++)
    {
      tabuleiro[i][j] = 0;
    }
  }
}

void posicionarNavios(int tabuleiro[TAM][TAM])
{
  // Horizontal
  for (int j = 1; j <= 3; j++)
  {
    tabuleiro[2][j] = 1;
  }

  // Vertical
  for (int i = 5; i <= 7; i++)
  {
    tabuleiro[i][6] = 1;
  }

  // Diagonal
  for (int i = 0; i < 3; i++)
  {
    tabuleiro[i][i] = 1;
  }
}

// Cruz: afeta o centro e os 4 lados
void aplicarHabilidadeCruz(int tabuleiro[TAM][TAM], int x, int y)
{
  int dx[] = {0, -1, 1, 0, 0};
  int dy[] = {0, 0, 0, -1, 1};

  for (int i = 0; i < 5; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM)
    {
      if (tabuleiro[nx][ny] == 0)
      {
        tabuleiro[nx][ny] = 2;
      }
    }
  }
}

// Cone para cima: linha acima e diagonais
void aplicarHabilidadeCone(int tabuleiro[TAM][TAM], int x, int y)
{
  int dx[] = {-1, -1, -1};
  int dy[] = {-1, 0, 1};

  for (int i = 0; i < 3; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && ny >= 0 && nx < TAM && ny < TAM)
    {
      if (tabuleiro[nx][ny] == 0)
      {
        tabuleiro[nx][ny] = 2;
      }
    }
  }
}

// Octaedro: 8 posições ao redor
void aplicarHabilidadeOctaedro(int tabuleiro[TAM][TAM], int x, int y)
{
  int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int i = 0; i < 8; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && ny >= 0 && nx < TAM && ny < TAM)
    {
      if (tabuleiro[nx][ny] == 0)
      {
        tabuleiro[nx][ny] = 2;
      }
    }
  }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM])
{
  printf("   ");
  for (int j = 0; j < TAM; j++)
  {
    printf("%2d ", j);
  }
  printf("\n");

  for (int i = 0; i < TAM; i++)
  {
    printf("%2d ", i);
    for (int j = 0; j < TAM; j++)
    {
      if (tabuleiro[i][j] == 0)
      {
        printf("[~]"); // água
      }
      else if (tabuleiro[i][j] == 1)
      {
        printf("[N]"); // navio
      }
      else if (tabuleiro[i][j] == 2)
      {
        printf("[*]"); // ataque
      }
    }
    printf("\n");
  }
}

int main()
{
  int tabuleiro[TAM][TAM];

  inicializarTabuleiro(tabuleiro);
  posicionarNavios(tabuleiro);

  // Exibir tabuleiro antes da habilidade
  printf("\n=== Tabuleiro Inicial ===\n");
  exibirTabuleiro(tabuleiro);

  // Aplicar habilidades
  aplicarHabilidadeCruz(tabuleiro, 4, 4);
  aplicarHabilidadeCone(tabuleiro, 6, 6);
  aplicarHabilidadeOctaedro(tabuleiro, 1, 7);

  // Exibir tabuleiro depois da habilidade
  printf("\n=== Tabuleiro Após Habilidades ===\n");
  exibirTabuleiro(tabuleiro);

  return 0;
}
