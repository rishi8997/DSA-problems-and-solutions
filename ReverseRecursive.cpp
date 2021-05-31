#include<iostream>
using namespace std;
struct Node{             // structure to define the node data type
        int data;
         Node* next;
    };

    Node* head = NULL;              //pointer to head node and is global
void insertAtBeginning(int data);
void reverseList(Node *temp1);
void print();

int main(){
    int data, n;
    printf("How many elements? ");
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        printf("Enter element: ");
        scanf("%d",&data);
        insertAtBeginning(data);
        print();
    }
    printf("Reversed List is : ");
    reverseList(head);
    print();
    
    return 0;
}


 void insertAtBeginning(int data){
   Node* temp = (Node*)malloc(sizeof(Node));      //creating a node pointed by temp
     temp->data = data;
     temp->next = head;    //adjusting links to add node in beginning
     head = temp;
    }

void reverseList(Node *temp1){
    if(temp1->next == NULL){       //true if reaches the last node
        head = temp1;              //head points to last node 
        return;
    }
        reverseList(temp1->next);
        Node *temp2 = temp1->next;   //temp2 points to the node after temp1
        temp2->next = temp1;         //setting the backward link
        temp1->next = NULL;          
    
}

void print(){
    Node* temp = head;            //temp points to first node
    while(temp != NULL){          //til the end of list
        printf("%d ",temp->data);  
        temp = temp->next;       //moving forward in the list
    }
    printf("\n");
}


