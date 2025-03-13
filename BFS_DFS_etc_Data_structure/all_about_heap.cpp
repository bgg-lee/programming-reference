// C++에서 priority_queue는 기본적으로 Max-heap 구조
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
#include <tuple>


// 사용자 정의 비교 함수 객체
struct MyCompare {
    // operator()(a, b)가 true면 "a가 b보다 우선순위가 낮다" (즉, b가 top에 온다).
    // priority_queue에서는 "가장 false(=작은)인 쪽"이 top에 오도록 설계되어 있음.
    // 보통 'less' 스타일이면 "return a < b" 
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        // 예: first를 내림차순, first 같으면 second 오름차순
        if(a.first != b.first){
            return a.first < b.first; 
            // a.first가 더 작으면 true → a의 우선순위가 낮다는 의미 → b가 top에
            // 즉, first가 큰 게 top --> max heap
        } else {
            return a.second > b.second;
            // first 같으면 second가 작은 게 top --> min heap
        }
    }
};
struct MyCompare2{ // pair의 두 번째 항목으로만 min-heap,
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        // return a.second > b.second; // 그냥 두 번째 기준으로만 비교하고 싶으면 달랑 이거만 쓰면 됨
        // 두 번째 기준 min heap, 동점시 첫 번째 기준 min heap
        if(a.second != b.second){
            return a.second > b.second; // min heap
        }else{
            return a.first > b.first; // min heap
        }
    }
};

struct MyCompare3 {
    bool operator()(const tuple<int,int,int>& t1,
                    const tuple<int,int,int>& t2) const
    {
        // 예) a값 내림차순, a 같으면 b 오름차순, 그래도 같으면 c 내림차순..
        // 실제 로직은 원하는 대로 작성
        auto [a1,b1,c1] = t1;
        auto [a2,b2,c2] = t2;
        
        if(a1 != a2) {
            return a1 < a2; // max heap
            // a1 < a2 이면 t1의 우선순위가 더 낮다 => t2가 top.
            // 즉 a가 큰 게 top
        } else if(b1 != b2) {
            return b1 > b2; // min heap
            // b1 > b2 이면 t1 우선순위 낮음 => b가 작은 게 top
        } else {
            // 나머지는 c 내림차순
            return c1 < c2; // max heap
        }
    }
};


int main(){
// 기본 int 기준 Min/Max heap
    // // 1. Default : Max heap
    // priority_queue<int> maxPQ;

    // // 2. Min Heap
    // priority_queue<int,vector<int>,greater<int>> minPQ;

    // // 간단 예시
    // maxPQ.push(1);
    // maxPQ.push(3);
    // maxPQ.push(2);

    // minPQ.push(1);
    // minPQ.push(3);
    // minPQ.push(2);

    // cout<< maxPQ.top() << " " << minPQ.top() << endl; // 3 , 1

// Pair<int,int> 기준 Min/Max heap
    // priority_queue<pair<int,int>> maxPQ; 

    // maxPQ.push({1,2});
    // maxPQ.push({2,3});
    // maxPQ.push({2,2});
    // auto topVal = maxPQ.top(); 
    // cout << "(" << topVal.first << "," << topVal.second << ")\n"; // (2,3)

    // priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minPQ; 

    // minPQ.push({1,7});
    // minPQ.push({1,3});
    // minPQ.push({2,2});
    // minPQ.push({1,2});
    // minPQ.push({3,2});


    // // top: (1,2)  (사전순으로 가장 작은 pair)
    // auto topVal2 = minPQ.top(); 
    // cout << "(" << topVal2.first << "," << topVal2.second << ")\n"; // (1,2)
    // return 0;

// PQ customizing -> MyCompare 이용 -> 이 경우 pair의 first Max heap -> 동점 시 pair의 second Min heap
    // priority_queue< pair<int,int>, vector<pair<int,int>>, MyCompare > pq;
    // pq.push({2,3});
    // pq.push({2,2});
    // pq.push({1,5});
    // pq.push({2,5});
    // pq.push({1,0});
    // while(!pq.empty()){
    //     auto x = pq.top();
    //     pq.pop();
    //     cout << x.first << " , " << x.second << endl;
    // }

// PQ의 2번 째 항목으로만 Minheap 되게 내가 customize 함 해봄
    // priority_queue< pair<int,int>, vector<pair<int,int>>, MyCompare2 > pq;
    // pq.push({2,3});
    // pq.push({2,2});
    // pq.push({1,5});
    // pq.push({7,0});
    // pq.push({1,5});
    // pq.push({2,5});
    // pq.push({1,0});
    // pq.push({3,0});
    // pq.push({3,5});
    // while(!pq.empty()){
    //     auto x = pq.top();
    //     pq.pop();
    //     cout << x.first << " , " << x.second << endl;
    // }

// tuple 튜플을 이용한 pq 사용해보기
    // // 튜플에 대한 기본 설명, 다양한 variable type을 한 번에 저장할 수 있는 Container이다.
    // tuple<int, double, string> t(10, 3.14, "hello");
    //     // get<인덱스>(튜플) 로 접근. 인덱스는 0부터 시작
    // cout << get<0>(t) << endl; // 10
    // cout << get<1>(t) << endl; // 3.14
    // cout << get<2>(t) << endl; // "hello"
    //     // 생성 시 make_tuple 사용 가능
    // auto t2 = make_tuple(1, 2.5, "world");
    // cout << get<0>(t2) << ", " << get<1>(t2) << ", " << get<2>(t2) << endl;

    // MAX-HEAP
    // priority_queue< tuple<int,int,int> > maxPQ;
    // // push
    // maxPQ.push({1,2,3});
    // maxPQ.push({2,1,0});
    // maxPQ.push({2,1,5});
    // /*
    //   사전순으로 (1,2,3) vs (2,1,0) vs (2,1,5)
    //   (2,1,5)가 가장 크다 => top
    // */
    // auto topVal = maxPQ.top();
    // cout << "(" << get<0>(topVal) 
    //      << "," << get<1>(topVal) 
    //      << "," << get<2>(topVal) << ")\n";
    // // 출력: (2,1,5)


    // MIN-HEAP
    // 최소 힙: greater<tuple<int,int,int>>
    // priority_queue< 
    //     tuple<int,int,int>, 
    //     vector< tuple<int,int,int> >,
    //     greater< tuple<int,int,int> >
    // > minPQ;

    // minPQ.push({1,2,4});
    // minPQ.push({1,2,3});
    // minPQ.push({2,1,0});
    // minPQ.push({2,1,5});

    // // 사전순 가장 작은 tuple이 top => (1,2,3)
    // auto topVal = minPQ.top();
    // cout << "(" << get<0>(topVal)
    //      << "," << get<1>(topVal)
    //      << "," << get<2>(topVal) << ")\n";
    // // (1,2,3)

    // Custom Heap 기준

    priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, MyCompare3 > pq;
    pq.push({1,1,2});
    pq.push({1,1,3});
    pq.push({1,1,1});
    pq.push({1,2,2});
    pq.push({1,3,2});
    pq.push({1,1,2});
    pq.push({2,1,2});
    pq.push({3,1,2});
    pq.push({1,1,2});
    while(!pq.empty()){
        // auto val = pq.top();
        auto [a1,b1,c1] = pq.top();
        pq.pop();
        // cout << get<0>(val) << "," << get<1>(val) << "," << get<2>(val) <<endl;
        cout << a1 << "," << b1 << "," << c1 <<endl;        
    }
    return 0;

}
