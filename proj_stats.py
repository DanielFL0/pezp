from os import getcwd, listdir, path

cwd = getcwd()

def stats(filepath):
    line_count = 0
    word_count = 0
    with open(filepath, 'r') as file_object:
        lines = file_object.readlines()
        for line in lines:
            word_count = len(line.split(' '))
            line_count += 1
    print(f"FILENAME:\t{filepath}\nWORDS:\t{word_count}\nLINES:\t{line_count}")


def recursive_check(dirpath):
    dirs = listdir(dirpath)
    for item in dirs:
        if path.isdir(item):
            recursive_check(item)
        print(item)
recursive_check(cwd)