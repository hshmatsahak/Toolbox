# python3
import sys

def compute_min_refills(distance, tank, stops):
    stops.append(distance)
    curr_refill = 0
    m=0
    while (curr_refill <= len(stops)):
        last_refill = curr_refill
        if (last_refill == 0): last_dist = 0
        else: last_dist = stops[last_refill-1]
        while (curr_refill < len(stops) and stops[curr_refill]-last_dist<=tank):
            curr_refill+=1
        if (curr_refill == last_refill):
            return -1
        if (curr_refill == len(stops)):
            return m
        m+=1
    return -1

if __name__ == '__main__':
    d, m, _, *stops = map(int, sys.stdin.read().split())
    print(compute_min_refills(d, m, stops))