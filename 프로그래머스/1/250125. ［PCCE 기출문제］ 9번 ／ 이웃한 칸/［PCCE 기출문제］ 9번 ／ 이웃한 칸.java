import java.util.*;

class Solution {
    private int n; 
    
    private boolean inRange(int h, int w) {
        return h >= 0 && h < n && w >= 0 && w < n;
    }
    
    public int solution(String[][] board, int h, int w) {        
        n = board.length;
        int count = 0;
        
        int[] dh = {0, 1, -1, 0};
        int[] dw = {1, 0, 0, -1};
        
        for(int i=0; i<4; i++) {
            int h_check = h + dh[i];
            int w_check = w + dw[i];
                        
            if (inRange(h_check, w_check) && board[h][w].equals(board[h_check][w_check])) {
                count++;
            }
                
        }
        
        return count;
    }
}