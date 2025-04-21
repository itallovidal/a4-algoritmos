#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SELL_FILE_PATH "data/sell.txt"

struct Sale {
  // char id[10]; // TODO: gerar UUID
  char productName[50];
  char productBrand[50];
  int quantity;
  float unitValue;
  float totalValue;
  time_t saleDate;
};

void getSoldProducts(struct Sale *soldProducts, int *soldProductsCount) {
  FILE *file = fopen(SELL_FILE_PATH, "r");

  if (file == NULL) {
    return;
  }

  while (fscanf(file, "%s %s %d %f %f %ld",
                soldProducts[*soldProductsCount].productName,
                soldProducts[*soldProductsCount].productBrand,
                &soldProducts[*soldProductsCount].quantity,
                &soldProducts[*soldProductsCount].unitValue,
                &soldProducts[*soldProductsCount].totalValue,
                &soldProducts[*soldProductsCount].saleDate) != EOF) {

    (*soldProductsCount)++;
    if (*soldProductsCount != 0 && *soldProductsCount % 10 == 0) {
      soldProducts = realloc(soldProducts, sizeof(struct Sale) * 10);
    }
  }
}

void showSoldProducts() {
  int soldProductsCount = 0;
  struct Sale *soldProducts = malloc(sizeof(struct Sale) * 10);

  getSoldProducts(soldProducts, &soldProductsCount);

  printf("Quantidade de registros: %d", soldProductsCount);

  for (int i = 0; i < soldProductsCount; i++) {
    printf("Product:\n");
    printf("  Nome: %s\n", soldProducts[i].productName);
    printf("  Marca: %s\n", soldProducts[i].productBrand);
    printf("  Quantidade: %d\n", soldProducts[i].quantity);
    printf("  Valor unitário: %.2f\n", soldProducts[i].unitValue);
    printf("  Total: %.2f\n", soldProducts[i].totalValue);
    printf("  Data de venda: %ld\n", soldProducts[i].saleDate);
  }
}

void insertNewSale(struct Sale salesToRegister[], int saleCount) {
  FILE *file = fopen(SELL_FILE_PATH, "a");

  if (file == NULL) {
    printf("\nErro ao abrir o arquivo %s\n", SELL_FILE_PATH);
    return;
  }

  for (int i = 0; i < saleCount; i++) {
    printf("Product:\n");
    printf("  Nome: %s\n", salesToRegister[i].productName);
    printf("  Marca: %s\n", salesToRegister[i].productBrand);
    printf("  Quantidade: %d\n", salesToRegister[i].quantity);
    printf("  Valor unitário: %.2f\n", salesToRegister[i].unitValue);
    printf("  Total: %.2f\n", salesToRegister[i].totalValue);
    printf("  Data de venda: %ld\n", salesToRegister[i].saleDate);

    fprintf(file, "%s %s %d %1.2f %1.2f %ld\n", salesToRegister[i].productName,
            salesToRegister[i].productBrand, salesToRegister[i].quantity,
            salesToRegister[i].unitValue, salesToRegister[i].totalValue,
            salesToRegister[i].saleDate);
  }

  fclose(file);
  printf("\nVenda registrada com sucesso!\n");
}

void registerNewSale() {
  int isAddingProduct = 1;
  struct Sale *itemsSold = NULL;
  int itemsSoldCount = 0;

  while (isAddingProduct) {
    itemsSoldCount++;

    struct Sale newSale;
    newSale.saleDate = time(NULL);

    printf("\nDigite o nome do produto: ");
    scanf("%s", newSale.productName);

    printf("\nDigite a marca do produto: ");
    scanf("%s", newSale.productBrand);

    printf("\nDigite a quantidade vendida: ");
    scanf("%d", &newSale.quantity);

    printf("\nDigite o valor unitário: ");
    scanf("%f", &newSale.unitValue);

    newSale.totalValue = newSale.unitValue * newSale.quantity;

    if (newSale.quantity > 3) {
      printf("\nAplicando desconto..");
      newSale.totalValue = newSale.totalValue * 0.9;
    }

    printf("\n\nDeseja registrar a venda de mais um produto?");
    printf("\n1 - Sim");
    printf("\n2 - Não");
    printf("\n");
    scanf("%d", &isAddingProduct);

    if (isAddingProduct != 1) {
      isAddingProduct = 0;
    }

    itemsSold =
        (struct Sale *)realloc(itemsSold, sizeof(struct Sale) * itemsSoldCount);

    itemsSold[itemsSoldCount - 1] = newSale;
  }

  printf("\nSalvando..\n");
  insertNewSale(itemsSold, itemsSoldCount);
}

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
    scanf("%d", &option);
    printf("\n");

    switch (option) {
    case 1:
      registerNewSale();
      break;
    case 2:
      showSoldProducts();
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