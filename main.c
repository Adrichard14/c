#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

time_t t;
int totalEstacionamento = 0;

// Tabela hash

// Hash* criarHash(int SIZE);
// void liberaHash(Hash* ha);
// int valorString (char *str);
// int insereHash_SemColisao(Hash* ha, struct CarroPilha p);
// int buscaHash_SemColisao(Hash* ha, int mat, struct CarroPilha* p);

struct hash
{
  int SIZE;
  int itens[20];
  int qtd;
};
typedef struct hash Hash;

Hash *criaHash(int SIZE)
{
  Hash *ha = (Hash*)malloc(sizeof(Hash*));
  if (ha != NULL)
  {
    int i;
    ha->SIZE = SIZE;
    ha->itens = (struct CarroPilha **)malloc(SIZE * sizeof(struct CarroPilha *));
    if (ha->itens == NULL)
    {
      free(ha);
      return NULL;
    }
    ha->qtd = 0;
    for (i = 0; i < ha->SIZE; i++)
      ha->itens[i] = NULL;
  }
  return ha;
}

void liberaHash(Hash *ha);

void liberaHash(Hash *ha)
{
  if (ha != NULL)
  {
    int i;
    for (i = 0; i < ha->SIZE; i++)
    {
      if (ha->itens[i] != NULL)
        free(ha->itens[i]);
    }
    free(ha->itens);
    free(ha);
  }
}

int insereHash_SemColisao(Hash *ha, struct CarroPilha p)
{
  if (ha == NULL || ha->qtd == ha->SIZE)
    return 0;
  int chave = p->item[p->topo];
  int pos = chaveDivisao(chave, ha->SIZE);
  struct CarroPilha *novo;
  novo = (struct CarroPilha *)malloc(sizeof(struct CarroPilha));
  if (novo == NULL)
    return 0;
  *novo = al;
  ha->itens[pos] = novo;
  ha->qtd++;
  return 1;
}

int buscaHash_SemColisao(Hash *ha, int mat, struct CarroPilha *p)
{
  if (ha == NULL)
    return 0;

  int pos = chaveDivisao(mat, ha->SIZE);
  if (ha->itens[pos] == NULL)
    return 0;
  *p = *(ha->itens[pos]);
  return 1;
}

struct CarroPilha
{
  int item[4];
  int topo;
  struct CarroPilha *proximo;
};
void CarroPilha_Inicia(struct CarroPilha *p)
{
  p->topo = -1;
};

int CarroPilha_Vazia(struct CarroPilha *p)
{
  if (p->topo == -1)
  {
    return 1;
  }
  else
    return 0;
};

int CarroPilha_Cheia(struct CarroPilha *p)
{
  if (p->topo == 3)
  {
    return 1;
  }
  else
  {
    return 0;
  }
};

void CarroPilha_Insere(struct CarroPilha *p, int x)
{
  if (CarroPilha_Cheia(p))
  {
    printf("ERRO: O estacionamento esta cheio \n");
  }
  else
  {
    p->topo++;
    p->item[p->topo] = x;
    printf("O carro com placa %i entrou no estacionamento \n", x);
  }
};

int CarroPilha_Remove(struct CarroPilha *p)
{
  int aux;
  if (CarroPilha_Vazia(p) == 1)
  {
    printf("ERRO: a pilha está vazia");
    exit(1);
  }
  else
  {
    aux = p->item[p->topo];
    p->topo--;
    printf("O carro com placa %d foi removido! \n", aux);
    return aux;
  }
};

struct funcionarios
{
  int ID, idade;
  char nome[10];
  struct funcionarios *proximo;
};

struct funcionarios *aloca()
{
  return malloc(sizeof(struct funcionarios));
};

void addFuncionario(struct funcionarios *inicio)
{
  struct funcionarios *aux, *novo;

  aux = inicio;

  while (aux->proximo != NULL)
  {
    aux = aux->proximo;
  }
  novo = aloca();

  printf("Digite o nome do funcionario: ");
  scanf("%s", &novo->nome);
  printf("Digite a idade do funcionario: ");
  scanf("%i", &novo->idade);
  printf("Digite o ID do funcionario: ");
  scanf("%i", &novo->ID);
  novo->proximo = NULL;

  aux->proximo = novo;
}

void removeFuncionario(struct funcionarios *inicio, struct funcionarios *inicio2)
{
  struct funcionarios *aux, *aux2, *novo;

  aux = inicio;
  aux2 = inicio2;
  novo = aloca();
  if (aux->proximo != NULL)
  {
    novo->proximo = aux->proximo;
    printf("Funcionario %s \n", &aux->proximo->nome);
    aux->proximo = aux->proximo->proximo;
  }
}

void addFuncionarioMock(struct funcionarios *inicio, char *nomeL, int idadeL, int IDL)
{
  struct funcionarios *aux, *novo;
  aux = inicio;

  while (aux->proximo != NULL)
  {
    aux = aux->proximo;
  }
  novo = aloca();
  sprintf(novo->nome, nomeL);
  novo->idade = idadeL;
  novo->ID = IDL;
  printf("Funcionario de nome %s cadastrado! (ID = %d, Idade = %d) \n", novo->nome, novo->ID, novo->idade);
  novo->proximo = NULL;

  aux->proximo = novo;
}

void addCarro(struct CarroPilha *p)
{
  int placa;
  printf("Digite a placa do carro que ira entrar no estacionamento: ");
  scanf("%i", &placa);
  CarroPilha_Insere(p, placa);
}
int removeCarro(struct CarroPilha *p, int placa, struct funcionarios *p1, struct funcionarios *p1aux)
{
  int aux;
  int valueAux;
  struct CarroPilha *auxPilha = (struct CarroPilha *)malloc(sizeof(struct CarroPilha));
  CarroPilha_Inicia(auxPilha);
  if (CarroPilha_Vazia(p) == 1)
  {
    printf("ERRO: a pilha está vazia");
    exit(1);
  }
  else
  {
    aux = p->item[p->topo];
    if (aux == placa)
    {
      p->topo--;
      printf(" O carro com placa %d foi removido!", aux);
      valueAux = rand() % ((150 + 1) - 100) + 100;
      totalEstacionamento = totalEstacionamento + valueAux;
      printf("(Pagou R$ %d)", valueAux);
    }
    else
    {
      int control = 1;
      while (control)
      {
        if (aux == placa)
        {
          p->topo--;
          printf("O carro com placa %d foi removido!", aux);
          valueAux = rand() % ((150 + 1) - 100) + 100;
          totalEstacionamento = totalEstacionamento + valueAux;
          printf("(Pagou R$ %d)", valueAux);
          control = 0;
          removeFuncionario(p1, p1aux);

          while (CarroPilha_Vazia(auxPilha) == 0)
          {
            int aux2 = auxPilha->item[auxPilha->topo];
            CarroPilha_Insere(p, aux2);
            // printf("O carro com placa %d voltou para o estacionamento! \n", p->item[p->topo]);
            auxPilha->topo--;
          }
        }
        else
        {
          printf("O carro com placa %d precisou ser manobrado! \n", aux);
          auxPilha->topo++;
          auxPilha->item[auxPilha->topo] = aux;
          p->topo--;
          aux = p->item[p->topo];
        }
      }
    }

    return aux;
  }
  free(auxPilha);
  free(&aux);
  free(&valueAux);
}
void removerTodos(struct CarroPilha *p)
{
  int valueAux;
  while (CarroPilha_Vazia(p) == 0)
  {
    printf(" O carro com placa %d foi removido!", p->item[p->topo]);
    valueAux = rand() % ((150 + 1) - 100) + 100;
    totalEstacionamento = totalEstacionamento + valueAux;
    printf("(Pagou R$ %d) \n", valueAux);
    p->topo--;
  }
}
int checarMeta(struct CarroPilha *p)
{
  if (totalEstacionamento >= 300)
  {
    printf("\n Valor do portao obtido. Nenhum carro podera mais entrar!\n");
    removerTodos(p);
    return 1;
  }
  else
  {
    return 0;
  }
}
int main()
{
  Hash *ha = criaHash(1427);
  int x = insereHash_SemColisao(ha, p);
  int z = buscaHash_SemColisao(ha, mat, &p);

  int resp;
  int value;
  struct funcionarios lista_funcionarios;
  lista_funcionarios.proximo = NULL;
  struct funcionarios lista_funcionarios_aux;
  lista_funcionarios_aux.proximo = NULL;
  struct CarroPilha *p = (struct CarroPilha *)malloc(sizeof(struct CarroPilha));
  CarroPilha_Inicia(p);
  addFuncionarioMock(&lista_funcionarios, "Adrian", 21, 1);
  addFuncionarioMock(&lista_funcionarios, "Andrey", 14, 2);
  addFuncionarioMock(&lista_funcionarios, "Taina", 20, 1);
  CarroPilha_Insere(p, 100);
  CarroPilha_Insere(p, 101);
  CarroPilha_Insere(p, 102);
  CarroPilha_Insere(p, 103);
  CarroPilha_Insere(p, 104);
  removeCarro(p, 102, &lista_funcionarios, &lista_funcionarios_aux);
  removeCarro(p, 101, &lista_funcionarios, &lista_funcionarios_aux);
  removeCarro(p, 100, &lista_funcionarios, &lista_funcionarios_aux);
  if (checarMeta(p) == 0)
  {
    removeCarro(p, 104, &lista_funcionarios, &lista_funcionarios_aux);
  }
  free(p);
}