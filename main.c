//Libs
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Data
int GetIndexOf(char alphabet[27], char x);
//Functions
int main() {
    char phrase[51], alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    printf("Type the phrase: ");
    scanf("%[^\n]",phrase); fflush(stdin);
    for (int i =0; i < 27; i++) {
        printf("Skipped letters [%d] = ", i);
        for (int ii = 0; ii < strlen(phrase); ii++) {
            char x = phrase[ii]; x = tolower(x);
            int index = GetIndexOf(alphabet, x);
            if (index == NULL) {
                printf("%c", x);
            } else {
                index = index + i;
                if (index >= 26) {
                    index = index - 26;
                }
                printf("%c", alphabet[index]);
            }
        }
        printf("\n");
    }
}
int GetIndexOf(char alphabet[27], char x) {
    for (int i = 0; i<strlen(alphabet); i++) {
        if (alphabet[i] == x) {
            return i;
        }
    }
    return NULL;
}
//Procedures