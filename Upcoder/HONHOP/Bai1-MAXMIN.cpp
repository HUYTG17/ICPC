#include <iostream>
#include <fstream>

using namespace std;

int main()
{   
    ifstream in("MAXMIN.INP");
    ofstream out("MAXMIN.OUT");
    int a, b, c;
    in >> a >> b >> c;
    int Max = max(a, max(b, c));
    int Min = min(a, min(b, c));
    out << Max << '\n' << Min << '\n' << Max + Min;
    in.close();
    out.close();
}