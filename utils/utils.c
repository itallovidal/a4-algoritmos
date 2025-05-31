#include <stdlib.h>
#include "utils.h"
#include "../include/sales.h"
#include <stdio.h>

struct Map {
  int id;
  int count;
};

struct Hashmap {
  struct Map *map;
  int size;
};

int getMapIndex(struct Hashmap *hashmap, int id) {
  for (int i = 0; i < hashmap->size; i++) {
    if (hashmap->map[i].id == id) {
      return i;
    }
  }

  return -1;
}

struct Hashmap getProductHashmap(struct RegisteredSales *registry) {
  struct Hashmap hashmap = {
    .map = malloc(sizeof(struct Map) * (registry->count + 10)),
    .size = 0,
  };

  for (int i = 0; i < registry->count; i++) {
    for (int j = 0; j < registry->sales[i].saleList.count; j++) {
      int mapIndex = getMapIndex(&hashmap, registry->sales[i].saleList.items[j].productID);
  
      if (mapIndex == -1) {
        hashmap.map[hashmap.size].id = registry->sales[i].saleList.items[j].productID;
        hashmap.map[hashmap.size].count = registry->sales[i].saleList.items[j].quantity;
        hashmap.size++;
      } else {
        hashmap.map[mapIndex].count += registry->sales[i].saleList.items[j].quantity;
      }
    }
  }

  return hashmap;
}

struct ProductSalesSummary getLessSoldProduct(struct RegisteredSales *sales) {
  struct Hashmap hashmap = getProductHashmap(sales);

  struct ProductSalesSummary lessSoldProduct = {
    .id = -1,
    .count = 9999999,
  };

  for (int j = 0; j < hashmap.size; j++) {
    if (hashmap.map[j].count < lessSoldProduct.count) {
      lessSoldProduct.count = hashmap.map[j].count;
      lessSoldProduct.id = hashmap.map[j].id;
    }
  }

  free(hashmap.map);

  return lessSoldProduct;
}

struct ProductSalesSummary getMostSoldProduct(struct RegisteredSales *sales) {
  struct Hashmap hashmap = getProductHashmap(sales);

  struct ProductSalesSummary mostSoldProduct = {
    .id = -1,
    .count = 0,
  };

  for (int j = 0; j < hashmap.size; j++) {
    if (hashmap.map[j].count > mostSoldProduct.count) {
      mostSoldProduct.count = hashmap.map[j].count;
      mostSoldProduct.id = hashmap.map[j].id;
    }
  }

  free(hashmap.map);

  return mostSoldProduct;
}

struct DateToSearch getDateToSearchInput() {
  struct DateToSearch dateToSearch;

  printf("\nDigite o Dia abaixo para listar o relatório:\n");
  printf("Padrão da data: dd/mm -> ");
  char input[30];
  scanf("%s", input);
  sscanf(input, "%d/%d", &dateToSearch.day, &dateToSearch.month);
  dateToSearch.month -= 1;

  return dateToSearch;
}

void printSales(struct RegisteredSales *registered) {
  printf("\nTotal de vendas nesse dia: %d\n", registered->count);
  printf("- - - - - - - - - - - -\n\n");

  for (int i = 0; i < registered->count; i++) {
    printf("- - - - - - - - - - - -\n\n");
    printf("ID -> %d\n", registered->sales[i].id);
    printf("Quantidade de produtos diferentes comprados: %d\n",
           registered->sales[i].saleList.count);
    printf("ID do cliente: %s\n", registered->sales[i].clientID);
    printf("Valor Total da venda: %1.2f\n", registered->sales[i].total);
    printf("\nItens comprados:\n");
    printf(" id | qtd\n");

    int itemsCount = 0;

    for (int j = 0; j < registered->sales[i].saleList.count; j++) {
      printf("%03d |", registered->sales[i].saleList.items[j].productID);
      printf(" %d\n", registered->sales[i].saleList.items[j].quantity);
      itemsCount += registered->sales[i].saleList.items[j].quantity;
    }

    printf("\nQuantidade total de itens: %d\n", itemsCount);
    printf("- - - - - - - - - - - -\n\n");
  }
  return;
}

void printProducts(struct ProductList *list) {
  printf("\nTabela de produtos:\n");
  printf("- - - - - - - - - - - -\n\n");
  printf("%4s | %15s | %7s | %30s \n", "id", "marca", "valor", "nome");
  for (int i = 0; i < list->count; i++) {
    printf("%4d | %15s | %7.2f | %30s \n", list->product[i].id,
            list->product[i].brand,
           list->product[i].price, list->product[i].name);
  }

  return;
}

void clearTerminal() {
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
}

struct tm extractTime(long int timestamp) {
  time_t rawTime = (time_t)timestamp;
  struct tm formattedDate;

#ifdef _WIN32
  localtime_s(&formattedDate, &rawTime);
#else
  localtime_r(&formattedDate, &rawTime);
#endif

  return formattedDate;
}