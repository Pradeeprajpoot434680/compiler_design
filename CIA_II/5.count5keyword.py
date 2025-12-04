import re

def main():
    # Define the keywords to count
    keywords = ["if", "else", "for", "while", "return"]
    keyword_count = {key: 0 for key in keywords}

    filename = input("Enter file name: ")

    try:
        with open(filename, "r") as file:
            content = file.read()

            for key in keywords:
                matches = re.findall(rf'\b{key}\b', content)
                keyword_count[key] = len(matches)

        print("\n---- Keyword Count ----")
        for key, count in keyword_count.items():
            print(f"{key}: {count}")

    except FileNotFoundError:
        print(f"Cannot open file '{filename}'")

if __name__ == "__main__":
    main()
