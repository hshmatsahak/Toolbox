# Uses python3
def edit_distance(s, t):
    #write your code here
    distance = []
    for i in range(len(t)+1):
        temp = []
        for j in range(len(s)+1):
            temp.append(0)
        distance.append(temp)
    for i in range (0, len(s)+1):
        distance[0][i] = i
    for i in range (0, len(t)+1):
        distance[i][0] = i
    for i in range(1, len(t)+1):
        for j in range(1, len(s)+1):
            insert = distance[i-1][j]+1
            delete = distance[i][j-1]+1
            match = distance[i-1][j-1]
            mismatch = distance[i-1][j-1]+1
            if (s[j-1] == t[i-1]):
                distance[i][j] = min(insert, delete, match)
            else:
                distance[i][j] = min(insert, delete, mismatch)
    return distance[len(t)][len(s)]

if __name__ == "__main__":
    print(edit_distance(input(), input()))