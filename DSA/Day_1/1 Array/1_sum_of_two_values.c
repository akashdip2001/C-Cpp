// I have a arr = 1,2,3,5,7,10,11,15], Find the two values that sum to 15.
// using Normal method.

#include<stdio.h>
int main(){

    int sum;
    printf("Enter the Sum: ");
    scanf("%d",&sum);

    int arr[] = {1, 2, 3, 5, 7, 10, 11, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i=0;i < size; i++){
        for(int j=i+1; j < size; j++){
         if (arr[i] + arr[j] == sum){
            printf("The pair found: %d + %d = %d\n", arr[i], arr[j], sum);
            return 0;
         }
        }
    }
    
    printf("No pair found for this given sum\n");
    return 0;
}
