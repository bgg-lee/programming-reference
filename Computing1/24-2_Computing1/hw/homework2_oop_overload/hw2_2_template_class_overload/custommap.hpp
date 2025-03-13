#include <iostream>
#include <string>
#include <functional>

using namespace std;

// Fill in the empty templates and implement the definition of the class and each member functions
// TODO
template <typename K, typename V>
class TreeNode {
private:
    K key;
    V value;
    TreeNode<K,V>* left; // template 이용한 경우 이렇게 해줘야 한다. type을 명시해줘야 한다는 뜻
    TreeNode<K,V>* right;
    // TreeNode* left;
    // TreeNode* right;
public:
    // Constructor
    TreeNode(K key, V value):key(key),value(value){
        left = nullptr;
        right = nullptr;
    };
    K get_K(){return key;}
    V& get_V(){return value;} // **************operator를 위한 키다 요놈이이
    void set_K(K temp){key = temp;}
    void set_V(V temp){value = temp;}
    // TreeNode에 대한 getter/setter는 필요 없겠지?
    // 필요하다..
    TreeNode* get_L(){ return left;}
    TreeNode* get_R(){ return right;}
    void set_L(TreeNode* l){left = l;}
    void set_R(TreeNode* r){right = r;}
};


// Fill in the empty templates and implement the definition of the class and each member functions
// TODO
template < typename K, typename V, typename Compare = std::less<K> >
class CustomMap {
public:
    TreeNode<K,V>* root; // template 이용한 경우 이렇게 해준다.
    Compare comp;
    
    CustomMap():root(nullptr){};
    TreeNode<K,V>* get_root(){
        return root;
    }
    Compare get_compare(){ // 이건 어따가 쓰는 건지?
        return comp;
    }
    // Q 2.2
    void insert(K key, V value){
        TreeNode<K,V>* new_node = new TreeNode<K,V>(key,value);
        // root 없는 경우
        if(!root){
            root = new_node;
            return;
        }
        // root 있는 경우
        TreeNode<K,V>* curr = root;
        TreeNode<K,V>* parent = nullptr;
        while(1){
            parent = curr;
            if(comp(curr->get_K(),new_node->get_K())){ // Comp 쓰는 법법, curr이 작으면 True
                curr = curr->get_R();
                if(!curr){
                    parent->set_R(new_node);
                    break;
                }
            }else{
                curr = curr->get_L();
                if(!curr){
                    parent->set_L(new_node);
                    break;
                }
            }
            /* //LLM 권고 코드 위와 같은 내용
            if (comp(curr->get_K(), new_node->get_K())) {
                if (!curr->get_R()) {  
                    parent->set_R(new_node); // ✅ new_node를 부모의 자식 포인터로 설정해야 함!
                    break;
                }
                curr = curr->get_R();
            } else {
                if (!curr->get_L()) {
                    parent->set_L(new_node); // ✅ new_node를 부모의 자식 포인터로 설정해야 함!
                    break;
                }
                curr = curr->get_L();
            }
            */
        }
    }
    // Q 2.3
    void deleteKey(K key){ // key가 없으면 do nothing, key가 있으면 삭제 후 BST 성질 복구
        // 짜치는 BST 삭제 Case..
        // 일단 Target 찾기
        TreeNode<K,V>* curr = root;
        TreeNode<K,V>* parent = nullptr;
        while(curr){
            if(comp(curr->get_K(),key)){
                parent = curr;
                curr = curr -> get_R();
            }
            else if(comp(key,curr->get_K())){
                parent = curr;
                curr = curr -> get_L();
            }
            else{ // Target 찾은 경우
                // 1) 자식 둘 다 있는 경우 hardest
                if( curr->get_L() && curr->get_R()){
                    // 현재 기준 우측 sub에서 제일 왼쪽에 있는 node를 이식한 후 그 node를 제거한다.
                    TreeNode<K,V>* temp = curr->get_R();
                    while(temp->get_L()){
                        temp = temp->get_L();
                    }
                    // 이식 작업을 위한 데이터 따놓기, 여기서 이식을 해버리면 temp지울때 curr이 지워질까봐
                    K temp_key = temp->get_K();
                    V temp_value = temp->get_V();
                    // 이식 후 Node 삭제제
                    deleteKey(temp_key);
                    curr->set_K(temp_key);
                    curr->set_V(temp_value);
                }
                // 2) 자식이 하나 있는 경우
                else if(curr->get_L()){
                    // root 일 경우 추가
                    if(curr==root){
                        root = curr->get_L();
                        curr->set_L(nullptr);
                        delete curr;
                        return;
                    }

                    if(parent->get_R()==curr) parent->set_R(curr->get_L());
                    else parent->set_L(curr->get_L());
                    // 자신은 삭제
                    curr->set_L(nullptr);
                    delete curr;
                }
                else if(curr->get_R()){
                    // curr이 root 일 경우 추가 
                    if(curr==root){
                        root = curr->get_R();
                        curr->set_R(nullptr);
                        delete curr;
                        return;
                    }
                    if(parent->get_R()==curr) parent->set_R(curr->get_R());
                    else parent->set_L(curr->get_R());
                    // 자신은 삭제
                    curr->set_R(nullptr);
                    delete curr;
                }
                // 3) 자식이 없는 경우
                else{
                    if(curr==root){
                        root = nullptr;
                        delete curr;
                        return;
                    }
                    if(parent->get_R()==curr) parent->set_R(nullptr);
                    else parent->set_L(nullptr);
                    delete curr;
                }
            }
        }

    }

    // Q 2.4 // 이게 내가 생각하는 젤 깔끔한 정답!!!!!!!!!!!!!! 단, // get_value, get_K() 참조반환 SET
    V& get_value(K key){
        TreeNode<K,V>* curr = root;
        while(curr){
            if(comp(curr->get_K(),key)) curr = curr->get_R();
            else if(comp(key,curr->get_K())) curr = curr->get_L();
            else return curr->get_V();
        }
        static V defaultValue = V(); // ✅ 기본값 반환 (읽기 전용)
        return defaultValue; // DEFAULT 값
        // TreeNode<K,V>* temp = new TreeNode<K,V>(999,V()); //Memory 낭비
        // return temp->get_V();
    }
    V& operator[](const K key) { 
        // 1️⃣ get_value()를 사용하여 키 확인
        V& valueRef = get_value(key);
        // 2️⃣ 키가 존재하면 반환
        if (valueRef != V()) {
            return valueRef;
        }
        // 3️⃣ 키가 없으면 insert()를 호출하여 새로운 EMPTY 노드 추가
        insert(key, V());
        // 4️⃣ 새로 추가한 노드의 값 반환
        return get_value(key);
    }

    // V get_value(K key) {
    //     TreeNode<K, V>* curr = root;
    //     while (curr) {
    //         if (comp(curr->get_K(), key)) curr = curr->get_R();
    //         else if (comp(key, curr->get_K())) curr = curr->get_L();
    //         else return curr->get_V();  // ✅ 키가 존재하면 값 반환
    //     }
    
    //     return V();  // ✅ 기본값을 반환 (읽기 전용)
    // }
    // Q 2.5 //Overload [] operator -> get_value 기능 + modify(or add) 기능까지 있다. GG 어렵다.
    // 다시 하기 1. 조회: Key가 있으면 해당 값 반환, 없으면 V() 반환. 2. 변경 : Key가 있으면 해당 값 수정, 없으면 해당 값 추가 --> 수정을 하려면 반환값을 Reference로 해야하네.. 그리고 operator[]에 대해 정의를 2개하는 건 안된다고 한다.
// ✅ 쓰기 (수정, 삽입) 연산
// V& operator[](const K& key) {
//     TreeNode<K, V>* curr = root;
//     TreeNode<K, V>* parent = nullptr;

//     // 1️⃣ 키 탐색
//     while (curr) {
//         if (comp(curr->get_K(), key)) {
//             parent = curr;
//             curr = curr->get_R();
//         } else if (comp(key, curr->get_K())) {
//             parent = curr;
//             curr = curr->get_L();
//         } else {
//             return curr->get_V();  // ✅ 키가 존재하면 값 반환
//         }
//     }

//     // 2️⃣ 키가 없으면 새로운 노드 추가
//     TreeNode<K, V>* new_node = new TreeNode<K, V>(key, V());
//     if (!root) {
//         root = new_node;
//     } else {
//         if (comp(parent->get_K(), key)) {
//             parent->set_R(new_node);
//         } else {
//             parent->set_L(new_node);
//         }
//     }

//     return new_node->get_V();  // ✅ 새 노드의 값 반환
// }

// // ✅ 읽기 전용 (const 버전)
// V operator[](const K& key) const {
//     TreeNode<K, V>* curr = root;

//     // 1️⃣ 키 탐색
//     while (curr) {
//         if (comp(curr->get_K(), key)) {
//             curr = curr->get_R();
//         } else if (comp(key, curr->get_K())) {
//             curr = curr->get_L();
//         } else {
//             return curr->get_V();  // ✅ 키가 존재하면 값 반환
//         }
//     }

//     return V();  // ✅ 키가 없으면 기본값 반환 (노드 추가 ❌)
// }

// V& operator[](const K& key) {
//     TreeNode<K, V>* curr = root;
//     TreeNode<K, V>* parent = nullptr;

//     // 1️⃣ 키 탐색
//     while (curr) {
//         if (comp(curr->get_K(), key)) {
//             parent = curr;
//             curr = curr->get_R();
//         } else if (comp(key, curr->get_K())) {
//             parent = curr;
//             curr = curr->get_L();
//         } else {
//             return curr->get_V();  // ✅ 키가 존재하면 값 반환
//         }
//     }
//     // 2️⃣ 키가 존재하지 않으면 새 노드 추가 (쓰기 연산일 때만)
//     TreeNode<K, V>* new_node = new TreeNode<K, V>(key, V());

//     if (!root) {
//         root = new_node;
//     } else {
//         if (comp(parent->get_K(), key)) {
//             parent->set_R(new_node);
//         } else {
//             parent->set_L(new_node);
//         }
//     }

//     return new_node->get_V();  // ✅ map[key] = value; 수행 시 새로운 노드 반환
// }




    void print_map(){//in-order
        print_helper(root);
    }
    void print_helper(TreeNode<K,V>* node){
        if(!node) return;
        print_helper(node->get_L());
        // overrode 없이 cout이 되나..?
        cout << node->get_K() <<":"<<node->get_V()<< endl;
        print_helper(node->get_R());
    }

};



/*
LLM권고 delete code, 비슷함
void deleteKey(K key) {
    TreeNode<K, V>* curr = root;
    TreeNode<K, V>* parent = nullptr;

    while (curr) {
        if (comp(curr->get_K(), key)) {
            parent = curr;
            curr = curr->get_R();
        } else if (comp(key, curr->get_K())) {
            parent = curr;
            curr = curr->get_L();
        } else { // Target 노드 찾음
            // 1) 자식이 둘 다 있는 경우
            if (curr->get_L() && curr->get_R()) {
                TreeNode<K, V>* temp = curr->get_R();
                while (temp->get_L()) {
                    temp = temp->get_L();
                }
                K temp_key = temp->get_K();
                V temp_value = temp->get_V();
                deleteKey(temp_key);
                curr->set_K(temp_key);
                curr->set_V(temp_value);
            }
            // 2) 자식이 하나 있는 경우 (왼쪽 자식만 있는 경우)
            else if (curr->get_L()) {
                if (curr == root) {
                    root = curr->get_L();
                    delete curr;
                    return;
                }
                if (parent->get_R() == curr) parent->set_R(curr->get_L());
                else parent->set_L(curr->get_L());
                delete curr;
            }
            // 3) 자식이 하나 있는 경우 (오른쪽 자식만 있는 경우)
            else if (curr->get_R()) {
                if (curr == root) {
                    root = curr->get_R();
                    delete curr;
                    return;
                }
                if (parent->get_R() == curr) parent->set_R(curr->get_R());
                else parent->set_L(curr->get_R());
                delete curr;
            }
            // 4) 자식이 없는 경우
            else {
                if (curr == root) {
                    root = nullptr;
                    delete curr;
                    return;
                }
                if (parent->get_R() == curr) parent->set_R(nullptr);
                else parent->set_L(nullptr);
                delete curr;
            }
            return;
        }
    }
}

*/