#include<iostream>
using namespace std;
void insertAtBeginning(int data);
void deleteNodeAtPos(int pos);
void print();
int main(){
    int data, n, pos;
    printf("How many elements? ");
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        printf("Enter element: ");
        scanf("%d",&data);
        insertAtBeginning(data);
        print();
    }
    printf("Delete how many elements? ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter position to delete element from: ");
        scanf("%d",&pos);
        deleteNodeAtPos(pos);
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
     temp->next = head;    //adjusting links to add node in beginning
     head = temp;
    }
void deleteNodeAtPos(int pos){
    Node* temp1 = head;
    if(pos==1){
        head = temp1->next;
        free(temp1);
        return;
    }
    for(int i=1;i<pos-1;i++){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void print(){
    Node* temp = head;            //temp points to first node
    while(temp != NULL){          //til the end of list
        printf("%d ",temp->data);  
        temp = temp->next;       //moving forward in the list
    }
    printf("\n");
}

