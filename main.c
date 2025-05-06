#include <stdio.h>

// #include "./include/products.h"
// #include "./include/sales.h"
#include "./utils/utils.h"

// void registerNewSale() {
//   clearTerminal();  

//   printf("Cadastro de venda.\n");
//   printf("- - - - - - - - - - - -\n\n");
//   printf("Adicione o email do cliente e seus itens no sistema.\n");
//   printf("Gere relatórios de venda, de clientes e de itens posteriormente no menu.\n\n");
  
  
//   struct ProductList productList = getAllproducts();
//   int isAddingProduct = 1;
//   int i = 0;
//   struct SaleRowTXT* saleRows = malloc(sizeof(struct SaleRowTXT) * 20);
//   char clientID[50];

//   printf("Adicione o email do cliente:");
//   printf("\n-> ");
//   scanf("%s", clientID);

//   while (isAddingProduct) {
//     saleRows[i].id = time(NULL) / 100000 * 2;
//     saleRows[i].date = time(NULL);
//     strcpy(saleRows[i].clientID, clientID);

//     printProducts(&productList);

//     int isProductValid = 0;
//     while (!isProductValid) {
//       printf("\nEscolha um produto por id para acrescentar à venda.");
//       printf("\n-> ");
//       scanf("%d", &saleRows[i].productID);
//       isProductValid = verifyProductID(&productList, saleRows[i].productID);
//     }

//     printf("\nQual quantidade vendida deste produto?");
//     printf("\n-> ");
//     scanf("%d", &saleRows[i].quantity);

//     struct Product product = getProductByID(saleRows[i].productID);
//     saleRows[i].productTotalValue = saleRows[i].quantity * product.price;

//     if (saleRows[i].quantity >= 3) {
//       printf("\nDesconto sendo aplicado ao produto.");
//       printf("\n-> ");
//       saleRows[i].productTotalValue *= 0.90;
//     }

//     printf("\nDeseja registrar a venda de mais um produto?");
//     printf("\n1 - Sim | Outra tecla - Não\n");
//     printf("\n-> ");
//     scanf("%d", &isAddingProduct);

//     if (isAddingProduct != 1) {
//       isAddingProduct = 0;
//     }

//     i++;
//   }

//   printf("Salvando..\n");
//   createSale(saleRows, i);

//   printf("\n-----\n");

//   struct tm *formattedDate = gmtime(&saleRows[0].date);
//   struct DateToSearch dateToSearch = {
//       .day = formattedDate->tm_mday,
//       .month = formattedDate->tm_mon,
//   };
//   struct SaleList saleList = getSalesByDay(&dateToSearch);
//   printSales(&saleList);
// }

// // void printSalesProducts(struct Sale *soldProducts, int soldProductsCount) {
// //   int itensCount = 0;

// //   printf("nome | marca | quantidade | Valor unitário | total | Data\n\n");

// //   for (int i = 0; i < soldProductsCount; i++) {
// //     printf("%s ", soldProducts[i].productName);
// //     printf("| %s ", soldProducts[i].productBrand);
// //     printf("| %d ", soldProducts[i].quantity);
// //     printf("| %.2f ", soldProducts[i].unitValue);
// //     printf("| %.2f ", soldProducts[i].totalValue);
// //     printf("| %ld", soldProducts[i].saleDate);
// //     printf("\n");

// //     itensCount += soldProducts[i].quantity;
// //   }

// //   printf("\nQuantidade total de vendas: %d \n", soldProductsCount);
// //   printf("\nQuantidade total de itens: %d \n", itensCount);
// // }

// // void listAllSalesByDay() {
// //   struct DateToSearch dateToSearch = getDateToSearchInput();
// //   struct SaleList saleList = getSalesByDay(&dateToSearch);
// //   printSales(&saleList);
// // }

// // void listMostSoldProducts() {
// //   struct DateToSearch dateToSearch = getDateToSearchInput();
// //   struct SaleRowList saleRowList = getSaleRegistersByDay(&dateToSearch);
// //   struct ProductCountData mostSoldProduct = getMostSoldProduct(&saleRowList);

// //   struct Product product = getProductByID(mostSoldProduct.id);
// //   printf("\nProduto menos vendido: %s (ID: %03d)\n", product.name, product.id);
// // }

// // void getRevenueByDay() {
// //   struct DateToSearch dateToSearch = getDateToSearchInput();
// //   struct SaleList saleList = getSalesByDay(&dateToSearch);
// //   float totalRevenue = 0;

// //   for (int i = 0; i < saleList.count; i++) {
// //     printf("\nID da venda: %d\n", saleList.sale[i].id);
// //     printf("Valor Total da venda: %1.2f\n", saleList.sale[i].totalValue);

// //     totalRevenue += saleList.sale[i].totalValue;
// //   }

// //   printf("\nO valor total da venda no dia %d/%d foi de: %.2f\n",
// //          dateToSearch.day, dateToSearch.month + 1, totalRevenue);
// // }

// // void listLessSoldProducts() {
// //   struct DateToSearch dateToSearch = getDateToSearchInput();
// //   struct SaleRowList saleRowList = getSaleRegistersByDay(&dateToSearch);
// //   struct ProductCountData lessSoldProduct = getLessSoldProduct(&saleRowList);
  
// //   struct Product product = getProductByID(lessSoldProduct.id);
// //   printf("\nProduto menos vendido: %s (ID: %03d)\n", product.name, product.id);
// // }

int main() {
  clearTerminal();
  int isRunning = 1;
  printf("\n\nBem vindo ao seu sistema de PetShop!\n");
  printf("---------------------\n");

  while (isRunning) {
    printf("\n- - - - Menu - - - - \n\n");

    int option;
    printf("1 - Cadastrar uma nova venda\n");
    printf("- - - - - - - - - - - -\n");
    printf("2 - Listagem de vendas no dia X\n");
    printf("3 - Faturamento de vendas no dia X\n");
    printf("- - - - - - - - - - - -\n");
    printf("4 - Produtos mais vendido no dia X\n");
    printf("5 - Produtos menos vendido no dia X\n");
    printf("- - - - - - - - - - - -\n");
    printf("6 - Sair");
    printf("\n\n- - - - - - - - - - \n\n");
    printf("-> ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      // registerNewSale();
      break;
    case 2:
      // listAllSalesByDay();
      break;
    case 3:
      // getRevenueByDay();
      break;
    case 4:
      // listMostSoldProducts();
      break;
    case 5:
      // listLessSoldProducts();
      break;
    case 6:
      isRunning = 0;
      break;
    default:
      break;
    }
  }

  return 0;
}