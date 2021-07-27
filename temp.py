arr = [2,4,1,1,3,4]

# answer should be 3

# Sort the array

arr.sort();

length = len(arr)
last_max_val = arr[length - 1] # maximum value in array

index = length - 1

# while arr[index] is equal to last_max_val, keep decrementing value of index

while(arr[index] == last_max_val):
    index -= 1

print(arr[index])


