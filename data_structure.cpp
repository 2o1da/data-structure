using namespace std;

int LinearSearch(int ar[],int len, int target)
{
    int i;
    for(i=0;i<len;i++)
        if(ar[i]==target)
            return i;

    return -1;
}

int main() {

    int arr[]={3,5,2,4,9}; //길이5
    int idx;

    idx = Lsearch(arr,sizeof(arr)/sizeof(int),4);
    
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
