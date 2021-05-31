#include<iostream>
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
// int findMin(Node *root){    //iterative approach
//     if(root == NULL){
//         printf("Tree is empty\n");
//         return -1;
//     }
//     while(root->left !=NULL){
//         root = root->left;
//     }
//     return root->data;
// }
// int findMax(Node *root){       //iterative approach
//     if(root == NULL){
//         printf("Tree is empty\n");
//         return -1;
//     }
//     while(root->right !=NULL){
//         root = root->right;
//     }
//     return root->data;
// }
int findMin(Node *root){          //recursive approach
    if(root == NULL){
        printf("Tree is empty\n");
        return -1;
    }
    if(root->left == NULL)
        return root->data;
    return findMin(root->left);
}
int findMax(Node *root){          //recursive approach
    if(root == NULL){
        printf("Tree is empty\n");
        return -1;
    }
    if(root->right == NULL)
        return root->data;
    return findMax(root->right);
}
void inOrderTraversal(Node *root){      //prints the elements of the BST in sorted order
    if(root == NULL)return;
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}


int main(){
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);
    root = insert(root, 11);
    inOrderTraversal(root);

}
