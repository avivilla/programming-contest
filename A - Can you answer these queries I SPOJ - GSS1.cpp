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
//lint best[50055],prefix[50055],suffix[50055],ressum[50055],ressuf[50055],respre[50055];
struct st
{
	int sum,best,suffix,prefix;
}tree[3*50050];

void maketree(int node,int left,int right,int a[])
{
    if(left==right)
    {
    	tree[node].sum=a[left];
    	tree[node].best=a[left];
    	tree[node].prefix=a[left];
    	tree[node].suffix=a[left];
    	return ;
    }
    int mid=(left+right)/2;
    maketree(2*node,left,mid,a);
    maketree(2*node+1,mid+1,right,a);
    tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
       tree[node].prefix=max(tree[2*node].prefix,tree[2*node].sum+tree[2*node+1].prefix);
    tree[node].suffix=max(tree[2*node+1].suffix,tree[2*node+1].sum+tree[2*node].suffix);    
    tree[node].best=max(tree[2*node+1].best,max(tree[2*node].best,max(tree[node].suffix,max(tree[node].prefix,tree[2*node].suffix+tree[2*node+1].prefix))));
    // tree[node].best=max((tree[2*node+1].prefix+tree[2*node].suffix),max(tree[2*node].best,max(trtree[2*node+1].best)));
 


	return ;
}
st query(int node,int left,int right,int x,int y)
{
	st tem,result;
tem.sum=INT_MIN;
tem.best=INT_MIN;
tem.suffix=INT_MIN;
tem.prefix=INT_MIN;
	if(left>y || right<x)
		return tem;
     
  if(x<=left && y>=right)
  	return tree[node];
	int mid=(left+right)/2;
	if(x>mid)
		{
			//cout<<"HIII  "<<mid<<" "<<left<<" "<<right<<endl;
			return query(2*node+1,mid+1,right,x,y);
		}
	if(y<mid+1)
		{
			//cout<<"HIII111  "<<mid+1<<" "<<left<<" "<<right<<endl;
			return query(2*node,left,mid,x,y);
		}

    st l=query(2*node,left,mid,x,y);
    st r=query(2*node+1,mid+1,right,x,y);
    result.sum=l.sum+r.sum;
     result.suffix=max(r.suffix,r.sum+l.suffix);
    result.prefix=max(l.prefix,l.sum+r.prefix);
    result.best=max(l.suffix+r.prefix,max(result.suffix,max(result.prefix,max(l.best,r.best))));
   //cout<<left<<" "<<right<<" "<<result.sum<<" "<<result.best<<" "<<result.prefix<<" "<<result.suffix<<endl;
    return result;




}

int main()
{

int test,case_no=1;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int n;
scanf("%d",&n);
int a[n+5];
FOR1(i,n)
  scanf("%d",&a[i]);
  maketree(1,1,n,a);
int m;
scanf("%d",&m);
FOR(i,m)
{
	int x,y;
	scanf("%d",&x,&y);
	
	
	printf("%d\n",query(1,1,n,x,y).best);
}


return 0;
}
