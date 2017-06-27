//KAHN ALGORITHM FOR TOPOLOGICAL SORTING

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

queue<int >dd;
vector<int >vv;
int hh[111]={0};
void fire(vector<int>arr[101],int a,int b,int countt[])
{
    arr[a].push_back(b);
    hh[a]=hh[a]+1;
    countt[b]=countt[b]+1;
}

void kahn(vector<int>arr[101],int countt[],int n)
{
for(int k=1;k<=n;k++)
	{   
       if(countt[k]==0)
          dd.push(k);
  }
  while(!dd.empty())
  {

  	int v= dd.front();
  	cout<<v<<endl;
     dd.pop();
  	int jj=0;
  	 while(jj<hh[v])
   {    
      // cout<<"DS";
   	countt[arr[v][jj]]=countt[arr[v][jj]]-1;
   		if(countt[arr[v][jj]]==0)
     dd.push(arr[v][jj]);


     ++jj;
 }


  }
}









 









int main()
{
	int n,a,b;
	vector<int>arr[101];
	int countt[101]={0};
	cin>>n;
	for(int e=0;e<n;e++)
		{cin>>a>>b;
          fire(arr,a,b,countt);

		}

kahn(arr,countt,n);

}