from functions import *

def pycode_similar_cosmetic(file_left, files_right, path, return_list, type_view):
    list_paragraphs = []
    result_left = []
    result_right = []
    info = []
    list_prev_clone_lines_left = []
    clone_percent = 0
    i = -1
    mass_colors = ['red', 'fuchsia', 'green', 'blue', 'yellow', 'lime', 'maroon',
                   'aqua', 'navy', 'purple', 'teal', 'olive', 'silver', 'black']
    hfile_left = open(path + "\\" + file_left, 'r')
    file_left_data = hfile_left.readlines()
    file_left_functions = get_functions_from_python_file(file_left_data)
    file_left_data = line_numbering(file_left_data)
    file_left_data = get_lists_lines(file_left_data)

    for element in return_list:
        paragraph = []
        # Убираем лишнее из результата pycode_similar и получаем список строк
        string_list = str(element).replace("b'ref: ", '').\
            replace(path + '/', '').\
            replace('\'', '').\
            split('\\r\\n')
        for string in string_list:
            paragraph.append(string)
        list_paragraphs.append(paragraph)
    for element, file in zip(list_paragraphs, files_right):
        if element[0].find("error: can not find functions") == -1:
            hfile = open(path + "\\" + file, 'r')
            file_functions = get_functions_from_python_file(hfile.readlines())
            # Попаем строку с именем левого файла
            element.pop(0)
            # Попаем строку с именем правого файла
            info.append(element.pop(0))
            # Попаем строки с информацией исследования
            info.append(element.pop(0))
            info.append(element.pop(0))
            info.append('')
            result_right.append(get_obj_text('<big>', file, '</big>'))
            result_left.append(get_obj_text('', '', ''))
            clones = []
            for clone_info in element:
                if clone_info.find(':') != -1:
                    # Получаем вероятность заимствования
                    probability = clone_info.partition(':')[0]
                    # Получаем название фукнции в левом файле
                    file_left_function_name = clone_info.partition(': ')[2].split(' ')[1].split('<')[0]
                    # Получаем название фукнции в правом файле
                    files_right_function_name = clone_info.partition(': ')[2].split(' ')[3].split('<')[0]
                    clone_function_info = {
                        'probability': probability,
                        'file_left_function_name': file_left_function_name,
                        'file_right_function_name': files_right_function_name
                    }
                    clones.append(clone_function_info)
            if type_view:
                if len(clones) < 1:
                    result_right.append(get_obj_text('', 'Ничего не найдено', ''))
                for clone in clones:
                    result_right.append(get_obj_text('', "Часть заимствованного кода: " + clone['probability'], ''))
                    equalization_strings(result_left, result_right)
                    i += 1
                    color = mass_colors[i % 14]
                    left_function_info = get_function_by_name(clone['file_left_function_name'], file_left_functions)
                    right_function_info = get_function_by_name(clone['file_right_function_name'], file_functions)
                    if not left_function_info or not right_function_info:
                        result_right.pop()
                        continue
                    left_text = []
                    right_text = []
                    before_text_left = "<strong><font color='" + color + "'>"
                    for string in left_function_info['text']:
                        left_text.append(string)
                    before_text_right = "<strong><font color='" + color + "'>"
                    for string in right_function_info['text']:
                        right_text.append(string)
                    after_text_right = '</font></strong>'
                    after_text_left = '</font></strong>'
                    result_right.append({
                        'before': before_text_right,
                        'text': right_text,
                        'after': after_text_right
                    })
                    result_left.append({
                        'before': before_text_left,
                        'text': left_text,
                        'after': after_text_left
                    })
            else:
                for clone in clones:
                    i += 1
                    color = mass_colors[i % 14]
                    left_function_info = get_function_by_name(clone['file_left_function_name'], file_left_functions)
                    right_function_info = get_function_by_name(clone['file_right_function_name'], file_functions)
                    if not left_function_info or not right_function_info:
                        continue
                    file_left_data[left_function_info['start_index']]['before'] += "<div style='border-left: 4px solid " + color + "; padding-left: 10px; margin-left: 5px'>"
                    file_left_data[left_function_info['start_index'] + len(left_function_info['text']) - 1]['after'] += '</div>'

                    before_text_right = "Часть заимствованного кода: " + clone['probability'] + "<br><strong><font color='" + color + "'>"
                    right_text = []
                    for string in right_function_info['text']:
                        right_text.append(string)
                    after_text_right = '</font></strong>'
                    result_right.append({
                        'before': before_text_right,
                        'text': right_text,
                        'after': after_text_right
                    })
                    prev_clone_lines_left = {
                        'start': left_function_info['start_index'],
                        'end': left_function_info['start_index'] + len(left_function_info['text'])
                    }
                    list_prev_clone_lines_left.append(prev_clone_lines_left)
                clone_percent = calculate_percent(file_left_data, list_prev_clone_lines_left)
                result_left = file_left_data
    result = {
        'result_left': result_left,
        'result_right': result_right,
        'info': info,
        'percent': round(clone_percent, 2)
    }
    return result


def pycode_similar_run(file_left, files_right, path):
    result = []
    args_program_and_first_file = 'python pycode_similar\\pycode_similar.py -p 0.1 ' + path + '/' + file_left + ' '
    for file in files_right:
        args = args_program_and_first_file + path + '/' + file
        try:
            result.append(subprocess.check_output(args))
        except subprocess.CalledProcessError:
            return 0
    return result