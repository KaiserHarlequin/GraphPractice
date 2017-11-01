//FENWICK TREE TO FIND SUM FROM 1 TO NTH ELEMENT IN LOG(N)TIME

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 int arr[111111]={0};
 int n;
void built(int store[])
{
 
for(int e=1;e<=n;e++)
{
	int index=e;
while(index<=n)
{
	//cout<<index<<" ";
store[index]=store[index]+arr[e];
index=index+(index&(-1*index));
 
}
//cout<<endl;
}
}
int main()
{
int tch;
cin>>n>>tch;
for(int l=1;l<=n;l++)
cin>>arr[l];
int store[1111]={0};
built(store);
//for(int h=1;h<=n;h++)
//cout<<store[h]<<" ";

int j=0,uu;
uu=tch;
while(uu!=0)
{
j=j+store[uu];
uu=uu-(uu&(-uu));
}
cout<<j;
}






 