#ifndef UTILS
#define UTILS
#include "sales_dao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct MostSoldProduct {
  int id;
  int count;
};

struct DateToSearch getDateToSearchInput();
struct MostSoldProduct getMostSoldProduct(struct SaleRowList *saleRowList);
void printSales(struct SaleList *saleList);
#endif