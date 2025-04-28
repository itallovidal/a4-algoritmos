#include "sales.h"
#include "products.h" 

// void getAllSoldProducts(struct Sale *soldProducts, int *soldProductsCount) {
//   FILE *file = fopen(SELL_FILE_PATH, "r");

//   if (file == NULL) {
//     return;
//   }

//   while (fscanf(file, "%s %s %d %f %f %ld",
//                 soldProducts[*soldProductsCount].productName,
//                 soldProducts[*soldProductsCount].productBrand,
//                 &soldProducts[*soldProductsCount].quantity,
//                 &soldProducts[*soldProductsCount].unitValue,
//                 &soldProducts[*soldProductsCount].totalValue,
//                 &soldProducts[*soldProductsCount].saleDate) != EOF) {

//     (*soldProductsCount)++;
//   }

//   fclose(file);
// }

// struct SaleRowList getSaleRegistersByDay(struct DateToSearch *dateToSearch) {
//   FILE *file = fopen(SELL_FILE_PATH, "r");
//   struct SaleRowList saleRowList;
//   saleRowList.saleRow = malloc(sizeof(struct Sale) * 20);

//   if (saleRowList.saleRow == NULL) {
//     return saleRowList;
//   }

//   if (file == NULL) {
//     return saleRowList;
//   }

//   struct SaleRow row;

//   saleRowList.count = 0;
//   while (fscanf(file, "%d %d %d %d %f %ld", &row.id, &row.productID,
//                 &row.productCount, &row.totalProductCount, &row.totalSaleValue,
//                 &row.saleDate) == 6) {

//     struct tm *formattedDate = gmtime(&row.saleDate);

//     if (formattedDate->tm_mday == dateToSearch->day &&
//         formattedDate->tm_mon == dateToSearch->month) {

//       saleRowList.saleRow[saleRowList.count].id = row.id;
//       saleRowList.saleRow[saleRowList.count].productID = row.productID;
//       saleRowList.saleRow[saleRowList.count].productCount = row.productCount;
//       saleRowList.saleRow[saleRowList.count].saleDate = row.saleDate;
//       saleRowList.saleRow[saleRowList.count].totalProductCount =
//           row.totalProductCount;
//       saleRowList.saleRow[saleRowList.count].totalSaleValue =
//           row.totalSaleValue;
//       saleRowList.count++;
//     }
//   }

//   fclose(file);
//   return saleRowList;
// }

struct SaleList getSalesByDay(struct DateToSearch *dateToSearch) {
  struct SaleList saleList;

  FILE *file = fopen(SELL_FILE_PATH, "r");
  if (file == NULL) {
    return saleList;
  }

  saleList.sale = malloc(sizeof(struct Sale) * 20);
  saleList.count = 0;

  if (saleList.sale == NULL) {
    return saleList;
  }

  struct SaleRowTXT row;

  int previousSaleID = -1;
  int currentSale = 0;

  while (fscanf(file, "%d %d %d %d %f %ld", &row.id, &row.productID,
                &row.quantity, &row.productTotalValue, row.clientID, &row.date ) == 6) {

    struct tm *formattedDate = gmtime(&row.date);
    int i;

    if (formattedDate->tm_mday == dateToSearch->day &&
        formattedDate->tm_mon == dateToSearch->month) {

      if (previousSaleID != row.id) {
        currentSale = 0;
        saleList.count++;
        i = saleList.count - 1;
        
        saleList.sale[i].id = row.id;
        strcpy(saleList.sale[i].clientID, row.clientID);
        saleList.sale[i].productCount++;
        saleList.sale[i].total = row.productTotalValue;
        saleList.sale[i].date = row.date;

        saleList.sale[i].list.product =
            malloc(sizeof(struct ProductList) * 20);

        saleList.sale[i].list.product[0] = getProductByID(row.productID);
        currentSale++;

        saleList.sale[i].list.count = currentSale;
        previousSaleID = row.id;
        continue;
      }

      i = saleList.count - 1;

      struct Product product = 
      saleList.sale[i].list.product[currentSale] = getProductByID(row.productID);

      saleList.sale[i].total += row.productTotalValue;
      saleList.sale[i].productCount++;

      currentSale++;
    }
  }

  fclose(file);
  return saleList;
}

void createSale(struct SaleRowTXT *rows, int quantity) {
  FILE *file = fopen(SELL_FILE_PATH, "a");

  printf("quantidade: %d\n", quantity);

  if (file == NULL) {
    printf("\nErro ao abrir o arquivo %s\n", SELL_FILE_PATH);
    return;
  }

  for (int i = 0; i < quantity; i++) {
    fprintf(file, "%d %03d %d %1.2f %s %ld\n", rows[i].id, rows[i].productID,
            rows[i].quantity, rows[i].productTotalValue, rows[i].clientID,
            rows[i].date);
  }

  fclose(file);
  printf("Venda registrada com sucesso!\n");
}