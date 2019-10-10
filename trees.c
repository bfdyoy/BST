#include "trees.h"

void Display(Node* root, int nivel)
{
    int i;
    if (root != 0)
    {
        Display(root->right, nivel + 1);
        for (i = 0; i <= nivel; i++)
            printf("      ");
        printf("%d\n", root->data);
        Display(root->left, nivel + 1);
    }
}

//programul va primi ca parametru numărul pe care trebuie să îl adauge
Node *Add_Node(Node *root,int data)
{
    //verificam mai intai dacă există o rădăcină (dacă arborele a fost creat)
//Alocam memorie pentru noul nod si stabilim valorile pentru data,left_child,right_child.

    if(root==NULL)
    {
        root=(Node *)malloc(sizeof(Node));
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data <= root->data)
    {
        root->left=Add_Node(root->left,data);//se aseaza in stanga parintelui daca este mai mic
    }
    else
    {
        root->right=Add_Node(root->right,data);//se aseaza in dreapta parintelui daca este mai mare
    }
    return root;
}
void preorder (Node *root)//RSD
{
    //daca nu s-a ajuns la ultimul nod
    if(root!=NULL)
    {
        //se viziteaza radacina
        printf("\n%d",root->data);
        //se viziteaza copilul din stanga apoi cel din dreapta
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node *root) //SRD
{
    //daca nu s-a ajuns la ultimul nod
    if(root!=NULL)
    {
        inorder(root->left);//se viziteaza copilul din stanga
        printf("\n%d",root->data);//se viziteaza radacina
        inorder(root->right);//se viziteaza copilul din dreapta
    }
}
void postorder(Node *root)
{
    if (root!=NULL)//daca nu s-a ajuns la ultimul nod
    {
        postorder(root->left);//se viziteaza copilul din dreapta
        postorder(root->right);//se viziteaza copilul din stanga
        printf("\n%d",root->data);//se viziteaza radacina
    }
}

Node* FindMin(Node* root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}
Node* Delete( Node *root, int data)
{
    if(root == NULL)
        return root;
    else if(data < root->data)
        root->left = Delete(root->left,data);

    else if (data > root->data)
        root->right = Delete(root->right,data);

    else
    {
        // Cazul 1:
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        //Cazul 2:
        else if(root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        // cazul 3:
        else
        {
            Node *temp = FindMin(root->right);//mergem in dreapta si cautam  nr minim
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}


int findNode(Node* root, int searchedData)
{
    int found = 0;
    Node *current = root;

    while((current != NULL) && (found == 0))
    {
        if (current->data == searchedData)
        {
            found = 1;
        }
        else if (searchedData > current->data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    return found;
}


Node *findMax(Node *root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}


void findSuccessor(Node *root, Node *&successor,int data)
{
    if(root == NULL)
    {
        successor = NULL;
        return;
    }
    // daca nodul este gasit, succesorul este valoarea minima a
    // subtree ului din dreapta, daca exista
    if(root->data == data)
    {
        if(root->right != NULL)
        {
            successor = FindMin(root->right);
        }
    }
    // daca data transmisa functiei are o valoare mai mica decat cea
    // memorata in root, se apeleaza functia recursiv pentru
    // subtree ul din stanga
    else if (data < root->data)
    {
        successor = root;
        findSuccessor(root->left, successor, data);
    }
    else
    {
        findSuccessor(root->right, successor, data);
    }
}


void findPredecessor(Node *root, Node *&predecessor, int data)
{
    // tree ul nu are niciun element
    if(root == NULL)
    {
        predecessor = NULL;
        return;
    }
    // if node with key s value is found, the predecessor is maximum
    // value node in its left subtree
    // daca nodul este gasit, predecesorul este valoarea maxima din
    // subtree ul din stanga
    if (root->data == data)
    {
        if(root->left != NULL)
        {
            predecessor = findMax(root->left);
        }
    }
    // daca data transmisa functiei are o valoare mai mare decat cea
    // memorata in root, se apeleaza functia recursiv pentru
    // subtree ul din dreapta
    else if (data > root->data)
    {
        // update predecesorului la nodul curent inaintea apelului recursiv
        // in subtree ul din dreapta
        predecessor = root;
        findPredecessor(root->right, predecessor, data);
    }
    else
    {
        findPredecessor(root->right, predecessor, data);
    }
}
