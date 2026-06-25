#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool xorEncryptDecryptFile(const string& inputFilename, const string& outputFilename, const string& key) {
    ifstream inFile(inputFilename, ios::binary);
    if (!inFile) {
        cerr << "Error: Could not open input file '" << inputFilename << "'\n";
        return false;
    }

    ofstream outFile(outputFilename, ios::binary);
    if (!outFile) {
        cerr << "Error: Could not open output file '" << outputFilename << "'\n";
        return false;
    }

    char ch;
    size_t keyIndex = 0;
    size_t keyLength = key.length();

    while (inFile.get(ch)) {
        char encryptedChar = ch ^ key[keyIndex];
        outFile.put(encryptedChar);
        keyIndex = (keyIndex + 1) % keyLength;
    }

    inFile.close();
    outFile.close();
    
    return true;
}

int main() {
    string inputFile, outputFile, key;

    cout << "--- XOR File Encryption/Decryption Tool ---\n";
    
    cout << "Enter the input filename (e.g., plain.txt): ";
    getline(cin, inputFile);

    cout << "Enter the output filename (e.g., cipher.txt): ";
    getline(cin, outputFile);

    cout << "Enter an encryption key (any text string): ";
    getline(cin, key);

    if (key.empty()) {
        cerr << "Error: Key cannot be empty.\n";
        return 1;
    }

    cout << "Processing file...\n";

    if (xorEncryptDecryptFile(inputFile, outputFile, key)) {
        cout << "Success! Output saved to '" << outputFile << "'\n";
    } else {
        cout << "Operation failed.\n";
        return 1;
    }

    return 0;
}