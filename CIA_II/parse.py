import sys

# Global variables
i = 0
input_str = ""

def error():
    print("Error in parsing!")
    sys.exit(0)

def F():
    global i, input_str
    if i < len(input_str) and input_str[i] == '(':
        i += 1
        E()
        if i < len(input_str) and input_str[i] == ')':
            i += 1
        else:
            error()
    elif i < len(input_str) and input_str[i].isalpha():
        i += 1
    else:
        error()

def T():
    global i, input_str
    F()
    while i < len(input_str) and input_str[i] == '*':
        i += 1
        F()

def E():
    global i, input_str
    T()
    while i < len(input_str) and input_str[i] == '+':
        i += 1
        T()

def main():
    global i, input_str
    input_str = input("Enter expression: ").strip()
    input_str += "$"  # End marker

    E()

    if i < len(input_str) and input_str[i] == '$':
        print("Parsing successful!")
    else:
        error()

if __name__ == "__main__":
    main()
