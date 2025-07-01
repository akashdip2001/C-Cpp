#include<stdio.h>
int main(){
  
  int arr[] = {1,2,3,4,5,6,8,10};
  int size = sizeof(arr)/sizeof(arr[0]);
  int tearget=15;
  
  
  for(int i=0; i < size ; i++){
// for(int j = 1; j < size; j++) ----> NB*
    for(int j=i + 1; j < size; j++){
      if(arr[i] + arr[j] == tearget){
        printf("The pair is %d and %d ", arr[i], arr[j]);
        break;
      }
    }
  }
  
  return 0;
}

// NB*: Here’s what’s happening:

// output : The pair is 5 and 10 The pair is 10 and 5.

// When i = 4 (arr[i] = 5) and j = 7 (arr[j] = 10), it prints:
// → The pair is 5 and 10

// Later, when i = 7 (arr[i] = 10) and j = 4 (arr[j] = 5), it again matches
// → The pair is 10 and 5
