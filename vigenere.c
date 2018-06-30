// Vigenere Cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 512

// Strip punctuation
void stripPunctuation(char *strInput)
{
  int i, j, length;
	char scrubbedInput[MAX_CHARACTERS];

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

  scrubbedInput[j] = '\0';
  strcpy(strInput, scrubbedInput);
}

// Plaintext File Handler
char *ptextHandler(char *ptextfile)
{
  char *ptextarray = NULL;
  char ptextbuffer[MAX_CHARACTERS];
  int flag = 0;
  int ptextlen = 0;
  int index = 0;
  int i;

  FILE *plaintextfile = NULL;
  plaintextfile = fopen(ptextfile, "r");

  ptextarray = malloc(sizeof(char) * MAX_CHARACTERS);

  // Read the document
  while (fscanf(plaintextfile, "%s", ptextbuffer) != EOF)
  {
    // Scrub the file clean
    stripPunctuation(ptextbuffer);

    // Empty array must be copied into first
    if (flag == 0)
      strcpy(ptextarray, ptextbuffer);
    else
      strcat(ptextarray, ptextbuffer);

    flag = 1;
  }

  if (ptextlen != 512)
  {
    // Get the index value of where the array ends
    while(ptextarray[index] != '\0')
      index++;

    // Now continue looping and pad with X's
    while (index != 512)
    {
      ptextarray[index] = 'x';
      index++;
    }
  }

  // Check if plaintext is 512 chars and if not pad it with X's
  ptextlen = strlen(ptextarray);

  // Print out to console
  for (i = 0; i < ptextlen; i++)
  {
    if ( (i % 80) == 0)
      printf("\n");

    printf("%c", ptextarray[i]);
  }

  fclose(plaintextfile);
  return ptextarray;
}

char *keyHandler(char *key)
{
  char *keytextArray;
  char keybuffer[MAX_CHARACTERS];
  int flag = 0;
  int i, keytextlen;

  FILE *keyFile = NULL;
  keyFile = fopen(key, "r");

  keytextArray = malloc(sizeof(char) * MAX_CHARACTERS);

  // Read file contents
  while (fscanf(keyFile, "%s", keybuffer) != EOF)
  {
    // Scrub the string
    stripPunctuation(keybuffer);

    // Empty array must be copied into first
    if (flag == 0)
      strcpy(keytextArray, keybuffer);
    else
      strcat(keytextArray, keybuffer);

    flag = 1;
  }

  keytextlen = strlen(keytextArray);

  // Print out to console
  for (i = 0; i < keytextlen; i++)
  {
    if ( (i % 80) == 0)
      printf("\n");

    printf("%c", keytextArray[i]);
  }

  fclose(keyFile);
  return keytextArray;
}

char *ciphertexthandler(char *cleanptext, char *cleankey)
{
  char *ciphertext;
  char cipherLetter;
  int i = 0, j = 0;
  int keyIndex, ptextIndex, cipherIndex, cipherlen;

  // Malloc space for ciphertext array
  ciphertext = malloc(sizeof(char) * MAX_CHARACTERS);

  // Encryption Algorithm
  while (i != MAX_CHARACTERS)
  {
    // This resets the key
    if (cleankey[j] == '\0')
      j = 0;

    // Modular Math
    keyIndex = cleankey[j] - 'a';
    ptextIndex = cleanptext[i] - 'a';
    cipherIndex = ((keyIndex + ptextIndex) % 26);

    // Cipher text
    cipherLetter = cipherIndex + 'a';
    ciphertext[i] = cipherLetter;

    // Increment loop variables
    i++;
    j++;
  }

  cipherlen = strlen(ciphertext);

  // Print out to console
  for (i = 0; i < cipherlen; i++)
  {
    if ( (i % 80) == 0)
      printf("\n");

    printf("%c", ciphertext[i]);
  }

  return ciphertext;
}

int main(int argc, char *argv[])
{
  // variables
  char *plaintext, *key, *ciphertext;
  char *cleanPlainText, *keyText;

  // Read CLI and malloc appropriately
  key = malloc(sizeof(char) * strlen(argv[1]));
  plaintext = malloc(sizeof(char) * strlen(argv[2]));

  key = argv[1];
  plaintext = argv[2];

  printf("\n\nVigenere Key:\n");
  keyText = keyHandler(key);

  printf("\n\nPlaintext:\n");
  cleanPlainText = ptextHandler(plaintext);

  printf("\n\nCiphertext:\n");
  ciphertexthandler(cleanPlainText, keyText);

  printf("\n");

  return 0;
}
