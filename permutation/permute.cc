#include <stdio.h>
/*
 * Permute a string from p to the end and print out each
 * permutation starting from string_start (which never changes)
 * Does not avoid duplicates
 */
void permute(char *string_start, char *p, int &a) {
  if (*(p+1) == 0) { /* End of string - just print it */
    printf("%s\n", string_start);
  }
  else {
    char *swap;
    /* Go along the string, swapping each element in turn with p */
    for(swap = p; *swap; ++swap) {
      char tmp = *swap;

      *swap = *p;
      *p = tmp;
      
      permute(string_start, p+1,a);
      *p = *swap;
      *swap = tmp;
      a++;
    }
  }
}

main(int argc, char **argv) {
  char string[21];
   int anzahl = 0;
  
  printf("String to permute?\n");
  scanf("%20s", string);
  printf("Permutations of %s:\n", string);
  permute(string, string, anzahl);
  printf("Anzahl: %d\n", anzahl);
}
