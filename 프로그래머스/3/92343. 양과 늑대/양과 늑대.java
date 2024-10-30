import java.util.*;

class Solution {
    private int answer = 0;
    private int[] info;
    private HashMap<Integer, ArrayList<Integer>> graph = new HashMap();

    public void dfs(Integer node, int sheep, int wolf, List<Integer> nextNodes) {
        
        if (info[node] == 1) {
            wolf++;
        } else {
            sheep++;
        }
        
        if (wolf >= sheep) {
            return;
        }
        
        if (answer < sheep) {
            answer = sheep;
        }
        
        List<Integer> nodes = new ArrayList<Integer>(nextNodes);
        nodes.remove(node);
        nodes.addAll(graph.get(node));
        
        for (int i=0; i<nodes.size(); i++) {
            dfs(nodes.get(i), sheep, wolf, nodes);
        }
    }
    
    public int solution(int[] info, int[][] edges) {                
        this.info = info;
           
        // 모든 노드에 대해 빈 ArrayList 초기화
        for (int i = 0; i < info.length; i++) {
            graph.put(i, new ArrayList<>());
        }

        // 엣지 정보 추가
        for (int i = 0; i < edges.length; i++) {
            graph.get(edges[i][0]).add(edges[i][1]);
        }
        
        List<Integer> init = new ArrayList<Integer>();
        init.add(0);
        dfs(Integer.valueOf(0), 0, 0, init);
            
        return answer;
    }
}