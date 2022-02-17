//https://www.spoj.com/problems/NHAY/
#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
//typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
#ifdef LOCAL
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ' ' ;
	err(++it, args...);
}
#else
#define error(args...)
#endif
ll hash1[9000005],pw[9000005];
ll p = 243;
ll bigmod ( ll a, ll p, ll m)
{
	ll res = 1;
	ll x = a;
 
	while ( p )
	{
		if ( p & 1 )
		{
			res = (res*x)%m;
		}
		x = (x*x)% m;
		p = p >> 1;
	}
 
	return res;
}
ll get_hash(ll l, ll r) {
	ll has = hash1[r];
	 if(l>0) has=(has+mod-hash1[l-1])%mod;
	return has;
}
int main() {
	int test = 1, fac = 1,n1;
	//scanf("%d", &test);
	while (cin>>n1) {
		ll n, i, j, x, y, pp = 1,has1=0;
		string s,st;
		  cin>>st;
		  mem(hash1); 
		cin >> s;
		n = s.size();
		pw[0]=1;
		has1=st[0]-'a'+1;
		hash1[0] = (s[0] - 'a'+ 1);
		for (i = 1; i < n; i++) {
			pp = (pp*p)%mod;
			pw[i]=pp;
			hash1[i] = (hash1[i - 1]+(s[i] - 'a' + 1) * pp)%mod;
			if(i<n1) has1= (has1+(st[i] - 'a' + 1) * pp)%mod;
		}
		vi v;
		 //error(has1);
		for(i=n1-1;i<n;i++){  
               x=get_hash(i-n1+1,i);
               y=(has1*pw[i-n1+1])%mod;
              // error(x,y);
			 if(x==y) v.pb(i-n1+1);
		}
		for(int x:v) cout<<x<<endl;
 
	}
	return 0;
}
