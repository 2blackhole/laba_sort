import re
import subprocess
import matplotlib as plt
import numpy as np
from packaging.version import parse

exe_path = 'cmake-build-release/laba_sort.exe'

def parse_string_to_dict(input_string):
    pattern = r'(\w+)\s*:\s*([\w\d.-]+)'
    matches = re.findall(pattern, input_string)
    result_dict = {key: value for key, value in matches}
    return result_dict

def run_process(exe_file, params):
    try:
        result = subprocess.run([exe_file] + params, capture_output=True, text=True, check=True)
        output = result.stdout
        return output
    except subprocess.CalledProcessError as e:
        error = e.stderr
        return error


def get_sort_data(sort, x_set, mode):
    y = list()
    print('data parsing : ', sort, '\n')
    for i in x_set:
        params = [sort, str(i), str(mode), '0']
        output = run_process(exe_path, params)
        data = parse_string_to_dict(output)
        print(i / max(x_set) * 100, '%\n')
        y.append(float(data['time']))
    return y

