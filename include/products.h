#ifndef PRODUCTS
#define PRODUCTS

#define PRODUCT_LIST_PATH "data/products.txt"

struct ProductList
{
  struct Product *product;
  int count;
  int capacity;
};

struct Product
{
  int id;
  char name[50];
  char brand[50];
  float price;
};

struct ProductList getAllproducts();
struct Product getProductByID(int id);
int verifyProductID(struct ProductList *productList, char *prompt);
#endif