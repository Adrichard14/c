#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//ARVORE
struct arvore
{
    int data;                   //arvore will store an integer
    struct arvore *right_child; // right child
    struct arvore *left_child;  // left child
};

struct arvore *new_arvore(int x)
{
    struct arvore *p;
    p = malloc(sizeof(struct arvore));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct arvore *insert(struct arvore *root, int x)
{
    //searching for the place to insert
    if (root == NULL)
        return new_arvore(x);
    else if (x > root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child, x);
    return root;
}

int busca(struct arvore *root, int x)
{
    int counter = 0;
    if (root == NULL || root->data == x) //if root->data is x then the element is found
        return counter;
    else if (x > root->data)
    { // x is greater, so we will busca the right subtree
        counter++;
        return busca(root->right_child, x);
    }
    else
    { //x is smaller than the data, so we will busca the left subtree
        counter++;
        return busca(root->left_child, x);
    }
}

int busca2(struct arvore *raiz, int valor)
{
    if (raiz == NULL)
        return 0;
    struct arvore *atual = raiz;
    while (atual != NULL)
    {
        if (valor == atual->data)
        {
            return 1;
        }
        if (valor > atual->data)
            atual = atual->right_child;
        else
            atual = atual->left_child;
    }
    return 0;
}

void inorder(struct arvore *root)
{
    if (root != NULL) // checking if the root is not null
    {
        inorder(root->left_child);  // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right_child); // visiting right child
    }
}

int search(struct arvore *root, const int data)
{
    int counter = 0;
    if (root == NULL)
        return counter;
    int r;
    struct arvore *cursor = root;
    while (cursor != NULL)
    {
        if (data > cursor->data)
        {
            r = 1;
        }
        else if (data < cursor->data)
        {
            r = -1;
        }
        else
            r = 0;
        if (r < 0)
            cursor = cursor->left_child;
        else if (r > 0)
            cursor = cursor->right_child;
        else
            return counter;
        counter++;
    }
    return counter;
}

struct arvore *find_minimum(struct arvore *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left_child != NULL)
        return find_minimum(root->left_child);
    return root;
}

struct arvore *delete (struct arvore *root, int x)
{
    if (root == NULL)
        return NULL;
    if (x > root->data)
        root->right_child = delete (root->right_child, x);
    else if (x < root->data)
        root->left_child = delete (root->left_child, x);
    else
    {
        if (root->left_child == NULL && root->right_child == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left_child == NULL || root->right_child == NULL)
        {
            struct arvore *temp;
            if (root->left_child == NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }
        else
        {
            struct arvore *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete (root->right_child, temp->data);
        }
    }
    return root;
}

//FIM ARVORE

time_t t;
int totalEstacionamento = 0;
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
        offer(x);
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
                    dequeue(placa);
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

//FILA

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
int size;

void offer(int placa)
{
    if (head == NULL)
    {
        head = (Node *)malloc(sizeof(Node));
        head->data = placa;
        tail = head;
    }
    else
    {
        Node *newNode = NULL;
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = placa;
        newNode->next = tail;
        tail->prev = newNode;
        tail = newNode;
    }
    size++;
}

Node *poll()
{
    Node *p = head;
    if (p == NULL)
    {
        return NULL;
    }
    head = head->prev;
    p->next = NULL;
    p->prev = NULL;

    size--;
    return p;
}

int search_queue(int placa)
{
    int count = 1;
    Node *tmp = head;
    Node *node = NULL;
    if (tmp->data == placa)
    {
        return count;
    }
    while ((node = poll()) != NULL)
    {
        if (node->data == placa)
        {
            return count;
        }
        count++;
    }
    return count;
}

void output()
{
    Node *p = head;

    printf("Head");
    Node *node = NULL;
    while ((node = poll()) != NULL)
    {
        printf("%i<-", node->data);
        printf("Tail\n");
    }
}

void dequeue(int value)
{
    Node *p = head;
    Node *temp = p;

    while (p->data != value)
    {
        p = &p->next;
    }
    if (p->data == value)
    {
        p->data = NULL;
        return;
    }
    return;
}

void freeMemory()
{
    Node *p = head;
    Node *temp = p;

    while (p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
}
// END FILA

int main()
{

    int binary_search_result, queue_result;
    struct arvore *root;
    root = new_arvore(20);

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
    
    CarroPilha_Insere(p, 256);
    insert(root, 256);

    CarroPilha_Insere(p, 244);
    insert(root, 244);

    CarroPilha_Insere(p, 233);
    insert(root, 233);
    
    CarroPilha_Insere(p, 255);
    insert(root, 255);

    CarroPilha_Insere(p, 256);
    insert(root, 256);

    CarroPilha_Insere(p, 258);
    insert(root, 258);

    CarroPilha_Insere(p, 104);
    insert(root, 104);

    removeCarro(p, 256, &lista_funcionarios, &lista_funcionarios_aux);
    delete (root, 256);

    removeCarro(p, 244, &lista_funcionarios, &lista_funcionarios_aux);
    delete (root, 244);

    removeCarro(p, 255, &lista_funcionarios, &lista_funcionarios_aux);
    delete (root, 255);

    if (checarMeta(p) == 0)
    {
        removeCarro(p, 104, &lista_funcionarios, &lista_funcionarios_aux);
        dequeue(104);
    }

    queue_result = search_queue(233);
    binary_search_result = search(root, 233);
    printf("%i resultado da busca em fila \n", queue_result);
    printf("%i resultado da busca em arvore binária", binary_search_result);
    output();
    freeMemory();
    free(p);
}