#include "sales_dao.h"

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

struct SaleRowList getSaleRegistersByDay(struct DateToSearch *dateToSearch) {
  FILE *file = fopen(SELL_FILE_PATH, "r");
  struct SaleRowList saleRowList;
  saleRowList.saleRow = malloc(sizeof(struct Sale) * 20);

  if (saleRowList.saleRow == NULL) {
    return saleRowList;
  }

  if (file == NULL) {
    return saleRowList;
  }

  struct SaleRow row;

  saleRowList.count = 0;
  while (fscanf(file, "%d %d %d %d %f %ld", &row.id, &row.productID,
                &row.productCount, &row.totalProductCount, &row.totalSaleValue,
                &row.saleDate) == 6) {

    struct tm *formattedDate = gmtime(&row.saleDate);

    if (formattedDate->tm_mday == dateToSearch->day &&
        formattedDate->tm_mon == dateToSearch->month) {

      saleRowList.saleRow[saleRowList.count].id = row.id;
      saleRowList.saleRow[saleRowList.count].productID = row.productID;
      saleRowList.saleRow[saleRowList.count].productCount = row.productCount;
      saleRowList.saleRow[saleRowList.count].saleDate = row.saleDate;
      saleRowList.saleRow[saleRowList.count].totalProductCount =
          row.totalProductCount;
      saleRowList.saleRow[saleRowList.count].totalSaleValue =
          row.totalSaleValue;
      saleRowList.count++;
    }
  }

  fclose(file);
  return saleRowList;
}

struct SaleList getSalesByDay(struct DateToSearch *dateToSearch) {
  FILE *file = fopen(SELL_FILE_PATH, "r");
  struct SaleList saleList;
  saleList.sale = malloc(sizeof(struct Sale) * 20);

  if (saleList.sale == NULL) {
    return saleList;
  }

  if (file == NULL) {
    return saleList;
  }

  struct SaleRow row;

  saleList.count = 0;

  int previousSaleID = 0;
  int currentSale = 0;
  while (fscanf(file, "%d %d %d %d %f %ld", &row.id, &row.productID,
                &row.productCount, &row.totalProductCount, &row.totalSaleValue,
                &row.saleDate) == 6) {

    struct tm *formattedDate = gmtime(&row.saleDate);

    if (formattedDate->tm_mday == dateToSearch->day &&
        formattedDate->tm_mon == dateToSearch->month) {

      if (previousSaleID != row.id) {
        saleList.count++;
        previousSaleID = row.id;
        currentSale = 0;

        saleList.sale[saleList.count - 1].products =
            malloc(sizeof(struct SaleProductData) * 20);

        saleList.sale[saleList.count - 1].id = row.id;
        saleList.sale[saleList.count - 1].products[currentSale].productID =
            row.productID;
        saleList.sale[saleList.count - 1].products[currentSale].quantity =
            row.productCount;
        saleList.sale[saleList.count - 1].saleDate = row.saleDate;
        saleList.sale[saleList.count - 1].totalProducts = row.totalProductCount;
        saleList.sale[saleList.count - 1].totalValue = row.totalSaleValue;
        currentSale++;
        continue;
      }

      saleList.sale[saleList.count - 1].products[currentSale].productID =
          row.productID;
      saleList.sale[saleList.count - 1].products[currentSale].quantity =
          row.productCount;
      currentSale++;
    }
  }

  fclose(file);
  return saleList;
}

void createSale(struct Sale *sale, int productCount) {
  FILE *file = fopen(SELL_FILE_PATH, "a");

  if (file == NULL) {
    printf("\nErro ao abrir o arquivo %s\n", SELL_FILE_PATH);
    return;
  }

  for (int i = 0; i < productCount; i++) {
    fprintf(file, "%d %03d %d %d %1.2f %ld\n", sale->id,
            sale->products[i].productID, sale->products[i].quantity,
            sale->totalProducts, sale->totalValue, sale->saleDate);
  }

  fclose(file);
  printf("\nVenda registrada com sucesso!\n");
}