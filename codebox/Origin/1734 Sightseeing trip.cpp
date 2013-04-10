//floyd��Dijkstra����Dijkstra�Ǵ�һ����������������̾���;floyd������㵽��֮����̾��룬
//���Ѵ��ڵ�·��ͨ�����һ����ȥ�ɳڣ����Ƿ��ܵõ����̵�·��
//��С������ floyd����
#include<iostream>
using namespace std;
const int N = 101;
const int INF = 0x7ffffff;
int mat[N][N],dist[N][N],pre[N][N],path[N],n;
int main(){
#ifdef _DEBUG
	freopen("data","r",stdin);
#endif
	int i,j,k,m,a,b,c;
	int num;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				mat[i][j]=dist[i][j]=INF;
				pre[i][j]=i;
			}
		}
		while(m--){
			scanf("%d%d%d",&a,&b,&c);
			mat[a][b]=mat[b][a]=dist[a][b]=dist[b][a]=min(mat[a][b],c);
		}
		int min=INF;
		for(k=1;k<=n;k++){//���·����һ�㽫���·��β����,��ô�͵õ�һ����С��
			for(i=1;i<k;i++){//�����ɳڳ�(1,n),(i,k)֮������·,(k,j)֮������·�������غϵĲ���
				for(j=i+1;j<k;j++){
					//����С����������������·�ɳ�,��Ϊ(i,k)֮������·,(k,j)֮������·�������غϵĲ���
					//����mat[][]��ʵ�ǲ����µ�,����͵�����floyd���·��һ��
					//dist[i][j]������� i �� j �����·Ȩֵ��
					int tmp=dist[i][j]+mat[i][k]+mat[k][j];//���� k �ֱ�� i ���� j ��mat��ֱ������
					if(tmp<min){
						min=tmp;
						num=0;
						int p=j;
						while(p!=i){//���ݣ�Ѱ�Ҹ��ڵ㷨
							path[num++]=p;
							p=pre[i][p];//pre[i][j]��ʾ i �� j ���·���� j ǰ���һ����
						}
						path[num++]=i;
						path[num++]=k;
					}
				}
			}
			//���¾���ʹ�ͳfloydһ��
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(dist[i][j]>dist[i][k]+dist[k][j]){
						dist[i][j]=dist[i][k]+dist[k][j];//dist[][]�����������̾���
						pre[i][j]=pre[k][j];//��j��ǰһ������K��Ѱ�Ҹ��ڵ㷨
					}
				}
			}
		}
		if(min==INF)puts("No solution.");
		else{
			printf("%d",path[0]);
			for(i=1;i<num;i++)
				printf(" %d",path[i]);
			printf("\n");
		}
	}
#ifdef _DEBUG
	freopen("CON","r",stdin);
	system("pause");
#endif
	return 0;
}
