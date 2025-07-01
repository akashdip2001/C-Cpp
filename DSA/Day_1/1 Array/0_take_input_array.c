#include <stdio.h>
int main()
{

    int arr[100], size;
    printf("Input the size of array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The array is: ");
    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
    }
    return 0;
}