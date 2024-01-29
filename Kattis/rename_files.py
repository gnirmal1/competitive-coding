# renames all files in the specified directory to lowercase

import os


PATH = "./problems" # specify the path to the directory containing the files

def rename_lower(path):
    # Get the list of files in the specified directory
    files = os.listdir(path)
    
    # Iterate through each file
    for filename in files:
        # Check if it's a file (not a directory)
        if os.path.isfile(os.path.join(path, filename)):
            # Rename the file to lowercase
            new_filename = filename.lower()
            
            # Check if the new filename is different
            if new_filename != filename:
                os.rename(os.path.join(path, filename), os.path.join(path, new_filename))
                print(f"Renamed '{filename}' to '{new_filename}'")

if __name__ == "__main__":
    rename_lower(PATH)
