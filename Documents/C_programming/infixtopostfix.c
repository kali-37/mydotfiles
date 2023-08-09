
#if 0
clang -o $0.out ./$0 && ./$0.out
rm ./$0.out > /dev/null
exit
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
  int top;
  char* profix;
  char* stack;
  char* holder;
} stack;

stack* initializeStack(char* holder) {
  stack* stack = malloc(sizeof(stack));
  stack->top = -1;
  stack->stack = malloc(sizeof(char) * strlen(holder));
  stack->profix = malloc(sizeof(char) * strlen(holder));
  stack->holder = malloc(sizeof(char) * strlen(holder));
  strcpy(stack->holder, holder);
  return stack;
}

int precedence(char checker) {
  switch (checker) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
		return -1;
  }
}
int isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
			|| ch == '^');
}



char pop(stack* popper) {
  return popper->stack[popper->top--];
}

int isempty(stack* checker) {
  return (checker->top == -1);
}

void push(stack* pusher, char pushed) {
  pusher->stack[++pusher->top] = pushed;
}

char* infix_to_postfix(stack* stack) {
  int i, j;
  for (i = 0, j = 0; i < strlen(stack->holder); i++) {
    if (stack->holder[i] == ' ' || stack->holder[i] == '\t') {
      continue;
    }
	 else if ((stack->holder[i] >= 'a' && stack->holder[i] <= 'z') ||
               (stack->holder[i] >= 'A' && stack->holder[i] <= 'Z') ||
               (stack->holder[i] >= '0' && stack->holder[i] <= '9')) {
      stack->profix[j++] = stack->holder[i];
    } else if (stack->holder[i] == ')') {
      while (!(isempty(stack)) && stack->stack[stack->top] != '(') {
        stack->profix[j++] = pop(stack);
      }
      pop(stack);
	}
	  else if (stack->holder[i]=='(') push(stack,stack->holder[i]);


    else if (isOperator(stack->holder[i])) 
	{while(!(isempty(stack)) && precedence(stack->stack[stack->top]) >=precedence(stack->holder[i])) {
      stack->profix[j++] = pop(stack);
    } 
	push(stack,stack->holder[i]);
  }
  }
  while (!(isempty(stack))) {
    stack->profix[j++] = pop(stack);
  }
  stack->profix[j]='\0';
  return stack->profix;
}

int main() {
  char* holder = malloc(sizeof(char) * MAX);
  printf("Provide the infix expression to calculate postfix: ");
  fgets(holder, MAX, stdin);
  stack* stack = initializeStack(holder);
  char* answer = infix_to_postfix(stack);
  printf("%s", answer);
  free(holder);
  free(stack);
  return 0;
}
