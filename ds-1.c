#include <stdio.h>
// Linear search using iterative method
int linear_search(int arr[], int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}
// Linear search using recursion
int RecursiveLS(int arr[], int size, int i, int key)
{
    if (i >= size)
    {
        return -1;
    }
    else if (arr[i] == key)
    {
        return i;
    }
    else
    {
        return RecursiveLS(arr, size, i + 1, key);
    }
}
// Binary search using iteration
int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int RecursiveBS(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            return RecursiveBS(arr, low, mid - 1, key);
        }
        else
        {
            return RecursiveBS(arr, mid + 1, high, key);
        }
    }
    return -1;
}

int main()
{
    int choice;
    printf("1. linear search using iteration\n");
    printf("2. linear search using recursion\n");
    printf("3. binary search using iteration\n");
    printf("4. binary search using recursion\n");
    printf("Enter the choice: ");
    scanf("%d", &choice);
    int n, i;
    printf("Enter the size: ");
    scanf("%d", &n);
    int arr[n], key;
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    switch (choice)
    {
    case 1:
    {
        int index = linear_search(arr, n, key);
        if (index != -1)
        {
            printf("The number is found at %d using iteration (linear Search)\n", index);
        }
        else
        {
            printf("Number not found");
        }
        break;
    }
    case 2:
    {
        int x = RecursiveLS(arr, n, 0, key);
        if (x != -1)
        {
            printf("The number is found at %d using recursion (linear Search)\n", x);
        }
        else
        {
            printf("Number not found");
        }
        break;
    }
    case 3:
    {
        int bs = binarySearch(arr, n, key);
        if (bs != -1)
        {
            printf("The number is found at %d using iteration (binary Search)\n", bs);
        }
        else
        {
            printf("Number not found");
        }
        break;
    }
    case 4:
    {
        int rec_bs = RecursiveBS(arr, 0, n - 1, key);
        if (rec_bs != -1)
        {
            printf("The number is found at %d using recursion (binary Search)\n", rec_bs);
        }
        else
        {
            printf("Number not found");
        }
        break;
    }
    }
    return 0;
}
