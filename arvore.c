#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore
{
    int data;                 //arvore will store an integer
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

int busca2(struct arvore *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct arvore* atual = raiz;
    while (atual != NULL){
        if(valor == atual->data){
            return 1;
        }
        if(valor > atual->data)
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

int compare(int left,int right)
{
    if(left > right)
        return 1;
    if(left < right)
        return -1;
    return 0;
}

typedef int (*comparer)(int, int);

int search(struct arvore *root,const int data)
{
    int counter = 0;
    if(root == NULL)
        return counter;
    int r;
    struct arvore* cursor = root;
    while(cursor != NULL)
    {
        counter++;
        if(data > cursor->data){
            r = 1;
        }else if(data < cursor->data){
            r = -1;
        }else
            r = 0;
        if(r < 0)
            cursor = cursor->left_child;
        else if(r > 0)
            cursor = cursor->right_child;
        else
            return counter;
    }
    return counter;

}

int main()
{
    // int x = insere_ArvBin(raiz, valor);
    int t;
    struct arvore *root;
    root = new_arvore(20);

    insert(root, 5);
    insert(root, 1);
    insert(root, 15);
    insert(root, 9);
    insert(root, 7);
    inorder(root);
    printf("\n");
    t = search(root, 15);
    printf("%d", t);
}
