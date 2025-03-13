#include "prob2.hpp"
#include <vector>
using namespace std;
int main() {
    // -------------------------------------------
    // Test Case 1:
    // n=2, 비교가 없음. => 어떤 학생도 자신의 정확한 순위를 모름
    // 기대 결과: 0
    // -------------------------------------------
    {
        int n = 2;
        vector<pair<int,int>> comps = {}; // 아무 비교도 없음
        int result = findKnownOrderStudents(n, comps);
    }

    // -------------------------------------------
    // Test Case 2:
    // n=2, 비교 { (1,2) } => 1 < 2
    //   학생 1은 "자신보다 큰 학생이 2뿐"이라 전체 비교가 끝나고,
    //   학생 2는 "자신보다 작은 학생이 1뿐"이라 전체 비교가 끝남
    // 두 학생 모두 자신이 1등/2등임을 정확히 알게 됨
    // 기대 결과: 2
    // -------------------------------------------
    {
        int n = 2;
        vector<pair<int,int>> comps = {{1,2}};
        int result = findKnownOrderStudents(n, comps);
    }

    // -------------------------------------------
    // Test Case 3:
    // n=4, 비교 { (1,2), (2,3), (2,4), (3,4) }
    //   1 < 2, 2 < 3, 2 < 4, 3 < 4
    // 그래프 상에서:
    //   - 1보다 큰 사람: {2,3,4}
    //   - 2보다 큰 사람: {3,4}
    //   - 3보다 큰 사람: {4}
    //   - 4보다 큰 사람: 없음
    //
    // 실제 순서: 1 < 2 < 3 < 4
    // 학생별로 "도달 가능한 taller + 도달 가능한 smaller" 합이 (n-1)이 되는지 검사:
    //   - 1: tallerCount=3, smallerCount=0 => 합=3 => (n-1)=3 => O
    //   - 2: tallerCount=2, smallerCount=1 => 합=3 => (n-1)=3 => O
    //   - 3: tallerCount=1, smallerCount=2 => 합=3 => (n-1)=3 => O
    //   - 4: tallerCount=0, smallerCount=3 => 합=3 => (n-1)=3 => O
    // 모든 학생이 자신보다 큰/작은 학생 정보를 완전히 알 수 있음.
    // 기대 결과: 4
    // -------------------------------------------
    {
        int n2 = 4;
        vector<pair<int,int>> comps = {{1,2}, {2,3}, {2,4}, {3,4}};
        int result = findKnownOrderStudents(n2, comps);
    }

    // -------------------------------------------
    // Test Case 4 (예시):
    // n=6, comparisons = { (1,5), (3,4), (5,4), (4,2), (4,6), (5,2) }
    // => 문제 설명(PDF)에서 예로 들었던 케이스와 유사
    // 기대 결과: 1 (PDF 예시에 따르면 4번 학생만 전체 순위를 정확히 알 수 있다)
    // -------------------------------------------
    {
        int n3 = 6;
        vector<pair<int,int>> comps = {
            {1,5}, {3,4}, {5,4}, {4,2}, {4,6}, {5,2}
        };
        int result = findKnownOrderStudents(n3, comps);
    }
    
    return 0;
}
