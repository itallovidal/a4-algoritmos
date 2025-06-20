#include "../include/sales.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

struct RegisteredSales getAllSales()
{
  struct RegisteredSales registeredSales = {
      .count = 0,
      .sales = malloc(sizeof(struct Sale) * 50),
  };

  FILE *file = fopen(SELL_FILE_PATH, "r");
  if (file == NULL)
  {
    return registeredSales;
  }

  if (registeredSales.sales == NULL)
  {
    return registeredSales;
  }

  struct SaleRowTXT row;
  int previousSaleID = -1;
  int currentSale = 0;

  while (fscanf(file, "%d %s %d %d %f %ld",
                &row.id,
                row.clientID,
                &row.productID,
                &row.quantity,
                &row.productTotalValue,
                &row.date) == 6)
  {

    int i;

    if (previousSaleID != row.id)
    {
      currentSale = 0;
      registeredSales.count++;
      i = registeredSales.count - 1;

      registeredSales.sales[i].id = row.id;
      strcpy(registeredSales.sales[i].clientID, row.clientID);
      registeredSales.sales[i].total = row.productTotalValue;
      registeredSales.sales[i].date = row.date;

      registeredSales.sales[i].saleList.count = 1;
      registeredSales.sales[i].saleList.items = malloc(sizeof(struct SaleItems) * 20);

      registeredSales.sales[i].saleList.items[0].productID = row.productID;
      registeredSales.sales[i].saleList.items[0].quantity = row.quantity;
      registeredSales.sales[i].saleList.items[0].productTotalValue = row.productTotalValue;

      currentSale++;
      previousSaleID = row.id;
      continue;
    }

    i = registeredSales.count - 1;

    registeredSales.sales[i].saleList.items[currentSale].productID = row.productID;
    registeredSales.sales[i].saleList.items[currentSale].productTotalValue = row.productTotalValue;
    registeredSales.sales[i].saleList.items[currentSale].quantity = row.quantity;

    registeredSales.sales[i].total += row.productTotalValue;
    registeredSales.sales[i].saleList.count++;

    currentSale++;
  }

  fclose(file);
  return registeredSales;
}

struct RegisteredSales getSalesByDay(struct DateToSearch *dateToSearch)
{
  struct RegisteredSales registeredSales = {
      .count = 0,
      .sales = malloc(sizeof(struct Sale) * 50),
  };

  FILE *file = fopen(SELL_FILE_PATH, "r");
  if (file == NULL)
  {
    return registeredSales;
  }

  if (registeredSales.sales == NULL)
  {
    return registeredSales;
  }

  struct SaleRowTXT row;
  int previousSaleID = -1;
  int currentSale = 0;

  while (fscanf(file, "%d %s %d %d %f %ld",
                &row.id,
                row.clientID,
                &row.productID,
                &row.quantity,
                &row.productTotalValue,
                &row.date) == 6)
  {

    struct tm formattedDate = extractTime(row.date);
    int i;

    if (formattedDate.tm_mday == dateToSearch->day &&
        formattedDate.tm_mon == dateToSearch->month)
    {

      if (previousSaleID != row.id)
      {
        currentSale = 0;
        registeredSales.count++;
        i = registeredSales.count - 1;

        registeredSales.sales[i].id = row.id;
        strcpy(registeredSales.sales[i].clientID, row.clientID);
        registeredSales.sales[i].total = row.productTotalValue;
        registeredSales.sales[i].date = row.date;

        registeredSales.sales[i].saleList.count = 1;
        registeredSales.sales[i].saleList.items = malloc(sizeof(struct SaleItems) * 20);

        registeredSales.sales[i].saleList.items[0].productID = row.productID;
        registeredSales.sales[i].saleList.items[0].quantity = row.quantity;
        registeredSales.sales[i].saleList.items[0].productTotalValue = row.productTotalValue;

        currentSale++;
        previousSaleID = row.id;
        continue;
      }

      i = registeredSales.count - 1;

      registeredSales.sales[i].saleList.items[currentSale].productID = row.productID;
      registeredSales.sales[i].saleList.items[currentSale].productTotalValue = row.productTotalValue;
      registeredSales.sales[i].saleList.items[currentSale].quantity = row.quantity;

      registeredSales.sales[i].total += row.productTotalValue;
      registeredSales.sales[i].saleList.count++;

      currentSale++;
    }
  }

  fclose(file);
  return registeredSales;
}

void createSale(struct Sale *sale, int quantity)
{
  FILE *file = fopen(SELL_FILE_PATH, "a");

  if (file == NULL)
  {
    printf("\nErro ao abrir o arquivo %s\n", SELL_FILE_PATH);
    return;
  }

  for (int i = 0; i < quantity; i++)
  {
    fprintf(file, "%d %s %d %d %1.2f %ld \n",
            sale->id,
            sale->clientID,
            sale->saleList.items[i].productID,
            sale->saleList.items[i].quantity,
            sale->saleList.items[i].productTotalValue,
            sale->date);
  }

  fclose(file);
  printf("Venda registrada com sucesso!\n");
}

int deleteSaleById(struct RegisteredSales *sales, int id)
{
  struct RegisteredSales updatedSales =
      {
          .count = 0,
          .sales = malloc(sales->count * sizeof(struct Sale))};

  int j = 0;
  for (int i = 0; i < sales->count; i++)
  {
    if (sales->sales[i].id != id)
    {
      updatedSales.sales[j] = sales->sales[i];
      updatedSales.count++;
      j++;
    }
  }

  if (sales->count == updatedSales.count)
  {
    printf("ID não encontrado. Vendas permanecem as mesmas.\n");
    return 0;
  }

  free(sales->sales);
  sales->sales = updatedSales.sales;
  sales->count = updatedSales.count;

  return 1;
}

void updateTXT(struct RegisteredSales *sales)
{
  const char *oldFile = SELL_FILE_PATH;
  int isDeletionFailed = remove(oldFile);

  if (isDeletionFailed != 0)
  {
    printf("Falha na atualizacao do arquivo de vendas.");
  }

  for (int i = 0; i < sales->count; i++)
  {
    createSale(&sales->sales[i], sales->sales[i].saleList.count);
  }

  printf("\nVendas atualizadas!");
}