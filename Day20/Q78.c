#include <stdio.h>
int main() {
    int a[3][3] = {{1,2,3},{2,4,5},{3,5,6}};
    int sym = 1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[i][j] != a[j][i]) { sym = 0; break; }

    printf(sym ? "Symmetric Matrix" : "Not Symmetric");
    return 0;
}