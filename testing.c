#include<stdio.h>
#include<stdlib.h>

void multiply(int* arr1, int* arr2, int arraySize);
int main()
{
    // Will determine array size user gives
    int arraySize = 0;

    printf("Start program\n"); // has newline (\n)

    // Asking for user input
    printf("Input array size: ");

    // Takes the input from user
    scanf("%d", &arraySize);
   
   // Arrays start at index 0 so making arrays with arraysize as size argument makes it go to that int, not just size
    arraySize = arraySize - 1; 

    // Creates two arrays 
    int* arr1 = (int *)malloc(arraySize * sizeof(int));
    int* arr2 = (int *)malloc(arraySize * sizeof(int));

    // These two print information of the arrays
    printf("Address of arr1 after allocation: %p\n ", &arr1); 
    printf("Size of pointer arr1: %zu\n", sizeof(*arr1));

    printf("Input content of arrays \n");
    
    // for loop that reads in input for every index of arr1 
    int i;
    for(i = 0; i <= arraySize; i++)
    {
        printf("Enter value of arr1[%d]: ", i);
        scanf("%d", arr1[i]);
    }

    

    // same for loop as above but uses input values for arr2
    for(i = 0; i <= arraySize; i++)
    {
        printf("Enter value of arr2[%d]: ", i);
        scanf("%d", arr2[i]);
    }

   multiply(arr1, arr2, arraySize);



    return 0;
}
