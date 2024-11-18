#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a keyword
int isKeyword(char *str) {
    char keywords[32][10] = {
        "int", "float", "char", "if", "else", "while", "do", "return", "void",
        "for", "break", "continue", "switch", "case", "default", "sizeof",
        "struct", "typedef", "union", "static", "enum", "const", "volatile",
        "unsigned", "signed", "long", "double", "short", "goto", "extern", "auto", "register"
    };
    for (int i = 0; i < 32; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to identify if a character is an operator
int isOperator(char ch) {
    char operators[] = "+-*/%=<>&|!";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

// Function to check if a character is a special symbol
int isSpecialSymbol(char ch) {
    char symbols[] = ",;(){}[]";
    for (int i = 0; symbols[i] != '\0'; i++) {
        if (ch == symbols[i])
            return 1;
    }
    return 0;
}

// Main function
int main() {
    char code[100], token[20];
    int i = 0, j = 0;

    printf("Enter a line of code: ");
    fgets(code, sizeof(code), stdin);

    printf("\nTokens:\n");
    while (code[i] != '\0') {
        // Ignore whitespaces
        if (isspace(code[i])) {
            i++;
            continue;
        }

        // Check for keywords or identifiers
        if (isalpha(code[i]) || code[i] == '_') {
            j = 0;
            while (isalnum(code[i]) || code[i] == '_') {
                token[j++] = code[i++];
            }
            token[j] = '\0';
            if (isKeyword(token))
                printf("Keyword: %s\n", token);
            else
                printf("Identifier: %s\n", token);
        }

        // Check for numbers
        else if (isdigit(code[i])) {
            j = 0;
            while (isdigit(code[i])) {
                token[j++] = code[i++];
            }
            token[j] = '\0';

            // Check for invalid sequences like 1c
            if (isalpha(code[i]) || code[i] == '_') {
                printf("Error: Invalid token '%s%c'\n", token, code[i]);
                while (isalnum(code[i]) || code[i] == '_') i++; // Skip invalid sequence
            } else {
                printf("Number: %s\n", token);
            }
        }

        // Check for operators
        else if (isOperator(code[i])) {
            printf("Operator: %c\n", code[i]);
            i++;
        }

        // Check for special symbols
        else if (isSpecialSymbol(code[i])) {
            printf("Special Symbol: %c\n", code[i]);
            i++;
        }

        // If none of the above, it's an invalid character
        else {
            printf("Invalid character: %c\n", code[i]);
            i++;
        }
    }
    return 0;
}
