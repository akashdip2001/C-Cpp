#include<stdio.h>
#include <math.h>  // Needed for pow()

int main(){

	int num, lenth, reminder, sum = 0;

	printf("Enter the number to check: ");
	scanf("%d", &num);

    int original = num;
    lenth = 0;

    // Count the number of digits
	int q = num;
	while(q != 0){
		q = q/10;
		lenth++;	
	}

    // Calculate the sum of digits raised to the power of 'length'
    q = num;
    while(q != 0) {
        reminder = q % 10;
        // sum += pow(reminder, lenth); 
        sum = sum + pow(reminder, lenth);
        q = q / 10;
    }

    // Print the result
    printf("The length is: %d\n", lenth);
    printf("The Armstrong sum is: %d\n", sum);

    if(sum == original) {
        printf("%d is an Armstrong number.\n", original);
    } else {
        printf("%d is NOT an Armstrong number.\n", original);
    }

return 0;
}
