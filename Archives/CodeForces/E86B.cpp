#include<iostream>
#include<string.h>
using namespace std;

string inp;
int t;

int main(){
  cin >> t;
  cin.ignore();
  while(t--){
    getline(cin,inp);
    if(inp.find('0')==string::npos || inp.find('1')==string::npos){
      cout << inp << "\n";
      continue;
    }
    for(int i=0;i<inp.size();i++) cout << "01";
    cout << "\n";
  }
}
