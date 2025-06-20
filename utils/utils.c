#include <stdlib.h>
#include "utils.h"
#include "../include/sales.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Map
{
  int id;
  int count;
};

struct Hashmap
{
  struct Map *map;
  int size;
};

int getMapIndex(struct Hashmap *hashmap, int id)
{
  for (int i = 0; i < hashmap->size; i++)
  {
    if (hashmap->map[i].id == id)
    {
      return i;
    }
  }

  return -1;
}

struct Hashmap getProductHashmap(struct RegisteredSales *registry)
{
  struct Hashmap hashmap = {
      .map = malloc(sizeof(struct Map) * (registry->count + 10)),
      .size = 0,
  };

  for (int i = 0; i < registry->count; i++)
  {
    for (int j = 0; j < registry->sales[i].saleList.count; j++)
    {
      int mapIndex = getMapIndex(&hashmap, registry->sales[i].saleList.items[j].productID);

      if (mapIndex == -1)
      {
        hashmap.map[hashmap.size].id = registry->sales[i].saleList.items[j].productID;
        hashmap.map[hashmap.size].count = registry->sales[i].saleList.items[j].quantity;
        hashmap.size++;
      }
      else
      {
        hashmap.map[mapIndex].count += registry->sales[i].saleList.items[j].quantity;
      }
    }
  }

  return hashmap;
}

struct ProductSalesSummary getLessSoldProduct(struct RegisteredSales *sales)
{
  struct Hashmap hashmap = getProductHashmap(sales);

  struct ProductSalesSummary lessSoldProduct = {
      .id = -1,
      .count = 9999999,
  };

  for (int j = 0; j < hashmap.size; j++)
  {
    if (hashmap.map[j].count < lessSoldProduct.count)
    {
      lessSoldProduct.count = hashmap.map[j].count;
      lessSoldProduct.id = hashmap.map[j].id;
    }
  }

  free(hashmap.map);

  return lessSoldProduct;
}

struct ProductSalesSummary getMostSoldProduct(struct RegisteredSales *sales)
{
  struct Hashmap hashmap = getProductHashmap(sales);

  struct ProductSalesSummary mostSoldProduct = {
      .id = -1,
      .count = 0,
  };

  for (int j = 0; j < hashmap.size; j++)
  {
    if (hashmap.map[j].count > mostSoldProduct.count)
    {
      mostSoldProduct.count = hashmap.map[j].count;
      mostSoldProduct.id = hashmap.map[j].id;
    }
  }

  free(hashmap.map);

  return mostSoldProduct;
}

struct DateToSearch getDateToSearchInput()
{
  struct DateToSearch dateToSearch;
  char input[10];
  int isValidInput = 0;

  char day[3];
  char month[3];

  while (!isValidInput)
  {
    printf("\nDigite o Dia abaixo para listar o relatório:\n");
    printf("Padrão da data aceito: dd/mm -> ");
    scanf(" %s", input);

    int letterCount = 0;
    for (int i = 0; i < 10; i++)
    {
      if (input[i] == '\0')
      {
        break;
      }
      letterCount++;
    }

    if (letterCount != 5)
    {
      printf("Número de caracteres errado.");
      printf("O padrão é dd/mm. Exemplo: 03/04");
      continue;
    }

    if (input[2] != '/')
    {
      printf("falta a barra.");
      continue;
    }

    strncpy(day, input, 2);
    day[2] = '\0';

    strncpy(month, input + 3, 2);
    month[2] = '\0';

    for (int j = 0; j < 3; j++)
    {
      if (j == 2)
      {
        isValidInput = 1;
        break;
      }

      if (!isdigit(day[j]))
      {
        printf("\nDia não é um dígito.\n");
        break;
      }

      if (!isdigit(month[j]))
      {
        printf("\nMês não é um dígito.");
        break;
      }
    }
  }

  dateToSearch.day = atoi(day);
  dateToSearch.month = atoi(month);
  dateToSearch.month -= 1;

  return dateToSearch;
}

void printSales(struct RegisteredSales *registered)
{
  printf("\nTotal de vendas: %d\n", registered->count);
  printf("- - - - - - - - - - - -\n\n");

  for (int i = 0; i < registered->count; i++)
  {
    printf("- - - - - - - - - - - -\n\n");
    printf("ID -> %d\n", registered->sales[i].id);
    printf("Quantidade de produtos diferentes comprados: %d\n",
           registered->sales[i].saleList.count);
    printf("ID do cliente: %s\n", registered->sales[i].clientID);
    printf("Valor Total da venda: %1.2f\n", registered->sales[i].total);
    printf("\nItens comprados:\n");
    printf(" id | qtd\n");

    int itemsCount = 0;

    for (int j = 0; j < registered->sales[i].saleList.count; j++)
    {
      printf("%03d |", registered->sales[i].saleList.items[j].productID);
      printf(" %d\n", registered->sales[i].saleList.items[j].quantity);
      itemsCount += registered->sales[i].saleList.items[j].quantity;
    }

    printf("\nQuantidade total de itens: %d\n", itemsCount);
    printf("- - - - - - - - - - - -\n\n");
  }
  return;
}

void printProducts(struct ProductList *list)
{
  printf("\nTabela de produtos:\n");
  printf("- - - - - - - - - - - -\n\n");
  printf("%4s | %15s | %7s | %30s \n", "id", "marca", "valor", "nome");
  for (int i = 0; i < list->count; i++)
  {
    printf("%4d | %15s | %7.2f | %30s \n", list->product[i].id,
           list->product[i].brand,
           list->product[i].price, list->product[i].name);
  }

  return;
}

void clearTerminal()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

struct tm extractTime(long int timestamp)
{
  time_t rawTime = (time_t)timestamp;
  struct tm formattedDate;

#ifdef _WIN32
  formattedDate = *localtime(&rawTime);
#else
  formattedDate = *gmtime(&rawTime);
#endif

  return formattedDate;
}

void cleanBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}

void sortSales(struct RegisteredSales *sales)
{
  for (int i = 0; i < sales->count - 1; i++)
  {
    for (int j = 0; j < sales->count - 1 - i; j++)
    {
      if (sales->sales[j].total < sales->sales[j + 1].total)
      {
        struct Sale temp = sales->sales[j];
        sales->sales[j] = sales->sales[j + 1];
        sales->sales[j + 1] = temp;
      }
    }
  }
}