#ifndef UTILS
#define UTILS
#include "../include/products.h"
#include "../include/sales.h" 

struct ProductSalesSummary {
  int id;
  int count;
};

struct DateToSearch getDateToSearchInput();
void clearTerminal();

struct ProductSalesSummary getLessSoldProduct(struct RegisteredSales *sales) ;
struct ProductSalesSummary getMostSoldProduct(struct RegisteredSales *sales);
void printSales(struct RegisteredSales *registered);
void printProducts(struct ProductList *productList);
#endif