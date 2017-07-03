//KOSARAJU ALGORITHM


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void fire(vector<int> arr1[111],vector<int >arr2[111],int a,int b)
{   
	arr1[a].push_back(b);
	arr2[b].push_back(a);
}
vector<int>store;
int hh=0;
void DFS(vector<int >arr[111],int start,int fin[],int bb)
{

if(fin[start]==0)
{

fin[start]=bb;
if(hh==1)
	cout<<start<<" "<<bb<<endl;



for(int j=0;j<arr[start].size();j++)
{ 
DFS(arr,arr[start][j],fin,bb);
}
if(hh==0)

{
store.push_back(start);
//cout<<start<<endl;
}
}
}

int main()
{
	int n,a,b;
	int fin1[111]={0},fin2[111]={0},bb=1;
vector<int >arr1[111];
vector<int >arr2[111];
cin>>n;
for(int h=0;h<n;h++)
{  cin>>a>>b;
fire(arr1,arr2,a,b);
}
for(int q=1;q<=11;q++)
{
if(fin1[q]==0)
DFS(arr1,q,fin1,1);

}
hh=1;
for(int z=store.size()-1;z>=0;z--)
{
if(fin2[store[z]]==0)
{

	DFS(arr2,store[z],fin2,bb);
	++bb;
}





}
}




















 