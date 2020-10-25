#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    //ifstream file("question.txt",ifstream::in);

    int x,y,f=0;
    //while(file >> x >> y){
    while(cin >> x >> y){
        char matrix[x][y];
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                cin >> matrix[i][j];

        printf("Field #%d:\n",f++);
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(matrix[i][j]=='*'){
                    printf("*");
                    continue;
                }

                int bombs=0;
                if(i-1>=0){
                    if(matrix[i-1][j]=='*') bombs++;
                    if(j-1>=0) if(matrix[i-1][j-1]=='*') bombs++;
                    if(j+1<y) if(matrix[i-1][j+1]=='*') bombs++;
                }

                if(j-1>=0) if(matrix[i][j-1]=='*') bombs++;
                if(j+1<y) if(matrix[i][j+1]=='*') bombs++;

                if(i+1<x){
                    if(matrix[i+1][j]=='*') bombs++;
                    if(j-1>=0) if(matrix[i+1][j-1]=='*') bombs++;
                    if(j+1<y) if(matrix[i+1][j+1]=='*') bombs++;
                }
                printf("%d",bombs);
            }
            printf("\n");
        }
        printf("\n");       
    }    
}
 
