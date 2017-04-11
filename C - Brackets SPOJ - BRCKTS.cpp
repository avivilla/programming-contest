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
int tree[30050]={0},cnt=0;;
void update(int idx,int n,int value)
{
	while(idx<=n)
	{
		if(tree[idx]<0)
			cnt--;
		tree[idx]+=value;
		if(tree[idx]<0)
			cnt++;
		idx+=idx&(-idx);
	}
	return ;
}

int main()
{
ios_base::sync_with_stdio(false);
int test,case_no=1;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int n;
cin>>n;
string st;
cin>>st;
FOR(i,st.length())
{
	if(st[i]==')')
		update(i+1,st.length(),-1);
	else update(i+1,st.length(),1);
}
int m;
cin>>m;
while(m--)
{
	int x;
	cin>>x;
	if(x)
	{
		if(st[x-1]==')')
		{
			st[x-1]='(';
			update(x,st.length(),+2);

		}
		else 
		{
			st[x-1]=')';
			update(x,st.length(),-2);

		}
	}
	else 
	{
		if(cnt==0 && tree[n]==0)
		cout<<"YES\n";
		else cout<<"NO\n";
	}
}
return 0;
}
