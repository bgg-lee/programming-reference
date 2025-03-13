#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 조요한 교수님이 입시에 냈었던 문제 .. 미팅시간 잡기 문제
// 요런게 Main 문제로 여겨진다.

using namespace std;

// Function to find the minimum number of meeting rooms required
int minMeetingRooms(vector<pair<int, int> >& intervals) {
    //////////////
    // FILL HERE
    sort(intervals.begin(),intervals.end());
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(intervals[0].second);

    for(int i=1;i<intervals.size();i++){
        if(intervals[i].first>=minheap.top()) minheap.pop();
        minheap.push(intervals[i].second);
    }
    return minheap.size();
    // int ans = 1;
    // int n = intervals.size();
    // sort(intervals.rbegin(),intervals.rend());

    // for(int i=0;i<n;i++){
    //     auto temp = intervals[i];
    //     int cnt = 1;
    //     for(int j=i+1;j<n;j++){
    //         if(intervals[j].second<=temp.first || intervals[j].first>=temp.second) continue;
    //         else cnt++;
    //     }
    //     ans = max(ans,cnt);
    // }

    // return ans;
}

int main() {
    // Example input: pair of <start_time, end_time>
    vector<pair<int, int> > intervals;
    intervals.push_back(make_pair(0, 30));
    intervals.push_back(make_pair(5, 20));
    intervals.push_back(make_pair(15, 35));

    vector<pair<int, int> > intervals2;
    intervals2.push_back(make_pair(7, 10));
    intervals2.push_back(make_pair(2, 4));

    vector<pair<int, int> > intervals3;
    intervals3.push_back(make_pair(0, 30));
    intervals3.push_back(make_pair(5, 10));
    intervals3.push_back(make_pair(15, 20));

    // Find the minimum number of meeting rooms required
    int result = minMeetingRooms(intervals);
    int result2 = minMeetingRooms(intervals2);
    int result3 = minMeetingRooms(intervals3);

    cout << "Minimum number of meeting rooms required: " << result << endl; // expected : 3
    cout << "Minimum number of meeting rooms required: " << result2 << endl; // expected : 1
    cout << "Minimum number of meeting rooms required: " << result3 << endl; // expected : 2

    return 0;
}


/* Pair의 두번째 element 기준으로 min heap 만들기
#include <queue>
#include <vector>
#include <iostream>
#include <utility>


int main() {
    // Example vector of pairs
    vector<pair<int, int>> intervals = {{0, 30}, {5, 20}, {15, 35}};

    // Min-heap based on second value of pair
    auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // Min-heap based on second value
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);

    // Insert pairs into min-heap
    for (const auto& interval : intervals) {
        minHeap.push(interval);
    }

    // Display the pairs in the heap order
    while (!minHeap.empty()) {
        cout << "(" << minHeap.top().first << ", " << minHeap.top().second << ")" << endl;
        minHeap.pop();
    }

    return 0;
}
*/