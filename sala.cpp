// Banu Miruna-Elena 321CA
// Copyright 2020
#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, m;
    vector<pair<long long, long long>> dumbbells;

    void read_input() {
        ifstream fin("sala.in");
        fin >> n >> m;
        long long w, r;
        for (int i = 0; i < n; i++) {
            fin >> w >> r;
            dumbbells.push_back(make_pair(w, r));
        }
        fin.close();
    }

    // Sort the dumbbells decreasing by the weight and then by the rep number
    static bool desc(pair<long long, long long> p1,
        pair<long long, long long> p2) {
            if (p1.first > p2.first) {
                return true;
            } else if (p1.first == p2.first && p1.second > p2.second) {
                return true;
            }
            return false;
    }

    long long get_result() {
        sort(dumbbells.begin(), dumbbells.end(), desc);

        // Creates a min_heap to store the number of repetitions
        // using a priority queue
        priority_queue <long long, vector<long long>,
            greater<long long>> reps_heap;

        long long current_reps =  0;
        long long min_weight = dumbbells[0].first;
        long long current_solution = 0;

        // If the current number of used dumbbells is less than the maximum
        // number, compute the best current solution and add the number of
        // repetitions to the heap
        for (int i = 0; i < m; ++i) {
            reps_heap.push(dumbbells[i].second);
            current_reps += dumbbells[i].second;
            min_weight = dumbbells[i].first;

            if (min_weight * current_reps > current_solution) {
                current_solution = dumbbells[i].first * current_reps;
            }
        }

        // When the number of used dumbbells has reached the max, check if by
        // replacing one dumbbell already in use with one of the remaining ones
        // generates a better solution than the existing one
        for (int i = m; i < dumbbells.size(); ++i) {
            min_weight = dumbbells[i].first;

            if (dumbbells[i].second > reps_heap.top()) {
                current_reps -= reps_heap.top();
                current_reps += dumbbells[i].second;
                reps_heap.pop();
                reps_heap.push(dumbbells[i].second);
            }

            if (min_weight * current_reps > current_solution) {
                current_solution = min_weight * current_reps;
            }
        }

        return current_solution;
    }

    void print_output(long long result) {
        ofstream fout("sala.out");
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
