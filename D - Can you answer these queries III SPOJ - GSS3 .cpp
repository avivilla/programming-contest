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
struct st{
  int sum,prefix,suffix,best;
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
  int lc=2*node,rc=2*node+1;
  maketree(lc,left,mid,a);
  maketree(rc,mid+1,right,a);
  tree[node].sum=tree[lc].sum+tree[rc].sum;
  tree[node].prefix=max(tree[lc].prefix,tree[lc].sum+tree[rc].prefix);
  tree[node].suffix=max(tree[rc].suffix,tree[rc].sum+tree[lc].suffix);
  tree[node].best=max(tree[rc].best,max(tree[lc].best,tree[rc].prefix+tree[lc].suffix));

	return ;
}
void update(int node,int left,int  right,int x,int y)
{

  if(left==x && right==x)
  {
  	tree[node].sum=y;
  	tree[node].best=y;
  	tree[node].suffix=y;
  	tree[node].prefix=y;
  	return ;
  }
  if(x>right || x<left)
  	return ;
  int mid=(left+right)/2,lc=2*node,rc=2*node+1;
  update(lc,left,mid,x,y);
  update(rc,mid+1,right,x,y);
  tree[node].sum=tree[lc].sum+tree[rc].sum;
  tree[node].prefix=max(tree[lc].prefix,tree[lc].sum+tree[rc].prefix);
  tree[node].suffix=max(tree[rc].suffix,tree[rc].sum+tree[lc].suffix);
  tree[node].best=max(tree[rc].best,max(tree[lc].best,tree[rc].prefix+tree[lc].suffix));

	return ;




}
st query(int node,int left,int right,int x,int y)
{

  st result;
  if(x<=left && y>=right)
    return tree[node];
 int mid=(left+right)/2,lc=2*node,rc=2*node+1;

    if(mid<x)
    	return query(rc,mid+1,right,x,y);
    if(y<mid+1)
    	return query(lc,left,mid,x,y);
    st l=query(lc,left,mid,x,y);
    st r=query(rc,mid+1,right,x,y);
    result.sum=l.sum+r.sum;
    result.prefix=max(l.prefix,l.sum+r.prefix);
    result.suffix=max(r.suffix,r.sum+l.suffix);
    result.best=max(l.best,max(r.best,r.prefix+l.suffix));
    return result;





}
int main()
{
//ios_base::sync_with_stdio(false);
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
while(m--)
{
	int x,y,q;
	scanf("%d %d %d",&q,&x,&y);
	if(q)
	{
	   printf("%d\n",query(1,1,n,x,y).best);
	}
	else 
		update(1,1,n,x,y);
}
return 0;
}
