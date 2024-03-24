import control as ctl
import matplotlib.pyplot as plt
import numpy as np
s = ctl.TransferFunction.s


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


G     = 0.0206708134012297*(0.155605773*s**2 - 0.400634718*s + 1.0)/(0.15560577*s**2 - 0.78893795*s + 1.0)
C_aux = (s - 1.5)*(s - 1.5)/(s + 30)/(s + 30)


zeta = 0.6
zGrid(G*C_aux, zeta)
