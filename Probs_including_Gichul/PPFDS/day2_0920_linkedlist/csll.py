class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class CircularSinglyLinkedList:
    def __init__(self):
        self.head = None

    # 리스트의 끝에 노드를 추가
    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            new_node.next = self.head
        else:
            current = self.head
            while current.next != self.head:
                current = current.next
            current.next = new_node
            new_node.next = self.head

    # 리스트에서 특정 값을 가진 노드를 삭제
    def delete(self, key):
        if self.head is None:
            return
        
        current = self.head
        prev = None
        
        # 헤드가 삭제할 노드를 가리키는 경우
        if current.data == key:
            if current.next == self.head:  # 리스트에 노드가 하나만 있는 경우
                self.head = None
            else:
                # 헤드 노드를 제외한 나머지 노드들을 연결
                while current.next != self.head:
                    current = current.next
                current.next = self.head.next
                self.head = self.head.next
            return

        # 삭제할 노드를 찾으면서 이동
        while current.next != self.head and current.next.data != key:
            current = current.next
        
        # 노드가 리스트에 없는 경우
        if current.next == self.head:
            return
        
        # 노드를 삭제
        current.next = current.next.next

    # 리스트를 출력
    def print_list(self):
        if self.head is None:
            print("List is empty")
            return
        
        current = self.head
        while True:
            print(current.data, end=" -> ")
            current = current.next
            if current == self.head:
                break
        print("... (circular)")

# Circular Singly Linked List 사용 예제
if __name__ == "__main__":
    csll = CircularSinglyLinkedList()
    csll.append(1)
    csll.append(2)
    csll.append(3)
    csll.print_list()  # 1 -> 2 -> 3 -> ... (circular)

    csll.delete(2)
    csll.print_list()  # 1 -> 3 -> ... (circular)

    csll.delete(1)
    csll.print_list()  # 3 -> ... (circular)

    csll.delete(3)
    csll.print_list()  # List is empty