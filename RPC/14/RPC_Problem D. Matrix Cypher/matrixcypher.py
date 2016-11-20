# your code goes here

def identity(a, b, c, d):
	return a==1 and b==0 and c==0 and d==1

strg = input("")
arr = strg.split(" ")
a00 = int(arr[0])
a01 = int(arr[1])
strg = input("")
arr = strg.split(" ")
a10 = int(arr[0])
a11 = int(arr[1])

while(not identity(a00, a01, a10, a11)):
	if (a00+a01 > a10+a11):
		a00 -= a10
		a01 -= a11
		print("1", end="")
	else:
		a10 -= a00
		a11 -= a01
		print("0", end="")
print("")