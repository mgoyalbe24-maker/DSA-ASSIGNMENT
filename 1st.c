#include <stdio.h>
int inputarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element : ", i);
        scanf("%d", &arr[i]);
    }
}

int printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {

        printf("element at index %d is %d \n", i, arr[i]);
    }
}
int insertarr(int arr[], int n, int x, int pos)
{

    // initial array of size 10

    // print the original array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // increase the size by 1
    n++;
    // shift elements forward
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    // insert x at pos
    arr[pos - 1] = x;
    // print the updated array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int deletearr(int arr[], int n, int pos)
{

    // Taking array size input

    // Taking position input

    // Validating position
    if (pos < 1 || pos > n)
    {
        printf("Invalid position! Enter a valid position.\n");
    }
    else
    {
       
        for (int i = pos - 1; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--; 
        
        printf("Updated array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
int linearsearch(int arr[], int n, int search, int found)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            printf("%d is present at %d location ", search, i);
            found = 1;
            break;
        }
    }
    if (!found)

        printf("Element is not present ");
}

int main()
{

    int arr[100];
    int i, x, pos, n;
    
    x = 10;
   
    pos = 3;

    printf("enter size:");
    scanf("%d", &n);
    inputarr(arr, n);
    printarr(arr, n);
    insertarr(arr, n, x, pos);
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);
    deletearr(arr, n, pos);
    int search, found = 0;
    printf("Enter the element for searching:");
    scanf("%d", &search);
    linearsearch(arr, n, search, found);

    return 0;
}