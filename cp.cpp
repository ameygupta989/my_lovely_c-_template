/*
 *    author:  SilentVisitor_6
 *    created: 15.10.2021 : 12:52 A.M.       
*/
#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define re register 
#define ar array
#define ke string 


#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend() 
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

#define deb(x) cout << #x << "=" << x << endl; 
#define pb push_back 
#define mp make_pair
#define ff first 
#define ss second 
#define setbits(x) __builtin_popcountll(x)  // count the leading zeroes 
#define zrobits(x) __builtin_ctzll(x) // number of zeroes before 1
#define sp(x, y) fixed<<setprecision(y)<<x  // decimal places upto y
#define mk(ar,n,type) type*ar = new type[n]; //dynamic array || type = int, char etc.
#define tr(it, a) for(auto it = a.begin(); it!=a.end(); ++it); 
#define pi 3.14285714286
#define vpp vector<pair<int, int>>
typedef pair<int, int> pii;  
typedef pair<ll , ll> pll;
typedef vector<ll> vl; 
const int mod = 1e9+7;
const int mxN = 998244353;
class BIT {
 public:
  BIT(ll n) {
    sz = n;
    tree.resize(n + 1, 0);
  }

  ll sz;
  vector<ll> tree;

  void Update(ll x, ll y) {
    for (ll i = x; i <= sz; i += i & -i) {
      tree[i] += y;
    }
  }

  ll Query(ll x) {
    ll res = 0;
    for (ll i = x; i > 0; i -= i & - i) {
      res += tree[i];
    }
    return res;
  }
};
void pairsort(int a[], int b[], int n){
    vpp v(n);
    FOR(i, n){
        v[i] = make_pair(a[i], b[i]); 
    }
    sort(v.begin(), v.end()); 
    FOR(i, n){
        a[i] = v[i].ff; 
        b[i] = v[i].ss;  
    }
    return; 
}
template<typename T> class Cpoint
{
    public: 
    ll x, y, z; 
    Cpoint(T tmpx, T tmpy, T tmpz){
        x = tmpx; 
        y = tmpy; 
        z = tmpz; 
    }
    Cpoint operator+(Cpoint b){
        return Cpoint(this->x+b.x, this->y+b.y, this->z+b.z); 
    }
    Cpoint& operator+=(Cpoint b){
        *this = *this+b; 
        return *this; 
    }
}; 
template<typename T> T dot(Cpoint<T> a, Cpoint<T> b){
    return a.x*b.x+a.y*b.y+a.z*b.z; 
}
template<typename T> double ang(Cpoint<T> a, Cpoint<T> b) {
   return acos(dot(a,b)/sqrt(dot(a, a)*dot(b,b)));    
}
template<class T> bool umin(T& a, const T& b) {
    return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
    return a<b?a=b, 1:0;
} 

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1; 
    } 
    return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1; 
    } 
    return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}

ke to_string(char c) {
    return string(1, c);
}
ke to_string(bool b) {
    return b?"true":"false";
}
ke to_string(const char* s) {
    return ke(s);
}
ke to_string(ke s) {
    return s;
}
ke to_string(vt<bool> v) {
    ke res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}

template<size_t S> ke to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> ke to_string(T v) {
    bool f=1;
    ke res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}

template<class A> void write(A x) {
    cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
    write(h);
    write(t...);
}
void print() {
    write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);
}
void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
    x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
    EACH(a, x)
        offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
    EACH(a, x)
        offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}
class node{
  public: 
    int data;
    node* next; 
    node(int val){
        data = val; 
        next = NULL; 
    }
}; 
void insertAtTail(node* &head, int val){
    node* n = new node(val); 
    if(head == NULL){
        head = n; 
        return; 
    }
    node* temp = head; 
    while(temp->next != NULL){
        temp = temp->next; 
    }
    temp->next = n; 
}
void display(node* head){
    node* temp = head; 
    while(temp!=NULL){
        cout << temp->data << "->"; 
        temp = temp->next; 
    }
    cout << "NULL" << "\n";  
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
    v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)
        vti(a, x, m);
}

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
int smallestDivisor(int n)
{
    if (n % 2 == 0)
        return 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
 
    return n;
}
ll gcd(ll a, ll b){
    while(b){
        a%=b;swap(a,b);
    }
    return a;
}
ll lcm(int a, int b){
    ll a0 = a; 
    ll b0 = b; 
    return a*b/__gcd(a0, b0); 
}
int mpow(int base, int exp){
    base%=mod; 
    int result = 1; 
    while(exp > 0){
        if(exp & 1) result = ((ll)result*base)%mod; 
        base = ((ll)base * base)%mod; 
        exp >> 1; 
    }
    return result; 
}
int modulo(){
    int mpow_result = mpow(2, 1000); 
    deb(mpow_result); 
}
int divisible(int n,int a,int b){
    int c1 = n/a; 
    int c2 = n/b; 
    int c3 = n/(a*b);
    return c1+c2-c3; 
}
struct word{
    int a;
    int b;
    int c;
    int d;
    int e;
    int tot;
};
 
word ar[200005];
 
bool compa(word a , word b){
    int x = 2*a.a - a.tot;
    int y = 2*b.a - b.tot;
    
    return x < y;
}
 
bool compb(word a , word b){
    int x = 2*a.b - a.tot;
    int y = 2*b.b - b.tot;
    return x < y;
}
 
bool compc(word a , word b){
    int x = 2*a.c - a.tot;
    int y = 2*b.c - b.tot;
    return x < y;
}
 
bool compd(word a , word b){
    int x = 2*a.d - a.tot;
    int y = 2*b.d - b.tot;
    return x < y;
}
 
bool compe(word a , word b){
    int x = 2*a.e - a.tot;
    int y = 2*b.e - b.tot;
    return x < y;
}
ll int gcd_sum(ll int num){
    long long int tmp = num, digitsum = 0;

    while (tmp > 0) {
        digitsum += tmp % 10;
        tmp /= 10;
    }               

    long long int gcd = __gcd(num, digitsum);
    return gcd;
}
int sum(int a){
    int result = 0; 
    while(a>0){
        result += a%10; 
        a/= 10; 
    }
    return result; 
}  
bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}
int removedecimal( int number, int digitNo )
{
    int result = number;
    int decimal = (int)pow( 10, digitNo ); 

    int div = number / decimal;                      
    if ( div > 0 )                         // test if number is grater than 10.0e<digitNo>
    {
        int rest = number % decimal;       // calcualte right digits
        result = div / 10;                 // calcualte left digits
        result *= 10 * decimal;            // shift left digits to the left
        result += rest;                    // add right digits
    }
    return result;
}
int fact(int n){
    int res = 1;
    for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
    }
    return res;
}
int fast_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    } else {
      res = res * 1ll * a % mod;
      p--;
    }
  }
  return res;
}
int C(int n, int k) {
  return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
} 
inline int GCD(re int x,re int y){
    return y?gcd(y,x%y):x;
}
inline int LCM(re int x,re int y){
    return x/GCD(x,y)*y;
}
const ll biginteger = 1e6+5640;  
void input(vector<int> &arr){for(int &i : arr){cin>>i;}}
int c[biginteger];
ll power(ll a,ll b,ll mod){
    if(b == 0){
        return 1;
    }
    ll ans = power(a,b/2,mod);
    ans *= ans;
    ans %= mod;
    if(b % 2){
        ans *= a;
    }
    return ans % mod;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
bool isPerfectSquare(int n)
{
    int sr = sqrt(n); 
    if (sr * sr == n)
        return true;
    else
        return false;
}
int largestno(ll arr[], ll n)
{
    ll i;
    ll max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}

bool perfectCube(int N)
{
    int cube = cbrt(N); 
    if(cube * cube * cube == N) return true; 
    else return false; 
}
int reversDigits(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
vt<char> data = {'a', 'e', 'i', 'o', 'u'};      
void solve(){  
       ll n,k; read(n,k);
       ke s(n, 'a'); 
       for(int i = n -2; i>=0; --i){
            if(k <= (n - i - 1)){
                 s[i] = 'b'; 
                 s[n-k] = 'b'; 
                 print(s); 
                 break; 
            }
            k -= (n-i-1); 
       }
} 
int main(void)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    srand(chrono::high_resolution_clock::now().time_since_epoch().count()); 
    int t; 
    cin >> t; 
    while(t--) solve();  
    return 0; 
}
