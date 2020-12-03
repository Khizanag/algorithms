def solution(h, q):
	Q = {qq for qq in q}
	R = {2**h-1:-1}

	fn(1, 1, h, Q, R)

	return [R[elem] for elem in q]

def fn(i, cur_level, max_level, Q, R):
	if cur_level == max_level:
		return i

	recL = fn(i,      cur_level+1, max_level, Q, R)
	recR = fn(recL+1, cur_level+1, max_level, Q, R)

	if recL in Q:
		R[recL] = recR + 1
	if recR in Q:
		R[recR] = recR + 1

	return recR + 1