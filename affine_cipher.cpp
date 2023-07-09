#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

string uc(string s)
{
    string encry_uc = "";
    for (int i = 0; i < s.length(); i++)
    {
        encry_uc += (s[i] - 32);
    }
    return encry_uc;
}

string encrypt(string msg, int k1, int k2)
{

    string res = "";
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] != ' ')
        {
            res += (char)(((((msg[i] - 97) * k1) + k2) % 26) + 97);
        }
        else
        {
            res += " ";
        }
    }
    return res;
}

string decrypt(string msg, int k1, int k2)
{
    string res = "";
    int inv_k1;

    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        flag = (k1 * i) % 26;

        if (flag == 1)
            inv_k1 = i;
    }
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] != ' ')
        {
            int inter = (msg[i] - 97) - k2;
            if (inter < 0)
            {
                inter = (inter + 26);
            }
            res += (char)(((inter * inv_k1) % 26) + 97);
        }
        else
        {
            res += " ";
        }
    }

    return res;
}

int main()
{
    int k1, k2;
    string msg;
    cout << "Enter two keys: ";
    cin >> k1 >> k2;

    cout << "\nEnter the message: ";
    cin >> msg;

    cout << "\n-------------------------------------------\n\n";

    string encrypted_msg = encrypt(msg, k1, k2);

    cout << "Encrypted text - Cipher text: " << uc(encrypted_msg) << endl;
    cout << "Decrypted text - Plain text: " << decrypt(encrypted_msg, k1, k2) << endl;

    cout << "\n-------------------------------------------\n";

    return 0;
}
