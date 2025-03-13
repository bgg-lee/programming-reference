/*
연습 문제 2: Player 클래스 (복사/이동 생성자 및 할당 연산자)
게임 캐릭터(Player)를 표현하는 클래스를 만들고 다음 연산자를 오버로딩하세요.

복사 생성자 (Player(const Player& other))
복사 할당 연산자 (operator=)
이동 생성자 (Player(Player&& other))
이동 할당 연산자 (operator=)
operator<< 오버로딩 (출력 연산자)
정적 멤버 (static int playerCount)를 사용하여 생성된 객체 수 추적
*/

#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string name;
    int level;
    int* score;  // 동적 할당된 데이터 (메모리 관리 필요)

public:
    static int playerCount;  // 정적 멤버 변수

    // ✅ 기본 생성자
    Player(string n = "Unknown", int lvl = 1, int scr = 0)
        : name(n), level(lvl), score(new int(scr)) {
        playerCount++;
    }

    // ✅ 복사 생성자 (Deep Copy)
    Player(const Player& other)
        : name(other.name), level(other.level), score(new int(*other.score)) {
        playerCount++;
    }

    // ✅ 복사 할당 연산자 (Deep Copy)
    Player& operator=(const Player& other) {
        if (this == &other) return *this;  // 자기 할당 방지

        delete score;  // 기존 데이터 삭제
        name = other.name;
        level = other.level;
        score = new int(*other.score);  // 새 메모리 할당 후 복사

        return *this;
    }

    // ✅ 이동 생성자
    Player(Player&& other) noexcept
        : name(move(other.name)), level(other.level), score(other.score) {
        other.score = nullptr;  // 원본 객체의 포인터 초기화
        playerCount++;
    }

    // ✅ 이동 할당 연산자
    Player& operator=(Player&& other) noexcept {
        if (this == &other) return *this;

        delete score;
        name = move(other.name);
        level = other.level;
        score = other.score;
        other.score = nullptr;

        return *this;
    }

    // ✅ 출력 연산자 (`operator<<`)
    friend ostream& operator<<(ostream& os, const Player& player) {
        os << "Player: " << player.name << ", Level: " << player.level
           << ", Score: " << *player.score;
        return os;
    }

    // ✅ 소멸자
    ~Player() {
        delete score;
        playerCount--;
    }
};

// ✅ 정적 변수 초기화
int Player::playerCount = 0;

// ✅ 테스트 코드
int main() {
    Player p1("Alice", 10, 100);
    Player p2("Bob", 5, 50);
    
    cout << "Before Copy:\n" << p1 << endl;
    
    Player p3 = p1;  // 복사 생성자 호출
    cout << "'Construction' After Copy:\n" << p3 << endl;

    Player p4 = move(p2);  // 이동 생성자 호출
    cout << "After Move:\n" << p4 << endl;

    p4 = p1;  // 복사할당 연산자 내가 확인인
    cout << "After COPY:\n" << p4 << endl;

    cout << "Total Players: " << Player::playerCount << endl;

    return 0;
}
