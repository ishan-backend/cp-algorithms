int Sum() { return 0; }
template<typename T, typename... Args>
T Sum(T a, Args... args) { return a + Sum(args...); }
 
class Trie {
private:
    map<char,Trie*> m;
    bool isend;
public:
    Trie() {
        isend=false;
    }
    void insert(string s) {
        Trie* node =this;
        for(int i=0;i<s.size();i++)
        {
            if(node->m.find(s[i])==node->m.end())
            {
                auto temp = new Trie();
                node->m[s[i]] = temp;
                node=temp;
            }
            else
            {
                node = node->m[s[i]];
            }
        }
        node->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string s) {
        
        Trie* node = this;
        for(int i=0;i<s.size();i++)
        {
            if(node->m.find(s[i])==node->m.end())
                return false;
            else node = node->m[s[i]];
        }
        if(node->isend==true) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s) {
        
        Trie* node = this;
        for(int i=0;i<s.size();i++)
        {
            if(node->m.find(s[i])==node->m.end())
                return false;
            else node = node->m[s[i]];
        }
        return true;
    }
};
class KMP{
private:
    string str;
    vector<int> lps;
public:
    KMP(string s) {
        this->str = s;
    }
 
    vector<int> getLps(string s) {
        vector<int> lps(s.size(),0);
        int i=1; //always walks forword
        int j =0; //tracks prefix that matches suffix
        
        while(i<s.length()){
            if(s[i]==s[j]){
                j++;
                lps[i]=j;
                i++;
            }
            else {
                if(!j) {
                    // if its at 0 then leave this char, move forword
                    lps[i]=0;
                    i++;
                } else {
                    // backtrack j to check previous matching prefix
                    j = lps[j-1];
                }
            }
        }
        return lps;
    }
 
    vector<int> searchPattern(string s){
            vector<int> lps = getLps(s);
            vector<int> inds;
            int i=0;
            int j=0;
            while(i<str.length()) {
                if(str[i]==s[j]){
                    i++;
                    j++;
                    if(j==s.length()){
                        // store the index
                        inds.push_back(i-j);
                        // backtrack
                        j = lps[j-1];
                    }
                }
                else {
                    if(j==0) {
                        i++;
                    }
                    else {
                        j = lps[j-1];
                    }
                }
            }
            return inds;
    }
};
 
vector<int> rabin_karp(string const& s, string const& t) {
    // t= text
    // s = pattern
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();
 
    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;
 
    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 
 
    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}
