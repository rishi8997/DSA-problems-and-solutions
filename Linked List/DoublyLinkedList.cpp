#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
};
Node *head = NULL;
void print();
void reversePrint(Node* temp);
Node* getNewNode(int data);
void insertAtHead(int data);
int main(){
    int data, n;
    printf("How many elements? ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter element: ");
        scanf("%d",&data);
        insertAtHead(data);
        printf("List : ");
        print();
        printf("Reversed List : ");
        reversePrint(head);
    }
    return 0;
}

Node* getNewNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(int data){
    Node* newNode = getNewNode(data);
    if(head == NULL){           //if list is empty simply add to head
        head = newNode;
        return;
    }
    head->prev = newNode;       //if list is not empty adjust links and then add to head
    newNode->next = head;
    head = newNode;
}
void print(){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }printf("\n");
}
void reversePrint(Node* temp){
    if(temp==NULL)
    return;
    reversePrint(temp->next);
    printf("%d ",temp->data); 
}