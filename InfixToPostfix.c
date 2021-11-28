#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  stack{

    int top;
    unsigned capacity;
    char *array;

};

struct stack* newStack(unsigned size){

    struct stack *newStack =(struct stack*) malloc(sizeof(struct stack));
    newStack->capacity = size;
    newStack->top = -1;
    newStack->array =(char *) malloc(newStack->capacity * sizeof(char));
    return newStack;

}

int isEmpty(struct stack *temp){

    return temp->top == -1;

}

void push(struct stack *temp,char data){
    temp->array[++temp->top] = data;
}
char pop(struct stack *temp){
    if(!isEmpty(temp)){
        return temp->array[temp->top--];
    }
    return '$';

}
char peek(struct stack *temp){
    return temp->array[temp->top];
}

int isOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}



int priority(char ch){

    if(ch=='+' || ch=='-')
        return 1;
    if(ch=='*'||ch=='/')
        return 2;
    if(ch=='^')
        return 3;

    return -1;


}

int infixToPostfix(char *ch){

    int i,k;

    struct stack *stack = newStack(strlen(ch));



    for(i = 0, k = -1; ch[i] != '\0' ; i++){

        if(isOperand(ch[i])){
            ch[++k] = ch[i];
        }else if(ch[i]=='('){
            push(stack,ch[i]);
        }else if(ch[i] == ')'){

            while(!isEmpty(stack) && peek(stack) != '('){
                ch[++k] = pop(stack);
            }

                pop(stack); // ( bunu da stackden çıkar

        }else{
           
            while (!isEmpty(stack) && priority(ch[i]) <= priority(peek(stack))){
                ch[++k] = pop(stack);
            }
            push(stack,ch[i]);
        }


    }
    while(!isEmpty(stack)){
        ch[++k] = pop(stack);
    }
    ch[++k] = '\0';
    printf("%s",ch);



}

int main(){

    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(infix);


    return 0;
}



