#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    int lis[n];
    lis[1] = 1;

    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (array[j] < array[i] && lis[j] + 1 > lis[i])
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int maior = lis[0];

    for (int i = 1; i < n; i++)
    {
        if (lis[i] > maior)
        {
            maior = lis[i];
        }
    }

    printf("%d\n", maior);
    return 0;
}