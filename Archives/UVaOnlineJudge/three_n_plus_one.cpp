#include<stdio.h>
#include<vector>
#include<utility>
#include<map>

std::pair<int,int> cycleLength(int x,int buffer,std::map<int,int>& memory){
    if(memory.find(x)!=memory.end()) return std::make_pair(memory[x],buffer);
    
    std::pair<int,int> clength;
    if(x%2==0) clength = cycleLength(x/2,buffer+1,memory);
    else clength = cycleLength(3*x+1,buffer+1,memory);

    memory[x]=clength.first + clength.second - buffer;
    return clength;
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
            std::pair<int,int> clength = cycleLength(j,0,memory);
            int dist = clength.first + clength.second;
            if(dist>maximum) maximum=dist;
        }
        if(input[i]>input[i+1]) std::swap(x,y);
        printf("%d %d %d\n",x,y,maximum);
    }
} 
