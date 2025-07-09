#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // Negative numbers are not palindrome
    if (x < 0) return false;

    int original = x;
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x = x / 10;
    }

    return original == reversed;
}

int main() {
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (isPalindrome(x))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
