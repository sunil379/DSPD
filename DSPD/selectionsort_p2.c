#include <stdio.h>

void selection_sort(int arr[], int n) {
    int i, j, min_index, temp;

    for (i = 0; i < n - 1; i++) {
        // Assume the first element of the unsorted part is the minimum
        min_index = i;
        // Find the minimum element in the unsorted array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first unsorted element
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    // Prompt user to enter the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Declare an array of size n to store the elements
    int arr[n];
    // Prompt user to enter the elements
    printf("Enter %d elements:\n", n);
    // Read n elements from user input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the selection_sort function to sort the array
    selection_sort(arr, n);

    // Print the sorted array
    printf("Sorted array using Selection Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
