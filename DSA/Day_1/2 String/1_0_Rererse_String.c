// Using default function

//gets() is dangerous
//gets() does not do bounds checking, so if the user enters more characters than the array can hold, it causes a buffer overflow, which can lead to crashes or security issues.
//gets() has been removed from the C11 standard for this reason.
// fgets(car, sizeof(car), stdin);
// car[strcspn(car, "\n")] = '\0';  // Remove newline

#include<stdio.h>
#include<string.h>

int main(){

    char car[100];
    printf("\n Enter the String: ");
    gets(car);

    printf("\nThen reverse string is: %s", strrev(car));

    return 0;
}