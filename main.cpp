#include <stdio.h>
#include <string.h>

#define SELL_FILE_NAME "sell.txt"
#define CLIENT_FILE_NAME "client.txt"

FILE *initializeFile(const char fileName[20]) {
  char filePath[100] = "data/";
  strcat(filePath, fileName);

  FILE *fileData = fopen(filePath, "r");

  if (fileData != NULL) {
    printf("\nArquivo carregado com sucesso!\n");
    return fileData;
  };

  printf("\nArquivo não existe. Gerando...\n");
  fileData = fopen(filePath, "w");
  return fileData;
}

int main() {
  int isRunning = 1;

  printf("\nInicializando arquivos.\n");
  FILE *sellFile = initializeFile(SELL_FILE_NAME);
  FILE *clientFile = initializeFile(CLIENT_FILE_NAME);

  while (isRunning) {
    printf("\nBem vindo ao seu sistema de PetShop!");
    printf("\nO que deseja fazer?");

    int option;
    printf("\n1 - Cadastrar uma nova venda");
    printf("\n2 - Relatório de itens");
    printf("\n3 - Relatório de venda");
    printf("\n4 - Sair");
    printf("\n");
    scanf("%d", &option);
    printf("\n");

    switch (option) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      isRunning = 0;
      break;
    default:
      break;
    }
  }

  fclose(sellFile);
  fclose(clientFile);
  return 0;
}