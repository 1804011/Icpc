#include<bits/stdc++.h>
#define pb push_back
#define fin(i,arr,n) for(i=0;i<n;i++)cin>>arr[i]
#define fout(i,arr,n) for(i=0;i<n;i++)cout<<arr[i]<<" "
#define inf 9223372036854775807
#define vi vector<ll>
#define init ll m,a,i,b,j,k,t,x,y,z,tc,u,v,w
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
ll arr[200005],tree[200005*4],n;
struct info{
    ll prop=0,sum=0;
} tree1[200005*4];
void build(ll node, ll i,ll j){
    if(i==j){
        tree[node]=arr[i];
        return;
    }
    ll mid=(i+j)/2;
    ll left=2*node;
    ll right=2*node+1;
    build(left,i,mid);
    build(right,mid+1,j);
    tree[node]=tree[left]+tree[right];
}
ll query(ll node,ll b,ll e,ll i,ll j){
    if(i>e||j<b) return 0;
    if(b>=i&&e<=j) return tree[node];
    ll mid=(b+e)/2;
    ll left=2*node;
    ll right=2*node+1;
    ll p1=query(left,b,mid,i,j);
    ll p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
void update(ll node,ll b,ll e,ll i,ll val){
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) { 
        tree[node] = val;
        return;
    }
    ll mid=(b+e)/2;
    ll left=2*node;
    ll right=2*node+1;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);
    tree[node]=tree[left]+tree[right];

}

int main()
{   ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
      //freopen("read.txt","r",stdin);
      //freopen("write.txt","w",stdout);
      init;
      cin>>n>>m;
      fin(i,arr,n);
      //build the segment tree
      build(1,0,n-1);
      f(i,m){
        cin>>k;
        if(k==1){
            cin>>u>>v;
            update(1,0,n-1,u,v);
        }
        else {
            cin>>u>>v;
            cout<<query(1,0,n-1,u,v)<<endl;
        }
      }
      
    

      
     

}