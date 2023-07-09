#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

long long int exponentiate(long long int n1, long long int n2, long long int p)
{
    if (n2 == 1)
        return n1;

    else
        return (((long long int)pow(n1, n2)) % p);
}

int main()
{
    int p, g;

    cout << "Enter the values for p and g:\n";
    cin >> p >> g;

    cout << endl;

    int x, y;
    cout << "Enter the value of sender's secret key - x : \n";
    cin >> x;

    cout << endl;

    cout << "Enter the value of receiver's secret key - y : \n";
    cin >> y;

    cout << endl;

    long long R1, R2;

    R1 = exponentiate(g, x, p);
    R2 = exponentiate(g, y, p);

    cout << "The value of R1: " << R1 << endl;
    cout << "The value of R2: " << R2 << endl;

    cout << "\n---R1 calculated by sender is transmitted to receiver---\n";
    cout << "---R2 calculated by receiver is transmitted to sender---\n\n";

    long long K1, K2;

    K1 = exponentiate(R2, x, p);
    K2 = exponentiate(R1, y, p);

    cout << "K1 calculated by sender: " << K1 << endl;
    cout << "K2 calculated by receiver: " << K2 << endl;

    cout << "\n------------------------------------------\n\n";

    cout << "The secret key is " << K1 << endl;

    cout << "\n------------------------------------------\n\n";

    return 0;
}
