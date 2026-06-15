#include <iostream>
#include <string>
using namespace std;

// ========== XOR ENCRYPTION FUNCTIONS ==========

// Simple XOR with single character key
string xorEncryptDecrypt(string text, char key) {
    string result = text;
    for (int i = 0; i < text.length(); i++) {
        result[i] = text[i] ^ key;
    }
    return result;
}

// Advanced XOR with repeating string key
string xorWithKey(string text, string key) {
    string result = text;
    for (int i = 0; i < text.length(); i++) {
        result[i] = text[i] ^ key[i % key.length()];
    }
    return result;
}

// ========== MESSAGING FUNCTIONS ==========

// Send message (encrypt and display)
string sendMessage(string message, string key) {
    cout << "\n   📤 SENDING: \"" << message << "\"" << endl;
    
    // Encrypt using repeating key
    string encrypted = xorWithKey(message, key);
    
    // Display encrypted message as hex
    cout << "   🔐 ENCRYPTED to: ";
    for (char c : encrypted) {
        printf("%02x ", (unsigned char)c);
    }
    cout << endl;
    
    return encrypted;
}

// Receive message (decrypt and display)
string receiveMessage(string encrypted, string key) {
    string decrypted = xorWithKey(encrypted, key);
    cout << "   🔓 DECRYPTED to: \"" << decrypted << "\"" << endl;
    return decrypted;
}

// ========== MAIN FUNCTION ==========

int main() {
    string key;
    int choice;
    string message;
    string encryptedMsg;
    string decryptedMsg;
    
    // Display header
    cout << "\n";
    cout << "+_____________________________________________________________+\n";
    cout << "|                                                             |\n";
    cout << "|                        MESSAGING SYSTEM                     |\n";
    cout << "|                                                             |\n";
    cout << "|           XOR Encryption Messaging System                   |\n";
    cout << "+_____________________________________________________________+\n";
    
    cout << " \n";
    cout << "       Set Your Secret Key:   ";
    getline(cin, key);
    
    // Main menu loop
    while (true) {
        cout << "\n";
        cout << "+_____________________________________________________________+\n";
        cout << "|                                                             |\n";
        cout << "|                          MENU                               |\n";
        cout << "|                                                             |\n";
        cout << "|          1. Send Encrypted Message                          |\n";
        cout << "|                                                             |\n";
        cout << "|          2. Receive And Decrypt Message                     |\n";
        cout << "|                                                             |\n";
        cout << "|          3. Exit                                            |\n";
        cout << "|                                                             |\n";
        cout << "+_____________________________________________________________+\n";
        
        cout << "\n Enter Your Choice (1, 2, or 3): ";
        cin >> choice;
        cin.ignore();  // Clear the newline character
        
        if (choice == 1) {
            // SEND MESSAGE
            cout << "       Enter The message: ";
            getline(cin, message);
            encryptedMsg = sendMessage(message, key);
            
        } else if (choice == 2) {
            // RECEIVE MESSAGE
            cout << "       Enter Encrypted Message (hex): ";
            string hexInput;
            getline(cin, hexInput);
            
            cout << "       Enter Raw Encrypted Message: ";
            string encryptedInput;
            getline(cin, encryptedInput);
            
            // Decrypt the message
            decryptedMsg = receiveMessage(encryptedInput, key);
            
        } else if (choice == 3) {
            // EXIT
            cout << "\n      Goodbye!\n";
            break;
            
        } else {
            // INVALID CHOICE
            cout << "\n      Invalid choice! Please enter 1, 2, or 3.\n";
        }
    }
    
    return 0;
}