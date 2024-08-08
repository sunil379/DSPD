#include <stdio.h>
#define MAX 100 // Define the maximum size of the queue

// Define a queue structure
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int is_full(Queue *q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int is_empty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Insert an element into the queue
void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue overflow! Cannot insert %d into the queue.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->items[++(q->rear)] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Remove an element from the queue
int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue underflow! Cannot remove from the queue.\n");
        return -1;
    } else {
        int value = q->items[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1; // Reset the queue when the last element is removed
        } else {
            q->front++;
        }
        return value;
    }
}

// Display the elements of the queue
void display(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue queue;
    initialize(&queue);

    int choice, element;
    while (1) {
        printf("\n1. Insert (Enqueue)\n2. Remove (Dequeue)\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert into the queue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            case 2:
                element = dequeue(&queue);
                if (element != -1) {
                    printf("%d removed from the queue.\n", element);
                }
                break;
            case 3:
                display(&queue);
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
