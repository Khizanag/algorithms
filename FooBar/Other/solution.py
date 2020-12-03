import numpy as np
from fractions import Fraction

def get_terminal_and_non_terminal_indices(M):
	ts = []
	nts = []
	for i in range (len(M)):
		if sum(M[i]) == 0:
			ts.append(i)
		else:
			nts.append(i)
	return ts, nts

def get_R_matrix(M, sums, tcount, ntcount):
	R = []
	for i in range(tcount, len(M)):
		r = []
		for j in range(0, tcount):
			r.append(Fraction(M[i][j], sums[i]))
		R.append(r)
	return R

def get_Q_matrix(M, sums, tcount, ntcount):
	Q = []
	for i in range(tcount, len(M)):
		q = []
		for j in range(tcount, len(M)):
			q.append(Fraction(M[i][j], sums[i]))
		Q.append(q)
	return Q

def get_I_matrix(count):
	M = []
	for i in range(0, count):
		m = []
		for j in range(0, count):
			if i == j:
				m.append(1)
			else:
				m.append(0)
		M.append(m)
	return M

def get_MM_matrix(M, tis, ntis, tcount, ntcount):
	MM = []
	for i in range(0, tcount):
		row = []
		for j in range(tcount):
			row.append(M[tis[i]][tis[j]])
		for j in range(ntcount):
			row.append(M[tis[i]][ntis[j]])
		MM.append(row)

	for i in range(ntcount):
		row = []
		for j in range(tcount):
			row.append(M[ntis[i]][tis[j]])
		for j in range(ntcount):
			row.append(M[ntis[i]][ntis[j]])
		MM.append(row)
	return MM

def compute_lcm(x, y):
	if x > y:
		greater = x
	else:
		greater = y

	while(True):
		if((greater % x == 0) and (greater % y == 0)):
			lcm = greater
			break
		greater += 1

	return lcm

def solution(M):
	n = len(M)
	tis, ntis = get_terminal_and_non_terminal_indices(M)
	tcount = len(tis)		# terminal states count
	ntcount = n - tcount 	# non terminal states count

	MM = get_MM_matrix(M, tis, ntis, tcount, ntcount)

	sums = [sum(MM[i]) for i in range(n)]

	R = get_R_matrix(MM, sums, tcount, ntcount)
	Q = get_Q_matrix(MM, sums, tcount, ntcount)
	I = get_I_matrix(ntcount)
	IsubQ = np.subtract(I, Q)
	F = np.linalg.inv(IsubQ)
	FR = np.dot(F, R)

	result = [Fraction(elem).limit_denominator() for elem in FR[0]]

	lcm = 1
	for i in range(len(result)):
		lcm = compute_lcm(lcm, result[i].denominator)

	rslt = [a.numerator for a in result]
	rslt.append(lcm)

	return rslt

# ---------- ---------- ---------- Testing ---------- ---------- ----------
M1 = [
  [0,1,0,0,0,1],  # s0, the initial state, goes to s1 and s5 with equal probability
  [4,0,0,3,2,0],  # s1 can become s0, s3, or s4, but with different probabilities
  [0,0,0,0,0,0],  # s2 is terminal, and unreachable (never observed in practice)
  [0,0,0,0,0,0],  # s3 is terminal
  [0,0,0,0,0,0],  # s4 is terminal
  [0,0,0,0,0,0],  # s5 is terminal
]
print(solution(M1))