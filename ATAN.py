import sympy as sp

def angle(number, numeric=False):
    x = sp.re(number)
    y = sp.im(number)
    value = 0

    

    if x > 0 and y > 0:
        value = sp.atan(y/x) 
    if x < 0 and y > 0:
        value = -sp.atan(y/x) 
    if x > 0 and y < 0:
        value = -sp.atan(y/x) 
    if x < 0 and y < 0:
        value = sp.atan(y/x)
    
    value = value * 180/sp.pi
    return sp.N(value) if numeric else value  


val = 2*sp.var('k') + 5*sp.I
ang = angle(val)

print(ang)