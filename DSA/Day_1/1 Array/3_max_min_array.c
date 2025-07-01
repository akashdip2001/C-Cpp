#include <stdio.h>
int main()
{
    int arr[] = {1, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int a = arr[0];
    for (int i = 0; i < size; i++){

        if (a < arr[i]){
            a = arr[i];
        }
    }

    printf("The max of the array is: %d\n", a);

    return 0;
}