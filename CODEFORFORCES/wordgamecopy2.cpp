#include <bits/stdc++.h>
#include <fstream>
using namespace std;
// Author Shreyash Panchal
#define ll long long
#define F first
#define S second
#define pb push_back
#define si set<ll>
#define vi vector<ll>
#define pii pair<ll, ll>
#define vpi vector<pii>
#define vpp vector<pair<ll, pii>>
#define mii map<ll, ll>
#define mpi map<pii, ll>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((ll)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define print(a)          \
	for (auto x : a)      \
		cout << x << " "; \
	cout << endl
#define print1(a)    \
	for (auto x : a) \
	cout << x.F << " " << x.S << endl
#define print2(a, x, y)         \
	for (int i = x; i < y; i++) \
		cout << a[i] << " ";    \
	cout << endl

inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1)
			x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
	const char *comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}

// // check if number is even or odd
// bool oddeven(ll n)
// {
//     return n & 1;
// }
// ll getithbit(ll n, ll i)
// {
//     return (n >> i) & 1;
// }
// ll setithbit(ll n, ll i)
// {
//     return (1 << i) | n;
// }
// ll clearithbit(ll n, ll i)
// {
//     ll mask = 1 << i;
//     ll invmask = ~mask;
//     return n & invmask;
// }
// ll clearlastithbit(ll n, ll i)
// {

//     ll mask = (-1 << i);
//     return mask & n;
// }
// bool powerof2(ll n)
// {
//     return !(n & (n - 1));
// }
// ll removeLastSetBit(ll n)
// {
//     return n & (n - 1);
// }
// ll countSetBits(ll n)
// {
//     ll ans = 0;
//     while (n)
//     {
//         n = removeLastSetBit(n);
//         ans++;
//     }
//     return ans;
// }
// void subsets(vector<ll> &v)
// {
//     ll n = v.size();
//     for (ll i = 0; i < (1 << n); i++)
//     {
//         vector<ll> ans;
//         for (ll j = 0; j < n; j++)
//         {
//             if ((1 << j) & i)
//             {
//                 ans.push_back(v[j]);
//             }
//         }
//         print(ans);
//     }
// }
// // city 0001
// // pos  321"0"
// ll tsp(vector<vector<ll>> &v, ll pos, ll mask, ll n, vector<vector<ll>> &dp)
// {
//     if (mask == (1 << n) - 1)
//     {
//         return v[pos][0];
//     }
//     if (dp[pos][mask] != -1)
//         return dp[pos][mask];
//     ll ans = INT_MAX;
//     for (ll choice = 0; choice < n; choice++)
//     {
//         if ((mask & (1 << choice)) == 0)
//         {
//             ans = min(ans, v[pos][choice] + tsp(v, choice, mask | (1 << choice), n, dp));
//         }
//     }
//     return dp[pos][mask] = ans;
// }
// vector<ll> primeSieve()
// {
//     vector<ll> v(1000001, 1);
//     v[0] = v[1] = 0;
//     for (ll i = 2; i <= 1000000; i++)
//     {
//         if (v[i])
//         {
//             for (ll j = i * i; j <= 1000000; j = j + i)
//             {
//                 v[j] = 0;
//             }
//         }
//     }
//     return v;
// }
// map<ll, ll> primeFactorisation(ll n)
// {
//     //  Time Complexity:- sqrt(n)
//     // Space Complexity :- O(n);
//     // 48=2*2*2*2*3
//     map<ll, ll> ans;
//     for (ll i = 2; i * i <= n; i++)
//     {
//         // divide by divisors
//         while (!(n % i))
//         {
//             ans[i]++;
//             n /= i;
//         }
//     }
//     if (n != 1)
//     {
//         ans[n]++;
//     }
//     return ans;
// }
// vector<ll> highest_lowest_prime(bool flag = 0)
// {
//     // also used to find prime facotrisation in logn
//     //  flag=0 return lowest prime
//     //  flag=1 return highest prime in range using prime sieve
//     ll m = 1000000;
//     vector<ll> v(m + 1, 1);
//     vector<ll> lowprime(m + 1, 0);
//     vector<ll> highprime(m + 1, 0);
//     v[0] = v[1] = 0;
//     for (ll i = 2; i <= m; i++)
//     {

//         if (v[i])
//         {
//             lowprime[i] = i;
//             highprime[i] = i;
//             for (ll j = i * 2; j <= m; j = j + i)
//             {
//                 v[j] = 0;
//                 if (lowprime[j] == 0)
//                 {
//                     // bug("ji");
//                     lowprime[j] = i;
//                 }

//                 highprime[j] = i;
//                 // bug(j,highprime[j]);
//             }
//         }
//     }
//     // print(highprime);
//     if (!flag)
//         return lowprime;
//     return highprime;
// }

// ll gcd(ll a, ll b)
// {
//     if (a < b)
//         swap(a, b);
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }
// vector<ll> extendedGcd(ll a, ll b)
// {
//     if (b == 0)
//     {
//         return {1, 0, a};
//     }
//     vector<ll> subproblem = extendedGcd(b, a % b);
//     ll x1 = subproblem[0];
//     ll y1 = subproblem[1];
//     ll gcd = subproblem[2];
//     ll x = y1;
//     ll y = x1 - (a / b) * y1;
//     return {x, y, gcd};
// }
// ll modInverse(ll a, ll m = 100000007)
// {
//     // ax==1 mod(m)
//     // ax+my=gcd(a,m)==1 for mmi
//     // ax%m + my&m=1%m
//     // ax+0=1&m
//     vector<ll> ans = extendedGcd(a, m);
//     ll gcd = ans[2];
//     if (gcd != 1)
//     {
//         cout << "MMI does not exist";
//     }
//     ll x = ans[0];
//     // adding mod to avoid negative values
//     return (x % m + m) % m;
// }
// ll addMod(ll a, ll b, ll mod = 1000000007)
// {
//     return (a % mod + b % mod) % mod;
// }
// ll subMod(ll a, ll b, ll mod = 1000000007)
// {
//     return ((a - b) % mod + mod) % mod;
// }
// ll mulMod(ll a, ll b, ll mod = 10000000007)
// {
//     return ((a % mod) * (b % mod)) % mod;
// }
// ll powr(ll a, ll b, ll mod = 1000000007)
// {
//     if (b == 0)
//         return 1;
//     ll subproblem = mulMod(powr(a, b / 2), powr(a, b / 2), mod);
//     if (b % 2 == 0)
//     {
//         return subproblem;
//     }
//     return mulMod(a, subproblem, mod);
// }
// ll inverse(ll a, ll mod = 1000000007)
// {
//     return powr(a, mod - 2, mod);
// }

// ll divMod(ll a, ll b, ll mod = 1000000007)
// {
//     // femrat little theorm
//     // here mod should be prime number only
//     // a^p===a mod(P)
//     // a^p-2==a^-1 mod(P)

//     return mulMod(a, inverse(b, mod), mod);
//     // alterntative
//     /*
//        ll binverse=Modinverse(b,m);
//       return mulMod(a,binverse,mod);
//     */
// }
// // iterative binary
// ll binaryExponentiation(ll a, ll b, ll mod = 1000000007)
// {
//     ll ans = 1;
//     // a=3 b=13  1101
//     while (b)
//     {
//         if (b & 1)
//         {
//             ans = mulMod(a, ans, mod);
//         }
//         a = mulMod(a, 2, mod);
//         b = b >> 1;
//     }
//     return ans;
// }
// ll factorial(ll n, ll mod = 1000000007)
// {
//     vector<ll> v(n + 1, 1);
//     for (ll i = 2; i <= n; i++)
//     {
//         v[i] = i * v[i - 1];
//     }
//     return v[n];
// }
// ll phi(ll n)
// {
//     ll result = n;
//     for (ll i = 2; i * i <= n; i++)
//     {
//         if (n % i != 0)
//         {
//             continue;
//         }
//         while (!(n % i))
//         {
//             n = n / i;
//             result -= result / i;
//         }
//     }
//     if (n > 1)
//     {
//         result -= result / n;
//     }
//     return result;
// }
// struct fenwick
// {
//     vector<int> fn;
//     ll n;

//     void init(ll n)
//     {
//         this->n = n + 1;
//         fn.resize(this->n, 0);
//     }

//     void add(ll x, ll y)
//     {
//         x++; // 1 based index
//         while (x < n)
//         {
//             fn[x] += y;
//             x += (x & (-x)); // last set bit
//         }
//     }

//     // void add(int x, int y) {
//     // 	for (x++; x < n; x += (x & (-x))) fn[x] += y;
//     // }

//     ll sum(ll x)
//     {
//         x++; // 1 based index
//         ll ans = 0;
//         while (x)
//         {
//             ans += fn[x];
//             x -= (x & (-x)); // last set bit
//         }
//         return ans;
//     }

//     ll sum(ll l, ll r)
//     {
//         return sum(r) - sum(l - 1);
//     }
// };

// // summation
// struct segmenttree
// {
//     ll n;
//     vector<ll> st;

//     void init(ll _n)
//     {
//         this->n = _n;
//         st.resize(4 * n, 0);
//     }

//     void build(ll start, ll ending, ll node, vector<ll> &v)
//     {
//         // leaf node base case
//         if (start == ending)
//         {
//             st[node] = v[start];
//             return;
//         }

//         ll mid = (start + ending) / 2;

//         // left subtree is (start,mid)
//         build(start, mid, 2 * node + 1, v);

//         // right subtree is (mid+1,ending)
//         build(mid + 1, ending, 2 * node + 2, v);

//         st[node] = st[node * 2 + 1] + st[node * 2 + 2];
//     }

//     ll query(ll start, ll ending, ll l, ll r, ll node)
//     {
//         // non overlapping case
//         if (start > r || ending < l)
//         {
//             return 0;
//         }

//         // complete overlap
//         if (start >= l && ending <= r)
//         {
//             return st[node];
//         }

//         // partial case
//         ll mid = (start + ending) / 2;

//         ll q1 = query(start, mid, l, r, 2 * node + 1);
//         ll q2 = query(mid + 1, ending, l, r, 2 * node + 2);

//         return q1 + q2;
//     }

//     void update(ll start, ll ending, ll node, ll index, ll value)
//     {
//         // base case
//         if (start == ending)
//         {
//             st[node] = value;
//             return;
//         }

//         ll mid = (start + ending) / 2;
//         if (index <= mid)
//         {
//             // left subtree
//             update(start, mid, 2 * node + 1, index, value);
//         }
//         else
//         {
//             // right
//             update(mid + 1, ending, 2 * node + 2, index, value);
//         }

//         st[node] = st[node * 2 + 1] + st[node * 2 + 2];

//         return;
//     }

//     void build(vector<ll> &v)
//     {
//         build(0, n - 1, 0, v);
//     }

//     ll query(ll l, ll r)
//     {
//         return query(0, n - 1, l, r, 0);
//     }

//     void update(ll x, ll y)
//     {
//         update(0, n - 1, 0, x, y);
//     }
// };
// string RotateByKRight(string s, ll k)
// {
//     string p = s;
//     ll n = s.size();
//     for (ll i = 0; i < n; i++)
//     {
//         p[i] = s[(i - k + n) % n];
//     }
//     return p;
// }
// string RotateByKLeft(string s, ll k)
// {
//     string p = s;
//     ll n = s.size();
//     for (ll i = 0; i < n; i++)
//     {
//         p[i] = s[(i + k) % n];
//     }
//     return p;
// }
// // Author Shreyash Panchal
// class sqrtDecomposition
// {
// public:
//     vector<ll> v;
//     vector<ll> block;
//     ll n;

//     ll blockSize;
//     sqrtDecomposition(vector<ll> &p)
//     {
//         ll sz = p.size();
//         this->n = sz;
//         this->v = p;
//         ll sqrn = sqrt(n);
//         sqrn += sqrn % 2;

//         this->blockSize = sqrn;
//         // bug(sqrn);
//         block.resize(this->blockSize, 0);
//         for (ll i = 0; i < n; i++)
//         {
//             block[i / (this->blockSize)] += v[i];
//         }
//     }
//     ll findSum(ll l, ll r)
//     {
//         ll sum = 0;
//         ll startingblock = l / blockSize;
//         ll targetBlock = r / blockSize;
//         if (targetBlock == startingblock)
//         {
//             for (ll k = l; k <= r; k++)
//                 sum += v[k];
//             return sum;
//         }
//         for (ll m = startingblock + 1; m < targetBlock; m++)
//         {
//             sum += block[m];
//         }
//         for (ll g = l; g < (startingblock + 1) * blockSize; g++)
//             sum += v[g];
//         for (ll h = (targetBlock)*blockSize; h <= r; h++)
//             sum += v[h];
//         return sum;
//     }
// };
// class DSU
// {
// public:
//     ll n;
//     vector<ll> rank;
//     vector<ll> parent;
//     DSU(ll _n)
//     {
//         this->n = _n + 1;
//         parent.resize(this->n);
//         rank.resize(this->n, 1);
//         for (ll i = 0; i < this->n; i++)
//             parent[i] = i;
//     }
//     ll findSet(ll a)
//     {
//         // bug(a);
//         if (parent[a] == a)
//             return a;
//         parent[a] = findSet(parent[a]);
//     }
//     void unionSet(ll p, ll q)
//     {
//         // bug(p,q);
//         p = findSet(p);
//         q = findSet(q);
//         if (p != q)
//         {
//             if (rank[p] < rank[q])
//             {
//                 rank[q] += rank[p];
//                 parent[p] = q;
//             }
//             else
//             {
//                 parent[q] = p;
//                 rank[p] += rank[q];
//             }
//         }
//     }
//     bool isCycle(ll a, ll b)
//     {
//         ll p = findSet(a);
//         ll q = findSet(b);
//         if (p != q)
//             return false;
//         return true;
//     }
//     void printParent()
//     {
//         for (ll i = 0; i < parent.size(); i++)
//         {
//             cout << parent[i] << " ";
//         }
//         cout << endl;
//     }
// };
// void fillInput(vector<ll> &v)
// {
//     ll x;
//     cin >> x;
//     while (x--)
//     {
//         ll y;
//         cin >> y;
//         v.pb(y);
//     }
// }
// // shortest min path bellman ford Time conplexity:- O(V*E)
// vector<ll> bellmanford(ll src)
// {
//     ll nodes;
//     cin >> nodes;
//     ll edges;
//     cin >> edges;
//     vector<vector<ll>> v;
//     vector<ll> dist(nodes + 1, INT_MAX);
//     dist[src] = 0;
//     while (edges--)
//     {
//         ll x, y, wgt;
//         cin >> x >> y >> wgt;
//         v.push_back({x, y, wgt});
//     }
//     for (ll i = 1; i < nodes; i++)
//     {
//         for (auto it : v)
//         {
//             ll from = it[0];
//             ll to = it[1];
//             ll wgt = it[2];
//             if (dist[to] > dist[from] + wgt && dist[from] != INT_MAX)
//             {
//                 dist[to] = dist[from] + wgt;
//             }
//         }
//     }
//     for (auto it : v)
//     {
//         ll from = it[0];
//         ll to = it[1];
//         ll wgt = it[2];
//         if (dist[to] > dist[from] + wgt && dist[from] != INT_MAX)
//         {
//             return {-1};
//         }
//     }
//     auto it = dist.begin();
//     dist.erase(it);
//     return dist;
// }
// // floyd warshal Time Complexity:- O(N^3) DP
// void floydwarshall()
// {
//     ll nodes;
//     cin >> nodes;
//     ll edges;
//     cin >> edges;
//     map<pair<ll, ll>, ll> mp;
//     while (edges--)
//     {
//         ll a, b, wgt;
//         cin >> a >> b >> wgt;
//         mp[{a - 1, b - 1}] = wgt;
//     }
//     vector<vector<ll>> v(nodes, vector<ll>(nodes, 0));
//     for (ll i = 0; i < nodes; i++)
//     {
//         for (ll j = 0; j < nodes; j++)
//         {
//             if (i == j)
//             {
//                 v[i][j] = 0;
//             }
//             else if (mp[{i, j}] == 0)
//             {
//                 v[i][j] = INT_MAX;
//             }
//             else
//             {
//                 v[i][j] = mp[{i, j}];
//             }
//         }
//     }

//     for (ll k = 0; k < nodes; k++)
//     {
//         for (ll i = 0; i < nodes; i++)
//         {
//             for (ll j = 0; j < nodes; j++)
//             {
//                 if (v[i][j] > v[i][k] + v[k][j])
//                 {
//                     v[i][j] = v[i][k] + v[k][j];
//                 }
//             }
//         }
//     }
//     for (auto it : v)
//     {
//         print(it);
//     }
// }
// ll farm(vector<ll> a, ll index, ll food, vector<vector<ll>> &dp)
// {
//     if (index == a.size())
//     {
//         return 0;
//     }
//     if (dp[index][food] != -1)
//         return dp[index][food];
//     ll ans = 0;
//     if (food - a[index] >= 0)
//         ans = max(ans, 1 + farm(a, index + 1, food - a[index], dp));

//     ans = max(ans, farm(a, index + 1, food, dp));
//     return dp[index][food] = ans;
// }
// ll memo[10001][400];
// bool subsetSum(vector<ll> v, ll sum, ll index)
// {
//     if (index == 0)
//     {
//         return sum == 0;
//     }
//     if (memo[index][sum] != -1)
//         return memo[index][sum];
//     bool a = false;
//     // include
//     if (sum - v[index] >= 0)
//     {
//         a = a | subsetSum(v, sum - v[index], index - 1);
//     }
//     a = a | subsetSum(v, sum, index - 1);
//     return memo[index][sum] = a;
// }
// ll upper_bound_bs(vector<ll> v, ll key)
// {
//     ll ans = -1;
//     ll i = 0;
//     ll j = v.size() - 1;
//     // T T T T F F F
//     while (i <= j)
//     {

//         ll mid = i + (j - i) / 2;
//         if (v[mid] > key)
//         {
//             j = mid - 1;
//         }
//         else
//         {
//             i = mid + 1;
//         }
//     }
//     return i;
// }
// ll lower_bound_bs(vector<ll> v, ll key)
// {
//     ll ans = -1;
//     ll i = 0;
//     ll j = v.size() - 1;
//     // T T T T F F F
//     while (i <= j)
//     {

//         ll mid = i + (j - i) / 2;
//         if (v[mid] >= key)
//         {
//             j = mid - 1;
//         }
//         else
//         {
//             i = mid + 1;
//         }
//     }
//     return i;
// }
// ll range_bs(vector<ll> v, ll key)
// {
//     return upper_bound_bs(v, key) - lower_bound_bs(v, key) + 1;
// }

void solve(ll cnt)
{
	    ll n;
		cin>>n;
		ll m=3;
		map<string,vector<ll>>mp;
		vector<vector<string>>vp(3,vector<string>(n));
		for(ll i=1;i<=m;i++)
		{
			vector<string>sp;
			for(ll ip=0;ip<n;ip++)
			{
				string pk;
				cin>>pk;
				mp[pk].push_back(i);
				
				sp.push_back(pk);
			}
			
			vp[i-1]=sp;
		}
		vector<ll>res;
		for(ll km=0;km<m;km++)
		{
			vector<string>pl=vp[km];
			ll ans=0;
			for(auto ik:pl)
			{
				
               ll sz=mp[ik].size();
			  // bug(sz,"hi");
			   if(sz==2)ans+=1;
			   else if(sz==3)ans+=0;
			   else if(sz==1)ans+=3;
			}
			//bug(ans);
             res.pb(ans);
		}
		print(res);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	clock_t z = clock();
	ll cnt = 0;
	 ll t;
	//ll t = 1;
	 cin >> t;
	while (t--)
		solve(cnt++);

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}