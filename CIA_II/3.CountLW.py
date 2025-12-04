# Program to count blank spaces, words, and lines in a file

def count_file_stats(filename):
    try:
        with open(filename, 'r') as file:
            text = file.read()
            
            # Count lines
            lines = text.split('\n')
           
            line_count = len(lines) if text else 0

            # Count words
            words = text.split()
            word_count = len(words)

            # Count spaces
            space_count = text.count(' ')

            print("Number of lines:", line_count-1)
            print("Number of words:", word_count)
            print("Number of blank spaces:", space_count)

    except FileNotFoundError:
        print("File not found. Please check the file name.")

filename = input("Enter filename: ")
count_file_stats(filename)
