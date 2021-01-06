#include <stdio.h>
#include <malloc.h>

struct Link
{
    struct Link* next;
    int data;
};
struct Queue
{
    struct Link* front;
    struct Link* rear;
};

void queue_init(struct Link** L)
{
    //创建头节点
    *L = (struct Link*)malloc(sizeof(struct Link));
    (*L)->next = NULL;
}
void enqueue(struct Queue* L, struct Link** N, int d)
{
    struct Link* temp = *N;
    struct Link* P = (struct Link*)malloc(sizeof(struct Link));

    P->data = d;
    P->next = temp->next;
    temp->next = P;
    *N = P;
    L->rear = P;
}
int dequeue(struct Queue* L, struct Link* N,struct Queue* L1)
{
    struct Link* temp = N = (struct Link*)L;//节点指针（现在在末尾）回到头节点位置
    struct Link* temp_space = NULL;
    static int origin_data = 0;

    if (L->front ==L1->rear)
    {
        printf("The Queue Is Null \n");
        return 0;
    }
    temp_space = temp->next;
    origin_data = temp->next->data;
    temp->next = temp->next->next;
    L->front = temp->next;
    free(temp_space);

    return origin_data;
}
void print(struct Link* p)
{
    p = p->next;
    while (p != NULL)
    {
        printf("data=%d\n", p->data);
        p = p->next;
    }
}
int main()
{
    struct Queue* f = NULL;//列队头指针
    struct Queue* r = NULL;//列队尾指针
    struct Link * S = NULL;//链表头节点
    struct Link * t = NULL;//为了打印记录头节点
    int temp = 0;

    queue_init(&S);
    t = S;
    f = r = (struct Queue*)S;

    enqueue(r, &S, 1);
    enqueue(r, &S, 2);
    enqueue(r, &S, 3);
    print(t);
    temp = dequeue(f, S, r);
    printf("temp=%d\n", temp);
    temp = dequeue(f, S, r);
    printf("temp=%d\n", temp);
    temp = dequeue(f, S, r);
    printf("temp=%d\n", temp);

}