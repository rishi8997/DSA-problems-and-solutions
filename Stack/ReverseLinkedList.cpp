#include<iostream>
#include<stack>
using namespace std;
void reverseList();
void insertAtBeginning(int data);
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
    reverseList();
    print();
    
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

void print(){
    Node* temp = head;            //temp points to first node
    while(temp != NULL){          //til the end of list
        printf("%d ",temp->data);  
        temp = temp->next;       //moving forward in the list
    }
    printf("\n");
}
void reverseList(){
    if(head == NULL)return;
    stack<Node*>s;
    Node *temp = head;
    while(temp != NULL){
        s.push(temp);
        temp = temp->next;
    }
    temp = s.top();
    head = temp;
    s.pop();
    while(!s.empty()){
        temp->next = s.top();
        temp = temp->next;
        s.pop();        
    }
    temp->next = NULL;
}