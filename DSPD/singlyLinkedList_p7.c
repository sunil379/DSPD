#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
    printf("Node with data %d inserted at the beginning.\n", data);
}

// Function to insert a node at the end of the list
void insert_at_end(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Node with data %d inserted at the end.\n", data);
}

// Function to insert a node after a specific position
void insert_at_position(Node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insert_at_beginning(head, data);
        return;
    }

    Node *new_node = create_node(data);
    Node *temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
    } else {
        new_node->next = temp->next;
        temp->next = new_node;
        printf("Node with data %d inserted at position %d.\n", data, position);
    }
}

// Function to delete a node from the beginning of the list
void delete_from_beginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty. No nodes to delete.\n");
    } else {
        Node *temp = *head;
        *head = (*head)->next;
        printf("Node with data %d deleted from the beginning.\n", temp->data);
        free(temp);
    }
}

// Function to delete a node from the end of the list
void delete_from_end(Node **head) {
    if (*head == NULL) {
        printf("List is empty. No nodes to delete.\n");
    } else if ((*head)->next == NULL) {
        printf("Node with data %d deleted from the end.\n", (*head)->data);
        free(*head);
        *head = NULL;
    } else {
        Node *temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("Node with data %d deleted from the end.\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

// Function to delete a node from a specific position
void delete_from_position(Node **head, int position) {
    if (position < 1 || *head == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    if (position == 1) {
        delete_from_beginning(head);
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of range.\n");
    } else {
        Node *to_delete = temp->next;
        temp->next = to_delete->next;
        printf("Node with data %d deleted from position %d.\n", to_delete->data, position);
        free(to_delete);
    }
}

// Function to display the linked list
void display(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Linked list elements: ");
        Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete from beginning\n5. Delete from end\n6. Delete from position\n");
        printf("7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 3:
                printf("Enter the data to insert and position: ");
                scanf("%d %d", &data, &position);
                insert_at_position(&head, data, position);
                break;
            case 4:
                delete_from_beginning(&head);
                break;
            case 5:
                delete_from_end(&head);
                break;
            case 6:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                delete_from_position(&head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting...\n");
                // Free all nodes before exiting
                while (head != NULL) {
                    Node *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
