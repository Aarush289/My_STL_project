from collections import defaultdict, deque

# Simulate the final values given initial values and operations
def simulate(n, ops, a):
    final = a[:]
    changed = True
    while changed:
        changed = False
        for x, y, z in ops:
            new_val = min(final[x], final[y] + z)
            if new_val < final[x]:
                final[x] = new_val
                changed = True
    return final

def solve_stability_problem(n, m, operations, queries):
    # Adjust indices to 0-based
    ops = [(x-1, y-1, z) for x, y, z in operations]

    results = []
    for k, a in queries:
        # Stable final result
        final = simulate(n, ops, a)

        res = ['0'] * n

        for i in range(n):
            low = a[i] - min(k, a[i])  # Decrease as much as possible
            high = a[i]
            # Try binary search on decreasing i-th variable to see if final[i] can change
            l, r = low, high
            unstable = False
            while l <= r:
                mid = (l + r) // 2
                new_a = a[:]
                new_a[i] = mid
                new_final = simulate(n, ops, new_a)
                if new_final[i] != final[i]:
                    unstable = True
                    break
                r = mid - 1  # Try more decrement
            res[i] = '1' if unstable else '0'

        results.append("".join(res))
    return results
