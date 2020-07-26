int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}



ll power(ll a,ll b)
{
  ll res=1;
   while(b){
       if(b&1)res=(res*a)%mod;
       a=(a*a)%mod;
       b=b/2;
   }
   return res%mod;
}

lli pow(int X, int N, int D) {
    long long int res=1;
    long long int x=X,n=N,d=D;
    x=x%d;
    while(n){
        if(n&1)res=(res*x)%d;
        n=n/2;
        x=(x*x)%d;
    }
    if(x==0)return 0;
    if(res>=0)
    return res;
    return (res+d)%d;
}

//inversion
for(int i=n-1;i>=0;i--){
    for(int j=max(0,q[i]-2);j<i;j++){
        if(q[i]<q[j]){
            cnt++;
        }
    }
}

// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;

    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}

//modulus of + and - number
lli modulo(lli x,lli N){
    return (x % N + N) %N;
}

lli modulo_Euclidean(lli a, lli b) {
  lli m = a % b;
  if (m < 0) {
    m = (b < 0) ? m - b : m + b;
  }
  return m;
}


//ncr

lli ncr(int n,int k){
    lli c[n+1][k+1]={0};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0||j==i)c[i][j]=1;
            else c[i][j]=(c[i-1][j]%m+c[i-1][j-1]%m)%m;
        }
    }
    return c[n][k];
}

//lucas
int nCrModpDP(int n, int r, int p) 
{
      int C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

// fermats theorem
ll f[1000005];

ll ncr(ll n,ll r)
{
    if(r>n)
    return 0;
    ll ans=1;
    ans=(ans*f[n])%mod;
    ans=(ans%mod*power(f[n-r],mod-2)%mod)%mod;
    ans=(ans%mod*power(f[r],mod-2)%mod)%mod;
    return ans%mod;
}





//Count the number of ones in the binary representation of the given number.

int count_one (int n)
        {
            while( n )
            {
            n = n&(n-1);
               count++;
            }
            return count;
    }

//left and right rotation of string

void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}

// In-place rotates s towards right by d
void rightrotate(string &s, int d)
{
   leftrotate(s, s.length()-d);
}

//is a power of two

bool isPowerOfTwo(int x)
    {
        // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
        return (x && !(x & (x - 1)));
    }
//possible subset
  void possibleSubsets(char A[], int N)
    {
        for(int i = 0;i < (1 << N); ++i)
        {
            for(int j = 0;j < N;++j)
                if(i & (1 << j))
                    cout << A[j] << ‘ ‘;
            cout << endl;
    }
    }

    //largest power of two
    long largest_power(long N)
    {
        N = N| (N>>1);
        N = N| (N>>2);
        N = N| (N>>4);
        N = N| (N>>8);

        return (N+1)>>1;

    }



//perfect cube
curoot=round(pow(num, 1.0/3.0));

if(curoot*curoot*curoot==num)
{
  cout<<" The number is a perfect Cube of "<<curoot<<endl;
}

//perfect square
	if(sqrt(n)==floor(sqrt(n)))
	{
		cout<<"Perfect Square";
	}




// count divisor

int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}


//modinverse
int modInverse(int A,int M)
{
    return modularExponentiation(A,M-2,M);
}


//is prime
bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

//factorial
unsigned int factorial(unsigned int n)
{
    if (n == 0)
    return 1;
    return n * factorial(n - 1);
}

void subsetSums(int arr[], int l, int r, int sum=0){
    if (l > r)
    {
        cout << sum << " ";
        return;
    }
    subsetSums(arr, l+1, r, sum+arr[l]);
    subsetSums(arr, l+1, r, sum);
}

//permute of string
void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        cout<<a<<endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}


//permute of array
void findPermutations(int a[], int n)
{

    // Sort the given array
    sort(a, a + n);

    // Find all possible permutations
    cout << "Possible permutations are:\n";
    do {
        display(a, n);
    } while (next_permutation(a, a + n));
}

// Function to return the only odd occurring element
int findOdd(int arr[], int n) {
   int res = 0, i;
   for (i = 0; i < n; i++)
     res ^= arr[i];
   return res;
}

//factorize


vector<int>res;

vector<int> factorize(int n){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            res.push_back(i);
            n/=i;
        }
        if(n!=1)res.push_back(n);

    }
    return res;
}

//sieve for minimum prime factor
void sieve()
{
    fac[0]=0;
    fac[1]=0;
    int temp;
    for(int i=2; i<=MAX; i++)
    {
        temp=0;
        for(int j=i; j<=MAX; j=j+i)
        {
            if(fac[j]==0)
            {
                fac[j]=i;
                temp++;
            }
        }
        ans[i]=temp;
    }
}

// A simple method to evaluate Euler Totient Function relative prime
ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i*i <= n; i++) {
        if(n%i==0){
                while(n%i == 0)
                {
                    cout<<i;
                    n/=i;
                }
            result=result-result/i;
        }
    }
    if(n>1){
        result=result-result/n;
        cout<<n;
    }

    return result;
}


//fastscan
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}


//---------------------------hash function------------------------------//
vector <string> hashTable[20];
    int hashTableSize=20;

     int Frequency[26];

    int hashFunc(string word)
    {
         int sum = 0;
        for (int k = 0; k < word.length(); k++)
            sum = sum + int(word[k]);
        return  sum % hashTableSize;
    }

    void search(string s)
    {
        //Compute the index by using the hash function
        int index = hashFunc(s);
        //Search the linked list at that specific index
        for(int i = 0;i < hashTable[index].size();i++)
        {
            if(hashTable[index][i] == s)
            {
                cout << s << " is found! at " <<i<< endl;
                return;
            }
        }
        cout << s << " is not found!" << endl;
    }
    void insert(string s)
    {
                // Compute the index using Hash Function
        int index = hashFunc(s);
        cout<<index<<endl;
        // Insert the element in the linked list at the particular index
        hashTable[index].push_back(s);
    }

    void countFre(string S)
    {
        for(int i = 0;i < S.length();++i)
        {
            int index = hashFunc(S[i]);
            Frequency[index]++;
        }
        for(int i = 0;i < 26;++i)
            cout  << Frequency[i] <<" ";
    }
//---------------------------------------------------------------------------------//




//inverse factorial
#define mod 1000000007
#define k 100001
long fact[k];
long inv[k];
long fact_inv[k];
void init()
{
    fact[0] = fact[1] = 1;
    for(int i=2;i<k;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    inv[0]=inv[1]=1;
   for(int i=2;i<k;i++){
       inv[i]=(inv[mod%i]*(mod - mod / i))%mod;
   }
   fact_inv[0]=1;
   for(int i=1;i<k;i++){
      fact_inv[i]=(fact_inv[i-1]*inv[i])%mod;
   }
}


//-----------sorting using hashing-------------------//
#include <bits/stdc++.h>
using namespace std;

void sortUsingHash(int a[], int n)
{
    int max = *std::max_element(a, a + n);
    int min = abs(*std::min_element(a, a + n));

    int hashpos[max + 1] = { 0 };
    int hashneg[min + 1] = { 0 };

    for (int i = 0; i < n; i++) {
        if (a[i] >= 0)
            hashpos[a[i]] += 1;
        else
            hashneg[abs(a[i])] += 1;
    }

    for (int i = min; i > 0; i--) {
        if (hashneg[i]) {

            for (int j = 0; j < hashneg[i]; j++) {
                cout << (-1) * i << " ";
            }
        }
    }

    for (int i = 0; i <= max; i++) {

        if (hashpos[i]) {

            for (int j = 0; j < hashpos[i]; j++) {
                 cout << i << " ";
            }
        }
    }
}

//happy mnumbers
int ch(int n){
    int ans=0;
    while(n){
        int tmp=n%10;
        n=n/10;
        ans+=tmp*tmp;
    }
    return ans;
}

bool ishappy(int n){
    set<int>s;
    int t;
    while(1){
        n=ch(n);
        if(n==1)return true;
        if(s.find(n)!=s.end())return false;
        s.insert(n);
    }
}
