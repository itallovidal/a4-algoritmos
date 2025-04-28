#ifndef SALES
#define SALES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Modelo da venda
// esse modelo representa o conjunto das 
// informações de uma venda unidas

struct Sale {
  int id;
  char clientID[50];
  struct ProductList list;
  int productCount;
  float total;
  time_t date;
};

struct ProductList{
  struct ProductDataInList* product;
  int count;
};

struct ProductDataInList{
  int id;
  char name[50];
  char brand[50];
  float price;
  int quantity;
  float total;
};

// Modelo da venda para txt
// esse modelo representa como uma venda
// será registrada no txt

// cada produto será registrado em uma linha
// depois será agrupado pelo id da venda 

struct SaleRowTXT {
  int id;
  int productID;
  int quantity;
  float productTotalValue;
  char clientID[50];
  time_t date;
};

// ---

struct DateToSearch {
  int day;
  int month;
};

struct SaleList {
  struct Sale *sale;
  int count;
};

struct SaleRowList {
  struct SaleRow *saleRow;
  int count;
};

#define SELL_FILE_PATH "data/sales.txt"

struct SaleRowList getSaleRegistersByDay(struct DateToSearch *dateToSearch);
void getAllSoldProducts(struct Sale *soldProducts, int *soldProductsCount);
struct SaleList getSalesByDay(struct DateToSearch *dateToSearch);
void createSale(struct SaleRowTXT *rows, int quantity);

#endif
