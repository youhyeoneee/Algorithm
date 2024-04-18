class Solution {
    boolean solution(String s) {
        boolean answer = true;

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("Hello Java");
        
        int p_cnt = 0;
        int y_cnt = 0;
        
        for(int i=0; i<s.length(); i++) {   
            switch(s.charAt(i)) {
                case 'p':
                case 'P':
                    p_cnt++;
                    break;
                case 'y':
                case 'Y':
                    y_cnt++;
                    break;
                default:
                    break;
            }
        }
    
        return p_cnt == y_cnt;
    }
}