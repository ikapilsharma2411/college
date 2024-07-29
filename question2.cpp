#include <stdio.h>

int main() {
    int n, i;
    int sum = 0;
    float average;

    // Ask the user for the number of integers
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of integers must be positive.\n");
        return 1;
    }

    int numbers[n]; // Declare an array to hold the integers

    // Read integers from the user
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    // Calculate the average
    average = (float)sum / n;

    // Print the result
    printf("The average is: %.2f\n", average);

    return 0;
}
