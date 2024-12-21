from utils import *

print('input sort name: ')
print('bubble_sort | insertion_sort | selection_sort | merge_sort | quick_sort | counting_sort | bucket_sort | radix_sort')
sort_name = str(input())
print('input number of elements')
n = str(input())
print('input type of array')
print('0 - random , 1 - sorted , 2 - sorted and inverted')
t = str(input())
print('Show array before and after sort? 0 or 1')
s = str(input())
params = [sort_name, n, t, s]
output = run_process(exe_path, params)
if output == '':
    print('sort doesn\'t exists')
print(output)
