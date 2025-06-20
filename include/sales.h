#ifndef SALES
#define SALES
#include <time.h>

#define SELL_FILE_PATH "data/sales.txt"

// Modelo da venda
// esse modelo representa o conjunto das
// informações de uma venda unidas

// id   | clientID  | productID | quantity  | total             | date
// 1    | a@.com    | 1         | 2         | 10.00             | 1745730332
// 1    | a@.com    | 2         | 1         | 05.00             | 1745730332

struct SaleRowTXT
{
  int id;
  char clientID[100];
  int productID;
  int quantity;
  float productTotalValue;
  time_t date;
};

// {
//     id: 1,
//     clientID: "a@.com",
//     saleList: {
//         count: 2,
//         items: [
//             { productID: 1, quantity: 2, productTotalValue: 10.00 },
//             { productID: 2, quantity: 1, productTotalValue: 5.00 }
//         ]
//     },
//     total: 15.00,
//     date: 1745730332
// }

struct SaleItems
{
  int productID;
  int quantity;
  float productTotalValue;
};

struct SaleList
{
  int count;
  struct SaleItems *items;
};

struct Sale
{
  int id;
  char clientID[50];
  struct SaleList saleList;
  float total;
  time_t date;
};

struct RegisteredSales
{
  int count;
  struct Sale *sales;
};

// // ---

struct DateToSearch
{
  int day;
  int month;
};

struct RegisteredSales getSalesByDay(struct DateToSearch *dateToSearch);
void createSale(struct Sale *sale, int quantity);
struct RegisteredSales getAllSales();
int deleteSaleById(struct RegisteredSales *sales, int id);
void updateTXT(struct RegisteredSales *sales);
int updateSaleById(struct RegisteredSales *sales, int id);
struct Sale getNewSaleInformation();
#endif
