#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt text using Caesar cipher
string encrypt(const string& text, int shift) {
    string encryptedText = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            char shifted = (toupper(ch) - 'A' + shift) % 26 + 'A';
            encryptedText += shifted;
        }
        else {
            encryptedText += ch;
        }
    }
    return encryptedText;
}

// Function to decrypt text using Caesar cipher
string decrypt(const string& text, int shift) {
    return encrypt(text, 26 - shift); // Decryption is essentially encryption with the opposite shift
}

// Function to read text from file
string readFromFile(const string& filename) {
    ifstream file(filename);
    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    return content;
}

// Function to write text to file
void writeToFile(const string& filename, const string& content) {
    ofstream file(filename);
    file << content;
}

int main() {
    string filename;
    int shift;
    char choice;

    cout << "Enter filename: ";
    cin >> filename;
    cout << "Enter shift (positive for encryption, negative for decryption): ";
    cin >> shift;

    string content = readFromFile(filename);

    cout << "Do you want to encrypt (e) or decrypt (d) the file? (e/d): ";
    cin >> choice;

    if (choice == 'e') {
        string encryptedText = encrypt(content, shift);
        writeToFile(filename + ".encrypted", encryptedText);
        cout << "File encrypted successfully." << endl;
    }
    else if (choice == 'd') {
        string decryptedText = decrypt(content, shift);
        writeToFile(filename + ".decrypted", decryptedText);
        cout << "File decrypted successfully." << endl;
    }
    else {
        cout << "Invalid choice. Exiting..." << endl;
    }

    return 0;
}
