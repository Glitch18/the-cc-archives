vector<int> buildTable(string pat){
  int n=pat.size();
  vector<int> ans = {0};
  int j=0;

  for(int i=1;i<n;i++){
    while(j>0 && pat[j]!=pat[i]) j=ans[j-1];
    if(pat[j]==pat[i]) j++;
    ans.push_back(j);
  }
  return ans;
}
