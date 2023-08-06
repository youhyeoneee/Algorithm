#include <iostream>
#include <string>

using namespace std;

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Print(string str)
{
    cout << str << '\n';
}

int main()
{
    FastIO();
    Print("    8888888888  888    88888");
    Print("   88     88   88 88   88  88");
    Print("    8888  88  88   88  88888");
    Print("       88 88 888888888 88   88");
    Print("88888888  88 88     88 88    888888");
    Print("");
    Print("88  88  88   888    88888    888888");
    Print("88  88  88  88 88   88  88  88");
    Print("88 8888 88 88   88  88888    8888");
    Print(" 888  888 888888888 88  88      88");
    Print("  88  88  88     88 88   88888888");

    return 0;
}