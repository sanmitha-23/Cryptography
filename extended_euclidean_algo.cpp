#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int gcd(int u, int v)
{
    if (v == 0)
        return u;
    else
        gcd(v, u % v);
}

int multiplicative_inv(int num, int range)
{

    int inverse;

    int r1 = range;
    int r2 = num;
    int t1 = 0;
    int t2 = 1;

    int q, r, t;

    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (r1 == 1)
    {
        if (t1 > 0)
            inverse = t1;
        else
        {
            inverse = (t1 + range) % range;
        }
    }

    return inverse;
}

int main()
{
    int num, range;

    cout << "Enter the range number: ";
    cin >> range;

    cout << endl;

    cout << "Enter the number: ";
    cin >> num;

    cout << endl;

    if (gcd(num, range) == 1)
        cout << "The multiplicative inverse of the entered number is: " << multiplicative_inv(num, range) << endl;
    else
        cout << "Multiplicative inverse of the entered number does not exist\n";

    return 0;
}
