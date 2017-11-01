#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int > arr[999];
int check[999]={0};
vector<int > worl;
void DFS(int start)
{

if(check[start]==0)
{   
check[start]=1;
worl.push_back(start);
for(int u=0;u<arr[start].size();u++)
{
DFS(arr[start][u]);
if(worl[worl.size()-1]!=start)
worl.push_back(start);
}
 	
}
}
int main()
{
int n;
cin>>n;
for(int u=0;u<n-1;u++)
{
int a,b;
cin>>a>>b;
arr[a].push_back(b);
arr[b].push_back(a);
}

DFS(1);

for(int y=0;y<worl.size();y++)
	cout<<worl[y]<<" ";






}