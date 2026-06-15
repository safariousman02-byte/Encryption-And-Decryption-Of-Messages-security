#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// XOR encryption function (repeating key)
string xorEncrypt(string text, string key) {
    string result = text;
    for (int i = 0; i < text.length(); i++) {
        result[i] = text[i] ^ key[i % key.length()];
    }
    return result;
}

// Convert hex string (like "1b 00 0f") to actual binary string
string hexToString(string hexStr) {
    string result;
    stringstream ss(hexStr);
    string hexByte;
    
    while (ss >> hexByte) {
        // Convert hex string to integer
        char byte = (char)stoi(hexByte, nullptr, 16);
        result += byte;
    }
    
    return result;
}

// Convert binary string to hex for display
string stringToHex(string str) {
    stringstream ss;
    for (unsigned char c : str) {
        ss << hex << (int)c << " ";
    }
    return ss.str();
}

int main() {
    string key;
    int choice;
    string message;
    string encryptedMsg;
    string hexInput;
    
    // Header
    cout << "\n+===================================================+\n";
    cout << "|         XOR MESSAGING SYSTEM                      |\n";
    cout << "+===================================================+\n";
    
    cout << "\nSet your secret key: ";
    getline(cin, key);
    
    do {
        // Menu
        cout << "\n+------------------- MENU -----------------------+\n";
        cout << "|  1. Send Message (Encrypt)                     |\n";
        cout << "|  2. Receive Message (Decrypt)                  |\n";
        cout << "|  3. Exit                                       |\n";
        cout << "+------------------------------------------------+\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            // ENCRYPT
            cout << "Enter message: ";
            getline(cin, message);
            encryptedMsg = xorEncrypt(message, key);
            
            cout << "\n?? ORIGINAL: " << message << endl;
            cout << "?? ENCRYPTED (hex): " << stringToHex(encryptedMsg) << endl;
            
        } else if (choice == 2) {
            // DECRYPT - FIXED: Convert hex to bytes first
            cout << "Enter encrypted message (hex format, e.g., '1b 00 0f'): ";
            getline(cin, hexInput);
            
            // Convert hex string to actual binary data
            string encryptedBinary = hexToString(hexInput);
            
            // Now decrypt the binary data
            string decrypted = xorEncrypt(encryptedBinary, key);
            cout << "?? DECRYPTED: " << decrypted << endl;
            
        } else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
        
    } while (true);
    
    return 0;
}