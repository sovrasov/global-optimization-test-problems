import numpy as np
import json

def save_stats(cmc_curve, avg_calculations, filename, capture=None):
    if len(filename) == 0:
        return
    stats = {}
    stats['cmc_iters'] = list(cmc_curve[0])
    stats['cmc_vals'] = list(cmc_curve[1])
    stats['calc_counters'] = list(avg_calculations)
    if capture:
        stats['capture'] = capture

    with open(filename, 'w') as outfile:
        json.dump(stats, outfile)

def load_stats(filename):
    stats = {}
    with open(filename, 'r') as f:
        stats = json.load(f)
    return stats

def compute_stats(calc_stats, solved_status):
    assert len(calc_stats) == len(solved_status)

    num_solved = np.count_nonzero(solved_status)
    calc_stats = np.array(calc_stats)
    avg_calcs = np.mean(calc_stats, axis = 0)

    n_iters = calc_stats[:,0]
    n_iters_solved = n_iters[np.where(solved_status)]
    max_iters = np.max(n_iters)
    num_steps = 300
    check_points = np.linspace(1, max_iters + 1, endpoint=True, num=num_steps, dtype=np.float)
    cmc_values = []

    for i in range(len(check_points)):
        cmc_values.append(len(n_iters_solved[n_iters_solved < check_points[i]]))

    cmc_values = np.array(cmc_values) / float(len(solved_status))

    return (check_points, cmc_values), avg_calcs, num_solved
