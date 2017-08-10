//PRIM ALGORITHM TO FIND MINIMUM SPANNING TREE
//(PS:IGNORE THE FIRST LINE )


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class kys
{

public:
	bool operator ()(pair<int,int >q1,pair<int,int > q2)
	{

return(q1.second>=q2.second);



	}

};

void work(int a,int b,int c,vector<pair<int ,int > >arr[111])
{
   arr[a].push_back(make_pair(b,c));
   arr[b].push_back(make_pair(a,c));
}

int main()
{
	int m,n;
	int  store[999]={0};
	int value[999]={0};
    int zon[9999]={0};
    int vt[9999]={0};
	vector<pair<int ,int > >arr[111];
	 map<int ,map <int ,int> >mp;
	cin>>m;
	priority_queue<pair<int,int> ,vector<pair<int,int> >,kys >burn;
	cin>>n;
 
	for(int i=0;i<n;i++)
	{


int q1,q2,q3;
cin>>q1>>q2>>q3;
mp[q1][q2]=q3;
mp[q2][q1]=q3;
work(q1,q2,q3,arr);
 store[i+1]=9999;


	}
int mj=0;
burn.push(make_pair(1,0));

	while(!burn.empty())
	{
   int l1=burn.top().first;
   int l2=burn.top().second;
   burn.pop();
   int q=zon[l1];
   zon[l1]=1;
    if(q==0)
    { 
        
    	++mj;
    	//cout<<">>"<<arr[l1].size()<<"<<";
    	cout<<l1<<" "<<vt[l1]<<endl;
   for(int j=0;j<arr[l1].size();j++)
   {   
      // cout<<arr[l1][j].first<<endl;

   	if(store[arr[l1][j].first]>mp[l1][arr[l1][j].first] && zon[arr[l1][j].first]==0)
   {	
   	store[arr[l1][j].first]=mp[l1][arr[l1][j].first];
        //cout<< arr[l1][j].first<<endl;
   	vt[arr[l1][j].first]=l1 ;
        burn.push(make_pair(arr[l1][j].first,mp[l1][arr[l1][j].first]));

}

}
cout<<endl;
}
if(mj==m)
{break;
cout<<"du";
}
}
}