def solution(n):
	n = int(n)
	q = [n]
	iter = 0
	Been = {}
	while len(q) > 0:
		size = len(q)
		for i in range(size):
			n = q.pop(0)
			if n == 1:
				return iter
			else:
				if n % 2 == 0:
					if n/2 not in Been:
						q.append(n / 2)
						Been[n/2] = True
				else:
					if not (n+1 in Been):
						q.append(n+1)
						Been[n+1] = True
					if not (n-1 in Been):
						q.append(n-1)
						Been[n-1] = True
		iter += 1
	return -1	# wrong input

print(solution('15'))