import java.util.*;

class Solution {
    public String solution(String[] seoul) {
        int x = 0;
        
        for(String value: seoul) {
            if (value.equals("Kim")) break;
            x++;
        }

        return "김서방은 "+ x + "에 있다";
    }
}