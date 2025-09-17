import sys
input = sys.stdin.read

def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    primes = [i for i, val in enumerate(is_prime) if val]
    return primes

def solve():
    data = input().split()
    t = int(data[0])
    cases = list(map(int, data[1:]))
    max_n = max(cases)
    primes = sieve(max_n)[::-1]  # reverse to go from largest to smallest

    results = []

    for n in cases:
        p = [0] * (n + 1)  # 1-based indexing
        used = [False] * (n + 1)

        for prime in primes:
            group = []
            for multiple in range(prime, n + 1, prime):
                if not used[multiple]:
                    group.append(multiple)

            if len(group) > 1:
                # rotate and assign
                for i in range(len(group)):
                    p[group[i]] = group[(i + 1) % len(group)]
                    used[group[i]] = True

        # Fill remaining unassigned positions (very rare, usually just position 1)
        unused_numbers = set(range(1, n + 1)) - set(p[1:])
        for i in range(1, n + 1):
            if p[i] == 0:
                val = unused_numbers.pop()
                p[i] = val

        results.append(' '.join(map(str, p[1:])))

    print('\n'.join(results))

solve()
