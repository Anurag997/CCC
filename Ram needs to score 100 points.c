#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

char a[MAX_LEN], b[MAX_LEN], c[256] = {0};
int n, i, j, al, bl, y;

int main() {
  scanf("%s", a);
  al = strlen(a);
  for (i = 0; i < al; i++) c[(int)a[i]] = 1;
  scanf("%s", a);
  al = strlen(a);
  scanf("%d", &n);

  while (n--) {
    scanf("%s", b);
    bl = strlen(b);
    y = 1;
    for (i = j = 0; y && i < al; i++) {
      if (a[i] == '*') {
        while (j < bl - (al - i - 1))
          if (c[(int)b[j++]]) y = 0;
      } else {
        if (a[i] == '?' ? c[(int)b[j]] : a[i] == b[j])
          j < bl ? j++ : (y = 0);
        else
          y = 0;
      }
    }
    if (j < bl) y = 0;
    printf("%s\n", y ? "YES" : "NO");
  }
  return 0;
}
