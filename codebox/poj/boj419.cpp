//大于等于一半，先取出一个进行判断，如果是答案，输出，不是则去除，这样保证大于一半
#include<iostream>
#include<stdio.h>
using namespace std;
int a[5000001];
int b[5000001];
int main()
{
  freopen("data","r",stdin);
  int i,n,temp;
  int top;
  int sum=1;
  while(scanf("%d",&n)!=EOF) 
    {
      int count=0;
      for(i=0;i<n;i++)
	{
	  scanf("%d",&b[i]);
	  if(b[0]==b[i])
	    count++;
	}
      if(count>=n/2)
	{
	  cout<<"Case "<<sum<<": "<<b[0]<<endl; 
	  cout<<endl; 
	  sum++; 
	}
      else
	{
	  top=-1;
	  for(i=1;i<n;i++)
	    {
	      if(top==-1)
		{
		  top++;
		  a[top]=b[i];
		}
	      else
		{
		  if(b[i]==a[top])
		    {
		      top++;
		      a[top]=b[i];
		    }
		  else
		    {
		      top--;
		    }
		}
	    }
	  cout<<"Case "<<sum<<": "<<a[top]<<endl; 
	  cout<<endl; 
	  sum++; 
	}
    }
  freopen("CON","r",stdin);
  system("pause");
  return 0;
}
