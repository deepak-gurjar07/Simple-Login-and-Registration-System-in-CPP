#include <iostream>
#include <fstream> // We use file handling in this part of the code.
#include <cstring>
using namespace std;

// This section is for verifying if you have created an account or not.
// Here, we use a boolean value that always returns true or false.
// If you have an account, this means true; otherwise, false.

// Verify if the user is logged in or not.

bool IsLoggedIn()
{
    string username, password, un, pw; // The last two are comparison strings.

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Read from the file to check if you have an account.
    // We use a stream for reading the file.
    // 'read' is a variable here.
    ifstream read("data\\" + username + ".txt"); // Here, 'data.txt' is where our data will be saved.
    // The file name is enclosed in double quotes in file handling.
    getline(read, un); // Read the username to check if the user is valid.
    getline(read, pw); // Read the password to check if it is correct.

    // Comparison

    if (un == username && pw == password)
    {
        return true; // This means the user is valid and can log in.
    }
    else
    {
        return false;
    }
}

int main()
{
    // system("color 3f"); for color output in the console
    int choice;

    cout << "1: Register\n2: Login\nYour choice: ";
    cin >> choice;
    if (choice == 1)
    {
        string username, password;

        cout << "Select a username: ";
        cin >> username;
        cout << "Select a password: ";
        cin >> password;

        //

        ofstream file;
        // Open the file using the 'open' function.
        file.open("data\\" + username + ".txt");

        // Write to the file.
        file << "username: " << username << endl << "password: " << password; // The data is registered into our file.
        file.close();

        // Return to 'main' because we might want to log in again
        // or proceed to register another user.
        main();
    }

    // If a user already has an account and wants to log in.
    else if (choice == 2)
    {
        // Create a variable 'status' and assign it to the 'IsLoggedIn' function.
        // Proceed from there.
        bool status = IsLoggedIn();

        if (!status) // If login fails because the username and password are incorrect.
        {
            cout << "Invalid username or password." << endl;
            system("PAUSE");

            // This is a Windows-specific command that tells the OS to run the 'pause' program.
            // This program waits to be terminated and halts the execution of the parent C++ program.
            return 0;
        }
        else // If login is successful, return 1 or proceed further.
        {
            cout << "Successfully logged in." << endl;
            system("pause");
            return 1;
        }
    }
}
