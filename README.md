# String Operations in C

This project demonstrates three key string manipulation operations in C:
1. **Addition of Two Large Numbers**: Treats numbers as strings and performs the addition character by character.
2. **Concatenation of Two Strings**: Concatenates two input strings.
3. **Rotation of a String**: Rotates a string by a specified number of characters.

The program takes multiple sets of inputs, performs the corresponding operation based on the operator provided, and outputs the result.
- **Addition (`+`)**: Handles the addition of large numbers that cannot be stored in basic integer types.
- **Concatenation (`@`)**: Combines two strings into one.
- **Rotation (`r`)**: Rotates a string by a given number of positions and removes leading zeros if any.

# Function description

- **concatenate()**: This function concatenates two strings and prints the result.
- **addNumbers()**: Adds two large numbers represented as strings and prints the sum.
- **rotate()**: Rotates a string by the specified number of positions.
- **main()**: Takes inputs, determines the operation to be performed, and invokes the respective function.

# How It Works

1. The user first provides the number of operations to be performed.
2. For each operation:
   - The user inputs two strings and an operator.
   - The operator determines whether to add, concatenate, or rotate the strings.
   - The result of the operation is printed to the console.

# Input Format
- An integer `n` is provided, representing the number of operations.
- For each operation:
  - The first string (`num1`).
  - The operator: `+` for addition, `@` for concatenation, `r` for rotation.
  - The second string (`num2`).
  
### Output
The program outputs the result of each operation on a new line.
