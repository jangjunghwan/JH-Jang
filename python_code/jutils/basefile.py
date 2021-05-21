# -*- coding: utf-8 -*-
import os
import sys


class BaseFile:
    def __init__(self) -> None:
        self.base_add = os.getcwd()


    def get_file_line_list(self, filename):
        """ Get file line results.

        Args:
            filename: Target File name.(full path)

        Returns:
            List of file results.
        """
        lines = str()
        line_list = list()

        try:
            with open(filename, "r", encoding='utf-8') as rf:
                lines = rf.readlines()
            for line in lines:
                line = line.strip()
                line_list.append(line)

        except Exception as e:
            print(e)

        return line_list


    def write_file(self, result_list, write_filename):
        """ Write Method.

        Args:
            result_list: What to write to the file.
            write_filename: File name to write.(full path)
        """
        try:
            with open(write_filename, 'a', encoding='utf-8') as wf:
                for result in result_list:
                    wf.write(f"{result}\n")

        except Exception as e:
            print(e)


    def get_path_list(self, target_path, extension):
        """ Target directory list Method.

        Args:
            target_path: directory pull path.
            extension: target extension.

        Returns:
            Target Extension File List.
        """
        file_pull_list = list()
        try:
            dir_list = os.listdir(target_path)
            extension_list = [__ for __ in dir_list if __.endswith(extension)]

            for ex_file in extension_list:
                tmp = f'{target_path}/{ex_file}'
                file_pull_list.append(tmp)
            
            file_pull_list = (sorted(file_pull_list))

        except Exception as e:
            print(e)
            file_pull_list = list()

        return file_pull_list


