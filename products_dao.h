#ifndef PRODUCTS_DAO
#define PRODUCTS_DAO
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct Product {
  int id;
  char name[50];
  char brand[50];
  float price;
};

struct ProductList {
  struct Product *product;
  int count;
  int capacity;
};

#define PRODUCT_LIST_PATH "data/products.txt"

struct ProductList getAllproducts();
struct Product getProductByID(int id);
void printProducts(struct ProductList *productList);
int verifyID(struct ProductList *productList, int id);
#endif