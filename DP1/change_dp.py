# Uses python3
import sys

def get_change(m):
    num_coins = []
    num_coins.append(0)
    for i in range(1,m+1):
        if (i>=4):
            num_coins.append(min(num_coins[i-4], num_coins[i-3], num_coins[i-1])+1)
        elif (i>=3):
            num_coins.append(min(num_coins[i-3], num_coins[i-1])+1)
        else:
            num_coins.append(num_coins[i-1]+1)
    return num_coins[m]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
