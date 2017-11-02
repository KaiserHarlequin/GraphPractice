//LAZY PROPOGATION OF SEGMENT SERIES


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int store[999]={0};
int arr[999]={0};
void build(int pos,int start,int stop)
{
	int mid=(start+stop)/2;
if(start==stop)
	store[pos]=arr[start];

else
{
build(2*pos,start,mid);
build(2*pos+1,mid+1,stop);
store[pos]=min(store[2*pos+1],store[pos*2]);
}
}
int lazy[999]={0};
void updateSg(int pos,int start,int stop,int qst,int qsp,int d)
{
	int mid=(start+stop)/2;
	if(!(qst>stop || start>qsp))
	{
if(qst<=start && qsp>=stop)
{
	if(lazy[pos]==0)
		{   
			lazy[2*pos]=lazy[2*pos]+d;
			lazy[2*pos+1]=lazy[2*pos+1]+d;
			store[pos]=store[pos]+d;
		}
	else
	{
      store[pos]=store[pos]+lazy[pos]+d;
      lazy[2*pos]=lazy[pos]+lazy[2*pos]+d;
      lazy[2*pos+1]=lazy[pos]+lazy[2*pos+1]+d;
      lazy[pos]=0;
	}
}
else
{
	lazy[2*pos]=lazy[pos]+lazy[2*pos];
      lazy[2*pos+1]=lazy[pos]+lazy[2*pos+1];
      lazy[pos]=0;
updateSg(2*pos,start,mid,qst,qsp,d);
updateSg(2*pos+1,mid+1,stop,qst,qsp,d);
store[pos]=min(store[2*pos],store[2*pos+1]);
}
}
}
int query(int pos,int start,int stop,int qst,int qsp)
{  int mid=(start+stop)/2;
if((qst>stop || start>qsp))
return(9999);

if(qst<=start && qsp>=stop)
{
 store[pos]=store[pos]+lazy[pos];
      lazy[2*pos]=lazy[pos]+lazy[2*pos];
      lazy[2*pos+1]=lazy[pos]+lazy[2*pos+1];
      lazy[pos]=0;
      return(store[pos]);
}
else
{	 lazy[2*pos]=lazy[pos]+lazy[2*pos];
      lazy[2*pos+1]=lazy[pos]+lazy[2*pos+1];
      lazy[pos]=0;
store[pos]=min(query(2*pos,start,mid,qst,qsp),query(2*pos+1,mid+1,stop,qst,qsp));
return(store[pos]);
}

}

int main()
{
int n;
cin>>n;
for(int u=1;u<=n;u++)
	cin>>arr[u];
build(1,1,n);
for(int x=1;x<=2*n-1;x++)
	cout<<store[x]<<" ";
cout<<endl;

int m;
cin>>m;//NO OF UPDATES
for(int h=0;h<m;h++)
{
int qst,qsp,d;
cin>>qst>>qsp>>d;
updateSg(1,1,n,qst,qsp,d);
for(int x=1;x<=2*n-1;x++)
	cout<<store[x]<<" ";
cout<<endl;

}
int queryt;

cin>>queryt;//NUMBER OF QUERIES
for(int u=1;u<=queryt;u++)
{
int x,y;
cin>>x>>y;
cout<<query(1,1,n,x,y)<<endl;



}

}













 





 