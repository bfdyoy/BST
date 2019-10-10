#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *left;
    struct _Node *right;
}
Node;

void Display(Node* root, int nivel);
Node *Add_Node(Node *root,int data);
void preorder (Node *root);
void inorder(Node *root);
void postorder(Node *root);
Node* FindMin(Node *root);
Node* Delete( Node *root, int data);
int findNode(Node *root, int searchedData); // de adaugat
Node *findMax(Node *root); // de adaugat
void findSuccessor(Node *root, Node *&successor, int data);
void findPredecessor (Node *root, Node *&predecessor, int data);

#endif // TREES_H_INCLUDED
