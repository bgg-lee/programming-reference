'''
# 특정 합을 가지는 부분 연속 수열 찾기
[문제 설명]
* N개의 자연수로 이루어짐
* 합이 M인 부분 연속 수열의 개수를 반환하시오 !
* 시간 제한 O(N)
'''

# n: 데이터의 수, m: 더해서 m이 되는 수열을 찾기를 원함
n, m = 5, 5
data = [1, 2, 3, 2, 5]

result = 0
path = []

summary = 0
end = 0

# start를 차례로 증가시키며 반복
for start in range(n):
    # end를 가능한 만큼 이동 시키기
    while summary < m and end < n:
        summary += data[end]
        end += 1

    # 부분합이 m일때 카운트 증가
    if summary == m:
        if data[start] == data[end-1]:
            path.append([data[start]])
        else:
            path.append([data[start], data[end-1]])
        result += 1

    # for문으로 start를 이동하니 더했던 값을 다시 제거
    summary -= data[start]

print(result)
print(path)
