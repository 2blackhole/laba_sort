from utils import *
import matplotlib.pyplot as plt
import math


print('Input, which sorts you want to see')
print('0 : bubble sort, insert sort, selection sort')
print('1 : merge sort, quick sort')
print('2 : counting sort, bucket sort, radix sort')

running_mode = int(input())

if not running_mode in [0, 1, 2]:
    exit()

print('Load existed data or create new?')
print('Y / N')
data_load = input()
data_load = 0 if data_load in ['N', 'n'] else 1 if data_load in ['Y', 'y'] else exit()


if running_mode == 0:
    b_s_0 = list()
    b_s_1 = list()
    b_s_2 = list()
    i_s_0 = list()
    i_s_1 = list()
    i_s_2 = list()
    s_s_0 = list()
    s_s_1 = list()
    s_s_2 = list()



    if not data_load:
        sorts = list()

        b_s_0 =  get_sort_data('bubble_sort', o2_x_set, 0)
        sorts.append(b_s_0)

        b_s_1 =  get_sort_data('bubble_sort', o2_x_set, 1)
        sorts.append(b_s_1)

        b_s_2 =  get_sort_data('bubble_sort', o2_x_set, 2)
        sorts.append(b_s_2)


        i_s_0 = get_sort_data('insertion_sort', o2_x_set, 0)
        sorts.append(i_s_0)

        i_s_1 = get_sort_data('insertion_sort', o2_x_set, 1)
        sorts.append(i_s_1)

        i_s_2 = get_sort_data('insertion_sort', o2_x_set, 2)
        sorts.append(i_s_2)


        s_s_0 = get_sort_data('selection_sort', o2_x_set, 0)
        sorts.append(s_s_0)

        s_s_1 = get_sort_data('selection_sort', o2_x_set, 1)
        sorts.append(s_s_1)

        s_s_2 = get_sort_data('selection_sort', o2_x_set, 2)
        sorts.append(s_s_2)

        with open(f'data/o2.csv','w+') as file:
            for dv in sorts:
                for i in dv:
                    file.write(str(i))
                    file.write(' ')
                file.write('\n')
    else:
        with open(f'data/o2.csv','r') as file:
            j = 0
            for line in file:
                if j == 0:
                    for i in line.split(' '):
                        if i != '\n':
                            b_s_0.append(float(i))
                elif j == 1:
                    for i in line.split(' '):
                        if i != '\n':
                            b_s_1.append(float(i))
                elif j == 2:
                    for i in line.split(' '):
                        if i != '\n':
                            b_s_2.append(float(i))
                elif j == 3:
                    for i in line.split(' '):
                        if i != '\n':

                            i_s_0.append(float(i))
                elif j == 4:
                    for i in line.split(' '):
                        if i != '\n':

                            i_s_1.append(float(i))
                elif j == 5:
                    for i in line.split(' '):
                        if i != '\n':

                            i_s_2.append(float(i))
                elif j == 6:
                    for i in line.split(' '):
                        if i != '\n':

                            s_s_0.append(float(i))
                elif j == 7:
                    for i in line.split(' '):
                        if i != '\n':

                            s_s_1.append(float(i))
                elif j == 8:
                    for i in line.split(' '):
                        if i != '\n':

                            s_s_2.append(float(i))
                j += 1

    b_s_const = list()
    index = 0
    for i in o2_x_set:
        b_s_const.append(float(b_s_0[index]) / (i ** 2 if i != 0 else 1))
        index += 1

    i_s_const = list()
    index = 0
    for i in o2_x_set:
        i_s_const.append(float(i_s_0[index]) / (i ** 2 if i != 0 else 1))
        index += 1

    s_s_const = list()
    index = 0
    for i in o2_x_set:
        s_s_const.append(float(s_s_0[index]) / (i ** 2 if i != 0 else 1))
        index += 1

    fig, (ax1, ax2) = plt.subplots(ncols = 1, nrows=2)
    ax1.plot(o2_x_set, b_s_0, label='bubble random', linestyle='-', color='cyan')
    ax1.plot(o2_x_set, b_s_1, label='bubble sorted', linestyle='--', color='cyan')
    ax1.plot(o2_x_set, b_s_2, label='bubble inverted', linestyle=':', color='cyan')
    ax1.plot(o2_x_set, i_s_0, label='insertion random', linestyle='-', color='green')
    ax1.plot(o2_x_set, i_s_1, label='insertion sorted', linestyle='--', color='green')
    ax1.plot(o2_x_set, i_s_2, label='insertion inverted', linestyle=':', color='green')
    ax1.plot(o2_x_set, s_s_0, label='selection random', linestyle='-', color='red')
    ax1.plot(o2_x_set, s_s_1, label='selection sorted', linestyle='--', color='red')
    ax1.plot(o2_x_set, s_s_2, label='selection inverted', linestyle=':', color='red')
    ax1.grid(True)
    ax1.set_xlabel('number of elements, int')
    ax1.set_ylabel('time, s')
    ax1.set_title('Квадратичные сортировки')
    ax1.legend()


    ax2.plot(o2_x_set, b_s_const, label='bubble', linestyle='-', color='cyan')
    ax2.plot(o2_x_set, i_s_const, label='insertion', linestyle='-', color='green')
    ax2.plot(o2_x_set, s_s_const, label='selection', linestyle='-', color='red')
    ax2.grid(True)
    ax2.set_xlabel('number of elements, int')
    ax2.set_ylabel('time, s')
    ax2.set_title('Квадратичные сортировки - константа')
    ax2.legend()

    plt.show()


elif running_mode == 1:
    m_s_0 = list()
    m_s_1 = list()
    m_s_2 = list()
    q_s_0 = list()
    q_s_1 = list()
    q_s_2 = list()

    if not data_load:
        sorts = list()

        m_s_0 =  get_sort_data('merge_sort', ologn_x_set, 0)
        sorts.append(m_s_0)

        m_s_1 =  get_sort_data('merge_sort', ologn_x_set, 1)
        sorts.append(m_s_1)

        m_s_2 =  get_sort_data('merge_sort', ologn_x_set, 2)
        sorts.append(m_s_2)


        q_s_0 = get_sort_data('quick_sort', ologn_x_set, 0)
        sorts.append(q_s_0)

        q_s_1 = get_sort_data('quick_sort', ologn_x_set, 1)
        sorts.append(q_s_1)

        q_s_2 = get_sort_data('quick_sort', ologn_x_set, 2)
        sorts.append(q_s_2)

        with open(f'data/ologn.csv','w+') as file:
            for dv in sorts:
                for i in dv:
                    file.write(str(i))
                    file.write(' ')
                file.write('\n')
    else:
        with open(f'data/ologn.csv','r') as file:
            j = 0
            for line in file:
                if j == 0:
                    for i in line.split(' '):
                        if i != '\n':
                            m_s_0.append(float(i))
                elif j == 1:
                    for i in line.split(' '):
                        if i != '\n':
                            m_s_1.append(float(i))
                elif j == 2:
                    for i in line.split(' '):
                        if i != '\n':
                            m_s_2.append(float(i))
                elif j == 3:
                    for i in line.split(' '):
                        if i != '\n':
                            q_s_0.append(float(i))
                elif j == 4:
                    for i in line.split(' '):
                        if i != '\n':
                            q_s_1.append(float(i))
                elif j == 5:
                    for i in line.split(' '):
                        if i != '\n':
                            q_s_2.append(float(i))
                j += 1

    m_s_const = list()
    index = 0
    for i in ologn_x_set:
        m_s_const.append(float(m_s_0[index]) / (i * math.log2(i) if i != 0 else 1))
        index += 1

    q_s_const = list()
    index = 0
    for i in ologn_x_set:
        q_s_const.append(float(q_s_0[index]) / (i * math.log2(i) if i != 0 else 1))
        index += 1

    fig, (ax1, ax2) = plt.subplots(ncols = 1, nrows=2)
    ax1.plot(ologn_x_set, m_s_0, label='merge random', linestyle='-', color='cyan')
    ax1.plot(ologn_x_set, m_s_1, label='merge sorted', linestyle='--', color='cyan')
    ax1.plot(ologn_x_set, m_s_2, label='merge inverted', linestyle=':', color='cyan')
    ax1.plot(ologn_x_set, q_s_0, label='quick random', linestyle='-', color='green')
    ax1.plot(ologn_x_set, q_s_1, label='quick sorted', linestyle='--', color='green')
    ax1.plot(ologn_x_set, q_s_2, label='quick inverted', linestyle=':', color='green')
    ax1.grid(True)
    ax1.set_xlabel('number of elements, int')
    ax1.set_ylabel('time, s')
    ax1.set_title('Сортировки за n log n')
    ax1.legend()


    ax2.plot(ologn_x_set, m_s_const, label='merge', linestyle='-', color='cyan')
    ax2.plot(ologn_x_set, q_s_const, label='quick', linestyle='-', color='green')
    ax2.grid(True)
    ax2.set_xlabel('number of elements, int')
    ax2.set_ylabel('time, s')
    ax2.set_title('Сортировки за n log n - константа')
    ax2.legend()
    plt.show()

elif running_mode == 2:
    c_s_0 = list()
    c_s_1 = list()
    c_s_2 = list()
    bucket_s_0 = list()
    bucket_s_1 = list()
    bucket_s_2 = list()
    r_s_0 = list()
    r_s_1 = list()
    r_s_2 = list()



    if not data_load:
        sorts = list()

        c_s_0 =  get_sort_data('counting_sort', o_x_set, 0)
        sorts.append(c_s_0)

        c_s_1 =  get_sort_data('counting_sort', o_x_set, 1)
        sorts.append(c_s_1)

        c_s_2 =  get_sort_data('counting_sort', o_x_set, 2)
        sorts.append(c_s_2)


        bucket_s_0 = get_sort_data('bucket_sort', o_x_set, 0)
        sorts.append(bucket_s_0)

        bucket_s_1 = get_sort_data('bucket_sort', o_x_set, 1)
        sorts.append(bucket_s_1)

        bucket_s_2 = get_sort_data('bucket_sort', o_x_set, 2)
        sorts.append(bucket_s_2)


        r_s_0 = get_sort_data('radix_sort', o_x_set, 0)
        sorts.append(r_s_0)

        r_s_1 = get_sort_data('radix_sort', o_x_set, 1)
        sorts.append(r_s_1)

        r_s_2 = get_sort_data('radix_sort', o_x_set, 2)
        sorts.append(r_s_2)

        with open(f'data/on.csv','w+') as file:
            for dv in sorts:
                for i in dv:
                    file.write(str(i))
                    file.write(' ')
                file.write('\n')
    else:
        with open(f'data/on.csv','r') as file:
            j = 0
            for line in file:
                if j == 0:
                    for i in line.split(' '):
                        if i != '\n':
                            c_s_0.append(float(i))
                elif j == 1:
                    for i in line.split(' '):
                        if i != '\n':
                            c_s_1.append(float(i))
                elif j == 2:
                    for i in line.split(' '):
                        if i != '\n':
                            c_s_2.append(float(i))
                elif j == 3:
                    for i in line.split(' '):
                        if i != '\n':

                            bucket_s_0.append(float(i))
                elif j == 4:
                    for i in line.split(' '):
                        if i != '\n':

                            bucket_s_1.append(float(i))
                elif j == 5:
                    for i in line.split(' '):
                        if i != '\n':

                            bucket_s_2.append(float(i))
                elif j == 6:
                    for i in line.split(' '):
                        if i != '\n':

                            r_s_0.append(float(i))
                elif j == 7:
                    for i in line.split(' '):
                        if i != '\n':

                            r_s_1.append(float(i))
                elif j == 8:
                    for i in line.split(' '):
                        if i != '\n':

                            r_s_2.append(float(i))
                j += 1

    c_s_const = list()
    index = 0
    for i in o_x_set:
        c_s_const.append(float(c_s_0[index]) / (i if i != 0 else 1))
        index += 1

    bucket_s_const = list()
    index = 0
    for i in o_x_set:
        bucket_s_const.append(float(bucket_s_0[index]) / (i if i != 0 else 1))
        index += 1

    r_s_const = list()
    index = 0
    for i in o_x_set:
        r_s_const.append(float(r_s_0[index]) / (i if i != 0 else 1))
        index += 1

    fig, (ax1, ax2) = plt.subplots(ncols = 1, nrows=2)
    ax1.plot(o_x_set, c_s_0, label='counting random', linestyle='-', color='cyan')
    ax1.plot(o_x_set, c_s_1, label='counting sorted', linestyle='--', color='cyan')
    ax1.plot(o_x_set, c_s_2, label='counting inverted', linestyle=':', color='cyan')
    ax1.plot(o_x_set, bucket_s_0, label='bucket random', linestyle='-', color='green')
    ax1.plot(o_x_set, bucket_s_1, label='bucket sorted', linestyle='--', color='green')
    ax1.plot(o_x_set, bucket_s_2, label='bucket inverted', linestyle=':', color='green')
    ax1.plot(o_x_set, r_s_0, label='radix random', linestyle='-', color='red')
    ax1.plot(o_x_set, r_s_1, label='radix sorted', linestyle='--', color='red')
    ax1.plot(o_x_set, r_s_2, label='radix inverted', linestyle=':', color='red')
    ax1.grid(True)
    ax1.set_xlabel('number of elements, int')
    ax1.set_ylabel('time, s')
    ax1.set_title('Линейные сортировки')
    ax1.legend()


    ax2.plot(o_x_set, c_s_const, label='counting', linestyle='--', color='cyan')
    ax2.plot(o_x_set, bucket_s_const, label='bucket', linestyle='-', color='green')
    ax2.plot(o_x_set, r_s_const, label='radix', linestyle='--', color='red')
    ax2.grid(True)
    ax2.set_xlabel('number of elements, int')
    ax2.set_ylabel('time, s')
    ax2.set_title('Линейные сортировки - константа')
    ax2.legend()

    plt.show()










