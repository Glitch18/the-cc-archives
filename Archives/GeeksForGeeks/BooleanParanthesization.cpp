//https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0
#include <iostream>
#include <string>
using namespace std;

long long solve(string expr){
    string symb="";
    string opr="";

    for(int i=0;i<expr.length();i++){
        if(i%2==0) symb+=expr.at(i);
        else opr+=expr.at(i);
    }

    int n = symb.length();

    long long T[n][n],F[n][n];

    for(int i=0;i<n;i++){
        T[i][i] = (symb.at(i)=='T')?1:0;
        F[i][i] = (symb.at(i)=='F')?1:0;
    }

    for(int gap=1;gap<n;gap++)
        for(int i=0,j=gap;j<n;i++,j++){
            T[i][j]=0;
            F[i][j]=0;
            for(int g=0;g<gap;g++){
                int k=i+g;

                long long tik = T[i][k]%1003 + F[i][k]%1003;
                long long tkj = T[k+1][j]%1003 + F[k+1][j]%1003;

                if(opr.at(k)=='&'){
                    T[i][j]+= (T[i][k]%1003)*(T[k+1][j]%1003);
                    F[i][j]+= (tik%1003)*(tkj%1003) - (T[i][k]%1003)*(T[k+1][j]%1003);
                }
                else if(opr.at(k)=='|'){
                    F[i][j]+= (F[i][k]%1003)*(F[k+1][j]%1003);
                    T[i][j]+= (tik%1003)*(tkj%1003) - (F[i][k]%1003)*(F[k+1][j]%1003);
                }
                else{
                    T[i][j]+= (T[i][k]%1003)*(F[k+1][j]%1003) + (T[k+1][j]%1003)*(F[i][k]%1003);
                    F[i][j]+= (T[i][k]%1003)*(T[k+1][j]%1003) + (F[k+1][j]%1003)*(F[i][k]%1003);
                }
            }
        }

    return T[0][n-1];
}

int main() {
	int T; cin >> T;
	while(T--){
	    //int n; cin >> n;
	    //string expr;
	    //cin>>expr;
      string expr = "F|T^T|T|F^F^F|T&T|F^T|F^F^F&T|T^F&T|F&T^T^T&F|T&T^F^F|T&T&F^T^T|T&T^T&T&T^T^F^F^T|F&T^T&F|T&T&F^F&F&F^T^T^F&F&T^T^F^T^F&F|F^F&T|F&F&T&F&F|T^T&T^T&T&F&T|T^T^T|F|F|T|T|F&F&T^T|T^F^T^T^F|F|T^F|T&T^T&F";
	    cout << solve(expr)%1003 << "\n";
	}
	return 0;
}
