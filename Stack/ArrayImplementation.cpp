#include<iostream>
#define MAX_SIZE 101
using namespace std;
int A[MAX_SIZE];
int top = -1;
void push(int data){
    if(top == MAX_SIZE-1){
        printf("Stack overflow\n");
        return;
    }
    A[++top] = data;
}
void pop(){
    if(top == -1){
        printf("No element to pop\n");
        return;
    }
    top--;
}
int getTop(){
    return A[top];
}
bool isEmpty(){
    if(top == -1)return true;
    else return false;
}
void print(){
    int i=0;
    while(i<=top)
    printf("%d ",A[i++]);
    printf("\n");
}
int main(){
    if(isEmpty())printf("Stack is empty\n");
    else printf("Stack not empty\n");
    push(2);print();
    push(1);print();
    push(5);print();
    pop();print();
    push(8);print();
    printf("%d\n",getTop());
    if(isEmpty())printf("Stack is empty\n");
    else printf("Stack not empty\n");
    return 0;
}