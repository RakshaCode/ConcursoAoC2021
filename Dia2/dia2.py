def problem1(file):

	horizontal = depth = 0

	for line in file.readlines():
		num = int(line[-2])
		#print(line, end = "")
		if "forward" in line:
			horizontal += num
		if "down" in line:
			depth += num
		if "up" in line:
			depth -= num
	print("Horizontal: ", horizontal)
	print("Profundidad: ", depth)
	print("Producto: ", horizontal * depth)

def problem2(file):
	horizontal = depth = 0
	aim = 0

	for line in file.readlines():
		num = int(line[-2])
		#print(line, end = "")
		if "forward" in line:
			horizontal += num
			depth += aim * num
		if "down" in line:
			aim +=num
		if "up" in line:
			aim -=num
	print("Horizontal: ", horizontal)
	print("Profundidad: ", depth)
	print("Puntería: ", aim)
	print("Producto: ", horizontal * depth)

def main():
	problem1(open("input","r"))
	problem2(open("input","r"))

if __name__ == "__main__":
	main()
