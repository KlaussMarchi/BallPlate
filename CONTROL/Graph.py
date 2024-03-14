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
G = 5.858/(s**2 + 4.997*s + 13.26)
zGrid(G, 0.5370292721463151)