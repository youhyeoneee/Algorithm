#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Keypad {
    public:
        int number; // 번호
        pair<int, int> pos;
        string hand;
    
    Keypad(char number, int x, int y) {
        this->number = number;
        pos = {y, x};
        if (number == 1 || number == 4 || number == 7)
            hand = 'L';
        else if (number == 3 || number == 6 || number == 9)
            hand = 'R';
        else
            hand = "";
    }
    
    int getDistance(pair<int, int> other) {
        return abs(pos.first - other.first) + abs(pos.second - other.second);
    }
};
    
string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    vector<Keypad> keypads;
    
    int x=0, y=0;
    
    Keypad zero(0, 1, 3);
    keypads.push_back(zero);
    for(int i=1; i<=9; i++) {
        Keypad k(i, x, y);
        keypads.push_back(k);
        
        x++;
        if (x % 3 == 0) {
            y++;
            x = 0;
        }
    }    
    
    // y, x
    pair<int, int> leftPos = {3, 0};
    pair<int, int> rightPos = {3, 2};
    
    for(int targetNumber : numbers) {   
        Keypad k = keypads[targetNumber];
        string currHand = k.hand;

        if (currHand == "") {
            int leftDiff = k.getDistance(leftPos);
            int rightDiff = k.getDistance(rightPos);
        
            if (leftDiff < rightDiff) {
                leftPos = k.pos;
                answer += "L";
            } else if (leftDiff > rightDiff) {
                rightPos = k.pos;
                answer += "R";
            } else {
                if (hand == "right") {
                    rightPos = k.pos;
                    answer += "R";
                } else {
                    leftPos = k.pos;
                    answer += "L";
                }
            }
        } else {
            answer += currHand;
            if (currHand == "L") leftPos = k.pos;
            else rightPos = k.pos;
        }
        
        
    }
    return answer;
}