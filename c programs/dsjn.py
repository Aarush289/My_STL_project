def main():
    import sys
    input = sys.stdin.readline
    t = int(input())
    results = []
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        S = sum(a)
        q, r = divmod(S, n)
        target = [q + 1] * r + [q] * (n - r)
        a_sorted = sorted(a)
        target_sorted = sorted(target)
        move = 0
        for orig, tgt in zip(a_sorted, target_sorted):
            if orig > tgt:
                move += orig - tgt
        movement_cost = move * k
        angriness = r * (q + 1) * (q + 2) // 2 + (n - r) * q * (q + 1) // 2
        results.append(angriness + movement_cost)
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()
