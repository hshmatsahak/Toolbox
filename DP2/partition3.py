# Uses python3
import sys
import itertools

def partition3(A):
    tsum = sum(A)
    if (tsum%3!=0): return 0
    group_sum = tsum//3
    attainable = []
    for i in range(group_sum+1):
        temp = []
        for j in range(len(A)+1):
            temp.append(0)
        attainable.append(temp)
    for i in range(len(A)):
        attainable[0][i] = 1
    for i in range(1,group_sum+1):
        attainable[i][0] = 0
    for i in range (1, group_sum+1):
        for j in range(1, len(A)+1):
            if (attainable[i][j-1] == 1):
                attainable[i][j] = 1
            if (attainable[i-A[j-1]][j-1] == 1):
                attainable[i][j] = 1
    if (attainable[group_sum][len(A)] == 0):
        return 0
    count = 0
    for i in range (1, len(A)+1):
        if (attainable[group_sum-A[i-1]][i-1]):
            count+=1
    if (count >= 3):
        return 1
    return 0

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *A = list(map(int, input.split()))
    print(partition3(A))

