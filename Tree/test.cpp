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
int findMin(Node *root){
    if(root == NULL)return -1;
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

Node* deleteNode(Node *root, int data){
    if(root == NULL)return root;
    if(data < root->data) 
        root->left = deleteNode(root->left, data);
    else if(data > root-> data)
        root->right = deleteNode(root->right, data);
    else{
        if(root->left == NULL && root->right == NULL){
            root = NULL;
            delete root;
        }
        else if(root->left == NULL){
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else{
            root->data = findMin(root->right);
            root->right = deleteNode(root->right, root->data);
        }
    }
    return root;
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
    printf("\nSorted Order : \n");
    printSorted(root);

    printf("\nLevel Order : \n");
    levelOrderTraversal(root);

    printf("\nEnter element to be deleted:\n");
    scanf("%d",&data);
    root = deleteNode(root, data);

    printf("\nSorted Order : \n");
    printSorted(root);

    printf("\nLevel Order : \n");
    levelOrderTraversal(root);
}