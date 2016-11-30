#include<stdio.h>

#define MIN 100000
int m,n,u,v,bestw;

int e[100][100],w[100],c[100];

int cover()
{
	int i,j,t;
	i=1;
	while(i<=n)
	{
		t=0;
		if(c[i]==0)
		{
			j=1;
			while(j<i)
			{
				if(e[j][i]==1&&c[j]==1)
					t=1;
				j++;
			}
			j++;
			while(j<=n)
			{
				if(e[i][j]==1&&c[j]==1)
					t=1;
				j++;
			}
			if(t==0)
				return 0;
		}
		i++;
	}
	return 1;
}
void cut(int i,int s)
{
	if(s>=bestw)
		return;
	if(i>n)
	{
		if(cover())
			bestw=s;
		return;
	}
	c[i]=0;
	cut(i+1,s);
	c[i]=1;
	cut(i+1,s+w[i]);
}

int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		c[i]=0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			e[i][j]=0;
		for(k=1;k<=m;k++)
		{
			scanf("%d%d",&u,&v);
			e[u][v]=1;
		}
		bestw=MIN;
		cut(1,0);
		printf("%d",bestw);
		return 0;
}
