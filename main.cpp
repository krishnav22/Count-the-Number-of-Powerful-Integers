
using ll = long long;
using namespace std;

class Solution {
public:
    // Function to calculate a^b
    ll pw(ll a, ll b) {
        ll ans = 1;
        while (b--) ans *= a;
        return ans;
    }

    // Function to count powerful integers up to n with a given limit and suffix s
    ll get(ll n, ll l, string &s) {
        // Convert n to a string representation
        string N = to_string(n);
        ll ans = 0;

        // If the length of N is less than the length of s, there are no powerful integers
        if (N.size() < s.size()) {
            return 0;
        } else if (N.size() > s.size()) {
            // If the length of N is greater than the length of s
            bool ok = 1; // Flag to check if all digits are within the limit
            for (int i = 0; i < N.size() - s.size(); i++) {
                ok &= ((N[i] - '0') <= l); // Check if each digit is less than or equal to the limit
                ll cur = min(l + 1, ll(N[i] - '0')); // Calculate the contribution of the current digit

                // Adjust the contribution for the last segment of digits, considering the suffix s
                if (i == (N.size() - s.size() - 1LL))
                    cur += ok && (N.substr(N.size() - s.size(), s.size()) >= s);

                // Multiply the current contribution by the count of remaining digits
                for (int j = i + 1; j < N.size() - s.size(); j++)
                    cur *= l + 1;

                // Add the current contribution to the total count
                ans += cur;

                // If the current digit exceeds the limit, break the loop
                if ((N[i] - '0') > l) break;
            }
        } else {
            // If the length of N is equal to the length of s
            ans += N >= s; // Check if N is greater than or equal to s
        }
        return ans;
    }


    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return get(finish, limit, s) - get(start - 1, limit, s);
    }
};
