// Time:  seat:  O(logn),
//        leave: O(logn)
// Space: O(n)

// bst solution, inspired by zqzwxec
class ExamRoom {
public:
    ExamRoom(int N)
      : num_(N)
      , max_bst_(Compare(N))
    {
        seats_.emplace(-1);
        seats_.emplace(num_);
        max_bst_.emplace(-1, num_);
    }
    
    int seat() {
        const auto top = *max_bst_.cbegin();
        max_bst_.erase(top);
        const auto& mid = top.first == -1 ? 0
                          : top.second == num_ ? num_ - 1
                          : (top.first + top.second) / 2;
        seats_.emplace(mid);
        max_bst_.emplace(top.first, mid);
        max_bst_.emplace(mid, top.second);
        return mid;
    }
    
    void leave(int p) {
        const auto& it = seats_.find(p);
        const auto& left = *prev(it), &right = *next(it);
        max_bst_.erase({left, p});
        max_bst_.erase({p, right});
        seats_.erase(p);
        max_bst_.emplace(left, right);
    }

private:
    class Compare {
    public:
        Compare(int N) : num_(N) {}

        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            const auto& dist_a = distance(a), &dist_b = distance(b);
            return dist_a == dist_b ? less<int>()(a.first, b.first)
                   : greater<int>()(dist_a, dist_b);
        }
    
    private:
        int distance(const pair<int, int>& segment) const {
            return segment.first == -1 || segment.second == num_
                   ? segment.second - segment.first - 1
                   : (segment.second - segment.first) / 2;
        }

        int num_;
    };
    
    int num_;
    set<pair<int, int>, Compare> max_bst_;
    set<int> seats_;
};

// Time:  seat:  O(logn),
//        leave: O(logn)
// Space: O(n)
// bst solution, inspired by zqzwxec
class ExamRoom2 {
public:
    ExamRoom2(int N)
      : num_(N)
      , max_bst_(Compare(N))
    {
        seats_[-1] = {-1, num_};
        seats_[num_] = {-1, num_};
        max_bst_.emplace(-1, num_);
    }
    
    int seat() {
        const auto top = *max_bst_.cbegin();
        max_bst_.erase(top);
        const auto& mid = top.first == -1 ? 0
                          : top.second == num_ ? num_ - 1
                          : (top.first + top.second) / 2;
        seats_[mid] = top;
        seats_[top.first].second = mid;
        seats_[top.second].first = mid;
        max_bst_.emplace(top.first, mid);
        max_bst_.emplace(mid, top.second);
        return mid;
    }
    
    void leave(int p) {
        const auto left = seats_[p].first, right = seats_[p].second;
        max_bst_.erase({left, p});
        max_bst_.erase({p, right});
        seats_.erase(p);
        seats_[left].second = right;
        seats_[right].first = left;
        max_bst_.emplace(left, right);
    }

private:
    class Compare {
    public:
        Compare(int N) : num_(N) {}

        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            const auto& dist_a = distance(a), &dist_b = distance(b);
            return dist_a == dist_b ? less<int>()(a.first, b.first)
                   : greater<int>()(dist_a, dist_b);
        }
    
    private:
        int distance(const pair<int, int>& segment) const {
            return segment.first == -1 || segment.second == num_
                   ? segment.second - segment.first - 1
                   : (segment.second - segment.first) / 2;
        }

        int num_;
    };
    
    int num_;
    set<pair<int, int>, Compare> max_bst_;
    unordered_map<int, pair<int, int>> seats_;
};

// Time:  seat:  O(logn) on average,
//        leave: O(logn)
// Space: O(n)
// heap solution
class ExamRoom3 {
public:
    ExamRoom3(int N)
      : num_(N)
      , max_heap_(Compare(N))
     {
        seats_[-1] = {-1, num_};
        seats_[num_] = {-1, num_};
        max_heap_.emplace(-1, num_);
    }
    
    int seat() {
        while (!seats_.count(max_heap_.top().first) ||
               !seats_.count(max_heap_.top().second) ||
               seats_[max_heap_.top().first].second != max_heap_.top().second ||
               seats_[max_heap_.top().second].first != max_heap_.top().first) {
            max_heap_.pop();  // lazy deletion
        }
        
        const auto top = max_heap_.top(); max_heap_.pop();
        const auto& mid = top.first == -1 ? 0
                          : top.second == num_ ? num_ - 1
                          : (top.first + top.second) / 2;
        seats_[mid] = top;
        seats_[top.first].second = mid;
        seats_[top.second].first = mid;
        max_heap_.emplace(top.first, mid);
        max_heap_.emplace(mid, top.second);
        return mid;
    }
    
    void leave(int p) {
        const auto left = seats_[p].first, right = seats_[p].second;
        seats_.erase(p);
        seats_[left].second = right;
        seats_[right].first = left;
        max_heap_.emplace(left, right);
    }
    
private:
    class Compare {
    public:
        Compare(int N) : num_(N) {}

        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            const auto& dist_a = distance(a), &dist_b = distance(b);
            return dist_a == dist_b ? greater<int>()(a.first, b.first)
                   : less<int>()(dist_a, dist_b);
        }
    
    private:
        int distance(const pair<int, int>& segment) const {
            return segment.first == -1 || segment.second == num_
                   ? segment.second - segment.first - 1
                   : (segment.second - segment.first) / 2;
        }

        int num_;
    };
    
    int num_;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> max_heap_;
    unordered_map<int, pair<int, int>> seats_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */


// solve by C
// #include <stdlib.h>

// typedef struct {
//     int* seats;     // 앉아있는 학생들의 위치를 저장하는 배열
//     int count;      // 현재 앉아있는 학생 수
//     int capacity;   // 전체 좌석 수
// } ExamRoom;

// ExamRoom* examRoomCreate(int n) {
//     ExamRoom* room = (ExamRoom*)malloc(sizeof(ExamRoom));
//     room->seats = (int*)malloc(sizeof(int) * n);  // 최대 n개의 좌석
//     room->count = 0;
//     room->capacity = n;
//     return room;
// }

// int examRoomSeat(ExamRoom* obj) {
//     if (obj->count == 0) {
//         // 아무도 앉아있지 않은 경우, 0번 자리에 배치
//         obj->seats[0] = 0;
//         obj->count++;
//         return 0;
//     }

//     int maxDist = obj->seats[0];  // 첫 좌석까지의 거리
//     int position = 0;             // 선택될 위치

//     // 인접한 좌석들 사이의 거리를 확인
//     for (int i = 0; i < obj->count - 1; i++) {
//         int dist = (obj->seats[i + 1] - obj->seats[i]) / 2;
//         if (dist > maxDist) {
//             maxDist = dist;
//             position = obj->seats[i] + dist;
//         }
//     }

//     // 마지막 좌석부터 끝까지의 거리 확인
//     if (obj->capacity - 1 - obj->seats[obj->count - 1] > maxDist) {
//         position = obj->capacity - 1;
//     }

//     // 새로운 위치를 정렬된 상태로 삽입
//     int i;
//     for (i = obj->count; i > 0 && obj->seats[i - 1] > position; i--) {
//         obj->seats[i] = obj->seats[i - 1];
//     }
//     obj->seats[i] = position;
//     obj->count++;

//     return position;
// }

// void examRoomLeave(ExamRoom* obj, int p) {
//     // p 위치의 학생을 찾아서 제거
//     int i;
//     for (i = 0; i < obj->count; i++) {
//         if (obj->seats[i] == p) {
//             break;
//         }
//     }
    
//     // 찾은 위치부터 나머지 요소들을 한 칸씩 앞으로 이동
//     for (; i < obj->count - 1; i++) {
//         obj->seats[i] = obj->seats[i + 1];
//     }
//     obj->count--;
// }

// void examRoomFree(ExamRoom* obj) {
//     free(obj->seats);  // 좌석 배열 메모리 해제
//     free(obj);         // ExamRoom 구조체 메모리 해제
// }