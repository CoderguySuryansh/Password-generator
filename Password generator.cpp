#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random password of the given length
string generatePassword(int length) {
    const string lowercase_chars = "abcdefghijklmnopqrstuvwxyz";
    const string uppercase_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    const string special_chars = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    const string all_chars = lowercase_chars + uppercase_chars + digits + special_chars;
    const int total_chars = all_chars.length();

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    string password;
    for (int i = 0; i < length; ++i) {
        int random_index = rand() % total_chars;
        password += all_chars[random_index];
    }

    return password;
}

int main() {
    int password_length;

    cout << "Password Generator" << endl;
    cout << "Enter the length of the password: ";
    cin >> password_length;

    if (password_length <= 0) {
        cout << "Invalid password length. Please enter a positive value." << endl;
        return 1;
    }

    string generated_password = generatePassword(password_length);
    cout << "Generated Password: " << generated_password << endl;

    return 0;
}
