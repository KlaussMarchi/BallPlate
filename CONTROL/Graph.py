import control as ctl
import matplotlib.pyplot as plt
import numpy as np

def zGrid(G, zeta):
    ctl.root_locus(G)

    angle  = np.arccos(zeta)
    radius = np.linspace(0, 100, 400)

    x = radius * np.cos(angle)
    y = radius * np.sin(angle)
    
    plt.plot(-x, y, 'r--')
    plt.plot(-x, -y, 'r--')

    plt.title(f'Root Locus with zeta = {zeta} line')
    plt.xlabel('Real')
    plt.ylabel('Imaginary')
    plt.show()


s = ctl.TransferFunction.s
G = 0.053826279970789*s/(0.417035106*s**2 - 1.0*s + 0.599469914)
zGrid(G, 0.5911550337988976)