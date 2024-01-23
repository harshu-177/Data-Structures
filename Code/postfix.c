#include<stdio.h>
#include<ctype.h>
#define STACK_SIZE 10
char stack[STACK_SIZE];
int top=-1;

void push(char value){
    if(top >= STACK_SIZE - 1){
        printf("\nStack Overflow. Cannot push %c", value);
        return;
    }
    stack[++top] = value;
}

char pop(){
    if(top < 0){
        printf("\nStack Underflow. Cannot pop");
        return -1;
    }
    return(stack[top--]);
}

int precedence(char symbols){
    switch(symbols){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int main(){
    char infix[50],postfix[50],ch;
    int i=0,j=0;
    printf("Enter infix expression:");
    scanf("%s", infix);
    push('#');
    while((ch=infix[i++])!='\0'){
        if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else{
            if(ch=='('){
                push(ch);
            }
            else if(ch==')'){
                while(stack[top]!='('){
                    postfix[j++]=pop();
                }
                pop();
            }
            else{
                while(precedence(stack[top])>=precedence(ch)){
                    postfix[j++]=pop();
                }
                push(ch);
            }
        }
    }
    while(stack[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("Postfix expression=%s",postfix);
    return 0;
}
