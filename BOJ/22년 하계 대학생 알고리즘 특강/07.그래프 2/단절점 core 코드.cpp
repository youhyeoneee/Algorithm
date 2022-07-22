int dfs(int curr, int parent) {
  VisitOrder[curr] = ++order; // 방문 order 저장

  // 내 부모에게 넘겨줄 low (현재 나의 return 값) 저장하는 변수.
  // 나와 연결된 점을 방문했을 때 방문한 연결 점이 방문(시도)했던 점들 중
  // order가 가장 빠른 것.
  int minOrder = VisitOrder[curr];

  // child 의 개수를 저장
  int child = 0;

  // 다음 방문 예정인 점을 탐색
  for (int next : AL[curr]) {
    if (next == parent) continue; // 부모노드인 경우 방문 시도를 하지 않는다.

    // 부모 노드가 아닌 경우 next에 방문 시도를 해 본다.
    if (VisitOrder[next] > 0) { // next 가 이미 방문을 한 노드인 경우
      // 이 부분 집중!!!!!!!
      // DST 의 관점에서 보면 이러한 노드들은 curr의 조상인 경우 외엔 존재할 수 없다.
      // 다시 말해, next 노드는 현재 dfs 작업이 끝난 상태가 아니므로, next 노드
      // 에서의 유효한 order 값은 VisitOrder[next] 가 유일하다.
      minOrder = VisitOrder[next] < minOrder ? VisitOrder[next] : minOrder;
    }
    else { // next 가 미 방문 상태인 경우
      ++child;
      int low = dfs(next, curr);

      if (parent != 0 && VisitOrder[curr] <= low) CutVertex[curr] = 1;

      minOrder = low < minOrder ? low : minOrder;
    }
  }

  // 루트노드일경우 자식이 2개 이상이면 단절점.
  if (parent == 0 && child >= 2) CutVertex[curr] = 1;
  return minOrder;
}

// 여기서 minOrder 가 무엇이고, low 가 무엇인지를 확실히 구분할 줄 알아야 합니다.
// dfs 호출 바깥에서 로직을 완성하는 방법은 직접 생각하여 프로그래밍해 보시기 바랍니다.
// 물론 위에 공유 드린 dfs 코드도 직접 손으로 따라 쳐 보시면서 익히시는 것을 권장합니다.