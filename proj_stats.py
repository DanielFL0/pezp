from os import getcwd, listdir, path

cwd = getcwd()
src_dir = path.join(cwd, 'src')

def print_file_stats(filepath):
    line_count = 0
    word_count = 0
    with open(filepath, 'r') as file_object:
        lines = file_object.readlines()
        for line in lines:
            word_count += len(line.split(' '))
            line_count += 1
    print(f"{filepath}\nWORDS:\t{word_count}\nLINES:\t{line_count}")


def get_file_stats(dirpath):
    files = listdir(dirpath)
    for filename in files:
        filepath = path.join(dirpath, filename)
        print_file_stats(filepath)

get_file_stats(src_dir)