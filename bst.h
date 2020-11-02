#include <iostream>
#include <string>
#ifndef BST_H_
#define BST_H_
using namespace std;

//Definir clase BST con estructura Nodo y metodos
class BST
{
    private:
        struct Node
        {
            string letter;
            int value;
            Node *left;
            Node *right;
        };

        Node *root;

        void insert(Node *&, Node *&, string);
        void inorder(Node *) const;

public:
        BST()
        {
            root = NULL;
        }
        void insertN(string);
        void remove(int);
        void inorder() const
        {
            inorder(root);
        }
};

//Metodo para agregar elementos al BST, para funcionalidal del metodo 
//Agregar nodo
void BST::insert(Node *&nodePtr, Node *&newNode, string letter)
{

    if (nodePtr == NULL)
    {
        Node *newTreeNode = new Node;
        newTreeNode->letter = letter;
        newTreeNode->value = 1;
        newTreeNode->left = newTreeNode->right = NULL;
        if(newNode->letter > newTreeNode->letter)
            newNode->left = newTreeNode;
        else
            newNode->right = newTreeNode;
    }
    else if (nodePtr->letter > letter)
        insert(nodePtr->left, nodePtr, letter);
    else if (nodePtr->letter < letter)
        insert(nodePtr->right, nodePtr, letter);
    else if (nodePtr->letter == letter)
        nodePtr->value += 1;
}

//Metodo para agregar nodos o registros al BST
void BST::insertN(string letter)
{
    if (root == NULL)
    {
        root = new Node;
        root->letter = letter;
        root->value = 1;
        root->left = root->right = NULL;
    }
    else if(root->letter > letter)
        insert(root->left, root, letter);
    else if(root->letter < letter)
        insert(root->right, root, letter);
    else if(root->letter == letter)
        root->value += 1;
}

//Metodo de correcta impresion
void BST::inorder(Node *nodePtr) const
{
    if (nodePtr)
    {
        inorder(nodePtr->left);
        cout << nodePtr->letter << " found " << nodePtr->value << " times "<<endl;
        inorder(nodePtr->right);
    }
}
#endif /* BST_H_ */
