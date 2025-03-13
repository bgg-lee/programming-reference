def read_meetings_from_file(filename:str) -> list[tuple[str,str]]:
   # filename : the name of the file containing meeting
   # python으로 text 파일 읽어오는 것...
   with open(filename,'r') as file:
      temp = file.read().split()
   ans = []
   i = 0
   n = len(temp)
   while i<n:
      temp2 = (temp[i],temp[i+1])
      ans.append(temp2)
      i += 2
   # print(type(ans))
   # print(type(ans[0]))
   # print(type(ans[0][0]))
   return ans

def min_meeting_rooms(meetings:list[tuple[str,str]]) ->tuple[int,list[tuple[str,str]]]:
   # write your function
   lst = sorted(meetings)
   ans = []
   import heapq
   n = len(lst)
   heapq.heappush(ans,lst[0][1])

   for i in range(1,n):
      temp =  heapq.heappop(ans)
      if lst[i][0] >= temp:
         heapq.heappush(ans,lst[i][1])      
         continue
      heapq.heappush(ans,temp)
      heapq.heappush(ans,lst[i][1])
   

   num = len(ans)
   lst2 = [[] for _ in range(num)]
   ans2 = []
   for x in lst:
      heapq.heappush(ans2,x)
   while ans2:
      curr = heapq.heappop(ans2)
      for idx in range(num):
         if lst2[idx] and lst2[idx][-1][1] < curr[0]:
            lst2[idx].append(curr)
            break
         if not lst2[idx]:
            lst2[idx].append(curr)
            break
         else:
            continue
   # 뭣이 문제지..
   # print(lst2)
   return (num,lst2)         

if __name__ == "__main__" :
   # print(read_meetings_from_file('meeting1.txt'))
   # print(read_meetings_from_file('meeting2.txt'))
   # print(read_meetings_from_file('meeting3.txt'))
   print(min_meeting_rooms(read_meetings_from_file('meeting1.txt')))