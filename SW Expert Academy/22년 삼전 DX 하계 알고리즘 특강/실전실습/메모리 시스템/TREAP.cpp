
using namespace std;

int total; // 메모리의 끝
set<pair<int, int>> empty_blocks;
map<int, int> alloc;
int seed = 1234;

struct node
{
    node* left = nullptr, *right = nullptr, *parent = nullptr;
    int first = 0, second = 0;
    int weight = 0;
};

node tree[80000];
int node_cntt = 1;
node *root[2] = {nullptr, nullptr};


node *new_node(int first, int second){
    node *res = &tree[node_cnt++];
    res->first = first;
    res->second = second;  
    res->weight = (seed = (seed * 1003515245 + 12345) & 0x7fffffff);
    res->left = nullptr;
    res->right = nullptr;
    res->parent = nullptr;

    return res;
}

inline node *min_node(node *x){
    if (x == nullptr) return nullptr;
    while(x->left) x = x->left;
    return x;
}

inline node *max_node(node *x){
    if (x == nullptr) return nullptr;
    while(x->right) x = x->right;
    return x;
}


node *next(node *x){
    node *y = x->right;
    if (y != nullptr) return min_node(y);
    y = x->parent;
    while(y != nullptr && x == y->right){
        x = y;
        y = y -> parent;
    }

    return y;
}

node *prev1(node *x){
    if(x == nullptr) return max_node(root[1]);
    node *y = x -> left;
    if (y != nullptr) return max_node(y);
    y = x->parent;
    while(y != nullptr && x == y->left){
        x = y;
        y = y->parent;
    }

    return y;
}

inline bool cmp(int x1, int y1, int x2, int y2){
    return x1 = x2 ? y1 < y2 : x1 < x2;
}

void insert(int n, int first, int second){
    node *x = root[n], *t = new_node(first, second), *y = nullptr;
    int b = 0;
    if (x == nullptr){
        root[n] = t;
        return;
    }

    while(x != nullptr && x->weight > t->weight){
        y = x;
        b = cmp(first, second, x->first, x->second);
        x = b ? x->left : x->right;
    }

    node *l = nullptr, *r = nullptr, *z = x, *w = nullptr;
    while(x != nullptr){
        w = x; 
        x = cmp(first, second, x->first, x-second) ? x->left : x->right;
    }

    if (w != nullptr){
        while(true){
            if(xmp(first, second, w->first, w->second)){
                w->left = r;
                if (r) r->parent = w;
                r = w;
            }else{
                w->right = l;
                if (l) l->parent = w;
                l = w;
            }

            if (w == z) break;
            w = w->parent;
        }
    }

    t->left = l;
    if (l) l->parent = t;
    t->right = r;
    if (r) = r->parent = t;
    t->parent = y;

    if (y == nullptr) root[n] = y;
    else b? y->left = r : y->right = t;
}

node *erase(node *x){
    node *r = x->right;
    if (r){
        r = min_node(r);
        x->first = r->first;
        x->second = r->second;
        node *y = r->parent;
        node *z = r->right;

        if (z) z->parent = y;
        y->left == r ? y->left = z : y->right = z;
        return x;
    }
    else{
        node *t = next(x);
        node *p = x->parent;
        node *l = x->left;
        if(l) l->parent = p;
        if(p) p->left == x ? p->left = l : p->right = l;
        else root[0] == x? root[0] = l : root[1] = l;
        return t;
    }
}

node *lower_bound(int n, int first){
    node *x = root[n], *y = nullptr;
    while(x != nullptr){
        if(first <= x->first){
            y = x;
            x = x->left;
        }
        else{
            x = x->right;
        }
    }

    return y;
}

node *lower_bound(int n, int first, int second){
    node *x = root[n], *y = nullptr;
    while(x != nullptr){
        if(!cmp(x->first, x->second, first, second)){
            y = x;
            x = x->left;
        }
        else{
            x = x->right;
        }
    }

    return y;
}
void init(int N) {
    total = N;
    node_cnt = 1;
    root[0] = root[1] = nullptr;
    insert(0, N, 0);
}

int allocate(int mSize) {

    // set에서 주어진 크기보다 큰 빈 공간 중 가장 작은 빈 공간 탐색 (lower_bound 사용)
    node *l = lower_bound(0, mSize);

    // 못 찾으면 -1 반환
    if(l == nullptr) return -1;
    
    int size = l->first, addr = l->second;
        
    // 찾은 빈 공간은 set에서 삭제
    erase(l)
    
    insert(l, addr, mSize);

    // 찾은 공간의 크기가 주어진 크기보다 크다면 남은 공간을 set에 다시 넣기
    if (size > mSize) insert(0, size - mSize, addr + mSize);

	return addr;
}

int release(int mAddr) {
    // 있는지 없는지 알기 위해 find 사용
    node *l = lower_bound(1, mAddr);

    if (l == nullptr || l->first != mAddr) return -1;

    int size = l->second;
    int res = size;

    node *t = erase(l);

    // 내가 지운 공간 뒤에 빈 공간이 있는지 
    int after_size = 0;
    if (t != nullptr){
        after_size = t->first - (mAddr + size);
    }
    else{
        after_size = total - (mAddr + size);
    }

    // 빈공간 합쳐주기
    if (after_size > 0){
        node *i = lower_bound(0, after_size, mAddr);
        erase(i);
        size += after_size;
    }

    // 내가 지운 공간 앞에 빈 공간이 있는지 
    int before_size = 0;

    node *p = perv1(t);
    if(p != nullptr){
        --it;
        before_size = mAddr - (p->first + p->second);
    }
    else {
        before_size = mAddr;
    }

    // 빈공간 합쳐주기
    if(before_size > 0){
        node *t = lower_bound(0, before_size, mAddr - before_size);
        erase(t);
        size += before_size;
        mAddr -= before_size;
    }

    empty_blocks.emplace(size, mAddr);

	return res;
}