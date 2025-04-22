#ifndef SALES_DAO
#define SALES_DAO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct SaleProductData {
  int productID;
  int quantity;
};

struct Sale {
  int id;
  struct SaleProductData *products;
  int totalProducts;
  float totalValue;
  time_t saleDate;
};

struct DateToSearch {
  int day;
  int month;
};

struct SaleList {
  struct Sale *sale;
  int count;
};

#define SELL_FILE_PATH "data/sales.txt"

void getAllSoldProducts(struct Sale *soldProducts, int *soldProductsCount);
struct SaleList getSalesByDay(struct DateToSearch *dateToSearch);
void createSale(struct Sale *sale, int productCount);

#endif
