//FINDING ARTICULATION POINT

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void fire(vector<int> arr[99],int a,int b)
{ arr[a].push_back(b);
	arr[b].push_back(a);
}
int lv=0;
set<int >zz;
void DFS(vector<int > arr[99],int st,int cot[],int prt[],int time[],int low[],int jb,int prev)
{


	if(cot[st]==0)
	{    
        cot[st]=1;
        time[st]=lv;
        //cout<<st<<" "<<time[st]<<endl;
        low[st]=lv;
        ++lv;
        ++jb;
		int jj=0;
		prev=st;
		for(int h=0;h<arr[st].size();h++)
		{     if(cot[arr[st][h]]==0)      
             prt[arr[st][h]]=st;
			DFS(arr,arr[st][h],cot,prt,time,low,jb,prev);
        }
           if(prt[st]!=-1)
        if(low[st]>=time[prt[st]]  && arr[prt[st]].size()>1)
        	{
                  //if(prt[st]==0) cout<<">"<<st<<"<";
        		zz.insert(prt[st]);



        	}
    }
    else if(cot[st]==1 && st!=prt[prev]  )
    	{   low[prev]=min(low[prev],low[st]);
            //cout<<st<<" "<<prev<<endl;
    	}
     





}
int main()
{  int n,a,b,cot[99]={0},prt[99]={0},time[99]={0},low[99]={0},jb=0,prev=0;
	cin>>n;
	vector<int >arr[99];
	for(int f=0;f<n;f++)
	{    cin>>a>>b;
		fire(arr,a,b);



	}
	set<int>::iterator it;
	prt[2]=-1; // starting from 2,can change it

	DFS(arr,2,cot,prt,time,low,jb,prev);
	for(it=zz.begin();it!=zz.end();it++)
		cout<<*it<<endl;



}