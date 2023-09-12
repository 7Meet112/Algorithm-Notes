```
#include <iostream>

typedef int QELemType;

typedef struct QNode
{
    QELemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct 
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

enum Status
{
    OK = 0,
    ERROR = 1,
};

Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front) return ERROR;
    Q.front->next = nullptr;
    return OK;
}

Status DestroyQueue(LinkQueue &Q)
{
    while (Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }

    return OK;
}

Status EnQueue(LinkQueue &Q, QELemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) return ERROR;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QELemType &e)
{
    if (Q.front == Q.rear) return ERROR;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return OK;
}

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    QELemType e;
    EnQueue(Q, 10);
    DeQueue(Q, e);
    DestroyQueue(Q);

    return 0;
}
```
