#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node* nodeCreate(int info)
{
    node *newNode = new node();
    newNode->data = info;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int info)
{
    if (root == NULL) 
        return nodeCreate(info);
    else if(root->data > info)
        root->left = insert(root->left, info);
    else 
        root->right = insert(root->right, info);
    
    return root;
}

node* search(node* headNode, int toFind)
{
    if (headNode == NULL || headNode->data == toFind)
        return headNode;
    else if (headNode->data < toFind)
        return search(headNode->right, toFind);
    else
        return search(headNode->left, toFind);
}

void traversePreOrder(node *root)
{
    if (root == NULL) return;
    traversePreOrder(root->left);
    cout << root->data << endl;
    traversePreOrder(root->right);
}

int pathLength(node *root, int len)
{
    if (root == NULL) 
        return 0;
    return pathLength(root->left, len + 1) + pathLength(root->right, len + 1) + len;
}

int main(void)
{
    node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (root == NULL)
            root = insert(root, a);
        else    
            insert(root, a);
    }

    int num; cin >> num;
    if (search(root, num) != NULL) cout << "found" << endl;
    else cout << "not found" << endl;

    traversePreOrder(root);
    cout << pathLength(root, 0) << endl;
}