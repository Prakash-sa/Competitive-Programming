int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

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

void factorize(long long n) 
{ 
    int count = 0; 
  
    // count the number of times 2 divides  
    while (!(n % 2)) { 
        n >>= 1; // equivalent to n=n/2; 
        count++; 
    } 
  
    // if 2 divides it 
    if (count) 
        cout << 2 << "  " << count << endl; 
  
    // check for all the possible numbers that can  
    // divide it 
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
            cout << i << "  " << count << endl; 
    } 
  
    // if n at the end is a prime number. 
    if (n > 2) 
        cout << n << "  " << 1 << endl; 
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

