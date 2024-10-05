#include <iostream>

using namespace std;

int main()
{
    string adn;
    cin >> adn;
    int cnt = 1;
    int Max = 1;
    for(int i = 1; i < adn.size(); i++)
    {
        if(adn[i] == adn[i -1])
        {
            cnt++;
        }
        else 
        {
            Max = max(Max, cnt);
            cnt = 1;
        }
    }
    Max = max(Max, cnt);
    cout << Max;
    return 0;
}