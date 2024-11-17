import java.util.Arrays;
class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        int answer = citations.length;
        for(int c: citations){
            if(c >= answer){
                break;
            }else{
                answer -= 1;
            }
        }
        return answer;
    }
}