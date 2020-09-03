/*

The Rabin–Karp string search algorithm is often explained using a rolling hash function that only uses multiplications and additions:

H = c 1 a k − 1 + c 2 a k − 2 + c 3 a k − 3 + . . . + c k a 0 , 

where  a is a constant, and c 1 , . . . , c k  are the input characters (but this function is not a Rabin fingerprint, see below).

In order to avoid manipulating huge H { values, all math is done modulo n . The choice of a and n is critical to get good hashing; see linear congruential generator for more discussion.

Removing and adding characters simply involves adding or subtracting the first or last term. Shifting all characters by one position to the left
requires multiplying the entire sum H by a. Shifting all characters by one position to the right requires dividing the entire sum H by a. 
Note that in modulo arithmetic, a can be chosen to have a multiplicative inverse a − 1 {\displaystyle a^{-1}} a^{-1} by which H can be multiplied to get the result of the division without actually performing a division. 


Use Cases ::

1>  To count substrings in a string that differs by some content (predecided). Sort the hashes of all matched substrings -> then count unique hashes, use set / sort+count.
    But this method is unreliable, as hashes are unreliable in general.
    
    So, what's better ? 
    
    e.g. CF- Good substrings.
    For all order n^2 possible substrings, every index can be a starting point, then flow from start to last. if cnt1 > k, then break. if current substring isnt present in trie,
    Otherwise, make a string till here, move pointer ahead.Keep a count and ++.
    
2> 
*/
Code ::


//Rabin Karp block ::

const int mod = 1e9 + 7;


//***helper functions ::
inline int add(int a, int b, int p = mod)
{
    int c = a + b; if (c >= p) c -= p; return c;
}
inline int sub(int a, int b, int p = mod)
{
    int c = a - b; if (c < 0) c += p; return c;
}
inline int mul(int a, int b, int p = mod)
{
    return (a * 1ll * b) % p;
}
int floor1(int n, int k)
{
    if (n % k == 0 || n >= 0)return n / k;
    return (n / k) - 1;
}
int ceil1(int n, int k)
{
    return floor1(n + k - 1, k);
}

int gen_base(const int before, const int after)
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed);
    int base = std::uniform_int_distribution<int>(before + 1, after)(mt_rand);
    return base % 2 == 0 ? base - 1 : base;
}


int n;
string s;


struct StringHashing
{
    int base; //prime
    string s;
    int n;

    //hash of prefix of length i
    vector<int> pref;
    //base^i (mod modulo)
    vector<int> powb;

    //O(n) ::using constructor to initialise string and chosen base
    StringHashing(string s, int p = 255)
    {
        base = p;
        s = s;
        n = s.size();

        pref.resize(n + 1);
        powb.resize(n + 1);

        pref[0] = 0;
        powb[0] = 1;

        for (int i = 0; i < n; i++)
        {
            pref[i + 1] = add(mul(pref[i], base, mod), s[i], mod);
            powb[i + 1] = mul(powb[i], base, mod);
        }
    }

    //returns hash of substring of length len starting at idx i
    //O(1)
    int hashvalue(int i, int len)
    {
        if (!len)
            return 0;

        len = min(len, n - i);
        int rb = i + len - 1;
        int ret;
        ret = sub(pref[rb + 1], mul(pref[i], powb[len], mod), mod);
        return ret;
    }
};


void solve()
{
    cin >> s;
    n = (int)s.size();

    int p = gen_base(256, mod);



    //text object
    StringHashing hash1(s, p);
    //pattern object
    string t;
    cin >> t;
    StringHashing hash2(t, p);
    int patlen = (int)t.size();
    int pattern_hashval = hash2.hashvalue(0, patlen);


    for (int i = 0; i < n; i++)
    {
        int text_hashval_startat_i = hash1.hashvalue(i, patlen);

        if (pattern_hashval == text_hashval_startat_i)
        {
            cout << i << endl;
        }
    }

}
