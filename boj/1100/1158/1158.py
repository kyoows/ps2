# 1158 - 요세푸스 문제
# 20423700  helloneo    1158    맞았습니다!!    29380   72  Python 3 / 수정 297
n,k = map(int, input().split())
jo = []
for i in range(0, n):
    jo.append(i)
cur = 0
print('<',end='')
for i in range(0, n):
    idx = (cur+k-1)%len(jo)
    if (i == 0):
        print(jo[idx]+1, end='')
    else:
        print(', %d'%(jo[idx]+1),end='')
    jo.pop(idx)
    cur = idx
print('>')
