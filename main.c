#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

time_t t;
int totalEstacionamento = 0;

struct CarroPilha{
  int item[5];
  int topo;
  struct CarroPilha *proximo;
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
    printf("ERRO: O estacionamento esta cheio \n");
  }else{
    p->topo++;
    p->item[p->topo] = x;
    printf("O carro com placa %i entrou no estacionamento \n", x);
  }
};
int removeCarro(struct CarroPilha *p, int placa){
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
      printf("\n O carro com placa %d foi removido! \n", aux);
    }else{
      int control = 1;
      while(control){
        if (aux == placa)
        {
          p->topo--;
          printf("O carro com placa %d foi removido!", aux);
          valueAux = rand() % ((200 + 1) - 100) + 100;
          totalEstacionamento = totalEstacionamento + valueAux;
          printf("(Pagou R$ %d) \n", valueAux);
          control = 0;
          while(CarroPilha_Vazia(auxPilha) == 0){
            p->item[p->topo] = auxPilha->item[auxPilha->topo];
            printf("O carro com placa %d voltou para o estacionamento! \n", p->item[p->topo]);
            auxPilha->topo--;
          }
        }else{
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
}

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

void addFuncionarioMock(struct funcionarios *inicio, char * nomeL, int idadeL, int IDL)
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
float desempilhar(struct CarroPilha *p)
{

  float aux = p->item[p->topo];
  p->topo--;
  return aux;
}
int checarMeta()
{
  if (totalEstacionamento >= 300)
  {
    printf("Valor do portão obtido. Nenhum carro poderá mais entrar!");
    // removerTodos(p);
    return 1;
  }
  else
  {
    return 0;
  }
}
int main()
{

  int resp;
  int value;
  struct funcionarios lista_funcionarios;
  lista_funcionarios.proximo = NULL;

  struct CarroPilha *p = (struct CarroPilha *)malloc(sizeof(struct CarroPilha));
  CarroPilha_Inicia(p);
  addFuncionarioMock(&lista_funcionarios, "Adrian", 21, 1);
  addFuncionarioMock(&lista_funcionarios, "Andrey", 14, 2);
  addFuncionarioMock(&lista_funcionarios, "Taina", 20, 1);
  CarroPilha_Insere(p, 256);
  CarroPilha_Insere(p, 856);
  CarroPilha_Insere(p, 156);
  CarroPilha_Insere(p, 251);
  CarroPilha_Insere(p, 857);
  CarroPilha_Insere(p, 156);
  removeCarro(p, 156);
  removeCarro(p, 256);
  if (checarMeta() == 1){
    removeCarro(p, 857);
  }

    printf("Valor do cash do estacionamento: %d", totalEstacionamento);
  // while (&lista_funcionarios.proximo != NULL)
  // {
  //   printf("Nome: %s, ID: %d, Idade: %d \n", lista_funcionarios.proximo->nome, lista_funcionarios.proximo->ID, lista_funcionarios.proximo->idade);
  //   lista_funcionarios.proximo = lista_funcionarios.proximo->proximo;
  // }
  // addCarro(p);
  // printf("Deseja adicionar mais carros? Digite 1 para <SIM> e 2 para <NAO>: \n");
  // scanf("%d", &resp);
  // while (resp == 1)
  // {
  // addCarro(p);
  //   printf("Deseja adicionar mais carros? Digite 1 para <SIM> e 2 para <NAO>: \n");
  //   scanf("%d", &resp);
  // }
  // printf("Tamanho da pilha de carros: %d \n", p->topo + 1);
  // printf("Valor da pilha: %d", p->item[p->topo]);

  // int r = CarroPilha_Remove(p);
  // printf("\n %d", r);
  // CarroPilha_Insere(t, r);
  // printf("Tamanho da pilha de carros: %d \n", p->topo + 1);
  // printf("Valor da pilha t: %d", t->item[t->topo]);
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