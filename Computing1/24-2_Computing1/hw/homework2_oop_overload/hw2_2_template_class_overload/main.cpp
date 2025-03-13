#include "custommap.hpp"

int main(void) {
    CustomMap<int, string> map;
    // map.insert(10, "A");  // 루트 노드
    // map.insert(20, "B");  // ❌ 정상적으로 삽입되지 않을 가능성이 있음
    // map.insert(5, "C");   // ❌ 정상적으로 삽입되지 않을 가능성이 있음
    map.insert(5, "Five");
    map.insert(3, "Three");
    map.insert(4, "Four");
    map.insert(8, "Eight");
    map.insert(10, "Ten");
    map.insert(7, "Seven");
    map.deleteKey(3);
    // map.print_map();
    // cout << endl;
    // map.deleteKey(5);
    // map.deleteKey(4);
    // map.deleteKey(8);
    map.print_map();
    cout<<endl;
    cout << map.get_value(151);
    cout << map.get_value(7)<<endl;
    cout << map[6] << endl; // 없는거 조회(빈 노드 삽입 ㅠ)
    cout << map[10] << endl; // 있는거 조회
    map[11] = "ELEVENNNNN"; // 삽입
    map[9] = "NINEEEEEEEEE"; // 삽입
    map[4] ="FOOOOOOOOOR"; // 수정
    map.print_map();
}