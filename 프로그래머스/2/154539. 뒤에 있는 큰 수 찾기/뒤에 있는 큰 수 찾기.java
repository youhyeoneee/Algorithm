import java.util.Stack;

class Solution {
    public int[] solution(int[] numbers) {
        int n = numbers.length;
        int[] answer = new int[n];
        for (int i=0; i<n; i++) {
            answer[i] = -1;
        }
        
        Stack<Integer> stack = new Stack();
        for (int i=0; i<n; i++) {
            int target = numbers[i];
            
            while (!stack.empty() && target > numbers[stack.peek()])
                answer[stack.pop()] = target;
            
            stack.push(i);
        }
        
        return answer;
    }
}