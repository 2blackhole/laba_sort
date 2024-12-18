from utils import *
import matplotlib.pyplot as plt
import numpy as np

running_mode = 0

if running_mode == 0:
    o2_x_set = list(range(0, 100001, 20000))
    b_s_0 =  get_sort_data('bubble_sort', o2_x_set, 0)
    i_s_0 = get_sort_data('insertion_sort', o2_x_set, 0)
    s_s_0 = get_sort_data('selection_sort', o2_x_set, 0)

    plt.figure(figsize=(10, 8))
    plt.subplot(2, 2, 1)  # 2 rows, 2 columns, 1st subplot
    plt.plot(o2_x_set, b_s_0, marker='o')
    plt.title('bubble random')
    plt.xlabel('number of elements')
    plt.ylabel('time, s')

    plt.subplot(2, 2, 2)  # 2 rows, 2 columns, 2nd subplot
    plt.plot(o2_x_set, i_s_0 , marker='o', color='green')
    plt.title('insertion random')
    plt.xlabel('number of elements')
    plt.ylabel('time, s')

    plt.subplot(2, 2, 3)  # 2 rows, 2 columns, 3rd subplot
    plt.plot(o2_x_set, s_s_0, marker='o', color = 'red')
    plt.title('selection random')
    plt.xlabel('number of elements')
    plt.ylabel('time, s')
    plt.show()


elif running_mode == 1:
    ologn_set = list(range(0, 1000000001, 100000000))
    m_s_0 = get_sort_data('merge_sort', ologn_set, 0)
    q_s_0 = get_sort_data('quick_sort', ologn_set, 0)

    #o log n sort

    plt.figure(figsize=(10, 8))
    plt.subplot(2, 2, 1)  # 2 rows, 2 columns, 3rd subplot
    plt.plot(ologn_set, m_s_0, marker='o', color = 'cyan')
    plt.title('merge sort')
    plt.xlabel('number of elements')
    plt.ylabel('time, s')

    plt.subplot(2, 2, 2)  # 2 rows, 2 columns, 3rd subplot
    plt.plot(ologn_set, q_s_0, marker='o', color = 'cyan')
    plt.title('quick sort')
    plt.xlabel('number of elements')
    plt.ylabel('time, s')
    plt.show()

elif running_mode == 2:
    o_x_set = list(range(0, 2000000001, 400000000 ))
    c_s_0 = get_sort_data('counting_sort', o_x_set, 0)
    bucket_s_0 = get_sort_data('bucket_sort', o_x_set, 0)

    #linear sort

    plt.figure(figsize=(10, 8))
    plt.subplot(2, 2, 1)  # 2 rows, 2 columns, 3rd subplot
    plt.plot(o_x_set, c_s_0, marker='o', color = 'green')
    plt.title('counting sort')
    plt.xlabel('number of elements')
    plt.ylabel('time, s')

    plt.subplot(2, 2, 2)  # 2 rows, 2 columns, 3rd subplot
    plt.plot(o_x_set, bucket_s_0, marker='o', color = 'cyan')
    plt.title('bucket sort')
    plt.xlabel('number of elements')
    plt.ylabel('time, s')
    plt.show()








