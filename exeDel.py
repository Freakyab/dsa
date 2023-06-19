import os

# Specify the source directory where the .exe files are located
source_directory = "C:\\Users\\aryan\\OneDrive\\Documents\\GitHub\\dsa"

# Iterate through all subdirectories and files in the source directory
for root, dirs, files in os.walk(source_directory):
    for file in files:
        # Check if the file has a .exe extension
        if file.endswith(".exe"):
            # Construct the file path
            file_path = os.path.join(root, file)
            
            # Delete the file
            os.remove(file_path)
            print(f"Deleted {file_path}")
