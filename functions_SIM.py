#!/usr/bin/env python
# -*- coding: utf-8 -*-
from functions import *


def sim_run(file_left, files_right, path, extension):
    sim_name = get_sim_name(extension)
    sim_return = ''
    args_program_and_first_file = sim_name + ' ' + path + '/' + file_left + ' '
    for file in files_right:
        args = args_program_and_first_file + path + '/' + file
        sim_return += str(subprocess.check_output(args)) + '\\r\\n\\r\\n'
    return sim_return


def sim_cosmetic(sim_return, path, file_left, files_right, type_view):

    mass_colors = ['red', 'fuchsia', 'green', 'blue', 'yellow', 'lime', 'maroon',
                   'aqua', 'navy', 'purple', 'teal', 'olive', 'silver', 'black']
    i = -1
    result_left = []
    result_right = []
    clone_percent = 0
    prev_filename = None
    prev_clone_lines_left = None
    prev_clone_lines_right = None
    list_prev_clone_lines_left = []
    list_prev_clone_lines_right = []
    # Убираем путь до файла
    return_list = str(sim_return).replace(path + "/", "")
    # Получаем список обзацев
    return_list = str(return_list).split("\\r\\n\\r\\n")
    info_about_research = str(return_list.pop(0).replace('b"', '')).split("\\r\\n")
    return_list = delete_excess_paragraphs(file_left, return_list)
    return_list = sort_paragraphs_by_lines(return_list)

    # ------------------------------- Краткий вывод -------------------------------

    if type_view:
        for paragraph in return_list:
            # Получаем список строк
            list_strings = str(paragraph).split("\\r\\n")
            # Получаем имена файлов, указанные в абзаце
            first_line = list_strings[0].split("|")
            if len(first_line) == 2:
                first_line_paragraph_left = first_line[0]
                first_line_paragraph_right = first_line[1]
                left_filename = first_line_paragraph_left.split(":")[0]
                right_filename = first_line_paragraph_right.split(":")[0]
                if len(list_prev_clone_lines_left) and len(files_right) != 1:
                    color = check_color(right_filename, list_prev_clone_lines_left)
                    if not color:
                        i += 1
                        color = mass_colors[i % 14]
                else:
                    i += 1
                    color = mass_colors[i % 14]
                before_left_text = "<strong><font color='" + color + "'>"
                before_right_text = "<strong><font color='" + color + "'>"
                left_text = []
                right_text = []
                for element in list_strings:
                    element = str(element).split("|")
                    if len(element) == 2:
                        left_text.append(element[0])
                        right_text.append(element[1])
                after_left_text = "</font></strong>"
                after_right_text = "</font></strong>"
                result_left.append({
                    'before': before_left_text,
                    'text': left_text,
                    'after': after_left_text
                })
                result_right.append({
                    'before': before_right_text,
                    'text': right_text,
                    'after': after_right_text
                })
                prev_clone_lines_left = {
                    'color': color,
                    'filename': right_filename
                }
                list_prev_clone_lines_left.append(prev_clone_lines_left)

    # ------------------------------- Полный вывод исследования 1 с 1 -------------------------------

    else:
        if len(files_right) == 1:
            file_right = files_right[0]
            hfile_left = open(path + "\\" + file_left, 'r')
            hfile_right = open(path + "\\" + file_right, 'r')
            file_left_data = hfile_left.readlines()
            file_left_data = line_numbering(file_left_data)
            file_left_data = get_lists_lines(file_left_data)
            file_right_data = line_numbering(hfile_right.readlines())
            file_right_data = get_lists_lines(file_right_data)
            print(file_right_data)
            for paragraph in return_list:
                i += 1
                color = mass_colors[i % 14]
                # Получаем список строк обзаца
                strings = str(paragraph).split("\\r\\n")
                # Получаем первые строки левой и второй части
                first_strings = str(strings[0]).split("|")
                if str(first_strings).find(file_left) != -1 and str(first_strings).find(file_right) != -1:
                    # Получаем номера строк из левого файла и правого
                    lines_file_left = str(first_strings[0]).split(" ")[2]
                    lines_file_right = str(first_strings[1]).split(" ")[2]
                    # Получаем имя правого файла
                    right_filename = first_strings[1].split(":")[0]
                    # Получаем начальную строку плагиата и конечную
                    lines_left = str(lines_file_left).split("-")
                    lines_right =  str(lines_file_right).split("-")
                    start_line_file_left = lines_left[0]
                    end_line_file_left = lines_left[1]
                    start_line_file_right = lines_right[0]
                    end_line_file_right = lines_right[1].split("[")[0]
                    # Устанавливаем цвет полученных строк
                    set_color(file_left_data, start_line_file_left, end_line_file_left, [prev_clone_lines_left], color)
                    set_color(file_right_data, start_line_file_right, end_line_file_right, [prev_clone_lines_right], color)

                    prev_clone_lines_left = {
                        'start': start_line_file_left,
                        'end': end_line_file_left
                    }
                    prev_clone_lines_right = {
                        'start': start_line_file_right,
                        'end': end_line_file_right
                    }
                    list_prev_clone_lines_left.append(prev_clone_lines_left)

        # ------------------------------- Полный вывод исследования 1 с многими -------------------------------

        else:
            hfile_left = open(path + "\\" + file_left, 'r')
            file_left_data = line_numbering(hfile_left.readlines())
            file_left_data = get_lists_lines(file_left_data)
            file_right_data = []
            for paragraph in return_list:
                # Получаем список строк абзаца
                strings = str(paragraph).split("\\r\\n")
                # Получаем первые строки левой и второй части
                first_strings = str(strings[0]).split("|")
                # Получаем номера строк из левого файла
                lines_file_left = str(first_strings[0]).split(" ")[2]
                # Получаем начальную строку плагиата и конечную
                lines_left = str(lines_file_left).split("-")
                start_line_file_left = lines_left[0]
                end_line_file_left = lines_left[1]
                # Получаем имя правого файла
                right_filename = first_strings[1].split(":")[0]
                # Выбираем цвет
                if len(list_prev_clone_lines_left):
                    color = check_color(right_filename, list_prev_clone_lines_left)
                    if not color:
                        i += 1
                        color = mass_colors[i % 14]
                else:
                    i += 1
                    color = mass_colors[i % 14]
                # Устанавливаем цвет полученных строк
                set_color(file_left_data, start_line_file_left, end_line_file_left, list_prev_clone_lines_left, color)

                before_data = "<strong><font color='" + color + "'>"
                text = []
                for string in strings:
                    string = str(string).split("|")
                    text.append(string[1])
                after_data = "</font></strong>"
                file_right_data.append({
                    'before': before_data,
                    'text': text,
                    'after': after_data
                })
                prev_clone_lines_left = {
                    'start': start_line_file_left,
                    'end': end_line_file_left,
                    'color': color,
                    'filename': right_filename
                }
                list_prev_clone_lines_left.append(prev_clone_lines_left)
        clone_percent = calculate_percent(file_left_data, list_prev_clone_lines_left)
        result_left = file_left_data
        result_right = file_right_data
    result = {
        'result_left': result_left,
        'result_right': result_right,
        'info': info_about_research,
        'percent': round(clone_percent, 2)
    }
    return result