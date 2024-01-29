# removes all alphabets (a-z or A-Z) from the filenames in the specified directory
# alsao has function that appends .cpp extension to the filenames in the specified directory

import os
import re


PATH = "./problems" # specify the path to the directory containing the files

def remove_alphabets(path):
    # Get the list of files in the specified directory
    files = os.listdir(path)
    
    # Iterate through each file
    for filename in files:
        # Check if it's a file (not a directory)
        if os.path.isfile(os.path.join(path, filename)):
            # Rename the file to remove alphabets (a-z or A-Z)
            new_filename = re.sub('[a-zA-Z]', '', filename)
            
            # Check if the new filename is different
            if new_filename != filename:
                os.rename(os.path.join(path, filename), os.path.join(path, new_filename))
                print(f"Renamed '{filename}' to '{new_filename}'")

def append_cpp_extension(path):
    # Get the list of files in the specified directory
    files = os.listdir(path)
    
    # Iterate through each file
    for filename in files:
        # Check if it's a file (not a directory)
        if os.path.isfile(os.path.join(path, filename)):
            # Check if the file does not already have the .cpp extension
            if not filename.endswith(".cpp"):
                # Append .cpp to the filename
                new_filename = filename + ".cpp"
                
                # Rename the file
                os.rename(os.path.join(path, filename), os.path.join(path, new_filename))
                print(f"Appended '.cpp' to '{filename}'")

if __name__ == "__main__":
    remove_alphabets(PATH)
    append_cpp_extension(PATH)


