//ͬϵ������ ��λ������
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
using namespace std;
#define MOD 1000000007 
long long dp[50][450];//50 Ϊ����  450 ��ʾ����Υ�����֣�������Ϊͬһ��Ĳ��Ϸ�����
long long a[50];  
long long c[450][450];
void init(){  

    for( int i=0; i<450; ++i ){  
        c[i][0] = c[i][i] = 1;  
    }  

    for( int i=1; i<450; ++i ){  
        for( int j=1; j<i; ++j ){  
            c[i][j] = c[i-1][j-1] + c[i-1][j];  
            if( c[i][j] >= MOD )  
                c[i][j] -= MOD;  
        }  
    }  

    a[0] = 1;  
    for( int i=1; i<50; ++i )  
        a[i] = a[i-1] * i % MOD;  
}  
int main(){
#ifdef _DEBUG
    freopen("data","r",stdin);
#endif
    init();
    int T;
    int cas=0;
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        long long sumhole=1;//0����ʱ����϶��Ϊ1
        long long A=1;
        dp[0][0]=1;//0��ʱ��ֻ��һ���ŷ�����Υ��Ϊ0
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            for(int y=0;y<450;y++){//Υ����Ϊy����dp
                if(dp[i][y]>0){
                    for(int j=1;j<=x;j++){//��������
                        for(int k=0;k<=j&&k<=y;k++){//ѡ��k��ȥ��i��Υ��������k��Υ��
                            long long temp=c[x-1][j-1]%MOD*c[y][k]%MOD*c[sumhole-y][j-k]%MOD;
							           //x�����ܹ����j����ĸ���  ��y��Υ��ѡ��k������  ��ʣ�µ�j-k����뵽��Υ���Ŀ��еĸ���
                            dp[i+1][y-k+x-j]+=dp[i][y]*temp%MOD;
							//y-k���ٵ�Υ��������xѡj���ֶ����x-j��Υ��
                            dp[i+1][y-k+x-j]%=MOD;
                        }}
                }
            }
            sumhole+=x;//�ܿ�϶����
            A=A*a[x]%MOD;//����������
        }
        printf( "Case %d: %lld\n", ++cas, dp[n][0]*A %MOD );
    }
#ifdef _DEBUG
    freopen("CON","r",stdin);
    system("pause");
#endif
    return 1;
}
