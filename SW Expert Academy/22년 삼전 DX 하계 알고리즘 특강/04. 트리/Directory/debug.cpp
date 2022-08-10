#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        if (temp != "\0") answer.push_back(temp);
    }
 
    return answer;
}

string get_directory_name(char path[11], int type){
    vector<string> v;  
    v = split(path, '/');
    int vec_size = v.size();

    if (vec_size > 0){
        if (type == 1 && vec_size > 1) {
            return v[vec_size-2];
        }
        else if (type == 0) return v[vec_size-1];
    }
    return "/";
}


int main(){

    // vector<string> v;  
    // v = split(path, '/');
    // for(auto i : v){
    //     cout << i << "\n";
    // }

    // cout << v.size();
    char path[11] = "/cc/";
    cout << get_directory_name(path, 1);
}