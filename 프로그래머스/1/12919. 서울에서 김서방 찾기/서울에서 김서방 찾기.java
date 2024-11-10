import java.util.*;
import java.lang.StringBuilder;

class Solution {
    public String solution(String[] seoul) {
        int x = Arrays.asList(seoul).indexOf("Kim");
        return new StringBuilder("김서방은 ").append(x).append("에 있다").toString();
    }
}