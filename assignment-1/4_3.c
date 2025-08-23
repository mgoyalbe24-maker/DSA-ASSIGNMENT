#include <Stdio.h>
int main()
{
    int r, c;
    printf("Enter r:");
    scanf("%d", &r);
    printf("Enter c:");
    scanf("%d", &c);
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter [%d][%d] element: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    printf("Matrix :");
    printf("\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("Transpose of matrix:");
    printf("\n");
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d", arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}