def soluciona(K, C, R):
	mergeSort(R)
	return R[K-1]

def mergeSort(vet): 
	if len(vet) > 1: 
		i = j = k = 0
		meio = len(vet)//2
		Esq = vet[:meio]  
		Dir = vet[meio:]
		mergeSort(Esq) 
		mergeSort(Dir)
  
		while i < len(Esq) and j < len(Dir): 
			if Esq[i] > Dir[j]: 
				vet[k] = Esq[i] 
				i+= 1
			else: 
				vet[k] = Dir[j] 
				j+= 1
			k+= 1
         
		while i < len(Esq): 
			vet[k] = Esq[i] 
			i+= 1
			k+= 1
          
		while j < len(Dir): 
			vet[k] = Dir[j] 
			j += 1
			k += 1
						
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