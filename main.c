#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SELL_FILE_PATH "data/sell.txt"

struct Sell {
  // char id[10]; // TODO fazer funcão que gera UUID
  char productName[50];
  char productBrand[50];
  int quantity;
  float unitValue;
  float totalValue;
  time_t sellDate;
};

void getSelledProducts(struct Sell *selledProducts, int *selledProductsCount) {
  FILE *file = fopen(SELL_FILE_PATH, "r");

  if (file == NULL) {
    return;
  }

  while (fscanf(file, "%s %s %d %f %f %ld",
                selledProducts[*selledProductsCount].productName,
                selledProducts[*selledProductsCount].productBrand,
                &selledProducts[*selledProductsCount].quantity,
                &selledProducts[*selledProductsCount].unitValue,
                &selledProducts[*selledProductsCount].totalValue,
                &selledProducts[*selledProductsCount].sellDate) != EOF) {

    (*selledProductsCount)++;
    if (*selledProductsCount != 0 && *selledProductsCount % 10 == 0) {
      selledProducts = realloc(selledProducts, sizeof(struct Sell) * 10);
    }
  }
}

void showSelledProducts() {
  int selledProductsCount = 0;
  struct Sell *selledProducts = malloc(sizeof(struct Sell) * 10);

  getSelledProducts(selledProducts, &selledProductsCount);

  printf("Quantidade de registros: %d", selledProductsCount);

  for (int i = 0; i < selledProductsCount; i++) {
    printf("Produto:\n");
    printf("  Nome: %s\n", selledProducts[i].productName);
    printf("  Marca: %s\n", selledProducts[i].productBrand);
    printf("  Quantidade: %d\n", selledProducts[i].quantity);
    printf("  Unit: %.2f\n", selledProducts[i].unitValue);
    printf("  Total: %.2f\n", selledProducts[i].totalValue);
    printf("  Tempo: %ld\n", selledProducts[i].sellDate);
  }
}

void insertNewSell(struct Sell sellsToRegister[], int sellCount) {
  FILE *file = fopen(SELL_FILE_PATH, "a");

  if (file == NULL) {
    printf("\nErro ao abrir o arquivo %s\n", SELL_FILE_PATH);
    return;
  }

  for (int i = 0; i < sellCount; i++) {

    printf("Produto:\n");
    printf("  Nome: %s\n", sellsToRegister[i].productName);
    printf("  Marca: %s\n", sellsToRegister[i].productBrand);
    printf("  Quantidade: %d\n", sellsToRegister[i].quantity);
    printf("  Unit: %.2f\n", sellsToRegister[i].unitValue);
    printf("  Total: %.2f\n", sellsToRegister[i].totalValue);
    printf("  Tempo: %ld\n", sellsToRegister[i].sellDate);

    fprintf(file, "%s %s %d %1.2f %1.2f %ld\n", sellsToRegister[i].productName,
            sellsToRegister[i].productBrand, sellsToRegister[i].quantity,
            sellsToRegister[i].unitValue, sellsToRegister[i].totalValue,
            sellsToRegister[i].sellDate);
  }

  fclose(file);
  printf("\nVenda registrada com sucesso!\n");
}

void registerNewSell() {
  int isAddingProduct = 1;
  struct Sell *itemsSelled = NULL;
  int itemsSelledCount = 0;

  while (isAddingProduct) {
    itemsSelledCount++;

    struct Sell newSell;
    newSell.sellDate = time(NULL);

    printf("\nDigite o nome do produto: ");
    scanf("%s", newSell.productName);

    printf("\nDigite a marca do produto: ");
    scanf("%s", newSell.productBrand);

    printf("\nDigite a quantidade vendida: ");
    scanf("%d", &newSell.quantity);

    printf("\nDigite o valor unitário: ");
    scanf("%f", &newSell.unitValue);

    newSell.totalValue = newSell.unitValue * newSell.quantity;

    if (newSell.quantity > 3) {
      printf("\nAplicando desconto..");
      newSell.totalValue = newSell.totalValue * 0.9;
    }

    printf("\n\nDeseja registrar a venda de mais um produto?");
    printf("\n1 - Sim");
    printf("\n2 - Não");
    printf("\n");
    scanf("%d", &isAddingProduct);

    if (isAddingProduct != 1) {
      isAddingProduct = 0;
    }

    itemsSelled = (struct Sell *)realloc(itemsSelled, sizeof(struct Sell) *
                                                          itemsSelledCount);

    itemsSelled[itemsSelledCount - 1] = newSell;
  }

  printf("\nSalvando..\n");
  insertNewSell(itemsSelled, itemsSelledCount);
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
      registerNewSell();
      break;
    case 2:
      showSelledProducts();
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