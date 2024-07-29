#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_WORDS 100

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int isDelimiter(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',' || c == '!' || c == '?';
}

int findWordIndex(WordCount words[], int numWords, const char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char paragraph[MAX_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;

    // Read the paragraph from the user
    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *word = strtok(paragraph, " \n\t.,!?");
    while (word != NULL) {
        toLowerCase(word);

        int index = findWordIndex(words, numWords, word);
        if (index != -1) {
            words[index].count++;
        } else {
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }

        word = strtok(NULL, " \n\t.,!?");
    }

    // Print the frequencies
    printf("\nWord frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
