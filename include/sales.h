#ifndef SALES
#define SALES
#include <time.h>

// Modelo da venda
// esse modelo representa o conjunto das 
// informações de uma venda unidas

// id   | clientID  | productID | quantity  | productTotalValue | date
// 1    | a@.com    | 1         | 2         | 10.00             | 1745730332
// 1    | a@.com    | 2         | 1         | 05.00             | 1745730332

// {
//     id: 1,
//     clientID: "a@.com",
//     productList: {
//         count: 2,
//         list: [
//             { productID: 1, quantity: 2, productTotalValue: 10.00 },
//             { productID: 2, quantity: 1, productTotalValue: 5.00 }
//         ]
//     },
//     total: 15.00,
//     date: 1745730332
// }

struct SaleItems {
  int productID;
  int quantity;
  float productTotalValue;
};

struct SaleList {
  int count;
  struct SaleItems* items;
};

struct Sale {
  int id;
  char clientID[50];
  struct SaleList saleList;
  float total;
  time_t date;
};

#endif

// struct ProductDataInList{
//   int id;
//   char name[50];
//   char brand[50];
//   float price;
//   int quantity;
//   float total;
// };

// // Modelo da venda para txt
// // esse modelo representa como uma venda
// // será registrada no txt

// // cada produto será registrado em uma linha
// // depois será agrupado pelo id da venda 

// struct SaleRowTXT {
//   int id;
//   int productID;
//   int quantity;
//   float productTotalValue;
//   char clientID[50];
//   time_t date;
// };

// // ---

// struct DateToSearch {
//   int day;
//   int month;
// };


// struct SaleRowList {
//   struct SaleRow *saleRow;
//   int count;
// };

// #define SELL_FILE_PATH "data/sales.txt"

// struct SaleRowList getSaleRegistersByDay(struct DateToSearch *dateToSearch);
// void getAllSoldProducts(struct Sale *soldProducts, int *soldProductsCount);
// struct SaleList getSalesByDay(struct DateToSearch *dateToSearch);
// void createSale(struct SaleRowTXT *rows, int quantity);

