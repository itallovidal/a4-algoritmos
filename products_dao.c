#include "products_dao.h"

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

void printProducts(struct ProductList *productList) {
  printf("Tabela de produtos:\n");
  printf("id | nome | marca | valor\n");
  for (int i = 0; i < productList->count; i++) {
    printf("%03d | %s | %s | %1.2f\n", productList->product[i].id,
           productList->product[i].name, productList->product[i].brand,
           productList->product[i].price);
  }
}

int verifyID(struct ProductList *productList, int id) {
  for (int i = 0; i < productList->count; i++) {
    if (id == productList->product[i].id) {
      return 1;
    }
  }

  return 0;
}