from random import randint

print("Give the amount of numbers:")
number = int(input())
all_numbers = [*range(number)]
answer = []
while len(all_numbers) != 0:
	idx = randint(0, len(all_numbers) - 1)
	answer.append(all_numbers[idx])
	all_numbers.remove(all_numbers[idx])
print(' '.join(str(x) for x in answer))

