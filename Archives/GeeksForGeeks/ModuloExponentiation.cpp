//https://practice.geeksforgeeks.org/problems/number-of-subsets-and-mean1225/1
class Solution {
  public:
    vector<long long> numOfSubsets(int Arr[], int N) {
        sort(Arr,Arr+N);
        int count = 1;
        int i=N-2;
        while(Arr[i]==Arr[i+1]){
            count++;
            i--;
        }
        long long max = 1,min = 1;
        for(int i=0;i<count;i++) max = max%1000000007 * 2;
        max--;

        count = 1;
        i=1;
        while(Arr[i]==Arr[i-1]){
            count++;
            i++;
        }
        for(int i=0;i<count;i++) min = min%1000000007 * 2;
        min--;
        return {max,min};
    }
};
