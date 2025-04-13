# Trabalho A4 Algoritmos e Lab. de Programação
Desenvolvimento de um programa em C, que permita registrar as vendas diárias de uma loja de
roupas, imprimindo no final do dia, uma série de relatórios. 

- Data de Entrega: Segunda semana de maio
- Pontuação: 10,00

# Membros do Grupo

| Nome              | Matrícula      |
|-------------------|----------------|
| Itallo Vidal      | 1230114462    |
| Nome Sobrenome    | [Matrícula]    |

# Requisitos Funcionais:
### [ ❌ ] **Cadastro de Vendas:** 
Registrar os seguintes dados por venda realizada:
- Código do item
- Nome do item
- Marca do item
- Quantidade de itens
- Preço unitário do item

### [ ❌ ] **Cálculo do Valor Total da Venda:**
   - Após cada entrada de novo item, o programa deve chamar uma função para calcular automaticamente o valor total da venda.

### [ ❌ ] **Desconto Condicional:**
   - Aplicar automaticamente **10% de desconto** no valor total da venda quando a quantidade for **maior ou igual a 3 unidades**.

### [ ❌ ] **Cálculo de Clientes por Dia:**
   - O programa deve calcular automaticamente o número de clientes que realizaram compras em uma determinada data.

### [ ❌ ] **Relatórios Gerenciais (por data):**
   - Quantidade total de itens vendidos no dia (ao finalizar cada venda).
   - Lista de todas as vendas realizadas na data, **em ordem decrescente de valor**.
   - Faturamento bruto diário das vendas realizadas na data.
   - Quantidade de clientes que compraram na data.
   - Item mais vendido na data.
   - Item menos vendido na data.

### **Encerramento do Programa:**
   - O programa deverá ser encerrado ao final do dia (quando não houver novos clientes), gerando os relatórios acima.

# Requisitos Não - Funcionais:

**Linguagem de Programação:**
   - O sistema deve ser desenvolvido utilizando **Linguagem C**.

2. **Usabilidade:**
   - O programa deve permitir que o **usuário informe uma data** para consultar os relatórios.

3. **Organização e Modularidade:**
   - O código deve ser organizado em funções para:
     - Cálculo de valor total
     - Aplicação de desconto
     - Geração de relatórios
     - Contagem de clientes, etc.

4. **Eficiência:**
   - As vendas devem ser ordenadas de forma eficiente para exibição decrescente por valor.

5. **Persistência Temporária:**
   - As informações devem ser armazenadas em **memória** durante a execução do programa, até a finalização do dia.

# Comandos úteis

Compila o programa:
```bash
gcc main.c -o main
```

Roda o programa:
```bash
./ main
```
