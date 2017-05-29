 
//DEPTH FIRST SEARCH IMPEMENTATION

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countt=1 ;
void work(vector<int >h[],int x,int y)
{
h[x].push_back(y);
h[y].push_back(x);
}
void dfs(vector<int >e[],int l,int z[],int prev[])
{  int rt=0;
	z[l]=1;
	while(1!=0)
{  if(e[l][rt])
{      
	if(z[e[l][rt]]==0)
		{ ++countt;prev[e[l][rt]]=l;
		 dfs(e,e[l][rt],z,prev);}
++rt;}
else break;




}
}




int main()
{
vector<int >adj[100]; 
int z[999]={0}; 
int prev[999]={0}; 
int  g,h,i=0;
for(int e=0;e<=7;e++)
{ 
cin>>g>>h;
work(adj,g,h);
}
dfs(adj,2,z,prev);//start from 2
cout<<countt;//total no of vertices
int l=8;//finding a path from 2 to 8
while(1!=0)
{
int q=prev[l];
cout<<q<<endl;
l=q;
if(l==2)break;


}




}


