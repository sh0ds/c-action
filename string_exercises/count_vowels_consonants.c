#include <ctype.h>
#include <stdio.h>
#include <string.h>

void countVowelsAndConsonants(char* str, int* vowels, int* consonants) {
    int i = 0;

    while (str[i] != '\0') {
        while (!isalpha(str[i])) { i++; }
        if (str[i] == '\0') { return; }

        char lc = tolower(str[i]);
        if (lc == 'a' || lc == 'e' || lc == 'i' ||lc == 'o' || lc == 'u')
            { *vowels = *vowels + 1; }
        else { *consonants = *consonants + 1; }
        i++;
    }
}

int main() {
    int vowels = 0, consonants = 0;
    int *p_vowels = &vowels, *p_consonants = &consonants;
    char str[100];

    printf("Input a string:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    countVowelsAndConsonants(str, p_vowels, p_consonants);

    printf("Vowels: %d, Consonants: %d", vowels, consonants);

    return 0;
}
