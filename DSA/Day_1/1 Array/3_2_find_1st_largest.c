// Find the 1st largest number in an array using C.

#include<stdio.h>
int main(){

	int arr[] = {1,2,3,4,5,6,7};
	int size = sizeof(arr)/sizeof(arr[0]);

	int a = arr[0];

	for(int i=1; i<size; i++){
		if(arr[i]>a){
			a=arr[i];
		}
	}
	printf("the Largest number is: %d", a);
	return 0;
}