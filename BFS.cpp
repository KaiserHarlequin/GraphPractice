  //BREADTH FIRST SEARCH
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void api(vector<int >arr[],int a1,int a2)
{
arr[a1].push_back(a2);
arr[a2].push_back(a1);

}
int main()
{  int n,a1,a2,indic[99999]={0},prev[99999]={0};
	queue<int >bfs;
	vector<int>arr[100];
	 
	 cin>>n;
	 for(int j=0;j<n;j++)
	 	{
	 		cin>>a1>>a2;
	 		api(arr,a1,a2);
	 	}
int l=1;

bfs.push(l);

while(1!=0)
{  
	if(bfs.size()==0)
		break;
	int h=bfs.front();
	//cout<<h<<endl;
    int jj=0;
    indic[h]=1;

    bfs.pop();
	while(arr[h][jj])
	{    
		if(indic[arr[h][jj]]==0)
{   prev[arr[h][jj]]=h;
indic[arr[h][jj]]=1;
	bfs.push(arr[h][jj]);
	 }
++jj;


	}
}
int d=5;
while(1!=0)
{
    
    d=prev[d];
if(d==0)
break;
   cout<<d<<endl;//PRINTS THE PATH FROM 1 TO 5

 

}




}