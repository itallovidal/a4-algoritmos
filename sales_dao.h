#ifndef SALES_DAO
#define SALES_DAO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Sale {
  // char id[10]; // TODO: gerar UUID
  char productName[50];
  char productBrand[50];
  int quantity;
  float unitValue;
  float totalValue;
  time_t saleDate;
};

#define SELL_FILE_PATH "data/sell.txt"

void getSoldProducts(struct Sale *soldProducts, int *soldProductsCount);
void insertNewSale(struct Sale salesToRegister[], int saleCount);

#endif
