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
ll arr[500005],failure[400005];
void build_failure_function(string pattern,ll m) {
  failure[0] = 0 ;
  failure[1] = 0; 
  
  for(ll i = 2; i <= m; i++) 
  {  
    ll j = failure[i - 1];
    while(true) {
      if(pattern[j] == pattern[i - 1]) { 
        failure[i] = j + 1; 
        break; 
      }
      if(j == 0) { 
          failure[i] = 0; 
          break; 
      }
      j = failure[j];
    }
  }   
}
bool kmp(string text, string pattern)
{
  ll n = text.size();
  ll m = pattern.size();
  build_failure_function(pattern,m); 

  ll i = 0; 
  ll j = 0; 
  
  while(true) {
    if(j == n) {
        return false; 
    }

    // character matched
    if(text[j] == pattern[i]) {
      i++; 
      j++; 
      if(i == m) {
          return true;
      }
    } else {
        if (i == 0) {
           
            j++;
        }
        else {
            i = failure[i];
        }
    }
  }
  return false;
}
int main()
{   ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
      //freopen("read.txt","r",stdin);
      //freopen("write.txt","w",stdout);
      init;
      string text,pattern;
      cin>>text>>pattern;
      cout<<kmp(text,pattern)<<endl;
    
      
     

}