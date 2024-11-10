import java.util.*;

class Solution {
    public String solution(String[] seoul) {
        Integer idx = Arrays.asList(seoul).indexOf("Kim");
        
        String answer = "김서방은 " + idx.toString() + "에 있다";
        return answer;
    }
}