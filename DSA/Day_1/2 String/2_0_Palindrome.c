#include<stdio.h>
int main(){

	int num, result = 0, reminder;
	printf("Enter the number to check: ");
	scanf("%d", &num);

	int a = num; // Ex: 1221

	while(a != 0){
	
		reminder = a%10; // Get the last digit --> 1                //--> 2
		result = result*10 + reminder; // result = 0*10 + 1 = 1     //--> 1*10 + 2 = 12
		a  = a/10; // Remove the last digit --> 122                 //--> 12
	
	}

	if(result == num){
		printf("The number %d is Palindrom", result);
	}else{
		printf("The number %d is not Palindrom", result);
	}
	return 0;
}