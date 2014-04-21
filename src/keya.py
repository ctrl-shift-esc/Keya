import sys
contents = ""
f= open(sys.argv[1])
contents=f.read()
f.close()
arr=[[0 for x in range(20)] for y in range(20)]
ctr=0
for c in contents:
	if c=='8':
		ctr=ctr-4
		if ctr<0:
			ctr=0
	if c=='2':
		ctr=ctr+4
	if c=='4':
		ctr=ctr-1
		if ctr<0:
			ctr=0
	if c=='6':
		ctr=ctr+1
		if ctr>15:
			ctr=15
	if c=='+':
		arr[ctr]=arr[ctr]+1
	if c=='-':
		arr[ctr]=arr[ctr]-1
	if c=='.':
		print chr(arr[ctr])
	if c==',':
		arr[ctr]=raw_input()
