# Monty: A Scripting Language

Monty 0.98 is a scripting language compiled into Monty byte codes, similar to Python. It utilizes a unique stack with specific instructions for manipulation. The primary goal is to create an interpreter for Monty ByteCodes files in this project its about creating interpreter for stack and qeuue data structures using c.

## Monty Byte Code Files

Files containing Monty byte codes typically have the .m extension. While industry practice follows this standard, it's not mandatory. Each line should contain only one instruction, and there can be any number of spaces before or after the opcode and its argument.

Example for monty.m file:

```
push 0
push 1
push 2
  push 3
pall
push 4
push 5
push 6
pall
```

# Monty Program Usage
First you need to clone to my repo using:
```
git clone 
```

To run the Monty program:
```
./monty file.m
```