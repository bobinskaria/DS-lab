import matplotlib.pyplot as plt
def plot_line_from_file(filename):
    x_vals = []
    y_vals = []
    with open(filename, 'r') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            if  ',' in line:
                x,y = line.split(',')
            else:
                x,y = line.split(',')
            x_vals.append(float(x))
            y_vals.append(float(y))
        plt.plot(x_vals,y_vals,marker='0',linestyle='-')
        plt.xlabel('x axis')
        plt.ylabel('y axis')
        plt.title('Line Plot from Text File')
        plt.grid(True)
        plt.show()
        plot_line_from_file('data.txt')