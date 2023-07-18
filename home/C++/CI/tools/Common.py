import os

current_work_dir = os.path.dirname(__file__)


def get_generate_path():
    gen_path = os.path.join("C:/CiGenerate")
    if not os.path.isdir(gen_path):
        os.makedirs(gen_path)
    return gen_path


def get_coverage_site():
    return os.path.join(get_generate_path(), "coverageSite")
