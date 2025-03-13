# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import sys
input_s = lambda: sys.stdin.readline()
M, N = map(int, input_s().split())

_map = [list(input_s().strip()) for _ in range(M)]

def print_answer(arr):
	for x in range(M):
		for y in range(N):
			print(arr[x][y], end='')
		print()

result = [[0]*N for _ in range(M)]

# 상하좌우, 대각 4개
dx = [-1, 1, 0, 0, -1, 1, -1, 1]
dy = [0, 0, -1, 1, -1, 1, 1, -1]

for x in range(M):
	for y in range(N):
		if _map[x][y] == '*':
			result[x][y] = '*'
		else:
			for _dir in range(8):
				nx = x + dx[_dir]
				ny = y + dy[_dir]
				if nx < 0 or nx >= M or ny < 0 or ny >= N: continue
				if _map[nx][ny] == '*':
					result[x][y] += 1
	
print_answer(result)