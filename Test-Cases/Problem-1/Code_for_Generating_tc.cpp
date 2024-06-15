#include <iostream>
#include <fstream>   // For file handling
#include <unordered_map>
#include <vector>
#include <cstdlib>   // For rand and srand
#include <ctime>     // For time

using namespace std;

// Function to generate random test cases
vector<int> generateRandomTestCase(int size) {
    vector<int> v(size);
    srand(time(0)); 
    for (int i = 0; i < size; ++i) {
        v[i] = rand() % 10; 
    }

    return v;
}

// Function to run test cases and store results in a file
void runAndStoreTest(vector<int>& input, ofstream& outFile) {
    // Implement your isPossible function here
    int n = input.size();
    outFile<<n<<endl;
    for(int i=0;i<input.size()-1;i++){
        outFile<<input[i]<<" ";
    }
    outFile<<input[n-1]<<"\n";
}

int main() {
    ofstream outFile("test_cases.txt"); // Open a file for writing

    for (int i = 0; i < 100; ++i) {
        int size = rand() % 10 + 100; 
        vector<int> randomTest = generateRandomTestCase(size);
        runAndStoreTest(randomTest, outFile); 
    }

    outFile.close(); 

    return 0;
}
