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
struct tm extractTime(long int timestamp);
void printSales(struct RegisteredSales *registered);
void sortSales(struct RegisteredSales *sales);
void printProducts(struct ProductList *productList);
#endif