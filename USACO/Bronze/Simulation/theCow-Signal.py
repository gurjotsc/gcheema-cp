import sys

sys.stdin = open("cowsignal.in","r")
sys.stdout = open("cowsignal.out","w")

M,N,K = map(int,input().split()) #Map each input to an int M N and K

g = [input() for _ in range(M)] #iterates through M lines and stores it in an array '_' is a dummy

for i in range(K*M): #iterate through the new size
	for j in range(K*N):
		print(g[i//K][j//K],end='') #print each char(j)in the string K times. We int divide by K because because that is how many times we are printin the same line
	print() #next line
