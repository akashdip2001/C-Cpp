#include<stdio.h>
int main(){
  
  int n1, n2, rem=1;
  
   printf("Enter the 1st number: ");
   scanf("%d", &n1);
   printf("Enter the 2nd number: ");
   scanf("%d", &n2);
  
  while(rem != 0){
    rem = n1 - n2;
    if(rem>n2){
      n1=rem;
    }else{
      n1=n2;
      n2=rem;
    }
  }
   
printf("The GCD is %d: \n", n1);
// printf("The LCM is %d: ", (n1 * n2) / n1);

  return 0;
}

// Logic

// 60 - 24 = 36
// 36 - 24 = 12
// 24 - 12 = 12
// 12 - 12 = 0