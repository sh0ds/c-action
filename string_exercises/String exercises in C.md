
**1. `reverseWords`**

```c
void reverseWords(char* sentence, char* result);

```

It should take a sentence (a null-terminated string of space-separated words) and write into `result` the same words but in reverse order — with the words themselves *not* reversed, just their order.

**2. `isPalindrome`**

```c
int isPalindrome(char* str);

```

Check if a string reads the same forwards and backwards, ignoring spaces, punctuation, and case (e.g., `"A man a plan a canal Panama"` → true). Forces you to think about two-pointer traversal (one from each end) and what "skip non-letter characters" logic looks like without letting the pointers cross incorrectly.

**3. `removeDuplicateChars`**

```c
void removeDuplicateChars(char* str);

```

Modify a string in place so each character appears only once, keeping first occurrences (e.g., `"programming"` → `"progamin"`). Forces you to think about in-place modification — writing to an earlier index while still reading from a later one — and re-terminating the string at the new (shorter) length.

**4. `countVowelsAndConsonants`**

```c
void countVowelsAndConsonants(char* str, int* vowels, int* consonants);

```

Simple on the surface, but tests whether you handle uppercase/lowercase, non-letter characters (digits, punctuation, spaces shouldn't be counted as either), and correctly use output parameters (pointers) instead of a return value.

**5. `toTitleCase`**

```c
void toTitleCase(char* str);

```

Capitalize the first letter of each word, lowercase the rest (e.g., `"the QUICK brown FOX"` → `"The Quick Brown Fox"`). Forces tracking "am I at the start of a word" state correctly across spaces, punctuation, and multiple spaces.

**6. `findLongestWord`**

```c
char* findLongestWord(char* sentence);

```

Return a pointer to the start of the longest word in a sentence (don't copy it — return a pointer into the original string). This one is sneaky: you can't just null-terminate the word in place without destroying the rest of the sentence, so you have to think about what "returning a word" without a separate buffer actually means, and how the caller would know where it *ends*.

**7. `isValidInteger`**

```c
int isValidInteger(char* str);

```

Check whether a string represents a valid integer, allowing an optional leading `+`/`-`, and rejecting things like empty strings, strings with only a sign, decimal points, letters, or embedded spaces. Good for practicing careful edge-case enumeration rather than data structure bugs.

**8. `splitAndCount`**

```c
int splitAndCount(char* sentence, char delimiter, char words[][20], int maxWords);

```

Split a sentence into an array of words by a given delimiter (not just space), storing up to `maxWords` words into the provided 2D array, and return how many words were found. This combines the word-extraction logic from before with fixed-size 2D array bounds — two overflow risks at once (word length *and* word count).