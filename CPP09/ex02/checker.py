import sys

def is_sorted(numbers):
    """
    Checks if a list of numbers is sorted in non-decreasing order.

    Args:
        numbers (list): A list of numbers (integers or floats).

    Returns:
        bool: True if the list is sorted, False otherwise.
    """
    if not numbers:
        return True

    for i in range(len(numbers) - 1):
        if numbers[i] > numbers[i+1]:
            return False
    return True

if __name__ == "__main__":
    raw_input_data = []

    # Read all lines from stdin
    # This loop will continue until EOF (End Of File) is reached,
    # which happens when the piping program finishes its output.
    for line in sys.stdin:
        raw_input_data.append(line.strip()) # .strip() removes leading/trailing whitespace including newlines

    # Assuming the piped input is a single line of space-separated numbers,
    # or multiple lines where each line might contribute to the numbers.
    # For this example, let's assume one line of space-separated numbers.
    # If your piped output is one number per line, you'd adjust the parsing.

    numbers_str = " ".join(raw_input_data) # Join all lines into a single string
    
    parsed_numbers = []
    if numbers_str: # Only try to split and convert if the string is not empty
        try:
            # Attempt to convert each part to an integer
            parsed_numbers = [int(x) for x in numbers_str.split()]
        except ValueError:
            print("Error: Input contains non-numeric values. Please provide only numbers.")
            sys.exit(1) # Exit with an error code

    if is_sorted(parsed_numbers):
        print("The input numbers are sorted.")
    else:
        print("The input numbers are NOT sorted.")