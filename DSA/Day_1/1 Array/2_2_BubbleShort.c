#include<stdio.h>

int isShorted(int arr[], int size){
    if(size == 0 || size ==1)
    return 1;

    for(int i=1; i< size; i++){
        if(arr[i-1]>arr[i])
        return 0;
    }
    return 1;
}

int newArr(int arr[],int size){
    printf("Your New shorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}

// Bubble Short
void bubbleShort(int arr[],int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){

            if (arr[j] > arr[j + 1]){

            // j = 2 , j+1 = 6
                int temp = arr[j]; // temp = 2
                arr[j] = arr[j + 1]; // j = 6
                arr[j + 1] = temp; // j+1 = 2
            }
        }
    }
}

int main(){
 // int arr[] = {1,2,6,8,9};
    int arr[] = {1,6,2,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    if(isShorted(arr, size)){
        printf("The array is already shorted\n");
        newArr(arr, size);
    }else{
        printf("Your array is not shorted\n");
        bubbleShort(arr, size);
        newArr(arr,  size);
    }

    return 0;
}