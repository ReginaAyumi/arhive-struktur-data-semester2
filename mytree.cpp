#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *root, *newNode;

class binarytree
{
public:
    int data;
    Node *left;
    Node *right;

    // Empty
    bool empty()
    {
        if (root == NULL)
            return true;
        else
            return false;
    }

    void createNewTree(int data)
    {
        if (root != NULL)
            cout << "\nTree sudah dibuat" << endl;
        else
        {
            root = new Node();
            root->data = data;
            root->left = NULL;
            root->right = NULL;
            cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
        }
    }

    Node *insertLeft(int data, Node *node)
    {
        if (root == NULL)
        {
            cout << "\nTree is empty!" << endl;
            return NULL;
        }
        else
        {
            if (node->left != NULL)
            {
                cout << "\nNode " << node->data << " sudah ada anak kiri!!" << endl;
                return NULL;
            }
            else
            {
                newNode = new Node();
                newNode->data = data;
                newNode->left = NULL;
                newNode->right = NULL;
                node->left = newNode;
                cout << "\nNode " << data << " berhasil ditambahkan ke anak kiri " << newNode->data << endl;
                return newNode;
            }
        }
    }

    Node *insertRight(int data, Node *node)
    {
        if (root == NULL)
        {
            cout << "\ntree is empty!" << endl;
            return NULL;
        }
        else
        {
            if (node->right != NULL)
            {
                cout << "\nNode " << node->data << " sudah ada anak kanan!!" << endl;
                return NULL;
            }
            else
            {
                newNode = new Node();
                newNode->data = data;
                newNode->left = NULL;
                newNode->right = NULL;
                node->right = newNode;
                cout << "\nNode " << data << " berhasil ditambahkan ke anak kanan " << newNode->data << endl;
                return newNode;
            }
        }
    }

    // Print tree

    void preOrder(Node *node = root)
    {

        if (!root)
            cout << "Buat tree terlebih dahulu!!" << endl;
        else
        {
            if (node != NULL)
            {
                cout << node->data << ", ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }
    }

    void inOrder(Node *node = root)
    {

        if (!root)
            cout << "Buat tree terlebih dahulu!!" << endl;
        else
        {
            if (node != NULL)
            {
                inOrder(node->left);
                cout << node->data << ", ";
                inOrder(node->right);
            }
        }
    }

    void postOrder(Node *node = root)
    {

        if (!root)
            cout << "Buat tree terlebih dahulu!!" << endl;
        else
        {
            if (node != NULL)
            {
                postOrder(node->left);
                postOrder(node->right);
                cout << node->data << ", ";
            }
        }
    }

    // delete tree

    void deleteTree(Node *node)
    {

        if (!root)
            cout << "\nBuat tree terlebih dahulu!!" << endl;
        else
        {
            if (node != NULL)
            {
                if (node != root)
                {
                    node->left = NULL;
                    node->right = NULL;
                }
                deleteTree(node->left);
                deleteTree(node->right);

                if (node == root)
                {
                    delete root;
                    root = NULL;
                }
                else
                {
                    delete node;
                }
            }
        }
    }
};

int main()
{
    binarytree bt;

    bt.createNewTree(1);

    Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = bt.insertLeft(2, root);
    nodeC = bt.insertRight(3, root);
    nodeD = bt.insertLeft(4, nodeB);
    nodeE = bt.insertRight(5, nodeB);
    nodeF = bt.insertLeft(6, nodeC);
    nodeG = bt.insertLeft(7, nodeE);
    nodeH = bt.insertRight(8, nodeE);
    nodeI = bt.insertLeft(9, nodeG);
    nodeJ = bt.insertRight(10, nodeG);
    nodeJ = bt.insertRight(11, nodeG);

    cout << "\n\n=== Print Tree ===" << endl;
    cout << "\nPreOrder :" << endl;
    bt.preOrder(root);
    cout << endl;
    cout << "InOrder :" << endl;
    bt.inOrder(root);
    cout << endl;
    cout << "PostOrder :" << endl;
    bt.postOrder(root);
    cout << endl;

    cout << "\nDelete tree" << endl;
    bt.deleteTree(root);

    cout << "\n=== Print Tree ===" << endl;
    cout << "\nPreOrder :" << endl;
    bt.preOrder(root);

    return 0;
}
