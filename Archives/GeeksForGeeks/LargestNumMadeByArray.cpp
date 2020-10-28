#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool comparator(string s1,string s2){
  int len = min(s1.length(),s2.length());
  for(int i=0;i<len;i++){
    if(s1[i]>s2[i]) return true;
	  else if(s2[i]>s1[i]) return false;
  }

  if(s1.length()>s2.length()){
    int i = s2.length();
	  while(s1[i]==s1[i-1]){
      i++;
      if(i==s1.length()) return true;
    }
    return (s1[i]>s1[i-1]);
  }

  else if(s1.length()<s2.length()){
    int i = s1.length();
    while(s2[i]==s2[i-1]){
      i++;
      if(i==s2.length()) return true;
    }
    cout << i << "\n";
    return !(s2[i]>s2[i-1]);
  }
  else return true;
}

string printLargest(vector<string> &arr){
  sort(arr.begin(),arr.end(),comparator);
  string ans = "";
	for(auto i : arr) ans += i;
	return ans;
}

int main(){
  //vector<string> arr = {"3","30","34","5","9"};
  vector<string> arr = {"969","969","969","969","9","3"};
  string ans = printLargest(arr);
}

/*
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	static bool comparator(string s1,string s2){
	    int len = min(s1.length(),s2.length());
	    for(int i=0;i<len;i++){
	        if(s1[i]>s2[i]) return true;
	        else if(s2[i]>s1[i]) return false;
	    }
	    if(s1.length()>s2.length()){
	        int i = s2.length();
	        while(s1[i]==s1[i-1]){
	            i++;
	            if(i==s1.length()) return true;
	        }
	        return (s1[i]>s1[i-1]) ? true : false;
	    }
	    else if(s1.length()<s2.length()){
	        int i = s1.length();
	        while(s2[i]==s2[i-1]){
	            i++;
	            if(i==s1.length()) return true;
	        }
	        return (s2[i]>s2[i-1]) ? true : false;
	    }
	    else return true;
	}

	string printLargest(vector<string> &arr) {
	    sort(arr.begin(),arr.end(),comparator);
	    string ans = "";
	    for(auto i : arr) ans += i;
	    return ans;
	}
};

int main(){
	int n;
	cin >> n;
	vector<string> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];
	Solution ob;
	string ans = ob.printLargest(arr);
	cout << ans;
	return 0;
}
*/
