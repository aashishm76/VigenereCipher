// Vigenere Cipher

#include <stdio.h>
#include <stdlib.h>

// Helper Functions
//

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
void cipher_Print(char *ciphertext);

// Main Functions

// Plain text handler
char *plaintextHandler(char *plaintextfile)
{
  

}

// Input File handler
char *inputHandler(char *inputfile);

// Process both files and compute the cipher text
char *cipherProcessor(char *key, char *plaintext);
