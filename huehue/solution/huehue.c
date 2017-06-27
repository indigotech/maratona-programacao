#include <stdio.h>
#include <string.h>

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int isPalindrome(char *string) {
    int result = 1;

    int string_len = strlen(string);
    int half_len = string_len / 2;
    for (int i = 0; i < half_len; i++) {
        int mirror_index = (string_len - 1) - i;
        if (string[i] != string[mirror_index]) {
            return 0;
        }
    }
    return result;
}

void filterConsoant(char* input, char* no_consoant_input) {
  int no_consoant_index = 0;
        int input_len = strlen(input);
        for (int i = 0; i < input_len; i++) {
            char current_char = input[i];
            if (isVowel(current_char)) {
                no_consoant_input[no_consoant_index] = current_char;
                no_consoant_index++;
            }
        }
        no_consoant_input[no_consoant_index] = '\0';
}

int main(int argc, const char * argv[]) {
    char input[50];
    char no_consoant_input[50];
    while (scanf("%s", input) != EOF) {
        filterConsoant(input, no_consoant_input);
        printf(isPalindrome(no_consoant_input) ? "S" : "N");
        printf("\n");
    }
    return 0;
}
