def solution(data, n): 
    F = {}
    for d in data:
        if d in F:
        	F[d] += 1
        else:
        	F[d] = 1
    return [d for d in data if F[d] <= n]

print(solution([1, 2, 2, 3, 3, 3, 4, 5, 5], 1))