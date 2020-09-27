def soluciona(K, C, R):
	R.sort(reverse=True)
	return R[K-1]

if __name__ == '__main__':
	N = int(input())
	R = []

	for i in range(N):
		linha = input().split()

		K = int(linha[0])
		C = int(linha[1])

		R.clear()
		for j in linha:
			R.append(float(j))

		del R[0]
		del R[0]
		
		sol = soluciona(K, C, R)
		print(sol)