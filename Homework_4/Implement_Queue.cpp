struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
}
int Push( ElementType X, Deque D )
{
    struct Node* temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    if(!temp)
        return 0;
    temp->Element=X;
    if(D->Front==D->Rear){//空双端队列
        D->Front->Next=temp;
        temp->Last=D->Front;
        D->Rear=temp;
        temp->Next=NULL;
        return 1;
    }
    temp->Next=D->Front->Next;
    D->Front->Next->Last=temp;
    D->Front->Next=temp;
    temp->Last=D->Front;
    return 1;
}
ElementType Pop( Deque D )
{
    if(D->Front==D->Rear)//空双端队列
        return ERROR;
    int temp=D->Front->Next->Element;
    struct Node* t=D->Front->Next;
    if(D->Front->Next==D->Rear){//一个元素的特殊情况
        D->Rear=D->Front;
        D->Rear->Next=NULL;
        free(t);
        return temp;
    }
    D->Front->Next->Next->Last=D->Front;
    D->Front->Next=D->Front->Next->Next;
    free(t);
    return temp;
}
int Inject( ElementType X, Deque D )
{
    struct Node* temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    if(!temp)
        return 0;
    temp->Element=X;
    if(D->Front==D->Rear){//空双端队列
        D->Front->Next=temp;
        temp->Last=D->Front;
        D->Rear=temp;
        return 1;
    }
    D->Rear->Next=temp;
    temp->Last=D->Rear;
    temp->Next=NULL;
    D->Rear=temp;
    return 1;
}
ElementType Eject( Deque D )
{
    if(D->Front==D->Rear)
        return ERROR;
    int temp=D->Rear->Element;
    struct Node* t=D->Rear;
    D->Rear=D->Rear->Last;
    D->Rear->Next=NULL;
    free(t);
    return temp;
}