#ifndef UTILS
#define UTILS
#include "sales_dao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct ProductCountData {
  int id;
  int count;
};

struct DateToSearch getDateToSearchInput();
struct ProductCountData getLessSoldProduct(struct SaleRowList *saleRowList);
struct ProductCountData getMostSoldProduct(struct SaleRowList *saleRowList);
void printSales(struct SaleList *saleList);
#endif