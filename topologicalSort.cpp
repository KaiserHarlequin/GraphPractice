
//TOPOLOGICAL SORT
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void fire(vector<int>arr[99],int a,int b)
{
    arr[a].push_back(b);

}
vector<int>sty;
int countt[99]={0};
void dfs(vector<int >arr[99],int q,int stor[])
{
if(stor[q]==0)
{    stor[q]=1;

    int jj=0;
    sort(arr[q].begin(),arr[q].begin()+countt[q]);
    while(jj<countt[q])
    {

         dfs(arr,arr[q][jj],stor);
         ++jj;
   }


sty.push_back(q);
cout<<q<<" ";

} }


int main()
{
vector<int>arr[99];
int size,store[99]={0};
cin>>size;
int a,b;
for(int i=0;i<size;i++)
{

cin>>a>>b;
countt[a]=countt[a]+1;
fire(arr,a,b);

}
for(int e=0;e<=6;e++)
	{if(store[e]==0)
		dfs(arr,e,store);
	//cout<<"SD";
}}








 






 