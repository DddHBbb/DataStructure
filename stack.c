#include <stdio.h>
#include <malloc.h>

struct Link
{
    struct Link *next;
    int Data;
};
struct Link *S;
void Creat(struct Link **p)
{
    *p = malloc(sizeof(struct Link));
    (*p)->next = NULL;
}
void PushStack(struct Link *p,int d)
{
    struct Link *temp = p;
    struct Link *p1 = malloc(sizeof(struct Link));
    p1->Data = d;
    p1->next = temp->next;
    temp->next = p1;
}
int  PopStack(struct Link *p)
{
    static int tempdata = 0;
    struct Link *delnode = NULL;
    struct Link *temp = p;

    tempdata = temp->next->Data;
    delnode = temp->next;
    temp->next = temp->next->next;
    free(delnode);
    return tempdata;
}
void print(struct Link *p)
{
    p = p->next;
    while(p != NULL)
    {
        printf("data=%d\n", p->Data);
        p = p->next;
    }
}
int main()
{
    Creat(&S);
    PushStack(S, 1);
    PushStack(S, 2);
    PushStack(S, 3);
    PushStack(S, 4);
    PushStack(S, 5);
    PopStack(S);
    PopStack(S);
    print(S);
}