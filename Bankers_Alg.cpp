#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// Function to check if the system is in a safe state
bool isSafe(vector<vector<int>> &allocation, vector<vector<int>> &maximum, vector<int> &available, vector<int> &safeSequence) {
    int numProcesses = allocation.size();
    int numResources = available.size();

    vector<vector<int>> need(numProcesses, vector<int>(numResources));
    vector<bool> finished(numProcesses, false);

    // Calculate the Need matrix
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    vector<int> work = available; // Work vector to simulate resource allocation
    int count = 0; // Count of processes that can finish

    while (count < numProcesses) {
        bool found = false;

        for (int i = 0; i < numProcesses; i++) {
            if (!finished[i]) {
                bool canAllocate = true;

                // Check if the process can be allocated resources
                for (int j = 0; j < numResources; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    // Allocate resources to this process
                    for (int j = 0; j < numResources; j++) {
                        work[j] += allocation[i][j];
                    }

                    safeSequence.push_back(i);
                    finished[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found) {
            return false; // System is not in a safe state
        }
    }

    return true; // System is in a safe state
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    string line;
    int numProcesses = 5; // Fixed for this example
    int numResources = 3; // Fixed for this example

    vector<vector<int>> allocation(numProcesses, vector<int>(numResources));
    vector<vector<int>> maximum(numProcesses, vector<int>(numResources));
    vector<int> available(numResources);

    // Read Allocation matrix
    while (getline(inputFile, line)) {
        if (line[0] == '#') continue; // Skip comments
        stringstream ss(line);
        for (int i = 0; i < numProcesses; i++) {
            for (int j = 0; j < numResources; j++) {
                ss >> allocation[i][j];
            }
        }
        break;
    }

    // Read Maximum matrix
    while (getline(inputFile, line)) {
        if (line[0] == '#') continue; // Skip comments
        stringstream ss(line);
        for (int i = 0; i < numProcesses; i++) {
            for (int j = 0; j < numResources; j++) {
                ss >> maximum[i][j];
            }
        }
        break;
    }

    // Read Available resources
    while (getline(inputFile, line)) {
        if (line[0] == '#') continue; // Skip comments
        stringstream ss(line);
        for (int i = 0; i < numResources; i++) {
            ss >> available[i];
        }
        break;
    }

    inputFile.close();

    vector<int> safeSequence;

    if (isSafe(allocation, maximum, available, safeSequence)) {
        cout << "The system is in a safe state.\nSafe sequence is: ";
        for (int i : safeSequence) {
            cout << "P" << i << " ";
        }
        cout << endl;
    } else {
        cout << "The system is not in a safe state." << endl;
    }

    return 0;
}