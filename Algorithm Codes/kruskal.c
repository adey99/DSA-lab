#include<stdio.h>
#include<stdlib.h>
	int i,j,k,a,b,u,v,n,ne = 1;
	int min,mincost=0,cost[10][10],parent[10],min_span[10][10];
	int find(int);
	int uni(int,int);
	void main()
	{
		 printf("\nEnter the number of vertices in the graph:");
		 scanf("%d",&n);
		 printf("\nEnter the cost adjacency matrix:\n");
		 for(i = 1;i <= n;i++)
		  {
		 	for(j = 1;j <= n;j++)
		   {
		   	scanf("%d",&cost[i][j]);
		   	if(cost[i][j] == 0)
				cost[i][j] = 999;
		   }
		  }
		 printf("\nThe edges taken are in sequence - :");
		 while(ne < n)
		 {
		 	for(i = 1,min = 999;i <= n;i++)
		  {
		   		for(j = 1;j <= n;j++)
		   	  {
					if(cost[i][j] < min)
				{
			 			min = cost[i][j];
						 a = u = i;
			 			 b = v = j;
				}
		   	  }
  		  }
		  u = find(u);
		  v = find(v);
		  if(uni(u,v))
		  {
		   	printf("\n%d. cost of edge (%d,%d) is equal to %d\n",ne++,a,b,min);
			min_span[a][b]=min_span[b][a]=cost[a][b];
		   	mincost += min;
		  }
		  cost[a][b] = cost[b][a] = 999;
		 }
		printf("\n\nThe cost adjacency matrix for the minimum spanning tree is:\n");
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				printf("%d ",min_span[i][j]);
			printf("\n");
		}
		 printf("\n The minimum cost of the given graph is equal to %d\n",mincost);
		}
		int find(int i)
		{
		 	while(parent[i])
		  		i = parent[i];
		 	return i;
		}
		int uni(int i,int j)
		{
		 	if(i != j)
		 {
		  		parent[j] = i;
		  		return 1;
		 }
		 	return 0;
		}
