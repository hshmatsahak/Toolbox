# Uses python3
import sys

def optimal_sequence(n):
    num_calcs = []
    num_calcs.append(0)
    for i in range (1, n+1):
        if (i%6 == 0):
            num_calcs.append(min(num_calcs[int(i/2)], num_calcs[int(i/3)])+1)
        elif (i%3 == 0):
            num_calcs.append(min(num_calcs[int(i/3)], num_calcs[int(i-1)])+1)
        elif (i%2 == 0):
            num_calcs.append(min(num_calcs[int(i/2)],num_calcs[int(i-1)])+1)
        else:
            num_calcs.append(num_calcs[int(i-1)]+1)
    sequence = [n]
    curr = n
    while (curr>1):
        if (num_calcs[curr-1] + 1 == num_calcs[curr]):
            sequence.append(curr-1)
            curr -= 1
        elif (curr%3==0 and num_calcs[curr] == num_calcs[int(curr/3)]+1):
            sequence.append(int(curr/3))
            curr = int(curr/3)
        else:
            sequence.append(int(curr/2))
            curr = int (curr/2)

    sequence.reverse()
    return sequence

input = sys.stdin.read()
n = int(input)
sequence = list(optimal_sequence(n))
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
