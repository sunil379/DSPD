#include <stdio.h>
#include <ctype.h> // For isdigit function
#include <stdlib.h> // For atoi function
#define MAX 100 // Define the maximum size of the stack

// Define a stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int is_empty(Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow! Cannot push %d onto the stack.\n", value);
    } else {
        s->items[++(s->top)] = value;
    }
}

// Pop an element from the stack
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow! Cannot pop from the stack.\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

// Function to evaluate a postfix expression
int evaluate_postfix(const char *expression) {
    Stack stack;
    initialize(&stack);
    int i = 0;
    int operand1, operand2, result;

    while (expression[i] != '\0') {
        // If the character is a digit, convert it to an integer and push onto the stack
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            // The character is an operator; pop two operands and apply the operator
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero.\n");
                        return -1;
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operator '%c'.\n", expression[i]);
                    return -1;
            }
            // Push the result of the operation back onto the stack
            push(&stack, result);
        }
        i++;
    }

    // The result of the postfix expression is at the top of the stack
    return pop(&stack);
}

int main() {
    char expression[MAX];

    // Get the postfix expression from the user
    printf("Enter a postfix expression (single-digit numbers and operators +, -, *, /): ");
    scanf("%s", expression);

    // Evaluate the postfix expression
    int result = evaluate_postfix(expression);

    // Print the result
    if (result != -1) {
        printf("The result of the postfix expression is: %d\n", result);
    }

    return 0;
}
