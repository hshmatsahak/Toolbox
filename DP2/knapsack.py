# Uses python3
import sys

def optimal_weight(W, w):
    optimal_weight_numitems = []
    for i in range(W+1):
        temp = []
        for j in range(len(w)+1):
            temp.append(0)
        optimal_weight_numitems.append(temp)
    for i in range(len(w)+1):
        optimal_weight_numitems[0][i] = 0
    for i in range(W+1):
        optimal_weight_numitems[i][0] = 0
    for i in range(1, W+1):
        for j in range(1, len(w)+1):
            optimal_weight_numitems[i][j] = optimal_weight_numitems[i][j-1]
            if (w[j-1] <= i):
                val = optimal_weight_numitems[i-w[j-1]][j-1]+w[j-1]
                if (val > optimal_weight_numitems[i][j]):
                    optimal_weight_numitems[i][j] = val
    return optimal_weight_numitems[W][len(w)]

if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
