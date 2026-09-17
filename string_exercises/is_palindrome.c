#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char* str) {
    int len = strlen(str), i = 0, j = len - 1, pal = 1;

    while (j >= i) {
        while (ispunct(str[i]) || str[i] == ' ') { i++; }
        while (j > 0 && (ispunct(str[j]) || str[j] == ' ')) { j--; }
        if (tolower(str[i]) != tolower(str[j])) { pal = 0; }
        i++;
        j--;
    }

    return pal;
}

int main() {
    char str[100];

    printf("Enter a string:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    int pal = isPalindrome(str);

    switch (pal) {
        case 0: printf("Your string is not a palindrome."); break;
        case 1: printf("Your string is a palindrome."); break;
    }

    return 0;
}
