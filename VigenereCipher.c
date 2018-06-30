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

  // Check if plaintext is 512 chars and if not pad it with X's
  ptextlen = strlen(ptextarray);

  if (ptextlen != 512)
  {
    // Get the index value of where the array ends
    while(ptextarray[index] != '\0')
      index++;

    // Now continue looping and pad with X's
    while (index != 512)
    {
      ptextarray[index] = 'X';
      index++;
    }
  }
//TEST PRINT
printf("%s\n", ptextarray);
  return ptextarray;
}

char *keyHandler(char *key)
{
  char *keytextArray;
  char keybuffer[MAX_CHARACTERS];
  int flag = 0;

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
// TEST print
printf("%s\n", keytextArray);
  return keytextArray;
}

char *ciphertexthandler(char *cleanptext, char *cleankey)
{
  char *cipher = NULL;
  int i, letterNum;
  char letter;

  cipher = malloc(sizeof(char) * MAX_CHARACTERS);

  if (strlen(cleanptext) == strlen(cleankey))
  {
    while (i != 512)
    {
      letterNum = (cleanptext[i] + cleankey[i]) % 26;
      letterNum = letterNum + 'a';
      char letter =
    }
  }

}


int main(int argc, char *argv[])
{
  // variables
  char *plaintext, *key, *ciphertext;

  // Read CLI and malloc appropriately
  plaintext = malloc(sizeof(char) * strlen(argv[1]));
  key = malloc(sizeof(char) * strlen(argv[2]));
  plaintext = argv[1];
  key = argv[2];

  ptextHandler(plaintext);
  keyHandler(key);

  return 0;
}
