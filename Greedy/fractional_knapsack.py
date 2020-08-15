# Uses python3
import sys

def get_optimal_value(capacity, weights, values):
    value = 0.
    vperw = []
    for i in range (len(weights)):
        vperw.append(values[i]/weights[i])
    weightssorted = [x for _,x in sorted(zip(vperw,weights))]
    valuessorted = [x for _,x in sorted(zip(vperw,values))]
    
    weightssorted.reverse()
    valuessorted.reverse()
    list.sort(vperw)
    vperw.reverse()

    i = 0
    while(capacity > 0 and i<len(vperw)):
        a = min(capacity, weightssorted[i])
        capacity -= a
        value += a*vperw[i]
        i+=1
    return value


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
