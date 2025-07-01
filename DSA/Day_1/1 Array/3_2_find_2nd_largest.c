#include<stdio.h>
int main(){

    int arr[] = {1,3,5,9,4,2,9,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    int max=arr[0], min=arr[1];

    if(max<min){
        int temp = max;
        max = min;
        min = temp;
    }

    for(int i=2; i< size; i++){
        if(max<arr[i]){
            min = max;
            max = arr[i];
        }else if(min <arr[i] && arr[i] != max){
                min = arr[i];
            }
    }
    
    printf("The largest number is %d &\n2nd largest is %d, of the array: ", max, min);
    for(int i=0; i< size; i++){
        printf("%d, ", arr[i]);
    }
    return 0;
}