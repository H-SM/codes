#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <bits/stdc++.h>

typedef long long ll;
typedef long long ull;
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
using namespace std ;
bool sortbysec(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.second < b.second);
}
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++) {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}

// Function for finding difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i = n2 - 1; i >= 0; i--) {
        // Do school mathematics, compute difference of
        // current digits and carry
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0')
                   - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of str1[]
    for (int i = n1 - n2 - 1; i >= 0; i--) {
        if (str1[i] == '0' && carry) {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i] - '0') - carry);
        if (i > 0 || sub > 0) // remove preceding 0's
            str.push_back(sub + '0');
        carry = 0;
    }

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}
void bittemp(){
    string s,ans;cin>>s;
    int n = s.size();
    for (int i = 0; i < (1<<n); ++i) {
        string temp;
        for (int j = 0; j < n; ++j) {
            if(i & (1<<j)){
                temp+=s[j];
            }
        }
        string t2 = temp;
        std::reverse(t2.begin(), t2.end());
        if(t2 == temp){
            if(ans.size() == 0)ans=t2;
            else ans = max(ans,t2);
        }
    }
    cout<<ans;

}
ll fastpow(ll x,ll n){
    ll res = 1;
    while(n){
        if(n%2 != 0)
            res *= x;
        x = x*x;
        n /=2;
    }
    return res;
}
ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
/*bpmodm*/
/*
unordered_map<ll,ll>vis;
ll bpmodm(ll b , ll p,ll m){
    if(p == 1){
        return b%m;
    }else if(p == 0){
        return 1;
    }
    ll l;
    if(vis.find(p/2) != vis.end()){
        l = vis[p/2];
    }else{
        l = bpmodm(b,p/2,m);
        vis.insert(make_pair(p/2,l));
    }
    ll r;
    if(vis.find(p - (p/2)) != vis.end()){
        r = vis[p - (p/2)];
    }else{
        r = bpmodm(b,p - (p/2),m);
        vis.insert(make_pair(p-(p/2),r));
    }
    return (l*r)%m;
}
*/

ll add(ll a,ll b,ll m)
{
    return ((a%m)+(b%m))%m;
}
ll mul(ll a,ll b,ll m)
{
    return ((a%m)*(b%m))%m;
}
ll sub(ll a,ll b,ll m)
{
    return ((a%m)-(b%m)+m)%m;
}
int binaryExponentiation(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=result*x;}
        x=x*x;
        n=n/2;
    }
    return result;
}
ll modularExponentiation(ll x,ll n,ll m)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1){result=mul(result,x,m);}
        x=mul(x,x,m);
        n=n/2;
    }
    return result;
}
bool getBit(ll num, int idx) {
    return ((num >> idx) & 1);
}

ll setBit(ll num, int idx, bool val) {
    return val ? (num | (1LL << idx)) : (num & ~(1LL << idx));
}

ll flipBit(ll num, int idx) {
    return (num ^ (1LL << idx));
}

ll leastBit(ll num) {
    return (num & -num);
}
bool isPowerOfTwo(ll num) {
    return (num & num - 1) == 0;
}

int turnOnLastZero(int S) {
    return S | S + 1;
}

int turnOffLastBit(int S) {
    return S & S - 1;
}

int turnOnLastConsecutiveZeroes(int S) {
    return S | S - 1;
}

int turnOffLastConsecutiveBits(int S) {
    return S & S + 1;
}

vector<int> genAllSubmask(int mask) {
    vector<int> v;
    for (int subMask = mask;; subMask = (subMask - 1) & mask) {
        v.push_back(subMask);
        if (subMask == 0)
            break;
    }
    return v;
}

//o(sqrt(n))
void factorization(){
    int n;
    cin>>n;
    for (int i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            cout<<i<<" ";
            if (i*i!=n)
            {
                cout<<n/i;
            }
            cout<<endl;
        }
    }

}
//o(sqrt(n))
vector<ll> primeFactorization(ll n){
    vector<ll>v;
    for (int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            v.push_back(i);
        }
    }
    if (n!=1)
    {
        v.push_back(n);
    }
    return v;
}

void rad(){
    //what is the smallest +ve number that can be diveded by all numbers from 1 to n
    ll n, l =1;
    cin>>n;
    for (int i = 1; i <=n ; ++i) {
        l = lcm(i,l);
    }
    cout<<l<<endl;
    ll g = 0;cin>>n;
    for (int i = 1; i <=n ; ++i) {
        g = gcd(g,i);
    }
    cout<<g<<endl;
}
int extendedEuclid(int a, int b, int& x, int& y) {
    if (b==0) {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=extendedEuclid(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
int modInverse(int A, int M){
    return modularExponentiation(A,M-2,M);
}
/*sieve*/
/*const int sz=1e6+10;
bool composite[sz+1];
vector<int>prime;
void sieve()
{
    composite[0]=composite[1]=1;
    for (int i=2;i*i<=sz;i++)
    {
        if (!composite[i])
        {
            for (int j=i*i;j<=sz;j+=i)
            {
                composite[j]=1;
            }
        }
    }
}*/
/*const int sz=1e6+10;
bool composite[sz+1];
vector<int>prime;
void sieve()
{
    composite[0]=composite[1]=1;
    for (ll i=2;i*i<=sz;i++)
    {
        if (!composite[i])
        {
            //prime.push_back(i);
            for (ll j=i*i;j<=sz;j+=i)
            {
                composite[j]=1;
            }
        }
    }
}*/

bool judgePrime(ll x)
{
    if(x == 2)return true;
    if(x%2 == 0 ||x<2)return false;
    for (ll i = 3; i*i <= x ; i+=2) {
        if(x%i == 0)return false;
    }
    return true;
}
// start + (end-start)/2 = (start + end) / 2
int BSfindFirst(int start, int end, int val,int arr[]) {
    while(start < end) {
        int mid = start + (end-start)/2;
        if(arr[mid] < val)		start= mid+1;
        else if(arr[mid] > val)	end  = mid-1;
        else					end  = mid;
    }
    return start;
}

int BSfindLast(int start, int end, int val,int arr[]) {
    while(start < end) {
        int mid = start + (end-start)/2;
        if(arr[mid] < val)		start= mid+1;
        else if(arr[mid] > val)	end  = mid-1;
        else					start= mid;
    }
    return start;
}

// NCR
ll nCr(ll n, ll r){
    ll ans = 1;
    ll div = 1; // r!
    for (ll i = r + 1; i <= n; i++){
        ans = ans * i;
        ans /= div;
        div++;
    }
    return ans;
}
// NPR
ll NpR(ll n, ll r){
    const int mod = 1e9 + 7;
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++){
        ans *= i;
        ans %= mod;
    }
    return ans;
}
// CPER
ll CPer(ll n, ll r){
    const int mod = 1e9 + 7;
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++){
        ans *= i;
        if(ans %r == 0){
            ans /= r;
            r=1;
        }
    }
    return ans;
}
bool isPali(string s){
    int i =0,j=s.size()-1;
    while(i<j){
        if(s[i++] != s[j--])return false;
    }
    return true;
}
ll oo = 1e9+7;
/*DSU*/
const int Ndsu =0/*1e5+5*/;
int szdsu, pardsu[Ndsu], sizdsu[Ndsu];
void init()
{
    for ( int i = 1 ; i <= szdsu ;i++)
        pardsu[i] = i , sizdsu[i] = 1;
}
int findparent( int u)
{
    if(pardsu[u] == u)
        return  u;
    return pardsu[u] = findparent(pardsu[u]);
}
//bool iscyclicdsu = false;
void connect( int u , int v)
{
    u = findparent(u);
    v = findparent(v);
    /*if ( u == v)
    {
        iscyclicdsu =true;
        return;
    }*/
    if(sizdsu[v] < sizdsu[u])
        pardsu[v] = u ,sizdsu[u] += sizdsu[v];
    else
        pardsu[u] = v,sizdsu[v] += sizdsu[u];
}
bool iscon( int u , int v)
{
    return (findparent(u) == findparent(v));
}
const ll NDijkstra = 0;
ll nDijkstra , distDijkstra[NDijkstra], parDijkstra[NDijkstra];
//child  weight
vector < pair < ll , ll > > gDijkstra[NDijkstra];
//o(e+vlogv)
void Dijkstra( int src)
{
    for ( int i = 1 ; i <= nDijkstra ; i++)
        distDijkstra[i] = oo;
    distDijkstra[src] = 0;
    //  distance node
    priority_queue< pair < ll , ll >, vector<pair < ll , ll >>, greater<pair < ll , ll >> > pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        ll node = pq.top().second , distance = pq.top().first;
        pq.pop();
        if(distance > distDijkstra[node]) {
            continue;
        }
        for(auto ch : gDijkstra[node])
        {
            if(distDijkstra[node] + ch.second < distDijkstra[ch.first])
            {
                parDijkstra[ch.first] = node;
                distDijkstra[ch.first] = distDijkstra[node] + ch.second;
                pq.push({distDijkstra[ch.first],ch.first});
            }
        }
    }
}
const ll NBellman_Ford = 0, ooBellman_Ford = 1e18+7 ;
ll distBellman_Ford[NBellman_Ford] , nBellman_Ford;
vector < pair < ll , pair < int , int > > > edgesBellman_Ford;
bool negCycle = false;
void Bellman_Ford( int src)
{
    for ( int i = 1 ; i <= nBellman_Ford ; i++)
        distBellman_Ford[i] = oo;
    distBellman_Ford[src] = 0;
    // O(n * m)
    for(int lvl = 1 ; lvl <= nBellman_Ford ; lvl++) {
        for(int j = 0; j < edgesBellman_Ford.size(); j++) {
            int u = edgesBellman_Ford[j].second.first, v = edgesBellman_Ford[j].second.second, w = edgesBellman_Ford[j].first;
            if (distBellman_Ford[u] + w < distBellman_Ford[v])
            {
                if(lvl == nBellman_Ford)
                    negCycle = true;
                distBellman_Ford[v] = distBellman_Ford[u] + w;
            }
        }
    }
}
ll const ooFloyd_Warshall = 1e18+10,NFloyd_Warshall = 0;
ll dFloyd_Warshall[NFloyd_Warshall][NFloyd_Warshall];ll nFloyd_Warshall,mFloyd_Warshall;
void Floyd_Warshall(){
    for (int i = 1; i <= nFloyd_Warshall; ++i) {
        for (int j = 1; j <= nFloyd_Warshall; ++j) {
            cin>>dFloyd_Warshall[i][j];
        }
    }
    for (int k = 1; k <= nFloyd_Warshall; ++k)
        for (int i = 1; i <= nFloyd_Warshall; ++i)
            for (int j = 1; j <= nFloyd_Warshall; ++j)
                dFloyd_Warshall[i][j] = min(dFloyd_Warshall[i][j], dFloyd_Warshall[i][k] + dFloyd_Warshall[k][j]);
    /*for (int i = 0; i < nFloyd_Warshall; ++i) {
        if(dFloyd_Warshall[i][i]<0) {
            cout << "cyc\n";
        }
    }*/

}
/*eular*/
const int Neular = 0 , infeular = 1e9;
int ineular[Neular], outeular[Neular],viseular[Neular],vis2[Neular];
vector < int > geular[Neular];
void direular( int node)
{
    for (auto ch:geular[node])
    {
        if(!viseular[ch]){
            viseular[ch]=1;
            direular(ch);
        }
    }
}
const int Nundureular = 0 , infundureular = 1e9;
int visansundureular[Nundureular] , degundureular[Nundureular];
vector < pair < int , int > > undgeularg[Nundureular];
vector < int > ansundureular;
void undureular( int node)
{
    while(!undgeularg[node].empty())
    {
        int v = undgeularg[node].back().second;
        int idx = undgeularg[node].back().first;
        undgeularg[node].pop_back();
        if(visansundureular[idx])
            continue;
        visansundureular[idx] = 1 ;
        undureular(v);
    }
    ansundureular.push_back(node);
}

int LongestIncreasingSubsequenceLength(vector<int>& v)
{
    if (v.size() == 0) // boundary case
        return 0;
    else if (v.size() == 1)return 1;
    vector<int> tail,inc(v.size(),1),dec(v.size(),1);
    tail.push_back(v[0]);
    for (int i = 1; i < v.size(); i++) {
        auto b = tail.begin(), e = tail.end();
        auto it = lower_bound(b, e, v[i]);
        if (it == tail.end())
            tail.push_back(v[i]);
        else
            *it = v[i];
        inc[i] = max(inc[i],(int)tail.size());
    }
    return tail.size();
}

int maxSubArraySum(vector<vector<int>>& a)
{
    int n = a.size(),ans = INT32_MIN;
    int db[200+5];
    for (int i = 0; i < n; ++i) {
        vector<int>temp(n,0);
        for (int j = i; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                temp[k]+=a[j][k];
            }
            int cur;
            db[0]=cur=temp[0];
            for (int k = 1; k < n; ++k) {
                db[k]= max(db[k-1]+temp[k],temp[k]);
                cur = max(cur,db[k]);
            }
            ans = max(ans,cur);
        }
    }
    return ans;
}
/* 2D prefix sum*/
void pref2d(vector<vector<int>>arr){
    vector<vector<int>>pref(arr.size(),vector<int>(arr[0].size()));
    int n = pref.size();
    int m = pref[0].size();
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            pref[i][j] = arr[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            pref[i][j] += pref[i][j-1];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            pref[i][j] += pref[i-1][j];
        }
    }
}
void fast () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;cin>>t;
    while (t--) {
        int n;cin>>n;
        vector<vector<string>> a(3,vector<string>(n));
        set<string>s;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>a[i][j];
                s.insert(a[i][j]);
            }
        }
        for (int i = 0; i < 3; ++i) {
            std::sort(a[i].begin(), a[i].end());
        }
        int res[3]={0,0,0};
        for(auto& i: s) {
            auto f =binary_search(a[0].begin(), a[0].end(),i);
            auto s =binary_search(a[1].begin(), a[1].end(),i);
            auto t =binary_search(a[2].begin(), a[2].end(),i);
            if(f && s && t)continue;
            if(f && s ){
                res[0]++;
                res[1]++;
            }else if(f && t  ){
                res[0]++;
                res[2]++;
            }else if(s && t ){
                res[1]++;
                res[2]++;
            }else if(f){
                res[0]+=3;
            }else if(s){
                res[1]+=3;
            }else if(t){
                res[2]+=3;
            }
        }
        for (int i = 0; i < 3; ++i) {
            cout<<res[i]<<" ";
        }
        cout<<'\n';
    }
}