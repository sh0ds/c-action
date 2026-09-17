#include <stdio.h>
#include <string.h>

// TODO: Write your extractWord function here
int extractWord(char* sentence, int startIndex, char* word) {
    int i = startIndex;
    int j = 0;

    while (sentence[i] != '\0' && sentence[i] != ' ') {
        word[j] = sentence[i];
        i++;
        j++;
    }

    word[j] = '\0';

    return j;
}
// TODO: Write your countWordOccurrences function here
int countWordOccurrences(char* sentence, char* targetWord) {
    int i = 0;
    int count = 0;

    while (sentence[i] != '\0') {
        while (sentence[i] == ' ') {
            i++;
        }

        if (sentence[i] == '\0') {
            break;
        }

        int j = 0;
        char testWord[50];

        while (sentence[i] != ' ' && sentence[i] != '\0' && j < 19) {
            testWord[j] = sentence[i];
            i++;
            j++;
        }

        testWord[j] = '\0';

        if (strcmp(targetWord, testWord) == 0) {
            count++;
        }
    }

    return count;
}
// TODO: Write your analyzeText function here
int analyzeText(char* sentence) {
    int i = 0;
    int count = 0;

    while (sentence[i] != '\0') {
        while (sentence[i] == ' ') {
            i++;
        }

        if (sentence[i] == '\0') {
            break;
        }

        while (sentence[i] != ' ' && sentence[i] != '\0') {
            i++;
        }

        count++;
    }

    return count;
}


int main() {
    char inputSentence[200];
    char searchWord[50];

    // Read input sentence
    fgets(inputSentence, sizeof(inputSentence), stdin);
    // Remove newline character if present
    inputSentence[strcspn(inputSentence, "\n")] = '\0';

    // Read search word
    scanf("%s", searchWord);

    // TODO: Write your code below
    // Call analyzeText function and store total word count
    int totalWords = analyzeText(inputSentence);
    // Call countWordOccurrences function and store occurrences
    int occurrences = countWordOccurrences(inputSentence, searchWord);
    // Calculate frequency percentage
    float frequency = (float) (occurrences * 100) / totalWords;
    // Determine frequency category
    char category[10];

    if (frequency > 0.0 && frequency < 20.0) {
        strcpy(category, "Rare");
    } else if (frequency >= 20.0 && frequency <= 50.0) {
        strcpy(category, "Common");
    } else if (frequency > 50.0) {
        strcpy(category, "Frequent");
    } else {
        strcpy(category, "Not found");
    }

    // Output results in the required format
    printf("Total words: %d\n", totalWords);
    printf("Occurrences of '%s': %d\n", searchWord, occurrences);
    printf("Frequency: %.1f%%\n", frequency);
    printf("Category: %s\n", category);

    return 0;
}
