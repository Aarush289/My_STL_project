def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    results = []
    for _ in range(t):
        n, k = int(data[idx]), int(data[idx + 1])
        idx += 2
        a = list(map(int, data[idx:idx + n]))
        idx += n
        
        original_sum = 0
        max_a = 0
        total = 0
        for num in a:
            original_sum += num * (num + 1) // 2
            max_a = max(max_a, num)
            total += num
        
        merged_sum = total * (total + 1) // 2
        cost = k * (total - max_a)
        merged_total = merged_sum + cost
        
        results.append(min(original_sum, merged_total))
    
    sys.stdout.write('\n'.join(map(str, results)) + '\n')

if __name__ == "__main__":
    main()
