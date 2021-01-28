#include <iostream>
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



}
