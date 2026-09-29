 #include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string address;
    int a, b, c, d;
    char dot;

    // Take IPv4 address as a single string
    cout << "Enter IPv4 Address: ";
    cin >> address;

    // Separate the address
    stringstream ss(address);

    if (!(ss >> a >> dot >> b >> dot >> c >> dot >> d) ||
        dot != '.' ||
        a < 0 || a > 255 ||
        b < 0 || b > 255 ||
        c < 0 || c > 255 ||
        d < 0 || d > 255)
    {
        cout << "\nInvalid IPv4 Address";
        return 0;
    }

    cout << "\nValid IPv4 Address";

    // Class A
    if (a >= 1 && a <= 126)
    {
        cout << "\nClass     : A";
        cout << "\nNetwork ID: " << a << ".0.0.0";
        cout << "\nHost ID   : " << b << "." << c << "." << d;
    }

    // Class B
    else if (a >= 128 && a <= 191)
    {
        cout << "\nClass     : B";
        cout << "\nNetwork ID: " << a << "." << b << ".0.0";
        cout << "\nHost ID   : " << c << "." << d;
    }

    // Class C
    else if (a >= 192 && a <= 223)
    {
        cout << "\nClass     : C";
        cout << "\nNetwork ID: " << a << "." << b << "." << c << ".0";
        cout << "\nHost ID   : " << d;
    }

    // Class D
    else if (a >= 224 && a <= 239)
    {
        cout << "\nClass     : D";
        cout << "\nUsed for Multicasting";
    }

    // Class E
    else if (a >= 240 && a <= 255)
    {
        cout << "\nClass     : E";
        cout << "\nUsed for Experimental Purpose";
    }

    return 0;
}