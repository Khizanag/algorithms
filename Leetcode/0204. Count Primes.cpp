/* Count the number of prime numbers less than a non-negative number, n. */

class Solution {
public:
    template <typename T> 
    void Build_Eratosthenes_Sieve(vector<T> &d, vector<T> &f, T n) {
        T k = 0;
        for(T i = 2; i <= n; i++){
            if(d[i] == 0){
                d[i] = i;
                f[k++] = i;
            }
            for(T a = 0; ; a++){
                if ( (a == k) || ((i*f[a])>n) || (f[a]>d[i])  )
                    break;
                d[i * f[a]] = f[a];
            }
        }
    }
    
    int countPrimes(int n) {
        vector<int> d(n+1), f(n+1);
        Build_Eratosthenes_Sieve(d, f, n);
        int count = (n > 2);
        for(int i = 3; i < n; i+=2)
            if(d[i] == i)
                count+=1;
        return count;
    }
};