/*
    algorithm : Edmonds-Karp
 
    Memory 764K Time 0MS    Language G++
 
    code by : zhyu
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define inf 0x7fffffff
#define N 205
using namespace std;
int map[N][N],path[N],flow[N],start,end,m,n;
queue<int> q;
int bfs(void)//Ѱ������·���ù������
{
    register int i;
    int t;
    while(!q.empty()) q.pop();
    memset(path,-1,sizeof(path));
    path[start]=0,flow[start]=inf;
    q.push(start);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t==end) break;
        for(i=1;i<=m;i++)//Ѱ����һ�����ӵ�
        {
            if(i!=start && path[i]==-1 && map[t][i])//������㣬δ�����ʹ���ʣ��������0
            {
                flow[i]=flow[t]<map[t][i]?flow[t]:map[t][i];//����·ѡ����С��
                q.push(i);
                path[i]=t;
            }
        }
    }
    if(path[end]==-1) return -1;
    return flow[m];
}
int EK(void)
{
    int max_flow=0,step,pre,now;
    while((step=bfs())!=-1)//�������·����С��
    {
        max_flow+=step;//��������ϸô���С��
        now=end;
        while(now!=start)//�������·��
        {
            pre=path[now];//ǰһ��
            map[pre][now]-=step;//������
            map[now][pre]+=step;//���ӷ�����
            now=pre;
        }
    }
    return max_flow;
}
int main(void)
{
    register int i;
    int u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            map[u][v]+=w;
        }
        start=1,end=m;
        printf("%d\n",EK());
    }
    return 0;
}
 