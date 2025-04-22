#include "utils.h"

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

void printSales(struct SaleList *saleList) {
  printf("\nTotal de vendas nesse dia: %d\n", saleList->count);

  for (int i = 0; i < saleList->count; i++) {
    printf("------------------\n");
    printf("ID da venda: %d\n", saleList->sale[i].id);
    printf("Quantidade de produtos diferentes comprados: %d\n",
           saleList->sale[i].totalProducts);
    printf("Valor Total da venda: %1.2f\n", saleList->sale[i].totalValue);
    printf("\nItens comprados:\n");
    printf(" id | qtd\n");

    for (int j = 0; j < saleList->sale[i].totalProducts; j++) {
      printf("%03d |", saleList->sale[i].products[j].productID);
      printf(" %d\n", saleList->sale[i].products[j].quantity);
    }
  }
}