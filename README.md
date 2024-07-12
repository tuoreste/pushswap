# Push_swap

Push_swap is a project that focuses on sorting a stack of integers using two stacks and a limited set of operations. This README explains the process used to sort the stack, including manual sorting for small sets of numbers and a custom algorithm for larger sets.

## Project Overview

In this project, we have two stacks (`stack_a` and `stack_b`). The goal is to sort the numbers in `stack_a` using the least number of operations. The numbers are provided as command-line arguments.

## Operations

The allowed operations are:
- `sa`: Swap the first two elements of stack_a.
- `sb`: Swap the first two elements of stack_b.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Push the top element from stack_b to stack_a.
- `pb`: Push the top element from stack_a to stack_b.
- `ra`: Rotate stack_a (shift up all elements by 1).
- `rb`: Rotate stack_b (shift up all elements by 1).
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra`: Reverse rotate stack_a (shift down all elements by 1).
- `rrb`: Reverse rotate stack_b (shift down all elements by 1).
- `rrr`: Perform `rra` and `rrb` simultaneously.

## Sorting Strategy

### Manual Sorting for Small Sets

For small sets of numbers (2, 3, 4, and 5), a manual sorting approach is used:

1. **Two Numbers**: Simply swap if they are out of order.
2. **Three Numbers**: Use a series of swaps and rotations to sort the stack in minimal steps.
3. **Four Numbers**: Push the smallest element to stack_b, sort the remaining three in stack_a, then push the smallest element back to stack_a.
4. **Five Numbers**: Similar to four numbers, but push the two smallest elements to stack_b, sort the remaining three in stack_a, then push the two smallest elements back to stack_a in the correct order.

## Algorithm for Larger Sets

For larger sets of numbers, a systematic approach is employed to efficiently sort them using the two-stack structure. Here’s a step-by-step explanation of the algorithm:

### Step 1: Divide and Conquer with `stack_b`

1. **Push Elements to `stack_b`**: Begin by transferring elements from `stack_a` to `stack_b` based on a specific criterion (e.g., median value). This helps in dividing the elements into two manageable groups.

### Step 2: Utilizing Helper Functions

2. **Rotate Count Function**: Calculate the number of rotations needed to bring a specific index to the top of a stack (`rotate_count` function). This function aids in efficiently managing the movement of elements within the stacks.

3. **Near Square Root Function**: Determine the optimal size of subgroups by finding the largest integer whose square is less than a given number (`near_sqr_to_no` function). This function assists in grouping elements effectively for sorting.

### Step 3: Sorting and Returning to `stack_a`

4. **Switch to A Function**: Sort elements in `stack_b` and push them back to `stack_a` in the correct order. This function calculates the optimal rotations needed and performs the necessary push and rotate operations (`switch_to_a` function).

### Example Workflow

To illustrate the sorting process:
- Start with an unsorted set of numbers in `stack_a`.
- Divide the elements by pushing them to `stack_b` based on a pivot value.
- Sort and return elements to `stack_a` using optimal rotations calculated by helper functions.

This systematic approach ensures that larger sets of numbers are sorted efficiently using a combination of stack operations and optimized movement strategies.

## Data Structures

This project uses singly linked lists to implement the stacks. Each node in the linked list represents an element in the stack and contains:
- The value of the element.
- The index of the element.
- A pointer to the next node in the list.

## Compilation and Execution

To compile and run the `push_swap` program, follow these steps:

1. Clone this repository to your local machine.
2. Compile the program using a C compiler, such as GCC. You can use the following command:

    ```bash
    gcc -o push_swap push_swap.c
    ```

3. Run the program with a list of integers as arguments:

    ```bash
    ./push_swap 3 2 5 1 4
    ```

The program will output the series of operations needed to sort the stack.

## OR you can run the following simplest

`git clone https://github.com/tuoreste/pushswap.git && cd pushswap && make && ./push_swap 3 2 5 1 4`

## Example

Here is an example of how the program works:

```bash
$ ./push_swap 3 2 5 1 4
pb
pb
sa
pa
pa
ra
ra
