"내 풀이, 답은 나오는데 Time complexity가 무너진다"
# class Solution:
#     def canChange(self, start: str, target: str) -> bool:
#         if (start.count('L') != target.count('L')) or (start.count('R') != target.count('R')):
#             return False
#         n = len(start)
#         for i in range(n):
#             if start[i] == target[i]:
#                 continue
#             # Need move
#             temp = target[i]
#             if (start[i] == 'L')or(start[i] == '_' and temp == 'R')or(start[i] == 'R' and temp =='L'):
#                 return False
            
#             if start[i] == '_' and temp == 'L' :
#                 for j in range(i+1,n):
#                     if start[j] == '_': continue
#                     if start[j] == 'R': return False
#                     if start[j] == 'L':
#                         start = start[:i] + start[j] + start[i+1:j] + start[i] + start[j+1:]
#                         break
#             if start[i] == 'R' and temp == '_' :
#                 for j in range(i+1,n):
#                     if start[j] == '_':
#                         start = start[:i] + start[j] + start[i+1:j] + start[i] + start[j+1:]
#                         break
#                     if start[j] == 'R': continue
#                     if start[j] == 'L': return False
#         return True
    # GPT풀이
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        # Step 1: Count 'L' and 'R'
        if start.replace('_', '') != target.replace('_', ''):
            return False

        # Step 2: Extract positions of 'L' and 'R'
        start_positions = [(char, i) for i, char in enumerate(start) if char != '_']
        target_positions = [(char, i) for i, char in enumerate(target) if char != '_']

        # Step 3: Compare positions
        for (s_char, s_idx), (t_char, t_idx) in zip(start_positions, target_positions):
            if s_char != t_char:
                return False
            if s_char == 'L' and s_idx < t_idx:  # 'L' can only move left
                return False
            if s_char == 'R' and s_idx > t_idx:  # 'R' can only move right
                return False

        return True
# target1 = "LLL___RRR"
# target2 = "___LRLRLR"

# test1 = [(char,i) for i,char in enumerate(target1)]
# test2 = [(char,i) for i,char in enumerate(target2)]
# print(test1)
# print(test2)
# test3=zip(test1,test2)
# for a in test3:
#     print(a)
#     # print(b)
temp = (1,[0])
print(temp[1])
# temp[1]=5
print(temp)
temp2 = {1,0}
# print(temp2[1])
temp[1][0] = 5
print(temp)

"""
C/C++ 풀이


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1000

bool canChange(char* start, char* target) {
    int n = strlen(start);
    char startStripped[MAX_LEN], targetStripped[MAX_LEN];
    int startL[MAX_LEN], startR[MAX_LEN];
    int targetL[MAX_LEN], targetR[MAX_LEN];
    int startLCount = 0, startRCount = 0;
    int targetLCount = 0, targetRCount = 0;

    // Step 1: Remove '_' and check stripped strings
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (start[i] != '_') startStripped[k++] = start[i];
    }
    startStripped[k] = '\0';

    k = 0;
    for (int i = 0; i < n; i++) {
        if (target[i] != '_') targetStripped[k++] = target[i];
    }
    targetStripped[k] = '\0';

    if (strcmp(startStripped, targetStripped) != 0) return false;

    // Step 2: Extract positions of 'L' and 'R'
    for (int i = 0; i < n; i++) {
        if (start[i] == 'L') startL[startLCount++] = i;
        else if (start[i] == 'R') startR[startRCount++] = i;

        if (target[i] == 'L') targetL[targetLCount++] = i;
        else if (target[i] == 'R') targetR[targetRCount++] = i;
    }

    // Step 3: Compare positions of 'L' and 'R'
    for (int i = 0; i < startLCount; i++) {
        if (startL[i] < targetL[i]) return false; // 'L' can only move left
    }
    for (int i = 0; i < startRCount; i++) {
        if (startR[i] > targetR[i]) return false; // 'R' can only move right
    }

    return true;
}

int main() {
    char start[MAX_LEN] = "R_L__";
    char target[MAX_LEN] = "__RL_";

    if (canChange(start, target)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}


#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool canChange(string start, string target) {
    int n = start.size();

    // Step 1: Remove '_' and check stripped strings
    string startStripped, targetStripped;
    for (char c : start) {
        if (c != '_') startStripped += c;
    }
    for (char c : target) {
        if (c != '_') targetStripped += c;
    }
    if (startStripped != targetStripped) return false;

    // Step 2: Extract positions of 'L' and 'R'
    vector<int> startL, startR, targetL, targetR;
    for (int i = 0; i < n; i++) {
        if (start[i] == 'L') startL.push_back(i);
        if (start[i] == 'R') startR.push_back(i);
        if (target[i] == 'L') targetL.push_back(i);
        if (target[i] == 'R') targetR.push_back(i);
    }

    // Step 3: Compare positions of 'L' and 'R'
    for (int i = 0; i < startL.size(); i++) {
        if (startL[i] < targetL[i]) return false; // 'L' can only move left
    }
    for (int i = 0; i < startR.size(); i++) {
        if (startR[i] > targetR[i]) return false; // 'R' can only move right
    }

    return true;
}

int main() {
    string start = "R_L__";
    string target = "__RL_";

    if (canChange(start, target)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}


"""