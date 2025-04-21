#include "sales_dao.h"

void showSoldProducts() {
  int soldProductsCount = 0;
  struct Sale *soldProducts = malloc(sizeof(struct Sale) * 10);

  getAllSoldProducts(soldProducts, &soldProductsCount);

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
  createSale(itemsSold, itemsSoldCount);
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