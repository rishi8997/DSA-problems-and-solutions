#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *top = NULL;
void push(int data){
    Node * temp = new Node();
    temp->data = data;
    temp->next = top;
    top = temp;
}
void pop(){
    Node *temp = top;
    top = top->next;
    free(temp);
}
void print(){
    Node *temp = top;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    push(5);print();
    push(10);print();
    pop();print();
    push(15);print();

}