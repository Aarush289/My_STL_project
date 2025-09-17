import sys
input = sys.stdin.read
from bisect import bisect_right

def solve():
    data = input().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    results = []

    for _ in range(t):
        n = int(data[idx])
        q = int(data[idx + 1])
        idx += 2

        w = list(map(int, data[idx:idx + n]))
        idx += n
        queries = list(map(int, data[idx:idx + q]))
        idx += q

        # Build threshold list
        # We store thresholds: minimum x required to eat from position i
        thresholds = []
        x = w[-1]
        thresholds.append(x)
        for i in range(n - 2, -1, -1):
            if x >= w[i]:
                x ^= w[i]
                thresholds.append(x)
            else:
                break
        thresholds.reverse()  # So it's in the correct order for binary search

        for x in queries:
            # Binary search to find how many slimes can be eaten
            # We want largest index `i` such that x >= thresholds[i]
            # That means x can eat i+1 slimes
            lo, hi = 0, len(thresholds)
            while lo < hi:
                mid = (lo + hi) // 2
                if x >= thresholds[mid]:
                    lo = mid + 1
                else:
                    hi = mid
            results.append(str(lo))

    print("\n".join(results))

solve()
