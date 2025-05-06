// #include "utils.h"

// // struct Map {
// //   int id;
// //   int count;
// // };

// // struct Hashmap {
// //   struct Map *map;
// //   int size;
// // };

// // int getMapIndex(struct Hashmap *hashmap, int id) {
// //   for (int i = 0; i < hashmap->size; i++) {
// //     if (hashmap->map[i].id == id) {
// //       return i;
// //     }
// //   }

// //   return -1;
// // }

// // struct Hashmap getProductHashmap(struct SaleRowList *saleRowList) {
// //   struct Hashmap hashmap;
// //   hashmap.size = 0;
// //   hashmap.map = malloc(sizeof(struct Map) * saleRowList->count);

// //   for (int i = 0; i < saleRowList->count; i++) {
// //     int mapIndex = getMapIndex(&hashmap, saleRowList->saleRow[i].productID);

// //     if (mapIndex == -1) {
// //       hashmap.map[hashmap.size].id = saleRowList->saleRow[i].productID;
// //       hashmap.map[hashmap.size].count = 1;
// //       hashmap.size++;
// //     } else {
// //       hashmap.map[mapIndex].count++;
// //     }
// //   }

// //   return hashmap;
// // }

// // struct ProductCountData getLessSoldProduct(struct SaleRowList *saleRowList) {
// //   struct Hashmap hashmap = getProductHashmap(saleRowList);

// //   int lessSoldProductCount = 99999;
// //   int lessSoldProductId = -1;
// //   for (int j = 0; j < hashmap.size; j++) {
// //     if (hashmap.map[j].count < lessSoldProductCount) {
// //       lessSoldProductCount = hashmap.map[j].count;
// //       lessSoldProductId = hashmap.map[j].id;
// //     }
// //   }

// //   free(hashmap.map);

// //   struct ProductCountData mostSoldProduct;
// //   mostSoldProduct.id = lessSoldProductId;
// //   mostSoldProduct.count = lessSoldProductCount;

// //   return mostSoldProduct;
// // }

// // struct ProductCountData getMostSoldProduct(struct SaleRowList *saleRowList) {

// //   struct Hashmap hashmap = getProductHashmap(saleRowList);

// //   int mostSoldProductCount = 0;
// //   int mostSoldProductId = -1;
// //   for (int j = 0; j < hashmap.size; j++) {
// //     if (hashmap.map[j].count > mostSoldProductCount) {
// //       mostSoldProductCount = hashmap.map[j].count;
// //       mostSoldProductId = hashmap.map[j].id;
// //     }
// //   }

// //   free(hashmap.map);

// //   struct ProductCountData mostSoldProduct;
// //   mostSoldProduct.id = mostSoldProductId;
// //   mostSoldProduct.count = mostSoldProductCount;

// //   return mostSoldProduct;
// // }

// // struct DateToSearch getDateToSearchInput() {
// //   struct DateToSearch dateToSearch;

// //   printf("\nDigite o Dia abaixo para listar o relatório:\n");
// //   printf("Padrão da data: dd/mm -> ");
// //   char input[30];
// //   scanf("%s", input);
// //   sscanf(input, "%d/%d", &dateToSearch.day, &dateToSearch.month);
// //   dateToSearch.month -= 1;

// //   return dateToSearch;
// // }

// void printSales(struct SaleList *saleList) {
//   printf("\nTotal de vendas nesse dia: %d\n", saleList->count);
//   printf("- - - - - - - - - - - -\n\n");

//   for (int i = 0; i < saleList->count; i++) {
//     printf("ID -> %d\n", saleList->sale[i].id);
//     printf("Quantidade de produtos diferentes comprados: %d\n",
//            saleList->sale[i].productCount);
//     printf("Valor Total da venda: %1.2f\n", saleList->sale[i].total);
//     printf("\nItens comprados:\n");
//     printf(" id | qtd\n");

//     for (int j = 0; j < saleList->sale[i].list.count; j++) {
//       printf("%03d |", saleList->sale[i].list.product[j].id);
//       printf(" %d\n", saleList->sale[i].list.product[j].quantity);
//     }
//   }
// }

// void printProducts(struct ProductList *productList) {
//   printf("\nTabela de produtos:\n");
//   printf("- - - - - - - - - - - -\n\n");
//   printf("%4s | %15s | %7s | %30s \n", "id", "marca", "valor", "nome");
//   for (int i = 0; i < productList->count; i++) {
//     printf("%4d | %15s | %7.2f | %30s \n", productList->product[i].id,
//             productList->product[i].brand,
//            productList->product[i].price, productList->product[i].name);
//   }

//   return;
// }

// void clearTerminal() {
//   #ifdef _WIN32
//       system("cls");
//   #else
//       system("clear");
//   #endif
//   }