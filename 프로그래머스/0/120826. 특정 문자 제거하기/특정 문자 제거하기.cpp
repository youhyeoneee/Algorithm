#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string my_string, string letter) {    
    string new_string = "";
    
    for(int i=0; i<my_string.size(); i++) {
        if (my_string[i] != letter[0]) {
            new_string += my_string[i];
        }
    }
    return new_string;
}