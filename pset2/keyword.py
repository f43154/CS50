string = "Meet me at the park"
count = 0
bacon = 'bacon'
for i in range(len(string)):
	if string[i]==' ':
		print ' ',
	else:
		print bacon[count],
		count += 1
		if count==5:
			count = 0