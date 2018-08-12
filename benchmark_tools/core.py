import numpy as np
import go_problems

class Solver:
    def __init__(self, problem):
        pass

    def Solve(self, problem):
        return None

def solve_class(problems_set, solver):

    all_calcs = []
    solved_satus = []
    for problem in problems_set.get_problems():
        opt_point, opt_val, calcs = solver.Solve(problem)

        ref_point = np.array(problem.GetOptimumPoint())
        diff = np.linalg.norm(opt_point - ref_point)
        if diff < 0.01:
            solved_satus.append(True)
        else:
            solved_satus.append(False)
        all_calcs.append(calcs)

    num_solved = np.count_nonzero(solved_satus)

    return all_calcs, num_solved

class GrishClass():
    def __init__(self):
        pass

    def get_problems(self):
        for i in range(1, 101):
            yield go_problems.create_grishagin_function(i)

class GKLSClass():
    def get_problems(self):
        for i in range(1, 101):
            yield go_problems.create_gkls_function(i)
