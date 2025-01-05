# include<iostream>
# include<vector>
using namespace std;
void mergea(int arr[],int start,int mid,int end)
{
    int left=start;
    int right=mid+1;
    int  index=0;
    vector<int>temp(end-start+1);
    while(left<=mid && right<=end)
    {
        if(arr[left]<=arr[right])
        {
            temp[index]=arr[left];
            left++;
            index++;
        }
        else
        {
            temp[index]=arr[right];
            right++;
            index++;
        }
    }
    while(left<=mid)
    {
        temp[index]=arr[left];
            left++;
            index++;
    }
    while(right<=end)
    {
        temp[index]=arr[right];
            right++;
            index++;
    }
    int i=0;
    while(start<=end)
    {
        arr[start]=temp[i];
        start++;
        i++;
    }

}



void merge_sort(int arr[],int start,int end)
{
    int mid=(start+end)/2;
    if(start==end)
    {
        return;
    }



    else
    {
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        mergea(arr,start,mid,end);
    }
}

int main()
{
    int arr[]={6,7,3,5,3,24,56,67};
    merge_sort(arr,0,7);
    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
}
