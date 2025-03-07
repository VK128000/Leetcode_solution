class Solution {
    public:
        bool prime[1000001];
    
        void sieve() {
            for (int i = 0; i <= 1000000; i++) {
                prime[i] = true;
            }
    
            prime[0] = prime[1] = false;
    
            for (int i = 2; i * i <= 1000000; i++) {
                if (prime[i]) {
                    for (int j = i * i; j <= 1000000; j += i) {
                        prime[j] = false;
                    }
                }
            }
        }
    
        vector<int> closestPrimes(int left, int right) {
            sieve();
    
            vector<int> primes;
            for (int i = left; i <= right; i++) {
                if (prime[i]) primes.push_back(i);
            }
    
            if (primes.size() < 2) return {-1, -1};
    
            int minDiff = INT_MAX;
            int num1 = -1, num2 = -1;
            
            for (int i = 1; i < primes.size(); i++) {
                int diff = primes[i] - primes[i - 1];
                if (diff < minDiff) {
                    minDiff = diff;
                    num1 = primes[i - 1];
                    num2 = primes[i];
                }
            }
    
            return {num1, num2};
        }
    };
    