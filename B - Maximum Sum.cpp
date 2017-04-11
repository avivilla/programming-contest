#include<bits/stdc++.h>
#define pii                pair<int,int>
#define mkp            make_pair
#define fs                 first
#define sc                 second
#define pb                push_back
#define ppb              pop_back()
#define pcase(x)       cout<<"Case "<<x<<": ";
#define hi        cout<<"hi"<<endl;
#define mx                 1000000007
#define inf                  1000000007
#define pi                    acos(-1.0)
#define mem(arr,x)    memset((arr), (x), sizeof((arr)));
#define FOR(i,x)          for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i = 1; i<=(x) ; i++)
#define jora(a,b)       make_pair(a,b)
using namespace std;
typedef long long int lint;
typedef double dbl;

int atree[3*100005],btree[3*100005],a[100005];
void maketree(int node,int left,int right)
{
	if(left==right)
	{
		atree[node]=a[left];
		btree[node]=-1;
		//cout<<atree[node]<<" "<<btree[node]<<" "<<node<<endl;
		return ;
	}

	int mid=(left+right)/2;
	maketree(2*node,left,mid);
	maketree(2*node+1,mid+1,right);
	
	vector<int>vt;
	vt.push_back(atree[2*node]);
     vt.push_back(btree[2*node]);
     vt.push_back(atree[2*node+1]);
     vt.push_back(btree[2*node+1]);
     sort(vt.begin(),vt.end());
     atree[node]=vt[3];
     btree[node]=vt[2];
     return ;
}
void update(int node,int left,int right,int x,int value)
{

            if(left==right && left==x)
	{

		atree[node]=value;
		btree[node]=-1;

		return ;
	}
      if(left>x || right<x)
      	return ;
      int mid=(left+right)/2;
      update(2*node,left,mid,x,value);
       update(2*node+1,mid+1,right,x,value);

     vector<int>vt;
	 vt.push_back(atree[2*node]);
     vt.push_back(btree[2*node]);
     vt.push_back(atree[2*node+1]);
     vt.push_back(btree[2*node+1]);
     // FOR(i,vt.size())
     // cout<<vt[i]<<" ";
     // cout<<endl;
     sort(vt.begin(),vt.end());
     atree[node]=vt[3];
     btree[node]=vt[2];
      //cout<<left<<" "<<right<<" "<<node<<" "<<atree[node]<<"  "<<btree[node]<<endl;
   return ;
}
pii query(int node,int left,int right,int a,int b)
{
   if(left>b || right<a)
      return make_pair(-1,-1);
     //cout<<left<<" "<<right<<" "<<a<<" "<<b<<endl;
   if(left>=a && right<=b)
   	   return make_pair(atree[node],btree[node]);
   	int mid=(left+right)/2;
   	pii x=query(2*node,left,mid,a,b);
   	pii y=query(2*node+1,mid+1,right,a,b);

    vector<int>vt;
	vt.push_back(x.fs);
    vt.push_back(x.sc);
    vt.push_back(y.fs);
    vt.push_back(y.sc);
    sort(vt.begin(),vt.end());
    //cout<<" hhjhjj "<<left<<" "<<right<<" "<<a<<" "<<b<<endl;
    //cout<<" hi "<<x.fs<<" "<<x.sc<<" "<<y.fs<<" "<<y.sc<<endl;
   // cout<<endl;
    return make_pair(vt[3],vt[2]);


}
int main()
{
ios_base::sync_with_stdio(false);
int test,case_no=1;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int n;
cin>>n;
FOR1(i,n)
{
	cin>>a[i];
}
int m;
maketree(1,1,n);
cin>>m;
while(m--)
{
   char q; 
 int x,y;
 cin>>q>>x>>y;
 if(q=='U')
 	{
 		update(1,1,n,x,y);
 	    

 	}
 else {
 	    
 	    pii tem=query(1,1,n,x,y);
 	     // cout<<tem.fs<<" "<<tem.sc<<endl;
 	    cout<<tem.fs+tem.sc<<endl;
          
      }
}

return 0;
}
