#include <stdio.h>
#define MAX 100 // Define the maximum size of the stack

// Define a stack structure with an array and a top index
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int is_full(Stack *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int is_empty(Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, int element) {
    if (is_full(s)) {
        printf("Stack overflow! Cannot push %d onto the stack.\n", element);
    } else {
        s->items[++(s->top)] = element;
        printf("%d pushed onto the stack.\n", element);
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

// Display the elements of the stack
void display(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    int choice, element;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push onto the stack: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                element = pop(&stack);
                if (element != -1) {
                    printf("%d popped from the stack.\n", element);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
