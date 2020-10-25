#include<stdio.h>
#include<vector>
#include<utility>
#include<map>

int cycleLength(int x,std::map<int,int>& memory){
    if(memory.find(x)!=memory.end()) return memory[x];
    int clength;
    if(x%2==0) clength = cycleLength(x/2,memory);
    else clength = cycleLength(3*x+1,memory);

    memory[x]=clength + 1;
    return clength+1;
}

int main(){
    //FILE* inpfile = fopen("question.txt","r");
    
    int i,j;
    std::vector<int> input;
    std::map<int,int> memory;
    memory[1] = 1;
    memory[2] = 2;
    memory[3] = 8;
    //while(fscanf(inpfile,"%d %d",&i,&j)!=EOF){
    while(scanf("%d %d",&i,&j)!=EOF){
        input.push_back(i); input.push_back(j);
    }
    for(int i=0;i<=input.size()-2;i+=2){
        int x = input[i], y=input[i+1];
        if(x>y) std::swap(x,y);
        int maximum = 0;
        for(int j=x;j<=y;j++){
            int clength = cycleLength(j,memory);
            if(clength>maximum) maximum=clength;
        }
        if(input[i]>input[i+1]) std::swap(x,y);
        printf("%d %d %d\n",x,y,maximum);
    }
} 
