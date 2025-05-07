#include "../include/products.h"
#include <stdio.h>
#include <stdlib.h>

struct ProductList getAllproducts() {
  FILE *file = fopen(PRODUCT_LIST_PATH, "r");
  struct ProductList list;
  list.capacity = 20;
  list.count = 0;
  list.product = NULL;

  if (file == NULL) {
    return list;
  }

  struct Product *product = malloc(sizeof(struct Product) * list.capacity);

  while (fscanf(file, "%d %s %s %f", &product[list.count].id,
                product[list.count].name, product[list.count].brand,
                &product[list.count].price) == 4) {

    list.count++;
  }

  fclose(file);

  list.product = product;

  return list;
}

struct Product getProductByID(int id) {
  struct ProductList productList = getAllproducts();
  for (int i = 0; i < productList.count; i++) {
    if (productList.product[i].id == id) {
      return productList.product[i];
      break;
    }
  }
}

int verifyProductID(struct ProductList *productList, int id) {
  for (int i = 0; i < productList->count; i++) {
    if (id == productList->product[i].id) {
      return 1;
    }
  }

  return 0;
}