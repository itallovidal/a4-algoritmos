# Trabalho A4 Algoritmos e Lab. de Programação
Desenvolvimento de um programa em C, que permita registrar as vendas diárias de uma loja de
roupas, imprimindo no final do dia, uma série de relatórios. 

- Data de Entrega: Segunda semana de maio
- Pontuação: 10,00

# Membros do Grupo

| Nome              | Matrícula      |
|-------------------|----------------|
| Itallo Vidal      | 1230114462     |
| Maria Eduarda     | 1240107648     |


# Requisitos Não - Funcionais:
✅ Cadastrar os seguintes dados por venda realizada: 
  - código do item, 
  - nome do item, 
  - marca do item, 
  - quantidade de itens,
  - preço unitário do item;

✅ O programa deverá atribuir um desconto de 10% do valor total da venda realizada para
cada item, sempre que a quantidade de itens vendidos for maior ou igual a três unidades;

✅ Após cada entrada de novo item, o programa deverá chamar uma função para calcular
automaticamente o preço pago na venda realizada para cada item registrado;

❌ Item mais vendido em uma determinada data informada pelo usuário;


❌ Quantidade total de itens vendidos no dia, no ato do registro da venda, ou seja, assim que finalizar aquela venda específica;
❌ Listar todas as vendas realizadas no dia, em ordem decrescente, ou seja, considerar a venda de maior valor prioritariamente, e assim por diante, até que todas sejam listadas. O usuário informará a data da venda;
❌ Faturamento bruto diário sob as vendas (o usuário digitará a data);
❌ Quantidade de clientes que realizaram compras naquele dia (o usuário digitará a data);

❌ Item menos vendido em uma determinada data informada pelo usuário.

❌ O programa também deverá calcular automaticamente a quantidade de clientes que
realizaram compras naquele dia.
❌ Quantidade total de itens vendidos no dia, no ato do registro da venda, ou seja, assim
que finalizar aquela venda específica;
❌ Listar todas as vendas realizadas no dia, em ordem decrescente, ou seja, considerar a
venda de maior valor prioritariamente, e assim por diante, até que todas sejam listadas.
O usuário informará a data da venda;
❌ Faturamento bruto diário sob as vendas (o usuário digitará a data);
❌ Quantidade de clientes que realizaram compras naquele dia (o usuário digitará a data);

**Linguagem de Programação:**
   - O sistema deve ser desenvolvido utilizando **Linguagem C**.
   - O programa deve permitir que o **usuário informe uma data** para consultar os relatórios.
   - O código deve ser organizado em funções para:
     - Cálculo de valor total
     - Aplicação de desconto
     - Geração de relatórios
     - Contagem de clientes, etc.
   - As informações devem ser armazenadas em **memória** durante a execução do programa, até a finalização do dia.

# Comandos úteis

Compila o programa:
```bash
gcc main.c sales_dao.c products_dao -o main
```

Roda o programa:
```bash
./ main
```
