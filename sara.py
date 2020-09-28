def intercala (p, q, r, v):
	i = p
	j = q
	k = p
	w=[]

	for i in range (q):
		w[i-p] = v[i]
	for j in range (r):
		w[r-p+q-j-1] = v[j]
	i = 0
	j = r-p-1
	for k in range (r):
		contI=contI+1
		contJ=contJ-1
		if (w[i] <= w[j]): v[k] = w[contI]
		else: v[k] = w[contJ]

def mergesort (p, r, v):
	if (p < r-1):                 
		q = int((p + r)/2)          
		mergesort (p, q, v)        
		mergesort (q, r, v)        
		intercala (p, q, r, v)
   

def funcao_que_resolve(R, K, C):
	mergesort(0, C, R)
	return R[C-K]

if __name__ == "__main__":
	R = []
	N = int(input())
	for i in range (N):
		linha = input().split()
		K = int(linha[0])
		C = int(linha[1])
		for j in linha:
			R.append(float(j))

		sol = funcao_que_resolve(R, K, C)
		print(sol)