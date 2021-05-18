#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
void reverseString(char *c, int n){
    stack<char> s;
    for(int i=0;i<n;i++){
        s.push(c[i]);
    }
    for(int i=0;i<n;i++){
        c[i] = s.top();
        s.pop();
    }

}
int main(){
    printf("Enter string: ");
    char c[101];
    gets(c);
    reverseString(c, strlen(c));
    printf("%s", c);
}