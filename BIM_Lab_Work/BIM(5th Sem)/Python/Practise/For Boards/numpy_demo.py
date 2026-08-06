import numpy as np
# Create a 1-dimensional array from a list
arr1 = np.array([1, 2, 3, 4, 5])
print(arr1)
# Create a 2-dimensional array (matrix) from a nested list
arr2 = np.array([[1, 2, 3], [4, 5, 6]])
print(arr2)

print(np.zeros((2, 3)))  # Create a 2x3 array of zeros
print(np.ones((3, 4)))   # Create a 3x4 array of

print(np.empty((2, 3)))  # Create a 2x3 array of uninitialized values

print(np.arange(0, 11, 2))  # Create an array of even numbers from 0 to 10
print(np.linspace(0, 5, 5))  # Create an array of 5 evenly spaced numbers between 0 and 1

print(np.random.rand(3, 4))  # Create a 3x4 array of random numbers between 0 and 1

array_with_seven = np.full((3,4),7)
print(array_with_seven)  # Create a 3x4 array filled with the value 7

print(np.eye(3))

print(np.array(1))

# Create a 1D array with 12 elements
arr = np.arange(12)
print("Original 1D array:")
print(arr)
# Reshape the 1D array into a 3x4 2D array
arr_2d = arr.reshape(2, 6)
print("\nReshaped 2D array (2x6):")
print(arr_2d)

str_values = "1,2,3,4,5,6,7,8,9,10"

numeric_values=[int(str_val) for str_val in str_values.split(",")]

print(np.array(numeric_values))

# Create an array of integers
int_array = np.array([1, 2, 3])
# Get the data type object of the array
data_type = int_array.dtype
# Print the data type object
print(data_type)

# Create a sequence of integers from
a = np.arange(10, 1, -1) 
print("\n A sequential array with a negative step: \n",a)
# Indexes are specified inside the np.array method.
narr = a[np.array([3,1,2])]
print("\n Elements at these indices are:\n",narr)

print(a[1])

# Creating a 2D array
arr = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print("Original Array:")
print(arr)
# Accessing specific elements
print("\nElement at index (0, 0):", arr[0, 0])
print("Element at index (1, 2):", arr[1, 2])

arr1 = np.array([1, 2, 3, 4])
arr2 = np.array([4, 3, 2, 1])
# Element-wise equality
print("arr1 == arr2:", arr1 == arr2)

arr = np.array([3, 1, 2, 5, 4])
sorted_indices = np.argsort(arr)
print(sorted_indices)
print("Indices that would sort the array:", sorted_indices)
sorted_arr = arr[sorted_indices]
print("Array sorted using indices:", sorted_arr)