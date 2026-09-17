#include <stdio.h>
#include <string.h>

void removeDuplicateChars(char* str) {
    int i = 0, j;

    while (str[i] != '\0') {
        j = i + 1;

        while (str[j] != '\0') {
            if (str[i] == str[j]) {
                int k = j;
                while (str[k] != '\0') { str[k] = str[k + 1]; k++; }
            } else { j++; }
        }
        i++;
    }
}

int main() {
    char str[100];

    printf("Input a string:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    printf("Before removing duplicates:\n%s\n", str);
    removeDuplicateChars(str);
    printf("After removing duplicates:\n%s\n", str);

    return 0;
}
