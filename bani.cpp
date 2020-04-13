// Banu Miruna-Elena 321CA
// Copyright 2020
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, set;
    vector<vector<long>> bills;

    // Reads the input from the ".in" file
    void read_input() {
        ifstream fin("bani.in");
        fin >> set >> n;
        fin.close();
    }

    // Dynamic programming recurence for the 2nd type of set
    vector<vector<long>> get_result_set_2(int n) {
        // Initialize a matrix of 2 columns and bills + 1
        // lines with 1
        vector<vector<long>> bills(6, vector<long>(2, 1));

        for (int i = 2; i <= n; ++i) {
            // Get the parity of the current number so that
            // the other column can be used to get the new result
            int m = i % 2;

            // Each line represents one of the bills' types
            bills[1][m] = ((bills[2][(m + 1) % 2] % MOD) +
                (bills[3][(m + 1) % 2] % MOD) +
                (bills[5][(m + 1) % 2] % MOD)) % MOD;

            bills[2][m] = ((bills[1][(m + 1) % 2] % MOD) +
                (bills[4][(m + 1) % 2] % MOD)) % MOD;

            bills[3][m] = ((bills[1][(m + 1) % 2] % MOD) +
                (bills[3][(m + 1) % 2] % MOD) +
                (bills[4][(m + 1) % 2] % MOD)) % MOD;

            bills[4][m] = ((bills[2][(m + 1) % 2] % MOD) +
                (bills[5][(m + 1) % 2] % MOD)) % MOD;

            bills[5][m] = (bills[4][(m + 1) % 2] % MOD);
        }

        return bills;
    }

    // Recursively determines a given base at a given power
    long fast_pow(int base, int exponent, int mod) {
        long result;
        if (exponent == 0) {
            return 1;
        }
        if (exponent == 1) {
            return (base % mod);
        } else {
            if (exponent % 2 == 0) {
                result = fast_pow(base, exponent/2, mod);
                return ((1LL * result * result) % mod);
            } else {
                return ((1LL * base *
                fast_pow(base, exponent - 1, mod)) % mod);
            }
        }
        return result;
    }

    long get_result() {
        vector<vector<long>> bills(6, vector<long>(2, 0));
        long result = 0;

        // If the set is 1, then there is a mathematical formula
        // to determine the result
        if (set == 1) {
            return ((1LL * 5 * fast_pow(2, n - 1, MOD)) % MOD);
        } else {
            // If the set is 2, then we apply a dynamic programming concept
            // from the fourth category: Counting
            bills = get_result_set_2(n);

            // The result is the sum of all the possibilities on the column
            // corresponding to the parity of n
            for (int i = 1; i <= 5; ++i) {
                result = ((result % MOD) + (bills[i][n % 2] % MOD)) % MOD;
            }
        }

        return result;
    }

    void print_output(int result) {
        ofstream fout("bani.out");
        fout << result;
        fout.close();
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
