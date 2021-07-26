from os import path
import pathlib
import os
from .FileManagerPaths import *


def check_if_file_exists(filepath):
    return os.path.isfile(filepath)


def check_if_directory_exists(directory):
    return path.isdir(directory)


def get_file_manager_path(directory, filename):
    if not check_if_directory_exists(directory):
        print('directory', directory, 'doesnt exist')
        print('creating directory')
        os.makedirs(directory)

    return path.join(directory, filename)


# if __name__ == '__main__':
#     directory = "C:\\Temp\\mama"
#     print(INFLUX_INSTALLATION_ID_DATA)
#
#     # get_file_manager_path('hello', directory)
#     f = open(get_file_manager_path('hello.txt', INFLUX_INSTALLATION_ID_SIGNAL_DATA_HISTOGRAMS_PLOTS), 'w')
