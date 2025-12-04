import re

# Define token types as constants
KEYWORDS = [
    'false', 'None', 'true', 'and', 'as', 'assert', 'async', 'await', 'break', 'class',
    'continue', 'def', 'del', 'elif', 'else', 'except', 'finally', 'for', 'from', 'global',
    'if', 'import', 'in', 'is', 'lambda', 'nonlocal', 'not', 'or', 'pass', 'print','raise', 'return',
    'try', 'while', 'with', 'yield'
]

OPERATORS = [
    '+', '-', '*', '/', '%', '**', '//', 
    '==', '!=', '>', '<', '>=', '<=', 'is', 'is not', 'in', 'not in',
    'and', 'or', 'not',
    '=', '+=', '-=', '*=', '/=', '%=', '**=', '//=',
    '&', '|', '^', '~', '<<', '>>',
    'is', 'is not', 'in', 'not in',
]

SYMBOLS = [
    '(', ')', '{', '}', '[', ']', ':', ',', '.', ';', 
    '...', '@', '=', '->'
]

WHITESPACE = [
    ' ', '\t', '\n', '\r', '\f', '\v'
]

COMMENTS = [
    '#',   
    '"""', 
    "'''"  
]
def classify_token(token):
    if token in KEYWORDS:
        return ('KEYWORD', token)
    elif token in OPERATORS:
        return ('OPERATOR', token)
    elif token in SYMBOLS:
        return ('SYMBOL', token)
    elif re.match(r'^[a-zA-Z_][a-zA-Z0-9_]*$', token):
        return ('IDENTIFIER', token)
    elif re.match(r'^[0-9]+$', token):
        return ('NUMBER_LITERAL', token)
    elif token.startswith('//'):  # Handle single-line comments
        return ('COMMENT', token)
    else:
        return ('UNKNOWN', token)

def lexical_analyzer(code):
    tokens = []
    i = 0
    while i < len(code):
        char = code[i]
        
        if char in WHITESPACE:
            i += 1
            continue
        
        if char == '/' and i + 1 < len(code) and code[i + 1] == '/':
            j = i + 2
            while j < len(code) and code[j] not in '\n':
                j += 1
            tokens.append(classify_token(code[i:j]))
            i = j
            continue
        
        elif char.isalpha() or char == '_':  
            j = i
            while j < len(code) and (code[j].isalnum() or code[j] == '_'):
                j += 1
            token = code[i:j]
            tokens.append(classify_token(token))
            i = j
            continue
        
        elif char.isdigit():
            j = i
            while j < len(code) and code[j].isdigit():
                j += 1
            token = code[i:j]
            tokens.append(classify_token(token))
            i = j
            continue
        
        elif char in SYMBOLS:
            tokens.append(classify_token(char))
            i += 1
            continue
        
        elif char in OPERATORS:
            j = i + 1
            if j < len(code) and code[i:i+2] in OPERATORS:  # Handle two-character operators
                token = code[i:i+2]
                tokens.append(classify_token(token))
                i += 2
                continue
            else:  # Handle single-character operators
                token = code[i]
                tokens.append(classify_token(token))
                i += 1
                continue
        
        else:
            tokens.append(classify_token(char))
            i += 1
    
    return tokens



code = """if (x > 5) {
    // do something
    a = 10
    b=20;
    print(a+b)
}"""


tokens = lexical_analyzer(code)

for token in tokens:
    print(token)
