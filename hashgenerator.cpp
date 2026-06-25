#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

unsigned long generateHash(const string& input) {
    unsigned long hash = 5381;
    for (char c : input) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

int main() {
    vector<pair<string, unsigned long>> hashHistory;
    string input;
    char choice;

    cout << "--- Simple Text Hash Generator ---\n";

    do {
        cout << "Enter text to hash: ";
        getline(cin, input);

        unsigned long hashValue = generateHash(input);
        hashHistory.push_back(make_pair(input, hashValue));

        cout << "Generated Hash (Hex): 0x" << hex << hashValue << dec << "\n";
        cout << "Generated Hash (Dec): " << hashValue << "\n\n";

        cout << "Hash another string? (y/n): ";
        cin >> choice;
        cin.ignore(); 
        cout << "\n";

    } while (choice == 'y' || choice == 'Y');

    cout << "--- Session Hash History ---\n";
    for (const auto& entry : hashHistory) {
        cout << "Text: \"" << entry.first << "\" | Hash: 0x" << hex << entry.second << dec << "\n";
    }

    return 0;
}

