// check the array is shorted or not?

#include <stdio.h>

int isShorted(int arr[], int size){
    if (size == 0 || size == 1)
        return 1;
    for (int i = 1; i < size; i++){

        if (arr[i - 1] > arr[i])
            return 0;
    }
    return 1;
}

int main(){
    int arr[] = {1, 2, 3, 5, 9, 15};
 // int arr[] = {1, 2, 1, 5, 9, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isShorted(arr, size)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
