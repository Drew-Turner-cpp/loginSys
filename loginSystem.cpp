#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

bool logincheck( string filename, string userUN, string userPW );
void regIs( string filename, string usern, string passw );





int
main()
{
    int query;
    string usern, passw;
    string filename = "loginInfo.txt";

    cout << "Register(1) or Login(2)"; cin >> query;
    
    
    if ( query == 1 )
    {
        cout << ":::REGISTER:::" << endl;
        cout << "Username: "; cin >> usern;  // Define username
        cout << "Password: "; cin >> passw;  // Define password


        regIs(filename, usern, passw);

        cout << "Successfully Registered" << endl;
    }


    // Login check
    else if ( query == 2 )
    {
        cout << ":::LOGIN:::" << endl;
        cout << "Username: "; cin >> usern;  // Define username
        cout << "Password: "; cin >> passw;  // Define password

        
        // Conditional block
        bool check = logincheck(filename, usern, passw );  // Call function to check login
        if ( check == true )
        {
            cout << "LOGIN SUCCESSFUL" << endl;
        }
        else
        {
            cout << "LOGIN FAILED, TRY AGAIN" << endl;
        }
    }
    system("PAUSE");
    return 0;
}


bool
logincheck( string filename, string userUN, string userPW )
{

    string un, pw;

    ifstream read(filename);
    getline(read, un);
    getline(read, pw);

    if ( un == userUN && pw == userPW )
    {
        return true;
    }
    else
    {
        return false;
    }

}


void
regIs( string filename, string usern, string passw )
{

    ofstream file;
    file.open(filename);
    file << usern << endl << passw;
    file.close();

}
