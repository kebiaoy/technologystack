# coding:utf-8
from flask import Flask, render_template
import Common
from gevent import pywsgi

app = Flask(__name__, static_url_path="", static_folder=Common.get_coverage_site(),
            template_folder=Common.get_coverage_site())


@app.route('/')
def index():
    return render_template('index.html')


if __name__ == '__main__':
    server = pywsgi.WSGIServer(('0.0.0.0', 8080), app)
    server.serve_forever()
