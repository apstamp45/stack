
# Stack Lang

Stack Lang is a simple (or complex, depending on how you look at it) interpreted language consisting of a single line of code. Each operation is done on a single stack.   
The operations are as follows:   
number: adds an integer to the stack. Numbers can be seperated by a comma, or another operator.   
\+ : Removes the top two items from the stack, and pushes their sum to the top.  
\+\+ : Pushes the sum of the top to values to the stack without removing them.   
\- : Removes the top two items from the stack, and pushes the second value from the top minus the top value.
\-\- : Same as \+\+, except the difference is pushed.   
\* , \*\* , / , // , % , %% : Multiply, multiply and push; divide, divide and push; modulo, modulo and push. Each follows the same pattern as the preceding operators.
