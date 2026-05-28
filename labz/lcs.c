#include<stdio.h>
#include<string.h>

max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

void lcs(char x[100], char y[100], int m, int n);

void main()
{
    char x[100], y[100], lc[10];
    int m, n, len, i, j;

    printf(" Enter the first string \n");
    gets(x);

    printf(" Enter the second string \n");
    gets(y);

    m = strlen(x);
    n = strlen(y);

    lcs(x, y, m, n);
}

lcs(char x[100], char y[100], int m, int n)
{
    int len, i, j, L[100][100];
    char lc[100];

    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                L[i][j] = 0;
            else
            if(x[i-1] == y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    printf(" LCS length is %d \n", L[m][n]);

    len = L[m][n];
    lc[len] = '\0';

    i = m;
    j = n;

    while(i > 0 && j > 0)
    {
        if(x[i-1] == y[j-1])
        {
            lc[len-1] = x[i-1];
            i--;
            j--;
            len--;
        }
        else
        if(L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    printf(": THE LCS is %s \n", lc);
}