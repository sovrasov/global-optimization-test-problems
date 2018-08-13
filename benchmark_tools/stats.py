import numpy as np

def save_stats():
    pass

def load_stats():
    pass

def compute_stats(calc_stats, solved_status):
    assert len(calc_stats) == len(solved_status)

    num_solved = np.count_nonzero(solved_status)
    calc_stats = np.array(calc_stats)
    avg_calcs = np.mean(calc_stats, axis = 0)

    n_iters = calc_stats[:,0]
    n_iters_solved = n_iters[np.where(solved_status)]
    max_iters = np.max(n_iters)
    num_steps = max_iters // 150 + 1
    check_points = np.linspace(1, max_iters + 1, endpoint=True, num=num_steps, dtype=np.float)
    cmc_values = []

    for i in range(len(check_points)):
        cmc_values.append(len(n_iters_solved[n_iters_solved < check_points[i]]))

    cmc_values = np.array(cmc_values) / len(solved_status)

    return (check_points, cmc_values), avg_calcs, num_solved
