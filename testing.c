#include<stdio.h>

int main()
{
    // Will determine array size user gives
    int arraySize;

    printf("Start program");

    // Asking for user input
    printf("Input array size: ");

    // Takes the input from user
    scanf("%d", &arraySize);
   

    int *arr1[arraySize];
    int *arr2[arraySize];
    printf("Address of arr1 after allocation: %p\n ", &arr1); 

    return 0;
}
