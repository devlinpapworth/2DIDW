import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# Read data from the CSV file (make sure to provide the correct file path)
file_path = r'IDW_output.csv'  # Change this to the path of your CSV file
data = pd.read_csv(file_path, header=None)  # Assuming no header row, if there is one, adjust accordingly

# Convert the data to a NumPy array
data_array = data.to_numpy()

# Get the shape of the data (for automatically adjusting grid size)
rows, cols = data_array.shape

# Create a figure and axis with an automatically adjusted size
fig, ax = plt.subplots(figsize=(cols / 10, rows / 10))  # Adjust the figure size based on the data dimensions

# Choose any color map from the list above
cax = ax.matshow(data_array, cmap='Spectral')  # Change 'viridis' to any other color map like 'plasma', 'inferno', etc.

# Add a color bar
fig.colorbar(cax)

# Add gridlines
ax.set_xticks(np.arange(-0.5, cols, max(1, cols // 10)), minor=True)
ax.set_yticks(np.arange(-0.5, rows, max(1, rows // 10)), minor=True)
ax.grid(which='minor', color='gray', linestyle='-', linewidth=0.5)

# Set x and y axis ticks to be multiples of 5
x_ticks = np.arange(0, cols, 5)  # x-axis ticks, multiples of 5
y_ticks = np.arange(0, rows, 5)  # y-axis ticks, multiples of 5

# Remove default ticks but show axis labels
ax.set_xticks(x_ticks)
ax.set_yticks(y_ticks)

# Add x and y axis labels
ax.set_xlabel('X Axis')  # Customize the x-axis label
ax.set_ylabel('Y Axis')  # Customize the y-axis label

# Title
plt.title('2D Block Model from CSV')

# Show the plot
plt.show()
