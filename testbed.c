//vigenere test bed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int index1, index2, vigindex, i = 0, j = 0;
  char vigletter;

  // char string1[10] = "dog";
  // char string2[10] = "catleggo";
  // char vigenerestring[10];
  //
  // while (i != strlen(string2))
  // {
  //   if (string1[j] == '\0')
  //     j = 0;
  //
  //   index1 = string1[j] - 'a';
  //   index2 = string2[i] - 'a';
  //
  //   vigindex = (index1 + index2) % 26;
  //   vigletter = vigindex + 'a';
  //   vigenerestring[i] = vigletter;
  //   i++;
  //   j++;
  // }
  //
  // printf("%s\n",vigenerestring );

  char printoutput[100] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaafffffff";

  for (i = 0; i < strlen(printoutput); i++)
  {
    if ( (i % 3) == 0)
      printf("\n");

    printf("%c", printoutput[i]);
  }
}
