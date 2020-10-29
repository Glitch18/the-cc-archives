#include<algorithm>
#include<iostream>
using namespace std;

bool checkTriplet(int sum,int* arr, int right){
    if(right<0) return false;
    int left = 0;
    while(left!=right){
        if(arr[left]+arr[right]==sum) return true;
        else if(arr[left]+arr[right]<sum) left++;
        else right--;
    }
    return false;
}

bool findTriplets(int arr[], int n)
{
    sort(arr,arr+n);
    for(int i=n-1;i>=0;i--)
        if(checkTriplet(0-arr[i],arr,i-1))
            return true;

    return false;
}

int main(){
	int arr[] = {0, -1, 2, -3, 1};
	cout << findTriplets(arr,5);
}
