#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;


list<int> RemoveDuplicates(list<int>& in)
{
    list<int> out;

    for(auto ival : in)
    {
        bool found = false;

        for ( auto oval : out)
        {
            if (ival == oval)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            out.push_back(ival);
        }
    }


    return out;

}


list<int> RemoveDuplicates2(list<int>& in)
{
    unordered_set<int> s (in.begin(), in.end());
    list<int> out (s.begin(), s.end());

    return out;
}


void Print(list<int>& in)
{
    for(auto ival : in)
        cout << ival << " ";

    cout << '\n';

}

int main()
{
    list<int> inArr = {1, 5, 3, 3, 6, 7, 6, 1, 4, 2};

    list<int> outArr = RemoveDuplicates2(inArr);
    Print(outArr);
    
    return 0;
}