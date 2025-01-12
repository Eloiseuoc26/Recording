#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int sto[5005];
int main(){
	int n;
	cin>>n;
	int ans=0;  //方法数 
	int maxn=-1;
	int minn=5005;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		sto[num]++;  //统计每个长度的棍子出现的次数
		maxn=max(maxn,num);  //最大值和最小值 
		minn=min(minn,num);
	}
	for(int i=minn+1;i<=maxn;i++){  //遍历所有木棍 
		if (sto[i]>=2){  //有 N 根棍子，取四根做正三角形 →两根长度相同 
			for(int k=minn;k<=i/2;k++){  //另外两根拼起来跟i的长度一样 k取到i/2即可 不然会重复 
				if (k!=i-k){  //如果这两根长度不一样 
					ans+=(sto[i]*(sto[i]-1)/2%mod)*sto[k]*(sto[i-k])%mod;  //第一个括号内算的是sto[i]C2 第二个括号就是另外两根长度的木棍分别有几根就有几种取法 
				}
				else{  //另外两根长度一样 
					ans+=sto[i]*(sto[i]-1)/2%mod*sto[k]*(sto[k]-1)/2%mod;  //都为xC2 
				}
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
