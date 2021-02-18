#!/usr/bin/env python
# -*- coding: utf-8 -*-
from functions_SIM import *
from functions_pycode_similar import *


def run_research(file_left, files_right, path, extension):
    if extension == "8086" or \
            extension == "c" or \
            extension == "cpp" or\
            extension == "java" or \
            extension == "pasc" or \
            extension == 'lsp' or \
            extension == 'mod' or \
            extension == 'm2' or \
            extension == 'def' or \
            extension == 'mi' or \
            extension == 'md':
        result_full = sim_cosmetic(sim_run(file_left, files_right, path, extension), path, file_left, files_right, 0)
        result_brief = sim_cosmetic(sim_run(file_left, files_right, path, extension), path, file_left, files_right, 1)
        result = {
            'result_full': result_full,
            'result_brief': result_brief
        }
        return result
    elif extension == "py":
        result = pycode_similar_run(file_left, files_right, path)
        if result != 0:
            result_full = pycode_similar_cosmetic(file_left, files_right, path, result, 0)
            result_brief = pycode_similar_cosmetic(file_left, files_right, path, result, 1)
            if not result_full:
                result = 'Не удалось обработать вывод pycode_similar'
            else:
                result = {
                    'result_full': result_full,
                    'result_brief': result_brief
                }
        else:
            result = "Есть синтаксические ошибки в одном или более файлах"
        return result
