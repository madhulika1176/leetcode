#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    if (n == 1) {
        char* result = (char*)malloc(2);
        strcpy(result, "1");
        return result;
    }

    char* prev = countAndSay(n - 1);
    int len = strlen(prev);
    
    // Allocate enough space for worst case (e.g., all characters are different)
    char* result = (char*)malloc(len * 2 + 1);
    int index = 0;

    for (int i = 0; i < len;) {
        char currentChar = prev[i];
        int count = 0;

        // Count the number of repeating digits
        while (i < len && prev[i] == currentChar) {
            count++;
            i++;
        }

        // Convert count to char and append
        result[index++] = count + '0';
        result[index++] = currentChar;
    }

    result[index] = '\0';
    free(prev);  // free the previous string to avoid memory leak
    return result;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    char* output = countAndSay(n);
    printf("Count and Say of %d is: %s\n", n, output);

    free(output);  // free the final result
    return 0;
}
