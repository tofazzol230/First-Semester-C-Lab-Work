/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Valid Parentheses
note        : i have taken help from google to understand the logic
*/
#include<stdio.h>
int is_valid(char *arg){
    char stack[100];
    int top=-1;
    for(int i=0;arg[i]!='\0';i++){
        if(arg[i]=='(' || arg[i]=='{' || arg[i]=='['){
            stack[++top]=arg[i];
        }
        else if(arg[i]==')'){
            if(top==-1 || stack[top]!='('){
                return 0;
            }
            top--;
        }
        else if(arg[i]=='}'){
            if(top==-1 || stack[top]!='{'){
                return 0;
            }
            top--;
        }
        else if(arg[i]==']'){
            if(top==-1 || stack[top]!='['){
                return 0;
            }
            top--;
        }
    }
    return top==-1;
}
int main(){
    char arg[]={"[]"};
    if(is_valid(arg)){
        printf("Valid\n");
    }
    else{
        printf("Not Valid\n");
    }


return 0;
}