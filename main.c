#include <stdio.h>
#include <stdlib.h>

#include "./include/products.h"
#include "./include/sales.h"
#include "./utils/utils.h"

// OPTION 1 ->
void registerNewSale()
{
  clearTerminal();
  srand(time(NULL));

  printf("Cadastro de venda.\n");
  printf("- - - - - - - - - - - -\n\n");
  printf("Identifique o cliente e adicione seus itens no sistema.\n");
  printf("Gere relatórios de venda, de clientes e de itens posteriormente no menu.\n\n");

  printf("Salvando..\n");

  struct Sale sale = getNewSaleInformation();
  createSale(&sale, sale.saleList.count);

  printf("\n-----\n");

  struct tm *formattedDate = gmtime(&sale.date);
  struct DateToSearch dateToSearch = {
      .day = formattedDate->tm_mday,
      .month = formattedDate->tm_mon,
  };
  struct RegisteredSales registeredSales = getSalesByDay(&dateToSearch);

  int totalSoldProducts = 0;
  for (int i = 0; i < registeredSales.count; i++)
  {
    for (int j = 0; j < registeredSales.sales[i].saleList.count; j++)
    {
      totalSoldProducts += registeredSales.sales[i].saleList.items[j].quantity;
    }
  }

  printf("\n\n Total de itens vendidos no dia: %d\n", totalSoldProducts);
}

void alterSale()
{
  struct RegisteredSales registeredSales = getAllSales();

  if (registeredSales.count == 0)
  {
    printf("Sem vendas cadastradas por enquanto.\n");
    return;
  }

  int id;
  printf("Digite o id da venda a alterar:");
  scanf(" %d", &id);

  int isUpdateSuccessfull = updateSaleById(&registeredSales, id);

  if (isUpdateSuccessfull)
  {
    updateTXT(&registeredSales);
  }
}

void deleteSale()
{
  struct RegisteredSales registeredSales = getAllSales();

  if (registeredSales.count == 0)
  {
    printf("Sem vendas cadastradas por enquanto.\n");
    return;
  }

  int id;
  printf("Digite o id da venda a excluir:");
  scanf(" %d", &id);

  int isDeletinoSuccessfull = deleteSaleById(&registeredSales, id);

  if (isDeletinoSuccessfull)
  {
    updateTXT(&registeredSales);
  }
}

// OPTION 4 ->
void listAllSalesByDay()
{
  struct DateToSearch dateToSearch = getDateToSearchInput();
  struct RegisteredSales registeredSales = getSalesByDay(&dateToSearch);

  if (registeredSales.count == 0)
  {
    printf("Sem vendas nesse dia.");
    return;
  }

  if (registeredSales.count == 0)
  {
    printf("\nNenhuma venda registrada nesse dia.\n");
    return;
  }

  sortSales(&registeredSales);
  printSales(&registeredSales);
}

// OPTION 5 ->
void getRevenueByDay()
{
  struct DateToSearch dateToSearch = getDateToSearchInput();
  struct RegisteredSales registeredSales = getSalesByDay(&dateToSearch);

  if (registeredSales.count == 0)
  {
    printf("Sem vendas nesse dia.");
    return;
  }

  sortSales(&registeredSales);

  float totalRevenue = 0;

  for (int i = 0; i < registeredSales.count; i++)
  {
    printf("\nID da venda: %d\n", registeredSales.sales[i].id);
    printf("Valor Total da venda: %1.2f\n", registeredSales.sales[i].total);
    totalRevenue += registeredSales.sales[i].total;
  }

  printf("\nO valor total de vendas no dia %d/%d foi de: %.2f\n",
         dateToSearch.day, dateToSearch.month + 1, totalRevenue);
}

// OPTION 6 ->
void listMostSoldProducts()
{
  struct DateToSearch dateToSearch = getDateToSearchInput();
  struct RegisteredSales registeredSales = getSalesByDay(&dateToSearch);

  if (registeredSales.count == 0)
  {
    printf("Sem vendas nesse dia.");
    return;
  }

  struct ProductSalesSummary mostSoldProduct = getMostSoldProduct(&registeredSales);

  struct Product product = getProductByID(mostSoldProduct.id);
  printf("\nProduto mais vendido: %s (ID: %03d)\n", product.name, product.id);
  printf("Quantidade vendida: %d\n", mostSoldProduct.count);
}

// OPTION 7 ->
void listLessSoldProducts()
{
  struct DateToSearch dateToSearch = getDateToSearchInput();
  struct RegisteredSales registeredSales = getSalesByDay(&dateToSearch);

  if (registeredSales.count == 0)
  {
    printf("Sem vendas nesse dia.");
    return;
  }

  struct ProductSalesSummary mostSoldProduct = getLessSoldProduct(&registeredSales);

  struct Product product = getProductByID(mostSoldProduct.id);
  printf("\nProduto menos vendido: %s (ID: %03d)\n", product.name, product.id);
  printf("Quantidade vendida: %d\n", mostSoldProduct.count);
}

int main()
{
  clearTerminal();

  int isRunning = 1;
  printf("\n\nBem vindo ao sistema!\n");
  printf("---------------------\n");

  while (isRunning)
  {
    printf("\n- - - - Menu - - - - \n\n");

    int option;
    printf("1 - Cadastrar uma nova venda\n");
    printf("2 - Alterar uma venda pelo ID\n");
    printf("3 - Excluir uma venda pelo ID\n");
    printf("- - - - - - - - - - - -\n");
    printf("4 - Listagem de vendas no dia X\n");
    printf("5 - Faturamento de vendas no dia X\n");
    printf("- - - - - - - - - - - -\n");
    printf("6 - Produto mais vendido no dia X\n");
    printf("7 - Produto menos vendido no dia X\n");
    printf("- - - - - - - - - - - -\n");
    printf("8 - Sair");
    printf("\n\n- - - - - - - - - - \n\n");
    printf("-> ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      registerNewSale();
      break;
    case 2:
      alterSale();
      break;
    case 3:
      deleteSale();
      break;
    case 4:
      listAllSalesByDay();
      break;
    case 5:
      getRevenueByDay();
      break;
    case 6:
      listMostSoldProducts();
      break;
    case 7:
      listLessSoldProducts();
      break;
    case 8:
      isRunning = 0;
      break;
    default:
      break;
    }
  }

  return 0;
}