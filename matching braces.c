#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'matchingBraces' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY braces as parameter.
 */

/*
 * To return the string array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * char** return_string_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static char* a[5] = {"static", "allocation", "of", "string", "array"};
 *
 *     return a;
 * }
 *
 * char** return_string_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     char** a = malloc(5 * sizeof(char*));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = malloc(20 * sizeof(char));
 *     }
 *
 *     *(a + 0) = "dynamic";
 *     *(a + 1) = "allocation";
 *     *(a + 2) = "of";
 *     *(a + 3) = "string";
 *     *(a + 4) = "array";
 *
 *     return a;
 * }
 *
 */
char** matchingBraces(int braces_count, char** braces, int* result_count) {
    char** result = malloc(braces_count * sizeof(char*));
    *result_count = 0;

    for (int i = 0; i < braces_count; i++) {
        char* curr_braces = braces[i];
        int len = strlen(curr_braces);

        if (len % 2 != 0) {
            // odd length braces strings cannot be balanced
            result[*result_count] = "NO";
            (*result_count)++;
            continue;
        }

        char stack[len];
        int top = -1;
        bool is_balanced = true;

        for (int j = 0; j < len; j++) {
            char curr_char = curr_braces[j];

            if (curr_char == '(' || curr_char == '[' || curr_char == '{') {
                stack[++top] = curr_char;
            } else {
                if (top == -1) {
                    is_balanced = false;
                    break;
                } else {
                    char popped_char = stack[top--];

                    if (curr_char == ')' && popped_char != '(') {
                        is_balanced = false;
                        break;
                    } else if (curr_char == ']' && popped_char != '[') {
                        is_balanced = false;
                        break;
                    } else if (curr_char == '}' && popped_char != '{') {
                        is_balanced = false;
                        break;
                    }
                }
            }
        }

        if (is_balanced && top == -1) {
            result[*result_count] = "YES";
        } else {
            result[*result_count] = "NO";
        }
        (*result_count)++;
    }

    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int braces_count = parse_int(ltrim(rtrim(readline())));

    char** braces = malloc(braces_count * sizeof(char*));

    for (int i = 0; i < braces_count; i++) {
        char* braces_item = readline();

        *(braces + i) = braces_item;
    }

    int result_count;
    char** result = matchingBraces(braces_count, braces, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
