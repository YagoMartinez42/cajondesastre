def stoi (numStr):
	i = 0
	sign = 1
	num = 0
	sLen = len(numStr)
	base = "0123456789"
	while i < sLen and (numStr[i] == ' ' or numStr[i] == '	'):
		i += 1
	if i < sLen and numStr[i] == '-':
		sign = -1
	if i < sLen and (numStr[i] == '+' or numStr[i] == '-'):
		i += 1
	while i < sLen and (numStr[i] in base):
		num *= 10
		num += base.index(numStr[i])
		i += 1
	return (num * sign)


num = stoi(input('introduce número: '))
print ('el doble es: ', num*2)