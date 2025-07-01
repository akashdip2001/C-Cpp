#include<stdio.h>

// Bubble sort
void sortArray(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Remove duplicates from sorted array
int removeDuplicates(int arr[], int size, int result[]){
    if(size == 0) return 0;

    result[0] = arr[0];
    int j = 1;

    for(int i = 1; i < size; i++){
        if(arr[i] != arr[i - 1]){
            result[j] = arr[i];
            j++;
        }
    }

    return j; // new size
}

int main(){
    int arr[] = {1, 5, 9, 3, 7, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, size);

    int arr2[size];
    int newSize = removeDuplicates(arr, size, arr2);

    printf("The final array is: ");
    for(int i = 0; i < newSize; i++){
        printf("%d ", arr2[i]);
    }
    return 0;
}
