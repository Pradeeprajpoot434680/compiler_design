import re

def count_operators(filename):
    operator_pattern = r'(\+\+|--|==|!=|<=|>=|\+|-|\*|/|%|=|<|>)'

    try:
        with open(filename, 'r') as file:
            text = file.read()

            operators = re.findall(operator_pattern, text)

            print("Operators found:", operators)
            print("Total number of operators:", len(operators))

    except FileNotFoundError:
        print("File not found! Please check the filename.")

filename = input("Enter filename: ")
count_operators(filename)
