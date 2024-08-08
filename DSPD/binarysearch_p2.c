#include <stdio.h>

// Function to perform binary search
int binary_search(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Find the middle index

        if (arr[mid] == target) {
            return mid; // Return the index if the target is found
        }

        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
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
    printf("Enter %d elements (sorted):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Perform binary search
    int index = binary_search(arr, 0, n - 1, target);

    // Print the result
    if (index != -1) {
        printf("Element %d found at index %d using Binary Search.\n", target, index);
    } else {
        printf("Element %d not found using Binary Search.\n", target);
    }

    return 0;
}
