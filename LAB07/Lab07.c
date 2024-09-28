#include <stdio.h>

void printLIS(int arr[], int n) {
    int lis[n];
    int prev[n]; // To store the previous index in the LIS sequence

    // Initialize LIS values for all indexes as 1 and previous as -1
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        prev[i] = -1;
    }

    // Compute optimized LIS values in a bottom-up manner
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Find the maximum in lis[] and the corresponding index
    int maxLength = 0, maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (lis[i] > maxLength) {
            maxLength = lis[i];
            maxIndex = i;
        }
    }

    // Print the length of LIS
    printf("Length of LIS: %d\n", maxLength);

    // To print the LIS sequence, we trace the path back using the prev array
    int lisSequence[maxLength];
    int k = maxLength - 1;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
        lisSequence[k--] = arr[i];
        if (prev[i] == -1)
            break;
    }

    // Print the LIS sequence
    printf("LIS: ");
    for (int i = 0; i < maxLength; i++) {
        printf("%d", lisSequence[i]);
        if (i < maxLength - 1)
            printf(", ");
    }
    printf("\n");
}

int main() {
    int n;
    
    // Taking the input from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calling the function to print LIS
    printLIS(arr, n);

    return 0;
}
