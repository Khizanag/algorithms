def get_added_first_and_last_gates(sources, sinks, network):
	leng = len(network)
	newlen = len(network) + 2
	newNetwork = [[0 for x in range(newlen)] for y in range(newlen)] 
	for i in range(leng):
		for j in range(leng):
			newNetwork[i+1][j+1] = network[i][j]

	for i in sources:
		newNetwork[0][i+1] = float('inf')

	for i in sinks:
		newNetwork[i+1][newlen-1] = float('inf')

	return newNetwork

def get_parents_grid(RN):
	P = [-1 for x in range (len(RN))]
	q = [0]	# queue
	i = 0

	while P[len(P)-1] == -1 and len(q) > 0:
		i = q.pop(0)
		for j in range (len(P)):
			if RN[i][j] > 0 and P[j] == -1:
				q.append(j)
				P[j] = i
	return P

def get_path(P):
	path = []
	i = P[len(P)-1]
	while i > 0:
		path.append(i)
		i = P[i]
	if i == -1:
		return None
	path.reverse()
	return path

def BFS(RN):
	P = get_parents_grid(RN)
	path = get_path(P)
	return path


def get_residual_capacity(RN, path):
	rc = float('inf')
	u = 0
	for v in path:
		rc = min(rc, RN[u][v])
		u = v
	return rc

def update_residual_network(RN, path, rc):
	i = 0
	for j in path:
		RN[i][j] -= rc
		RN[j][i] += rc
		i = j	


def solve(RN):
	maxFlow = 0

	while True:
		path = BFS(RN)
		if path == None:
			break

		rc = get_residual_capacity(RN, path)
		maxFlow += rc
		update_residual_network(RN, path, rc)
	return maxFlow

def solution(sources, sinks, network):
	return solve(get_added_first_and_last_gates(sources, sinks, network))

print(solution([0], [3], [[0, 7, 0, 0], [0, 0, 6, 0], [0, 0, 0, 8], [9, 0, 0, 0]]))