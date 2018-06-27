// Vigenere Cipher

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARACTERS 512

// Strip punctuation
void stripPunctuation(char *strInput)
{
  int i, j, length;
	char scrubbedInput[512];

  // Length of inputArray (either plaintext or key)
	length = strlen(strInput);
	j = 0;

	for (i = 0; i < length; i++)
	{
		if(isalpha(strInput[i]))
		{
			scrubbedInput[j] = tolower(strInput[i]);
			j++;
		}
}

// Print CipherText
void printfunction(char *ciphertext);

// Handle Plain text input
char *plaintextHandler(char *plaintextfile)
{
  // variables
  char plaintextfile[MAX_CHARACTERS];

  // FILE IO
  FILE *input = NULL;
  input = fopen(plaintextfile, "r");

  // Read the plaintext file
  while (fscanf(input, "%s", plaintextfile) != EOF)
  {
    // Strip your punctuation
    stripPunctuation(input);

    // 

  }







}
// Input File handler
char *inputHandler(char *inputfile);

// Process both files and compute the cipher text
char *cipherProcessor(char *key, char *plaintext);
