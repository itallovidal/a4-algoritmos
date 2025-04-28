#ifndef PRODUCTS
#define PRODUCTS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct ProductList;

struct Product {
  int id;
  char name[50];
  char brand[50];
  float price;
};


#define PRODUCT_LIST_PATH "data/products.txt"

struct ProductList getAllproducts();
struct Product getProductByID(int id);
int verifyProductID(struct ProductList *productList, int id);
#endif