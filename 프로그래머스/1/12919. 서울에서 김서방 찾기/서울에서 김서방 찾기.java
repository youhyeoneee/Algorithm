import java.util.*;
import java.lang.StringBuilder;

class Solution {
    public String solution(String[] seoul) {
        int x = 0;
        
        for(String value: seoul) {
            if (value.equals("Kim")) break;
            x++;
        }
        
        return new StringBuilder("김서방은 ").append(x).append("에 있다").toString();
    }
}