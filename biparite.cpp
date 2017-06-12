//BIPARITE
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void api(vector<int >arr[],int a1,int a2)
{
arr[a1].push_back(a2);
arr[a2].push_back(a1);

}
int main()
{  int n,a1,a2,indic[99999]={0},prev[99999]={0},me,zz=0;
	queue<int >bfs;
	vector<int>arr[100];
	 
	 cin>>n;
	 for(int j=0;j<n;j++)
	 	{
	 		cin>>a1>>a2;
	 		api(arr,a1,a2);
	 	}
int l=1;
me=l;
bfs.push(l);
indic[1]=1;
while(1!=0)
{  
	if(bfs.size()==0)
		break;
	int h=bfs.front();
	//cout<<h<<endl;
    int jj=0;
    
me=indic[h];
    bfs.pop();
	while(arr[h][jj])
	{    
		if(indic[arr[h][jj]]==0)
{   prev[arr[h][jj]]=h;
indic[arr[h][jj]]=me*-1;
	bfs.push(arr[h][jj]);
	 }
	 else if(indic[arr[h][jj]]==me)
	 zz=11;
++jj;


	}
}
int d=6;
 
if(zz==11)
cout<<"NO!";
else
cout<<"biparite";


}