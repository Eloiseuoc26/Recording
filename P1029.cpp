#include<bits/stdc++.h>
using namespace std;
int x,y;
int gcd,cm;
inline void calculate(int a,int b){
	int aa=a;
	int bb=b;
	int r=a;
	while(r!=0){
		r=b%a;
		b=a;
		a=r;
	}
	cm=b;
	gcd=aa/cm*bb;
}
inline bool judge(int a,int b){
	gcd=0;
	cm=0;
	calculate(a,b);
	if (gcd==y && cm==x){
		return true;
	}
	return false;
}
int main(){
	int cnt=0;
	cin>>x>>y;
	for(int i=x;i<=y;i++){
		int j=y/i*x;
		if (judge(i,j)){
			if (i==j) cnt+=1;
			else cnt+=2;
		}
		if (j<=i){
			break;
		}
	}
	cout<<cnt;
	return 0;
}
