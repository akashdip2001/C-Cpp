#include <stdio.h>
#include <string.h>

// Creating function for Reverse
void reverseString(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char car[100];

    printf("\nEnter the String: ");
    fgets(car, sizeof(car), stdin);
    car[strcspn(car, "\n")] = '\0';  // Remove newline

    reverseString(car);

    printf("\nThe reversed string is: %s\n", car);

    return 0;
}
