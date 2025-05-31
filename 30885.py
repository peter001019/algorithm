class Node:
    def __init__(self, val, idx):
        self.val = val
        self.idx = idx
        self.prev = None
        self.next = None

N = int(input())
micrb = list(map(int, input().split()))

# 연결리스트로 옮긴다.
head = Node(micrb[0], 1)
prev_node = head

for i in range(1, len(micrb)):
    curr = Node(micrb[i], i + 1)
    prev_node.next = curr
    curr.prev = prev_node
    prev_node = curr

# head부터 순회하며 하나 남을때까지 반복한다.
cnt = N

while cnt > 1:
    u = head

    # 하루에서 한 턴 순회
    while u != None:
        curr_val = u.val
        prev = u.prev
        next = u.next

        # 왼쪽이 작다면 삭제
        if u.prev != None and curr_val >= prev.val:
            u.val += prev.val

            prev_prev = prev.prev

            if prev_prev != None:
                prev_prev.next = u
                u.prev = prev_prev
            
            else:
                head = u
                u.prev = None
            
            cnt -= 1

        # 오른쪽이 작다면 삭제
        if u.next != None and curr_val >= next.val:
            u.val += next.val

            next_next = next.next

            if next_next != None:
                next_next.prev = u
                u.next = next_next
            
            else:
                u.next = None

            cnt -= 1

        u = u.next

# head 출력
print(head.val)
print(head.idx)