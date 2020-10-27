//https://practice.geeksforgeeks.org/problems/pythagorean-triplet3018/1
#include<iostream>
#include<algorithm>
using namespace std;

bool findSum(int sum,int arr[],int right){
  if(right<0) return false;
  int left=0;
  while(left!=right){
    if(arr[left]+arr[right]==sum) return true;
    else if(arr[left]+arr[right]<sum) left++;
    else right--;
  }
  return false;
}

bool checkTriplet(int arr[], int n){
  for(int i=0;i<n;i++) arr[i] = arr[i]*arr[i];
  sort(arr,arr+n);
  for(int i=n-1;i>=0;i--) if(findSum(arr[i],arr,i-1)) return true;
  return false;
}

int main(){
  int N;cin>>N;
  int arr[N];
  for(int i=0;i<N;i++) cin >> arr[i];
  cout << ((checkTriplet(arr,N)) ? "True" : "False");
}
