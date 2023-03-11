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

int entryTime(char* s, char* keypad) {
    int pad[3][3];
    int tracer[10][2];

    int ABS(int a){return a<0?-a:a;}
    int MAX(int a,int b){return a>b?a:b;}
    int d(int r1,int c1,int r2,int c2){return MAX(ABS(c1-c2),ABS(r1-r2));}

    int c=0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            pad[i][j]=keypad[c]-'0';
            tracer[pad[i][j]][0]=i;
            tracer[pad[i][j]][1]=j;
            c++;
        }
    }
    
    int ris=0;
    int b4=s[0]-'0';
    
    for(int i=0;s[i]!='\0';i++) {
        int r1=tracer[b4][0],c1=tracer[b4][1];
        int r2=tracer[s[i]-'0'][0],c2=tracer[s[i]-'0'][1];
        ris+=d(r1,c1,r2,c2);
        b4=s[i]-'0';
    }
    return ris;
}

int main()
{
    char* s = readline();
    char* keypad = readline();

    int result = entryTime(s, keypad);

    printf("%d\n", result);

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
