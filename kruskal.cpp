//KRUSKAL ALGORITHM FOR MINIMUM SPANNING TREE

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool wind(pair <pair<int,int > ,int >a1,pair <pair<int,int > ,int >a2)
{
return(a1.second<a2.second);

}









void fire(vector<pair<int ,int> >arr[111],vector<int >jj[111],int a,int b,int wt)
{
	arr[a].push_back(make_pair(b,wt));
	arr[b].push_back(make_pair(a,wt));
    jj[a].push_back(b);
    jj[b].push_back(a);
}

void UNION(int a,int b,int prnt[111],int rank[111])

{
if(prnt[a]==0 && prnt[b]==0)
{
if(rank[a]>rank[b])
	prnt[b]=a;
else if(rank[a]==rank[b])
{
prnt[b]=a;
rank[a]=rank[a]+1;
}
else
{
prnt[a]=b;


}
}
}

int find(int prnt[111],int a)
{

if(prnt[a]==0)
	return(a);
else 
	return(find(prnt,prnt[a]));

}




int main()
{ 

	vector<pair<int ,int> >arr[111];
	vector<int >jj[111];
	vector<pair <pair<int,int > ,int > >www;
	int a,b,wt,sum=0;
	int prt[111]={0},rank[111]={0};

int n;

cin>>n;
for(int q=0;q<n;q++)
{ 
cin>>a>>b>>wt;
fire(arr,jj,a,b,wt);
www.push_back(make_pair(make_pair(a,b),wt));
}

sort(www.begin(),www.end(),wind);
int uu=0;
for(int u=0;u<n;u++)
{  
  int x1,x2,x3;
  x1=www[u].first.first;
  x2=www[u].first.second;
  x3=www[u].second;
  //cout<<x1<<" "<<x2<<" "<<x3<<endl;
  //if(x1==9 && x2==7)
  //cout<<find(prt,x1)<<" "<<find(prt,x2)<<endl;
  int m=find(prt,x1);
  int n=find(prt,x2);
 if(m!=n)
{   //cout<<m<< " <<"<<n<<endl;
 cout<<x1<<" "<<x2<<" "<<x3<<endl;
++uu;
UNION(find(prt,x1),find(prt,x2),prt,rank);
sum=sum+x3;
if(uu==n-1)
	break;
}
}
cout<<"SUM"<<sum<<endl;
}























 

 





 