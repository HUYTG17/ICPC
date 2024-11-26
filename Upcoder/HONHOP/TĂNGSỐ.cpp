#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '9')
            s[i] = '0';
        else
            s[i] += 1;
    }
    int n = stoi(s);
    cout << n;
}