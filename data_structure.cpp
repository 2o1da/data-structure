#include <iostream>
#include <list>
using namespace std;

int LinearSearch(int ar[],int len, int target)
{
    int i;
    for(i=0;i<len;i++)
        if(ar[i]==target)
            return i;

    return -1;
}

int BinarySearch(int ar[],int len, int target)
{
    int first=0;
    int last=len-1;
    int mid;

    while(first<=last)
    {
        mid=(first+last)/2;

        if(target==ar[mid])
            return mid;

        else
        {
            if(target<ar[mid])
                last=mid-1;
            else
                first=mid+1;
        }
    }
    return -1;
}

int BinarySearch2(int ar[],int len,int target)
{
    int first=0;
    int last=len-1;
    int mid;
    int opCount=0;

    while(first<=last)
    {
        mid=(first+last)/2;

        if(target==ar[mid])
        {
            return mid;
        }
        else{
            if(target<ar[mid])
                last=mid-1;
            else
                first=mid+1;
        }
        opCount+=1;
    }

    cout<<"비교연산횟수:"<<opCount<<endl;
    
    return -1;
}

int Recursive(int num)
{
    if(num<=0)
        return;
    cout<<"Recursive call:"<<num<<endl;
    Recursive(num-1);
}

int Factorial(int n)
{
    if(n==0)
        return 1;

    else
    {
        return n*Factorial(n-1);
    }   
}

int Fibo(int n)
{
    cout<<"func call param "<<n<<endl;

    if(n==1)
        return 0;

    else if(n==2)
        return 1;
    
    else
    {
        return Fibo(n-1)+Fibo(n-2);
    }
}

int BinarySearchRecur(int ar[],int first, int last, int target)
{
    int main;
    if(first>last)
        return -1;
    mid=(first+last)/2;

    if(ar[mid]==target)
        return mid;
    else if(target<ar[mid])
        return BinarySearchRecur(ar,first,mid-1,target);
    else
    {
        return BinarySearchRecur(ar,mid+1,last,target);
    }
    
}

void HanoiTowerMove(int num,char from,char by, char to)
{
    if(num==1)
    {
        cout<<"원반1을 "<<from<<"에서 "<<to<<"로 이동\n";
    }

    else
    {
        HanoiTowerMove(num-1,from,to,by);
        cout<<"원반"<<num<<"을(를) "<<from<<"에서 "<<to<<"로 이동\n";
        HanoiTowerMove(num-1,by,from,to);
    }    
}


int main() {

    int arr[]={3,5,2,4,9}; //길이5
    int idx;

    //idx = Lsearch(arr,sizeof(arr)/sizeof(int),4);
    idx=BinarySearch(arr,sizeof(arr)/sizeof(int),7);

    
    if(idx==-1)
        cout<<"탐색 실패\n";
    
    else
        cout<<"타겟 저장 인덱스:"<<idx<<endl;


    idx = Lsearch(arr,sizeof(arr)/sizeof(int),7);

    if(idx==-1)
        cout<<"탐색 실패\n";
    
    else
        cout<<"타겟 저장 인덱스:"<<idx<<endl;

    return 0;

    int arr1[500]={0,}; //모든 요소 0으로 초기화


    Recursive(3);
    
    
    HanoiTowerMove(3,'A','B','C');
    return 0;
    
    
}


void ListInit(list* plist);

void LInsert(list *plist,LData data);

int LFirst(List *plist,LData *data);

int LNext(List *plist, LData *data);

LData LRemove(list *plist);

int LCount(list *plist);

int main()
{
    list list;
    int data;
    ListInit(&list);

    LInsert(&list, 11); LInsert(&list, 11);
    LInsert(&list, 22); LInsert(&list, 22);
    LInsert(&list, 33);
    
    cout<<"현재 데이터의 수:"<<LCount(&list)<<endl;

    if(LFirst(&list, &data))
    {
        cout<<data<<endl;

        while(LNext(&list,&data))
            cout<<"data"<<endl;
    }
    cout<<endl<<endl;

    if(LFirst(&list,&data))
    {
        if(data==22)
            LRemove(&list);

            while(LNext(&list,&data))
            {
                if(data==22)
                    LRemove(&list);
            }
    }
    
    cout<<"현재 데이터의 수:"<<LCount(&list)<<endl;

    if(LFirst(&list, &data))
    {
        cout<<data<<endl;

        while(LNext(&list,&data))
            cout<<"data"<<endl;
    }
    cout<<endl<<endl;

    return 0;
}

#define LIST_LEN 100
typedef int LData;

typedef struct __ArrayList
{
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List *plist)
{
    (plist->numOfData)=0;
    (plist->curPosition)=-1;
}

void LInsert(List *plist, LData data)
{
    if(plist->numOfData>=LIST_LEN)
    {
        cout<<"저장불가\n";
        return;
    }
}

int LFirst(List *plist, LData *pdata)
{
    if(plist->numOfData==0)
        return false;

    (plist->curPosition)=0;
    *pdata=plist->arr[0];
    return true;
}

int LNext(List *plist, LData *pdata)
{
    if(plist->curPosition>=(plist->numOfData)-1)
        return false;

    (plist->curPosition)++;
    *pdata=plist->arr[plist->curPosition];
    return true;
}

LData LRemove(List *plist)
{
    int rpos=plist->curPosition;
    int num=plist->numOfData;
    int i;
    LData rdata=plist->arr[rpos];

    for(i=rpos;i<num-1;i++)
        plist->arr[i]=plist->arr[i+1];

    (plist->numOfData)--;
    (plist->curPosition)--;
    return rdata;
}

int LCount(List *plist);