#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;    
};

Node* getNewNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node *root, int data){
    if(root == NULL){
        root = getNewNode(data);
    }
    else if(data<=root->data){
        root->left = insert(root->left, data);
    }
    else
        root->right = insert(root->right, data);

    return root;
}
int findMin(Node *root){          //recursive approach
    if(root == NULL){
        printf("Tree is empty\n");
        return -1;
    }
    if(root->left == NULL)
        return root->data;
    return findMin(root->left);
}
void levelOrderTraversal(Node *root){
    queue<Node*> q;
    if(root == NULL)return;
    q.push(root);
    while(!q.empty()){
        Node *current = q.front();
        printf("%d ",current->data);
        if(current->left != NULL)q.push(current->left);
        if(current->right != NULL)q.push(current->right);
        q.pop();
    }
    printf("\n");
}
Node* deleteNode(Node *root, int data){
    if(root == NULL)return root;
    if(data<root->data)                         //delete in left subtree
        root->left = deleteNode(root->left,data);
    else if(data>root->data)                    //delete in right subtree
        root->right = deleteNode(root->right,data);
    else{                                       //element found.
        if(root->left == NULL && root->right == NULL){          //no child
        root = NULL;
        delete root;
    }
    else if(root->left == NULL){                                 //only right child
        Node *temp = root;
        root = root->right;
        delete temp;
    }
    else if(root->right == NULL){                               //only left child
        Node  *temp = root;
        root = root->left;
        delete temp;
    }
    else{                                                       //both childs
        root->data = findMin(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    
    }
     return root; 
}
int main(){
    Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 12);
    root = insert(root, 25);
    root = insert(root, 20);
    root = insert(root, 19);
    root = insert(root, 23);
    root = insert(root, 27);
    root = insert(root, 26);
    root = insert(root, 28);
    root = insert(root, 30);
    levelOrderTraversal(root);
    deleteNode(root, 25);
    levelOrderTraversal(root);  
    
}
