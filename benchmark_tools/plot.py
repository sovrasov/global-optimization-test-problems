import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
from matplotlib.lines import Line2D
from os.path import isfile, join

matplotlib.style.use('classic')

colors = ('b', 'g', 'r', 'c', 'm', 'y', 'k', 'tab:brown', 'w')
linestyles = ['--', '-', '--', ':', '-.', '--', ':', '-', '--']

def plot_cmcs(curves, show, filename):

    plt.xlabel(r'$K$', fontsize=15)
    plt.ylabel(r'$P$', fontsize=15)
    plt.xticks(fontsize=13)
    plt.yticks(fontsize=13)

    min_iters = sys.maxsize
    for curve in curves:
        min_iters = min(curve[0][-1], min_iters)

    plt.xlim([0., min_iters*1.2])

    for i, curve in enumerate(curves):
        plt.plot(curve[0], curve[1], color = colors[i], linestyle = linestyles[i], label = '', markersize=3, linewidth=2)

    plt.grid()
    plt.legend(loc = 'best', fontsize = 14)
    plt.tight_layout()

    if show:
        plt.show()
