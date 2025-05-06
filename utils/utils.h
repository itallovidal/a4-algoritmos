#ifndef UTILS
#define UTILS
#include "../include/products.h"

// 
// #include <string.h>
// #include <time.h>

// struct SaleList;
// struct ProductList;
// struct SaleRowList;

// struct ProductCountData {
//   int id;
//   int count;
// };
// struct DateToSearch getDateToSearchInput();

void clearTerminal();

// // struct ProductCountData getLessSoldProduct(struct SaleRowList *saleRowList);
// // struct ProductCountData getMostSoldProduct(struct SaleRowList *saleRowList);
// void printSales(struct SaleList *saleList);
void printProducts(struct ProductList *productList);
#endif