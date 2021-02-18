from flask import Flask, render_template, url_for, redirect, request, make_response, session
from functions import *
from run_research import run_research
from werkzeug.utils import secure_filename
from os.path import isdir, exists
from os import mkdir, urandom, remove
import random
from cyrtranslit import to_latin

app = Flask(__name__)


@app.route("/")
def index():
    if not ('error' in session):
        session['error'] = ""
    if not ('path' in session):
        tmp_hash = random.getrandbits(64)
        path_to_dir = "static/" + str(tmp_hash)
        session['path'] = path_to_dir
        mkdir(session['path'])
        if exists(session['path']):
            return render_template("index.html", files=sort_listdir(my_listdir(session['path'])), error=session['error'])
    else:
        return render_template("index.html", files=sort_listdir(my_listdir(session['path'])), error=session['error'])
    return render_template("index.html", files="Не удалось создать директорию для загрузки файлов", error=session['error'])


@app.route('/upload_or_delete_files', methods=["POST", "GET"])
def upload_or_delete_files():
    if not ('path' in session):
        session['error'] = "Что-то пошло не так. Попробуйте снова"
        return redirect("/")

    if request.method == 'POST':
        if request.form['button'] == "Загрузить":
            if not exists(session['path']):
                mkdir(session['path'])
            files = request.files.getlist('files[]')
            if not files[0].filename:
                session['error'] = "Не выбраны файлы для загрузки"
                return redirect('/')
            for file in files:
                file.filename = to_latin(file.filename, 'ru')
                file.filename = '.'.join([file.filename.split('.')[0], file.filename.split('.')[-1].lower()])
                print(file)
                if not check_extension(file.filename):
                    session['error'] = 'Один из файлов имеет неразрешенное расширение'
                    return redirect('/')
                file.save(session['path'] + "/" + secure_filename(file.filename))
            session['error'] = ''
            return redirect("/")
        elif request.form['button'] == "Удалить все":
            session['error'] = ''
            if session['path']:
                files = listdir(session['path'])
                for file in files:
                    remove(session['path'] + '\\' + file)
            return redirect('/')
        elif request.form['button'] == "Удалить выбранные":
            files = request.form.getlist("files")
            for file in files:
                remove(session['path'] + '\\' + file)
            return redirect('/')
        else:
            return redirect("error.html")
    else:
        pass


@app.route('/upload_dir', methods=["POST", "GET"])
def upload_dir():
    pass


@app.route('/goto_research', methods=["POST"])
def goto_research():
    # session['language'] = request.form.get('language')
    if len(listdir(session['path'])) < 2:
        session['error'] = "Недостаточно файлов для исследования"
        return redirect("/")
    # if not my_listdir_with_extension(session['path'], get_extension_files(session['language'])):
    #     session['error'] = "Не найдены файлы, соответствующие заданному языку"
    #     return redirect("/")
    session['error'] = ''
    return redirect('/research_files')


@app.route('/research_files', methods=["POST", "GET"])
def research_files():

    # --------------------------- для тестирования ---------------------------
    # session['path'] = "static/15867449305234218138"
    # session['language'] = "Python"
    # session['error'] = ""
    # ------------------------------------------------------------------------

    if not ('path' in session):
        return redirect("error.html")
    if len(my_listdir(session['path'])) < 2:
        session['error'] = 'Недостаточно файлов для исследования'
        return redirect('/')
    if request.method == 'POST':
        # Получаем файлы в папке с нужным расширением
        files = sort_listdir(my_listdir(session['path']))
        # Получаем выбранный файл в левом селекте
        file_left = request.form.get('file_left')
        # Получаем список выбранных файлов в правом селекте
        files_right = request.form.getlist('files_right')
        # Получаем расширение файлов
        extension = get_extension_files(file_left, files_right)
        # Запоминаем выделенные файлы
        highlights = highlight_select_files(file_left, files_right, files)
        out = "Выберите файлы для исследования"
        session['error'] = get_error_choice_files(file_left, files_right)
        if not session['error']:
            out = run_research(file_left, files_right, session['path'], extension)

        return render_template("research.html",
                               files=files,
                               out=out,
                               error=session['error'],
                               highlights=highlights)
    else:
        files = sort_listdir(my_listdir(session['path']))
        highlights = {
            'left': [0 for i in range(len(files))],
            'right': [0 for i in range(len(files))]
        }
        out = "Выберите файлы для исследования"
        return render_template("research.html",
                               files=files,
                               out=out,
                               error=session['error'],
                               highlights=highlights)


@app.route('/error.html')
def error():
    return render_template('error.html')


if __name__ == "__main__":
    app.config['MAX_CONTENT_LENGTH'] = 5 * 1024 * 1024
    app.secret_key = urandom(24)
    app.run(debug=True)
