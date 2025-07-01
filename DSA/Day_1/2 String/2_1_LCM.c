#include<stdio.h>
int main(){
  
  int n1, n2, a, b;
  
   printf("Enter the 1st number: ");
   scanf("%d", &n1);
   printf("Enter the 2nd number: ");
   scanf("%d", &n2);
  
a = n1;
b = n2;

  while (a != b) {
        if (a < b)
            a += n1; // a = a + n1
        else
            b += n2;
    }
   
printf("The Least Common Multiple is: %d\n", a);
  
  return 0;
}

// Logic

// 24 = 24, 48, 72, 96, 120
// 60 = 60 , 120

// c = 120- 120 = 0
