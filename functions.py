from os import listdir
import re
import subprocess

def my_listdir(path):
    list_dir = listdir(path)
    res = []
    if list_dir:
        for element in list_dir:
            res.append(element)
    return res


def sort_listdir(files):
    res = []
    split_names = []
    for file in files:
        split_names.append(file.split('.'))
    for i in range(len(split_names)):
        for j in range(len(split_names)):
            if len(split_names[j]) > 2:
                return None
            if split_names[i][-1].lower() < split_names[j][-1].lower():
                tmp = split_names[i]
                split_names[i] = split_names[j]
                split_names[j] = tmp
    for element in split_names:
        res.append(".".join(element))
    return res


def check_extension(filename):
    extensions = ['c', 'h', 'cpp', 'py', 'java', 'asm',
                  'pasc', 'lsp', 'mod', 'm2', 'def', 'mi', 'md']
    file_extension = filename.split('.')[-1]
    for extension in extensions:
        if extension == file_extension:
            return True
    return False


def get_sim_name(extension):
    res = "sim/sim_"
    extension.lower()
    if extension == "cpp" or extension == 'h':
        res += "c++"
    elif extension == "asm":
        res += '8086'
    elif extension == 'lsp':
        res += 'lisp'
    elif extension == 'mod' or extension == 'm2' or extension == 'def' or extension == 'mi' or extension == 'md':
        res += 'm2'
    else:
        res += extension
    res += ".exe"
    return res


def my_listdir_with_extension(path, extension):
    list_dir = my_listdir(path)
    res = []
    if list_dir:
        for element in list_dir:
            if re.search(str(extension), element):
                res.append(element)
    if not res:
        res = None
    return res


def calculate_percent(file_data, list_clone_lines):
    pieces = []
    i = 0
    start_of_a_piece = 0
    end_of_a_piece = 0
    while i < len(list_clone_lines):
        if int(start_of_a_piece) <= int(list_clone_lines[i]['start']) <= int(end_of_a_piece):
            if int(list_clone_lines[i]['start']) < int(start_of_a_piece):
                start_of_a_piece = list_clone_lines[i]['start']
            if int(list_clone_lines[i]['end']) > int(end_of_a_piece):
                end_of_a_piece = list_clone_lines[i]['end']
        elif not start_of_a_piece and not end_of_a_piece:
            start_of_a_piece = list_clone_lines[i]['start']
            end_of_a_piece = list_clone_lines[i]['end']
        else:
            pieces.append({
                'start': start_of_a_piece,
                'end': end_of_a_piece
            })
            start_of_a_piece = 0
            end_of_a_piece = 0
        i += 1
    else:
        pieces.append({
            'start': start_of_a_piece,
            'end': end_of_a_piece
        })
    clone_percent = 0
    for piece in pieces:
        clone_percent += (int(piece['end']) - int(piece['start'])) * 100 / len(file_data)
    return clone_percent



def set_color(file_data, start_line, end_line, list_prev_clone_lines, color):
    div = "<div style='border-left: 4px solid " + color + "; padding-left: 10px; margin-left: 5px'>"
    list_clones = list_prev_clone_lines.copy()
    list_clones.reverse()

    file_data[int(start_line) - 1]['before'] += div
    file_data[int(end_line) - 1]['after'] += '</div>'
    for prev_clone_lines in list_clones:
        if prev_clone_lines:
            if int(prev_clone_lines['start']) <= int(start_line) <= int(prev_clone_lines['end']):
                if int(prev_clone_lines['end']) < int(end_line):
                    file_data[int(prev_clone_lines['end']) - 1]['after'] += "</div>" + div


def check_color(filename, list_prev_clone_lines):
    result = None
    for element in list_prev_clone_lines:
        if filename == element['filename']:
            result = element['color']
    return result



def get_lists_lines(file_data):
    result = []
    for line in file_data:
        result.append({
            'before': '',
            'text': [line],
            'after': ''
        })
    return result


def delete_excess_paragraphs(file_left, paragraphs):
    result = []
    for paragraph in paragraphs:
        # Получаем список строк абзаца
        strings = str(paragraph).split("\\r\\n")
        first_string = strings[0].split('|')
        left_first_string = first_string[0]
        if str(left_first_string).find(file_left) != -1 and len(first_string) == 2:
            right_first_string = first_string[1]
            left_filename = left_first_string.split(":")[0]
            right_filename = right_first_string.split(":")[0]
            if left_filename != right_filename:
                result.append(paragraph)
    return result


def sort_paragraphs_by_lines(paragraphs):
    start_lines = []
    for paragraph in paragraphs:
        # Получаем список строк абзаца
        strings = str(paragraph).split("\\r\\n")
        # Получаем первые строки левой и второй части
        first_strings = str(strings[0]).split("|")
        # Получаем номера строк из левого файла
        lines_file_left = str(first_strings[0]).split(" ")[2]
        # Получаем начальную строку плагиата и конечную
        lines_left = str(lines_file_left).split("-")
        start_line_file_left = lines_left[0]
        start_lines.append(start_line_file_left)
    for i in range(len(start_lines)):
        for j in range(len(start_lines)):
            if int(start_lines[i]) < int(start_lines[j]):
                tmp = paragraphs[i]
                paragraphs[i] = paragraphs[j]
                paragraphs[j] = tmp

                tmp = start_lines[i]
                start_lines[i] = start_lines[j]
                start_lines[j] = tmp
    return paragraphs


def line_numbering(data):
    i = 1
    for element in data:
        data[i - 1] = str(i) + ". " + element.expandtabs(4)
        i += 1
    return data


def get_error_choice_files(file_left, files_right):
    error = ''
    if not file_left or not files_right:
        error = "Не выбраны файлы для исследования"
    else:
        for file_right in files_right:
            if file_left == file_right:
                error = "Выбраны одинаковые файлы для исследования"
    if not get_extension_files(file_left, files_right):
        error = 'Выбраны файлы с разным расширением'
    return error


def get_function_by_name(name, functions_info):
    for element in functions_info:
        if element['name'] == name:
            return element
    return 0


def get_functions_from_python_file(file_data):
    file_functions = []
    class_info = []
    defs = []
    spaces_to_def = []
    defs_count = 0
    i = 0
    while i < len(file_data):
        while class_info and str(file_data[i]).find(' ' * (class_info[-1]['spaces'] + 1)) != 0 and not file_data[i].isspace():
            class_info.pop()
        is_class = str(file_data[i]).lstrip().find('class ')
        if is_class == 0:
            class_name = str(file_data[i]).lstrip().split(' ')[1].split(':')[0]
            if class_name.find('('):
                class_name = class_name.split('(')[0]
            class_name += '.'
            class_info.append({
                'name': class_name,
                'spaces': str(file_data[i]).find('class ')
            })
        else:
            is_def = str(file_data[i]).lstrip().find('def ')
            if is_def == 0:
                def_name = str(file_data[i]).partition('def ')[2].split("(")[0]
                spaces_to_def.append(str(file_data[i]).find('def '))
                str_class = ''
                for el in class_info:
                    str_class += el['name']
                def_info = {
                    'name': str_class + def_name,
                    'text': [],
                    'start_index': i
                }
                def_info['text'].append(file_data[i])
                defs.append(def_info)
                i += 1
                while True:
                    if not len(defs):
                        break
                    if i < len(file_data) and (file_data[i].isspace() or file_data[i].find(' ' * (spaces_to_def[-1] + 1)) == 0):
                        is_def = str(file_data[i]).lstrip().find('def ')
                        if is_def == 0:
                            def_name = str(file_data[i]).partition('def ')[2].split("(")[0]
                            spaces_to_def.append(str(file_data[i]).find('def '))
                            def_info = {
                                'name': str_class + def_name,
                                'text': [],
                                'start_index': i
                            }
                            defs.append(def_info)
                        for element in defs:
                            element['text'].append(file_data[i])
                        i += 1
                    else:
                        spaces_to_def.pop()
                        file_functions.append(defs.pop())
                        if len(defs) and i < len(file_data):
                            continue
                for element in defs:
                    file_functions.append(element)
                i -= 1
        i += 1
    return file_functions


def equalization_strings(left_result, rigth_result):
    len_left_text = 0
    len_right_text = 0
    for element in left_result:
        for string in element['text']:
            len_left_text += 1
    for element in rigth_result:
        for string in element['text']:
            len_right_text += 1
    while len_left_text != len_right_text:
        if len_left_text < len_right_text:
            len_left_text += 1
            left_result.append(get_obj_text('', '', ''))
        else:
            len_right_text += 1
            rigth_result.append(get_obj_text('', '', ''))



def get_obj_text(before_text, string, after_text):
    result = {
        'before': before_text,
        'text': [string],
        'after': after_text
    }
    return result


def get_extension_files(file_left, files_right):
    left_file_extension = file_left.split(".")[-1].lower()
    for file in files_right:
        # Если расширения не совпадают, то возращаем None
        right_file_extension = file.split('.')[-1].lower()
        if left_file_extension != right_file_extension:
            return None
    extension = file_left.split('.')[1]
    return extension


def highlight_select_files(file_left, files_right, listdir):
    highlight_left = []
    highlight_right = [0 for i in range(len(listdir))]
    for file in listdir:
        if file == file_left:
            highlight_left.append(1)
        else:
            highlight_left.append(0)
    for file, i in zip(listdir, range(len(highlight_right))):
        for file_right in files_right:
            if file == file_right:
                highlight_right[i] = 1
    result = {
        'left': highlight_left,
        'right': highlight_right
    }
    return result
