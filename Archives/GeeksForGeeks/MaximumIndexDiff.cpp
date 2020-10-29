//https://practice.geeksforgeeks.org/problems/maximum-index3307/1#
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        unordered_map<int,vector<int>> index;
        for(int i=0;i<n;i++) index[arr[i]].push_back(i);

        int smallestIndex = n; //keeps track of smallest
        int maxAns = -1;
        sort(arr,arr+n);
        for(int i=0;i<n;i++){ //traversing the sorted array
            if(smallestIndex > index[arr[i]][0])
                smallestIndex = index[arr[i]][0];
            maxAns = max(maxAns,*index[arr[i]].rbegin()-smallestIndex);
        }
        return maxAns;
    }

};
