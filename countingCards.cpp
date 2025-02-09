#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <numeric>

using namespace std;
using namespace std::chrono;

template<typename T>
void print_vector(vector<T> vec){
    for (T i : vec)
        cout << i << ' ';
}

template<typename T>
vector<T> bad_shuffle(vector<T> vec){
    int n = static_cast<int>(vec.size());
    const int sz = static_cast<int>(vec.size());
    vector<bool> shuffled (n,false); // keep track of which elements have already been shuffled
    // shuffled[i] is true if element vec[i] has already been shuffled, false otherwise
    // Another approach would be to simulate deletion by replacing that element with a flag value (like -1) in place if it was shuffled,
    // but -1 or any other flag value we choose could be a valid element, so this doesn't work
    vector<T> out;
    int i;
    while(n){
        i = rand() % sz;
        if(!shuffled[i]){
            out.push_back(vec[i]);
            n--;
            shuffled[i] = true;
        }
    }
    return out;
}

template<typename T>
vector<T> better_shuffle(vector<T> vec){
    vector<T> out;
    int n = static_cast<int>(vec.size());
    int i;
    while(n){
        i = rand() % (n--);
        out.push_back(vec[i]);
        vec.erase(vec.begin()+i);
    }
    return out;
}

// Could change to pass by reference if want to change original array
template<typename T>
vector<T> best_shuffle(vector<T> vec){
    int n = static_cast<int>(vec.size());
    int i;
    while(n){
        i = rand() % (n--);  // pick remaining element
        swap(vec[n], vec[i]); // swap it with current element
        // shuffled elements end up in the back of the array
    }
    return vec;
}


template<typename Func, typename T>
void benchmark_vec(Func func, vector<T> vec, int iterations, const string& label) {
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++) {
        func(vec); // Call the function
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();
    cout << label << ": " << duration / iterations << " ns (average per call)" << endl;
}

template<typename T>
void test_algs(vector<T> vec_to_shuffle, int iterations){
    cout << "Original array: ";
    print_vector(vec_to_shuffle);
    cout << endl;
    
    cout << "Shuffling with a bad algorithm..." << endl;
    benchmark_vec(bad_shuffle<T>, vec_to_shuffle, iterations, "Slowest algorithm"); 
    cout << "Shuffled array: ";
    print_vector(bad_shuffle(vec_to_shuffle));
    cout << endl << endl;

    cout << "Shuffling with a better algorithm..." << endl;
    benchmark_vec(better_shuffle<T>, vec_to_shuffle, iterations, "Better algorithm"); 
    cout << "Shuffled array: ";
    print_vector(better_shuffle(vec_to_shuffle));
    cout << endl << endl;

    cout << "Shuffling with the best algorithm..." << endl;
    benchmark_vec(best_shuffle<T>, vec_to_shuffle, iterations, "Fastest algorithm"); 
    cout << "Shuffled array: ";
    print_vector(best_shuffle(vec_to_shuffle));
    cout << endl << endl << endl;
}

int main() {
    srand(time(nullptr)); 
    vector<int> test1 = {1, 2, 3, 4, 5};  // integer array, 5 values
    vector<double> test2 = {1.1, -2.5, 3.14, 0.0, 7.8, 21.1, 19.8, 3.11, 10.12, 1.1};  // double array, 10 values, some repeating
    vector<char> test3 = {'a', 'y', 'c', 'd', 'e', 'f', 'z'};    // character array, 7 values
    vector<string> test4 = {"apple", "banana", "cherry"}; // string array, 3 values 
    vector<int> test5 = {22}; // integer array, 1 value (edge case)  
    vector<int> test6 = {};  // empty array edge case
    vector<int> test7(1000) ; // integer array, 1000 values
    iota(begin(test7), end(test7), 0); // Fill with 0, 1, ..., 999.

    test_algs(test1, 10000);
    test_algs(test2, 10000);
    test_algs(test3, 10000);
    test_algs(test4, 10000);
    test_algs(test5, 10000);
    test_algs(test6, 10000);
    test_algs(test7, 10000);

    return 0;
}