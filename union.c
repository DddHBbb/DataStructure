#include <stdio.h>
int main()
{
    union
    {
        int n;
        char ch;
    } data;
    data.n = 0x00000001;  //也可以直接写作 data.n = 1;
    if(data.ch == 1)
    {
        printf("Little-endian\n");
    }else{
        printf("Big-endian\n");
    }

    printf("%p\n", &data.ch);
    return 0;
}