#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int sto[5005];
int main(){
	int n;
	cin>>n;
	int ans=0;  //������ 
	int maxn=-1;
	int minn=5005;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		sto[num]++;  //ͳ��ÿ�����ȵĹ��ӳ��ֵĴ���
		maxn=max(maxn,num);  //���ֵ����Сֵ 
		minn=min(minn,num);
	}
	for(int i=minn+1;i<=maxn;i++){  //��������ľ�� 
		if (sto[i]>=2){  //�� N �����ӣ�ȡ�ĸ����������� ������������ͬ 
			for(int k=minn;k<=i/2;k++){  //��������ƴ������i�ĳ���һ�� kȡ��i/2���� ��Ȼ���ظ� 
				if (k!=i-k){  //������������Ȳ�һ�� 
					ans+=(sto[i]*(sto[i]-1)/2%mod)*sto[k]*(sto[i-k])%mod;  //��һ�������������sto[i]C2 �ڶ������ž��������������ȵ�ľ���ֱ��м������м���ȡ�� 
				}
				else{  //������������һ�� 
					ans+=sto[i]*(sto[i]-1)/2%mod*sto[k]*(sto[k]-1)/2%mod;  //��ΪxC2 
				}
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
