#include <stdio.h>


// .
typedef struct
{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void cadastrarProduto(Produto produtos[], int *quantidadeProdutos)
{

    if (*quantidadeProdutos >= 100)
    {
        printf("\n O estoque esta cheio! Nao foi possivel cadastrar mais produtos.\n");
        return;
    }
    int codigoNovo;
    int codigoExiste = 0;

    printf("\n Codigo: \n");
    scanf("%d", &codigoNovo);

    for (int i = 0; i < *quantidadeProdutos; i++)
    {
        if (produtos[i].codigo == codigoNovo)
        {
            codigoExiste = 1;
            break;
        }
    }

    if (codigoExiste == 1)
    {
        printf("\n O codigo %d ja existe! Nao foi possivel cadastrar o produto.\n", codigoNovo);
        return;
    }

    produtos[*quantidadeProdutos].codigo = codigoNovo;

    printf("\n Nome: \n");
    scanf(" %49[^\n]", produtos[*quantidadeProdutos].nome);

    printf("\n Preco: \n");
    scanf("%f", &produtos[*quantidadeProdutos].preco);

    printf("\n Quantidade: \n");
    scanf("%d", &produtos[*quantidadeProdutos].quantidade);

    printf("\n O produto %s foi cadastrado com sucesso!\n", produtos[*quantidadeProdutos].nome);

    (*quantidadeProdutos)++;
}

void listarProdutos(Produto produtos[], int quantidadeProdutos)
{

    if (quantidadeProdutos == 0)
    {
        printf("\nNao existem produtos para ser listados!\n");
    }
    else
    {
        for (int i = 0; i < quantidadeProdutos; i++)
        {
            printf("\nCodigo: %d\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Preco: %.2f\n", produtos[i].preco);
            printf("Quantidade: %d\n", produtos[i].quantidade);
        }
    }
}

void buscarProduto(Produto produtos[], int quantidadeProdutos)
{

    int codigoBusca;
    int encontrado = 0;

    printf("\n Digite o codigo do produto que deseja buscar: ");
    scanf("%d", &codigoBusca);

    for (int i = 0; i < quantidadeProdutos; i++)
    {
        if (produtos[i].codigo == codigoBusca)
        {
            printf("\n Produto encontrado!\n");
            printf("\nCodigo: %d\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Preco: %.2f\n", produtos[i].preco);
            printf("Quantidade: %d\n", produtos[i].quantidade);

            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0)
    {
        printf("\n O produto com o codigo %d nao foi encontrado!\n", codigoBusca);
    }
}

void alterarProduto(Produto produtos[], int quantidadeProdutos)
{

    printf("\n Alterar um produto\n");

    int codigoAlterar;
    int encontradoAlterar = 0;

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigoAlterar);

    for (int i = 0; i < quantidadeProdutos; i++)
    {

        if (produtos[i].codigo == codigoAlterar)
        {
            printf("\n Produto encontrado!\n");

            printf("Novo nome: ");
            scanf(" %49[^\n]", produtos[i].nome);

            printf("Novo preco: ");
            scanf("%f", &produtos[i].preco);

            printf("Nova quantidade: ");
            scanf("%d", &produtos[i].quantidade);

            printf("\n Produto alterado com sucesso!\n");

            encontradoAlterar = 1;
            break;
        }
    }
    if (encontradoAlterar == 0)
    {
        printf("\n O produto com o codigo %d nao foi encontrado!\n", codigoAlterar);
    }
}

void excluirProduto(Produto produtos[], int *quantidadeProdutos)
{

    int codigoExcluir;
    int encontradoExcluir = 0;

    printf("\n Digite o codigo do produto que deseja excluir: ");
    scanf("%d", &codigoExcluir);

    for (int i = 0; i < *quantidadeProdutos; i++)
    {

        if (produtos[i].codigo == codigoExcluir)
        {
            for (int j = i; j < *quantidadeProdutos - 1; j++)
            {
                produtos[j] = produtos[j + 1];
            }
            (*quantidadeProdutos)--;
            printf("\n O produto com o codigo %d foi excluido com sucesso!\n", codigoExcluir);
            encontradoExcluir = 1;
            break;
        }
    }
    if (encontradoExcluir == 0)
    {
        printf("\n O produto com o codigo %d nao foi encontrado!\n", codigoExcluir);
    }
}

int main()
{
    int opcao;
    Produto produtos[100];
    int quantidadeProdutos = 0;

    while (1)
    {
        printf("\nSistema de Estoque\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar os Produtos\n");
        printf("3 - Buscar Produtos\n");
        printf("4 - Alterar Produtos\n");
        printf("5 - Excluir Produtos\n");
        printf("0 - Sair\n");
        printf("Digite a opcao que deseja: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarProduto(produtos, &quantidadeProdutos);
            break;

        case 2:
            printf("\nLista de Produtos\n");

            listarProdutos(produtos, quantidadeProdutos);

            break;

        case 3:
            printf("\nBuscar um produto\n");

            buscarProduto(produtos, quantidadeProdutos);

            break;

        case 4:
            printf("\nAlterar um produto\n");

            alterarProduto(produtos, quantidadeProdutos);

            break;

        case 5:
            printf("\nExcluir um produto\n");

            excluirProduto(produtos, &quantidadeProdutos);
            break;

        case 0:
            printf("\nEncerrando o Programa...\n");
            return 0;

        default:
            printf("\nA opcao digitada e invalida, tente novamente!\n");
        }
    }
}