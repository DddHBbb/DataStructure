#include <stdio.h>
#include <malloc.h>
int i = 0;
int sum = 0;
void add(int n)
{
    if (n <= 100)
    {
        printf("n=%d,sum=%d\n", n, sum);
        n = n + 1;
        sum = sum + n;
        add(n);
    }
}

int feibonaqie(int n)
{
    if (n == 1 || n == 2)
    {             
        return 1; 
    }
    return feibonaqie(n - 1) + feibonaqie(n - 2);
}
int main()
{
    int n = 0;
    //   add(0);

    n = feibonaqie(7);
    printf("n=%d\n", n);
}