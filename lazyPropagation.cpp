#include<bits/stdc++.h>
#define pb push_back
#define fin(i,arr,n) for(i=0;i<n;i++)cin>>arr[i]
#define fout(i,arr,n) for(i=0;i<n;i++)cout<<arr[i]<<" "
#define inf 9223372036854775807
#define vi vector<ll>
#define init ll n,m,a,i,b,j,k,t,x,y,z,tc,u,v,w
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
ll arr[200005];
struct info {
    ll sum=0,prop=0;
}tree[200005*4];
void build(ll node,ll i,ll j){
    if(i==j){
        tree[node].sum=arr[i];
        return;
    }
    ll left=2*node;
    ll right=2*node+1;
    ll mid=(i+j)/2;
    build(left,i,mid);
    build(right,mid+1,j);
    tree[node].sum=tree[left].sum+tree[right].sum;

}
ll query(ll node,ll b,ll e,ll i,ll j,ll carry=0){
     if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);
    ll Left = node << 1;
    ll Right = (node << 1) + 1;
    ll mid = (b + e) >> 1;
    ll p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}
void update(ll node,ll b,ll e,ll i,ll j,ll val){
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) 
    {
        tree[node].sum += ((e - b + 1) * val); 
        tree[node].prop += val; 
        return;
    }
    ll left=2*node;
    ll right=2*node+1;
    ll mid=(b+e)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
  tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}
int main()
{   ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
      //freopen("read.txt","r",stdin);
      //freopen("write.txt","w",stdout);
      init;
      cin>>n;
      fin(i,arr,n);
      build(1,0,n-1);
      cin>>m;
      f(i,m){
            cin>>k>>u>>v;
            if(k==1)
             {  cin>>x;
                update(1,0,n-1,u,v,x);
            }
            else cout<<query(1,0,n-1,u,v)<<endl;
            
      }
   
      
     

}