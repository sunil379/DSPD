#include <stdio.h>

// Function to perform linear search
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int n, target;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get the elements of the array from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Perform linear search
    int index = linear_search(arr, n, target);

    // Print the result
    if (index != -1) {
        printf("Element %d found at index %d using Linear Search.\n", target, index);
    } else {
        printf("Element %d not found using Linear Search.\n", target);
    }

    return 0;
}
