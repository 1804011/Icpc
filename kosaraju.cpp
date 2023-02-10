//strongly connected components
#include<bits/stdc++.h>
#define pb push_back
#define fin(i,arr,n) for(i=0;i<n;i++)cin>>arr[i]
#define fout(i,arr,n) for(i=0;i<n;i++)cout<<arr[i]<<" "
#define inf 9223372036854775807
#define vi vector<ll>
#define init ll a,i,b,j,k,t,x,y,z,tc,u,v,w
#define f(i,n) for(i=0;i<n;i++)
#define mem(a,x) memset(a,x,sizeof(a))
#define sortt(v)  sort(v.begin(),v.end())
#define sitr(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
#define pr pair<ll,ll>
#define pi acos(-1.00)
#define mod 1000000007
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define tr(exp)  exp?yes:no
#define flush fflush(stdout)
#define el cout<<endl
#define ell endl
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ll(a)/ll(gcd(a,b))*ll(b)
#define inp(a) scanf("%lld",&a)
using namespace std;
typedef long long ll;
/* Fenwick Tree
ll tree[200005],n;
ll read(ll idx){ll sum=0;while(idx>0){sum+=tree[idx];idx-=(idx&-idx);}return sum;}
void update(ll idx,ll val){while(idx<=n){tree[idx]+=val;idx+=(idx&-idx);}}
*/
ll visit[100005]={0},n,m;
vector<ll>adj[100005],transpose[100005],component;
stack<ll>stk;
void dfs1(ll x){
      visit[x]=1;
      for(ll u:adj[x]){
        if(!visit[u])
          dfs1(u);
      }
      stk.push(x);
}
void dfs2(ll x){
    visit[x]=1;
    component.pb(x);
    for(ll u:transpose[x]){
        if(!visit[u]){
            dfs2(u);
        }
    }
}
void scc(){
    ll i;
     for(i=1;i<=n;i++) {
        if(!visit[i])
          dfs1(i);
     }
    mem(visit,0);
    while(!stk.empty()){
        ll u=stk.top();
        if(!visit[u]){
            dfs2(u);
            fout(i,component,component.size());cout<<endl;
            component.clear();
        }
        stk.pop();
    }
    


}
int main()
{   ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
      //freopen("read.txt","r",stdin);
      //freopen("write.txt","w",stdout);
      init;
      cin>>n>>m;
      f(i,m){
     cin>>u>>v;
       adj[u].pb(v);
       transpose[v].pb(u);
      }
      scc();
      
     

}
