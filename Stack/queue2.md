```
// 循环队列
#define MAXQSIZE 100

typedef int QElemType;

typedef struct
{
    QElemType *base;
    int front;
    int rear;
}SqQueue;

enum Status
{
    OK = 0,
    ERROR = 1,
};

Status InitQueue(SqQueue &Q)
{
    Q.base = (QElemType *)malloc(sizeof(QElemType)*MAXQSIZE);
    if (!Q.base) return ERROR;
    Q.front = Q.rear = 0;
    return OK;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q, QElemType e)
{
    if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
    if (Q.rear == Q.front) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}
```
