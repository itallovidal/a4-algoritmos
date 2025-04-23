#include "products_dao.h"
#include "sales_dao.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printSalesProducts(struct Sale *soldProducts, int soldProductsCount) {
  int itensCount = 0;

  // printf("nome | marca | quantidade | Valor unitário | total | Data\n\n");

  // for (int i = 0; i < soldProductsCount; i++) {
  //   printf("%s ", soldProducts[i].productName);
  //   printf("| %s ", soldProducts[i].productBrand);
  //   printf("| %d ", soldProducts[i].quantity);
  //   printf("| %.2f ", soldProducts[i].unitValue);
  //   printf("| %.2f ", soldProducts[i].totalValue);
  //   printf("| %ld", soldProducts[i].saleDate);
  //   printf("\n");

  //   itensCount += soldProducts[i].quantity;
  // }

  // printf("\nQuantidade total de vendas: %d \n", soldProductsCount);
  // printf("\nQuantidade total de itens: %d \n", itensCount);
}

// void showSoldProducts() {
//   int soldProductsCount = 0;
//   struct Sale *soldProducts = malloc(sizeof(struct Sale) * 10);

//   getAllSoldProducts(soldProducts, &soldProductsCount);
//   printSalesProducts(soldProducts, soldProductsCount);
// }

void registerNewSale() {
  struct ProductList productList = getAllproducts();
  int isAddingProduct = 1;

  struct Sale sale;
  sale.products = malloc(sizeof(struct SaleProductData) * 20);
  sale.totalProducts = 0;

  while (isAddingProduct) {
    printProducts(&productList);

    int isProductValid = 0;
    int chosenID;
    while (!isProductValid) {
      printf("Escolha um produto por id para acrescentar à venda.\n");
      scanf("%d", &chosenID);
      isProductValid = verifyID(&productList, chosenID);
    }

    printf("\nQual quantidade vendida deste produto?");
    scanf("%d", &sale.products[sale.totalProducts].quantity);

    sale.products[sale.totalProducts].productID = chosenID;
    sale.id = time(NULL) / 1000;
    sale.saleDate = time(NULL);
    sale.totalProducts++;
    sale.totalValue = 0;

    for (int i = 0; i < productList.count; i++) {
      if (productList.product[i].id == chosenID) {
        sale.totalValue +=
            productList.product[i].price * sale.products->quantity;
        break;
      }
    }

    printf("\n\nDeseja registrar a venda de mais um produto?");
    printf("\n1 - Sim");
    printf("\nOutra tecla - Não");
    printf("\n");
    scanf("%d", &isAddingProduct);

    if (isAddingProduct != 1) {
      isAddingProduct = 0;
    }
  }

  if (sale.totalProducts >= 3) {
    printf("Desconto sendo aplicado!");
    sale.totalValue = sale.totalValue * 0.90;
  }

  printf("\nSalvando..\n");
  createSale(&sale, sale.totalProducts);
}

void listAllSalesByDay() {
  struct DateToSearch dateToSearch = getDateToSearchInput();
  struct SaleList saleList = getSalesByDay(&dateToSearch);
  printSales(&saleList);
}

void listMostSoldProducts() {
  struct DateToSearch dateToSearch = getDateToSearchInput();
  struct SaleRowList saleRowList = getSaleRegistersByDay(&dateToSearch);
  struct MostSoldProduct mostSoldProduct = getMostSoldProduct(&saleRowList);

  printf("\nProduto mais vendido: %03d\n", mostSoldProduct.id);
}

int main() {
  int isRunning = 1;
  printf("Bem vindo ao seu sistema de PetShop!");

  while (isRunning) {
    printf("\nMenu->\n");

    int option;
    printf("1 - Cadastrar uma nova venda\n");
    printf("- - - - - - - - - - - -\n");
    printf("Relatório de Vendas\n");
    printf("2 - Listagem de vendas no dia X\n");
    printf("- - - - - - - - - - - -\n");
    printf("Relatório de Produtos\n");
    printf("3 - Produtos mais vendido no dia X\n");
    printf("4 - Produtos menos vendido no dia X\n");
    printf("- - - - - - - - - - - -\n");
    printf("5 - Sair\n");
    printf("-> ");
    scanf("%d", &option);
    printf("\n");

    switch (option) {
    case 1:
      registerNewSale();
      break;
    case 2:
      listAllSalesByDay();
      break;
    case 3:
      listMostSoldProducts();
      break;
    case 4:
      isRunning = 0;
      break;
    default:
      break;
    }
  }

  return 0;
}