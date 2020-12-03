def solution(x, y):
	H = x + y - 1
	n = 1       # value when x = 1
	temp = 0    # n increases by temp
	for i in range(H):
		n += temp
		temp += 1
	print(n + x - 1)

print(solution(3, 2))