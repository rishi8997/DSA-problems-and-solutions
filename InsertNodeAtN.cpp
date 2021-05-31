#include<iostream>
using namespace std;
void insertAtBeginning(int data);
void insertNodeAtPos(int data, int pos);
void print();
int main(){
    int data, n, pos;
    printf("How many elements? ");
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        printf("Enter element:\n");
        scanf("%d",&data);
        insertAtBeginning(data);
        print();
    }
    printf("Insert elements at any position: \n");
    printf("How many elements?\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element with position:\n");
        scanf("%d%d",&data,&pos);
        insertNodeAtPos(data, pos);
        print();
    }
    
    return 0;
}
struct Node{             // structure to define the node data type
        int data;
         Node* next;
    };

    Node* head = NULL;              //pointer to head node and is global

 void insertAtBeginning(int data){
     Node* temp = (Node*)malloc(sizeof(Node));      //creating a node pointed by temp
     temp->data = data;
     temp->next = head;     //adjusting links to add node in beginning
     head = temp;
    }
void insertNodeAtPos(int data, int pos){
    Node* temp = (Node*)malloc(sizeof(Node));      //creating a node pointed by temp
    temp->data = data;
     if(pos == 1){
         temp->next = head;
         head = temp;
         return;
     }
    Node* temp1 = head;     //for traversing the list upto pos-1
    for(int i=1;i<pos-1;i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;    //adjusting the links to insert node at pos
    temp1->next = temp;
}

void print(){
    Node* temp = head;            //temp points to first node
    while(temp != NULL){          //til the end of list
        printf("%d ",temp->data);  
        temp = temp->next;       //moving forward in the list
    }
    printf("\n");
}
