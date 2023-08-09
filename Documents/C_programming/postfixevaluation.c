#if 0
clang -o $0.out ./$0 && ./$0.out
rm ./$0.out > /dev/null
exit
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  int top;
  char* stack;
} sul;

void push(sul* pusher, int val) {
  pusher->stack[++pusher->top] = val;
}

int pop(sul* popper) {
  return popper->stack[popper->top--];
}

int operation(int second_val, int first_val, char operator) {
  switch (operator) {
    case '+':
      return first_val + second_val;
    case '-':
      return first_val - second_val;
    case '*':
      return first_val * second_val;
    case '/':
      if (second_val != 0) {
        return first_val / second_val;
      }
      printf("\n Exit: Zero division error occur while dividing %d by %d ", first_val, second_val);
      exit(1);
    default:
      printf("invalid Operator %c",operator);
      exit(1);
  }
}

sul* initializeStack(unsigned size) {
  sul* stack = (sul*)malloc(sizeof(sul));
  stack->top = -1;
  stack->stack = (char*)malloc(sizeof(char) * size);
  return stack;
}

int main() {
  char* buffer;
  buffer = (char*)malloc(sizeof(char) * MAX);
  // printf("Please enter the postfix evaluation data: ");
  fgets(buffer, MAX, stdin);
  sul* stacks = initializeStack(strlen(buffer));  // Initialize stack with MAX size
  char currentvalue;
  int pusher, first_popped, second_popped;
  int i = 0;
  while (sscanf(buffer + i, " %c", &currentvalue) == 1) {
    if (currentvalue >= '0' && currentvalue <= '9') {
      pusher = currentvalue - '0';
      push(stacks, pusher);
    } else if (currentvalue != ' ') {
      first_popped = pop(stacks);
      second_popped = pop(stacks);
      pusher = operation(first_popped, second_popped, currentvalue);
      push(stacks, pusher);
    }
    i++;
  }
  printf("Result: %d\n", pop(stacks)); // Display the final result
  free(stacks->stack);
  free(stacks);
  free(buffer);

  return 0;
}
