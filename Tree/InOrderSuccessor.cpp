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
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* insert(Node *root, int data){
    if(root == NULL){
        root = getNewNode(data);
    }
    else if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
void printSorted(Node *root){
    if(root == NULL)return;
        printSorted(root->left);
        printf("%d ",root->data);
        printSorted(root->right);        
}
Node* findMin(Node *root){
    if(root == NULL)return root;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
Node* search(Node *root, int data){
    if(root == NULL)return root;
    else if(data == root->data)return root;
    else if(data<root->data)
        return search(root->left, data);
    else
        return search(root->right, data);    
}
Node* inOrderSuccesor(Node *root, int data){
    Node *current = search(root, data);
    if(current == NULL)return current;
    if(current->right != NULL)             //there is a right subtree
        return findMin(current->right);
    else{                                  //there is no right subtree
        Node *ancestor = root;
        Node *successor = NULL;
        while(current != ancestor){
            if(current->data < ancestor->data){
            successor = ancestor;
            ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }

}
int main(){
    printf("Enter number of elements: ");
    int n,data;
    Node *root = NULL;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter element:\n");
        scanf("%d",&data);
        root = insert(root, data);
    }
    printSorted(root);
    printf("Enter element to find its successor: \n");
    scanf("%d",&data);
    Node *successor = inOrderSuccesor(root, data);
    printf("%d ",successor->data);

    
}