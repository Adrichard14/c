#include <stdio.h>
#include <stdlib.h>

struct CarroPilha{
  int item[5];
  int topo;
};
void CarroPilha_Inicia (struct CarroPilha *p) {
  p->topo = -1;
};

int CarroPilha_Vazia (struct CarroPilha *p){
  if(p->topo == -1){
    return 1;
  } else
      return 0;
};

int CarroPilha_Cheia (struct CarroPilha *p){
  if(p->topo == 4){
    return 1;
  }else{
    return 0;
  }
};

void CarroPilha_Insere(struct CarroPilha *p, int x){
  if(CarroPilha_Cheia(p)){
    printf("ERRO: O estacionamento está cheio");
    exit(1);
  }else{
    p->topo++;
    p->item[p->topo] = x;
  }
};

int CarroPilha_Remove(struct CarroPilha *p)
{
  int aux;
  if(CarroPilha_Vazia(p) == 1){
    printf("ERRO: a pilha está vazia");
    exit(1);
  }else{
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

int main()
{
  int resp;
  struct funcionarios lista_funcionarios;
  lista_funcionarios.proximo = NULL;

  struct CarroPilha *p = (struct CarroPilha *)malloc(sizeof(struct CarroPilha));
  CarroPilha_Inicia(p);


  CarroPilha_Insere(p, 1458);
  CarroPilha_Insere(p, 5444);
  CarroPilha_Insere(p, 1225);


  int aux;
  aux = CarroPilha_Remove(p);
 
  aux = CarroPilha_Remove(p);
  
  // addFuncionario(&lista_funcionarios);
  // printf("Deseja adicionar mais funcionários? Digite 1 para <SIM> e 2 para <NAO>: ");
  // scanf("%d", &resp);
  // printf("%d", resp);
  // while (resp == 1)
  // {
  //   addFuncionario(&lista_funcionarios);
  //   printf("Deseja adicionar mais funcionarios? Digite 1 para <SIM> e 2 para <NAO>: ");
  //   scanf("%d", &resp);
  // }
  // while (&lista_funcionarios.proximo != NULL)
  // {
  //   printf("Nome: %s, ID: %d, Idade: %d \n", lista_funcionarios.proximo->nome, lista_funcionarios.proximo->ID, lista_funcionarios.proximo->idade);
  //   lista_funcionarios.proximo = lista_funcionarios.proximo->proximo;
  // }
}