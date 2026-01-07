*This project has been created as part of 42 carriculum by amamun*

# Push_swap

## Description
The main goal of this program is to sort integers in a stack. The program uses two stacks: Stack A and Stack B. Initially, Stack A contains a set of random integers, while Stack B is empty. The objective is to implement an algorithm that sorts the integers in Stack A using the minimum possible number of operations.  

Defined Operations:

PB: Push the integer at the top of stack A to stack B  
PA: Push the integer at the top of stack B to stack A  

SA: Swap the two integers at the top of stack A  
SB: Swap the two integers at the top of stack B  
SS: Perform SA and SB simultaneously  

RA: Rotate stack A — the top integer moves to the bottom  
RB: Rotate stack B — the top integer moves to the bottom  
RR: Perform RA and RB simultaneously  

RRA: Reverse rotate stack A — the bottom integer moves to the top  
RRB: Reverse rotate stack B — the bottom integer moves to the top  
RRR: Perform RRA and RRB simultaneously  


The program first validates the input, converts the values to integers, and checks whether they fall within the allowed limits. The validated integers are then initialized in stack A.  

The Algorithm:  
For the doubly linked list implementation, the Turk algorithm was chosen as it results in the minimum number of operations. When there are up to three integers, they are sorted by moving the highest value to the bottom and swapping the top two integers if necessary.  

When there are more than three integers, the program initially pushes two integers from stack A to the empty stack B. Next, for each value in stack A, a target node in stack B is determined. The target node is the closest smaller value. If no such value exists, the maximum value in stack B is selected as the target.  

The program then calculates the number of operations required to bring both the selected node in stack A and its target node in stack B to the top of their respective stacks. The move with the lowest cost is executed, followed by a PB operation. This process repeats until only three integers remain in stack A.  

At this point, stack B contains integers in descending order. The process is then reversed. For each value in stack B, the target node in stack A is chosen as the closest larger value. In case none exists, the minimum value in stack A becomes the target. The values are then pushed back to stack A.  

Finally, once all integers are in stack A, the program rotates/reverse rotate the stack to bring the smallest integer to the top, resulting in the stack being sorted in ascending order.

## Instruction
Use the make command to compile the program.  
Run the program using the following command:


`./pushswap 1 3 2`  

The numbers can be provided either with or without double quotation marks.  

## Resources
Following guides were followed for understanding and implentation of the project as well as the algorithm.  
https://www.geeksforgeeks.org/dsa/dsa-tutorial-learn-data-structures-and-algorithms/  
https://www.geeksforgeeks.org/dsa/data-structures/  
https://www.youtube.com/watch?v=0euvEdPwQnQ  
https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s&pp=ygUJcHVzaCBzd2Fw  
https://medium.com/@ayogun/push-swap-c1f5d2d41e97  