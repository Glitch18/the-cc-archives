#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int t,a,b,c,d,x,y,x1,y1,x2,y2;
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if(a>b){
			if((x-x1)<(a-b)){
				printf("NO\n");
				continue;
			}
		}
		else{
			if((x2-x)<(b-a)){
				printf("NO\n");
				continue;
			}
		}
		if(c>d){
			if((y-y1)<(c-d)){
				printf("NO\n");
				continue;
			}
		}
		else{
			if((y2-y)<(d-a)){
				printf("NO\n");
				continue;
			}
		}
		if(x==x1 && x==x2 && (a!=0 || b!=0)){
			printf("NO\n");
			continue;
		}
		if(y==y1 && y==y2 && (c!=0 || d!=0)){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
}
