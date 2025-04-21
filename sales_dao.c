#include "sales_dao.h"

void getAllSoldProducts(struct Sale *soldProducts, int *soldProductsCount) {

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

void createSale(struct Sale salesToRegister[], int saleCount) {
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