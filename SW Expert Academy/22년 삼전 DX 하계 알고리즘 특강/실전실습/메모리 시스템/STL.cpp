using namespace std;

int total; // 메모리의 끝
set<pair<int, int>> empty_blocks;
map<int, int> alloc;

void init(int N) {
    total = N;
    alloc.clear();
    // 빈 공간을 담고 있는 set 초기화
    empty_blocks.clear();
    // 처음 빈 공간은 메모리 전체
    empty_blocks.emplace(N, 0);
	return;
}

int allocate(int mSize) {

    // set에서 주어진 크기보다 큰 빈 공간 중 가장 작은 빈 공간 탐색 (lower_bound 사용)
    auto it = empty_blocks.lower_bound({mSize, 0});

    // 못 찾으면 -1 반환
    if(it == empty_blocks.end()) return -1;
    
    int size = it->first, addr = it->second;
        
    // 찾은 빈 공간은 set에서 삭제
    empty_blocks.erase(it);
    
    alloc[addr] = size;

    // 찾은 공간의 크기가 주어진 크기보다 크다면 남은 공간을 set에 다시 넣기
    if (size > mSize) empty_blocks.emplace(size - mSize, addr + mSize);

	return addr;
}

int release(int mAddr) {
    // 있는지 없는지 알기 위해 find 사용
    auto it = alloc.find(mAddr);
    if (it == alloc.end()) return -1;

    int size = it->second;
    int res = size;

    it = alloc.erase(it);

    // 내가 지운 공간 뒤에 빈 공간이 있는지 
    int after_size = 0;
    if (it != alloc.end()){
        after_size = it->first - (mAddr + size);
    }
    else if (mAddr + size < total){
        after_size = total - (mAddr + size);
    }

    // 빈공간 합쳐주기
    if (after_size > 0){
        empty_blocks.erase({after_size, mAddr + size});
        size += after_size;
    }

    // 내가 지운 공간 앞에 빈 공간이 있는지 
    int before_size = 0;
    if(it != alloc.begin()){
        --it;
        before_size = mAddr - (it->first + it->second);
    }
    else if (mAddr > 0){
        before_size = mAddr;
    }

    // 빈공간 합쳐주기
    if(before_size > 0){
        empty_blocks.erase({before_size, mAddr - before_size});
        size += before_size;
        mAddr -= before_size;
    }

    empty_blocks.emplace(size, mAddr);

	return res;
}