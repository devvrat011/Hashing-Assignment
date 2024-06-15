#include <iostream>
#include <fstream>   // For file handling
#include <unordered_map>
#include <vector>
#include <cstdlib>   // For rand and srand
#include <ctime>     // For time

using namespace std;

vector<int> generateRandomTestCase(int size) {
    vector<int> v(size);
    srand(time(0)); // Seed for random number generator

    // Generate random elements for the vector
    for (int i = 0; i < size; ++i) {
        v[i] = rand() % 21 - 100; // Generate random numbers between -10 to 10
    }

    return v;
}

// Function to calculate the length of the longest subarray with sum zero
int longestSubarrayWithSumZero(vector<int>& A) {
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    mp[0] = -1;

    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
        if (mp.count(sum)) {
            ans = max(ans, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    return ans;
}

// Function to run test cases and store results in a file
void runAndStoreTest(vector<int>& input, ofstream& outFile) {
    int N = input.size();
    outFile <<"Input N = "<<N<<"\n";
    outFile<<"A = [";
    for (int num : input) {
        outFile << num << " ";
    }
    outFile<<"]";
    outFile << endl;
    int result = longestSubarrayWithSumZero(input);
    outFile << "Output: " << result << endl << endl;
}

int main() {
    ofstream outFile("test_cases.txt"); // Open a file for writing

    if (!outFile) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    for (int i = 0; i < 100; ++i) {
        int size = rand() % 10 + 50; // Generate random size between 5 to 14
        vector<int> randomTest = generateRandomTestCase(size);
        runAndStoreTest(randomTest, outFile);
    }

    outFile.close(); 

    return 0;
}
