#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char** triangleOrNot(int a_size, int* a, int b_size, int* b, int c_size, int* c, int* result_size) {
    char** result = malloc(sizeof(char*) * a_size);
    *result_size = a_size;
    
    for (int i = 0; i < a_size; i++) {
        if (a[i] + b[i] > c[i] && a[i] + c[i] > b[i] && b[i] + c[i] > a[i]) {
            result[i] = "Yes";
        } else {
            result[i] = "No";
        }
    }
    
    return result;
}
int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    char** res;
int res_size;
    int a_size = 0;
    scanf("%d\n", &a_size);

    int a[a_size];
    for(int i = 0; i < a_size; i++) {
        int a_item;
        scanf("%d", &a_item);
        a[i] = a_item;
    }

    int b_size = 0;
    scanf("%d\n", &b_size);

    int b[b_size];
    for(int i = 0; i < b_size; i++) {
        int b_item;
        scanf("%d", &b_item);
        b[i] = b_item;
    }

    int c_size = 0;
    scanf("%d\n", &c_size);

    int c[c_size];
    for(int i = 0; i < c_size; i++) {
        int c_item;
        scanf("%d", &c_item);
        c[i] = c_item;
    }

    res = triangleOrNot(a_size, a, b_size, b, c_size, c, &res_size);
    for (int res_i = 0; res_i < res_size; res_i++) {

        fprintf(f, "%s\n", res[res_i]);

    }


    fclose(f);
    return 0;
}
