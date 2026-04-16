#include <stdio.h>
#include <string.h>
#include <math.h>


/* Implementation Hints
Name Christion Martinez
Date April 17, 2024
Course COMP-3365
*/



double compute_entropy(const char *str){
    int freq[128] = {0}; // Frequency array
    int length = strlen(str);

    // Count the frequency of each character
    for (int i = 0; i < length; i++) {
        freq[(int)str[i]]++;
    }

    double entropy = 0.0;

    // Calculate the entropy. H = -Σ(p(x) * log2(p(x)))
    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            double p = (double)freq[i] / length; // Probability of character i
            entropy += -p * log2(p); // Update entropy
        }
    }
    
  return -entropy;
}


int main(){
   // Prompts the user for a string
  printf("Enter a string (up to 100 characters): ");

  char str[101]; // Buffer to hold the input string
  fgets(str, 101, stdin); // Read the input string from the user

  // Remove newline character from the input string, if present
  str[strcspn(str, "\n")] = '\0';

   // Compute the entropy of the string
  double entropy = compute_entropy(str);

   // Display the computed entropy
  printf("\nEntropy: %.3f bits\n", entropy);

   // Display the character frequencies
  printf("\nCharacter Frequencies:\n");

  int freq[128] = {0}; // Frequency array for ASCII characters

  for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
  }
  for (int i = 0; i < 128; i++) {
          if (freq[i] > 0) {
              printf("'%c': %d\n", i, freq[i]);
          }
  }

  return 0;
};
