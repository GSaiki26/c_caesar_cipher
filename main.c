// Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Functions
/**
 * A function to return the index from some char in the provided string.
 * @param string The string that'll be used.
 * @param character The character that'll be seached in the string.
 * @return The char is not found, it should return -1;
*/
int strFindIndexOf(const char *str, const char character) {
  for (int i = 0; i < strlen(str); i++) {
    // printf("%c - %c\n", str[i], character);
    if (str[i] == character) return i;
  }

  return -1;
}

// Main
int main() {
  const int INPUT_LENGTH = 20;
  const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";

  // Get user's input.
  char input[INPUT_LENGTH];
  fgets(input, INPUT_LENGTH, stdin);

  // Loop through into all the length of alphabet.
  for (int alphIndex = 0; alphIndex < strlen(ALPHABET); alphIndex++) {

    // Loop through all the characters from the input.
    for (int inputIndex = 0; inputIndex < strlen(input); inputIndex++) {
      // Lower the current character and search in the alphabet.
      input[inputIndex] = tolower(input[inputIndex]);
      int charIndex = strFindIndexOf(ALPHABET, input[inputIndex]);

      // Check if the char was found and add +1 to it index.
      if (charIndex == -1) continue;
      charIndex++;

      // Check if the index is outbound.
      if (charIndex == strlen(ALPHABET)) charIndex = 0;
      input[inputIndex] = ALPHABET[charIndex];
    }

    printf("Result of [%i]: %s\n", alphIndex, input);
  }
}
