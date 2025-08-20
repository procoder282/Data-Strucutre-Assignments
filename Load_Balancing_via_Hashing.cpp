#include <iostream>
#include <string>
using namespace std;

int main() {
    int servers, requests;
    cout << "Enter number of servers: ";
    cin >> servers;

    cout << "\nEnter number of incoming requests: ";
    cin >> requests;

    string reqIDs[100];              // store request IDs (limit 100)
    string serverLoad[10][100];      // max 10 servers, each with up to 100 requests
    int serverCount[10] = {0};       // number of requests per server

    cout << "\nEnter request IDs:\n";
    for (int i = 0; i < requests; i++) {
        cout << "Request " << i + 1 << ": ";
        cin >> reqIDs[i];
    }

    // Round robin assignment
    for (int i = 0; i < requests; i++) {
        int serverIndex = i % servers;  // assign to server
        int pos = serverCount[serverIndex];
        serverLoad[serverIndex][pos] = reqIDs[i];
        serverCount[serverIndex]++;

        cout << "\nRequest '" << reqIDs[i] << "' is handled by Server " << serverIndex;
    }

    // Summary
    cout << "\n\n\nServer Load Summary:\n\n";
    for (int i = 0; i < servers; i++) {
        cout << "Server " << i << " handled " << serverCount[i] << " requests:";
        if (serverCount[i] > 0) cout << " ";
        for (int j = 0; j < serverCount[i]; j++) {
            cout << serverLoad[i][j];
            if (j < serverCount[i] - 1) cout << ", ";
        }
        cout << "\n\n";
    }

    return 0;
}
