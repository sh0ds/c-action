#include <stdio.h>
#include <string.h>

void reverseWords(char* sentence, char* result) {
    int i = 0;
    int j = 0;
    int count = 0;
    char buffer[20][20];

    // PART 1: write words into buffer
    while (sentence[i] != '\0') {

        while (sentence[i] == ' ') { i++; }

        if (sentence[i] == '\0') { break; }

        while (sentence[i] != ' ' && sentence[i] != '\0') {
            buffer[count][j] = sentence[i];
            i++;
            j++;
        }

        buffer[count][j] = '\0';
        count++;
        j = 0;
    }

    //PART 2: reverse words into result
    if (count == 0) { strcpy(result, "\0"); return; }

    count--;
    strcpy(result, buffer[count]);
    count--;

    while (count >= 0) {
        strcat(result, " ");
        strcat(result, buffer[count]);
        count--;
    }
}


int main() {

    char sentence[100];
    char result[100];

    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0;

    printf("You entered: %s\n", sentence);

    reverseWords(sentence, result);
    printf("Your reversed sentence: %s", result);

    return 0;
}
