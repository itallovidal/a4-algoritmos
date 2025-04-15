#include <stdio.h>

int main() {
  int isRunning = 1;
  while (isRunning) {
    printf("\nBem vindo ao seu sistema de PetShop!");
    printf("\nO que deseja fazer?");

    int option;
    printf("\n1 - Cadastrar uma nova venda");
    printf("\n2 - Relatório de itens");
    printf("\n3 - Relatório de venda");
    printf("\n4 - Sair");
    printf("\n");
    scanf("%d \n", &option);

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

  return 0;
}