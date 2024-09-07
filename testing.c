#include <stdio.h>
#include <stdlib.h>

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

int main() {
    int *array1, *array2;
    int size, i;
    FILE *fptr;

    // Ask the user for the size of the arrays
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the arrays
    array1 = (int *)malloc(size * sizeof(int));
    array2 = (int *)malloc(size * sizeof(int));

    if (array1 == NULL || array2 == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    // Print the address of the first array
    printf("Address of the first array: %p\n", (void *)array1);

    // Print the size of the array pointer
    printf("Size of the array pointer: %zu bytes\n", sizeof(array1));

    // Fill both arrays with user-provided values
    printf("Enter elements for the first array:\n");
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array1[i]);
    }

    printf("Enter elements for the second array:\n");
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array2[i]);
    }

    // Open file to write results
    fptr = fopen("hw1_output.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        free(array1);
        free(array2);
        return 1;
    }

    // Perform multiplication and write to file
    for (i = 0; i < size; i++) {
        int result = multiply(array1[i], array2[i]);
        if (result % 2 == 0) {
            fprintf(fptr, "Multiplication of %d and %d is %d (even)\n", array1[i], array2[i], result);
        } else {
            fprintf(fptr, "Multiplication of %d and %d is %d (odd)\n", array1[i], array2[i], result);
        }
    }

    // Close the file after writing
    fclose(fptr);

    // Open file to read and print its content
    fptr = fopen("hw1_output.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file for reading!\n");
        free(array1);
        free(array2);
        return 1;
    }

    // Print the content of the file
    char ch;
    printf("\nContents of the file 'hw1_output.txt':\n");
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }

    // Close the file after reading
    fclose(fptr);

    // Free dynamically allocated memory
    free(array1);
    free(array2);

    return 0;
}