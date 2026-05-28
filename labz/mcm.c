#include <stdio.h>
#include <conio.h>

//Function for matrix chain multiplication
int MCM(long int p[], long int n)
{
    long int m[10][10];
    long int i,j,k,L,q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = 30000;

            for (k = i; k <= j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    printf("---------------------------------------------\n");

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (i < j)
                printf("%10ld\t", m[i][j]);
            else if (i == j)
                printf("0\t");
            else
                printf("--\t");
        }

        printf("\n");
    }
}

//main program
int main()
{
    long int arr[10], n, i;

    clrscr();

    printf("Enter the number of matrices \n");
    scanf("%ld", &n);

    printf("Enter the sizes of matrices (p0,p1.....)\n");

    for(i = 0; i <= n; i++)
        scanf("%ld", &arr[i]);

    printf("Minimum number of multiplications is : \n");

    MCM(arr, n+1);

    getch();
}