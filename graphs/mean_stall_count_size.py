import numpy as np
import matplotlib.pyplot as plt
import json

f1 = open("values1.json")
data1 = json.load(f1)

f2 = open("values2.json")
data2 = json.load(f2)

f3 = open("values3.json")
data3 = json.load(f3)

N = 6

ind = np.arange(N)  # the x locations for the groups
width = 0.25  # the width of the bars
fig = plt.figure()
ax = fig.add_subplot(111)

setup_1 = (
    data1["40"]["mean_stall_count_size"],
    data1["50"]["mean_stall_count_size"],
    data1["60"]["mean_stall_count_size"],
    data1["70"]["mean_stall_count_size"],
    data1["80"]["mean_stall_count_size"],
    data1["90"]["mean_stall_count_size"],
)
rects1 = ax.bar(ind, setup_1, width, color="royalblue")

setup_2 = (
    data2["40"]["mean_stall_count_size"],
    data2["50"]["mean_stall_count_size"],
    data2["60"]["mean_stall_count_size"],
    data2["70"]["mean_stall_count_size"],
    data2["80"]["mean_stall_count_size"],
    data2["90"]["mean_stall_count_size"],
)
rects2 = ax.bar(ind + width, setup_2, width, color="seagreen")

setup_3 = (
    data3["40"]["mean_stall_count_size"],
    data3["50"]["mean_stall_count_size"],
    data3["60"]["mean_stall_count_size"],
    data3["70"]["mean_stall_count_size"],
    data3["80"]["mean_stall_count_size"],
    data3["90"]["mean_stall_count_size"],
)
rects3 = ax.bar(ind + (width*2), setup_3, width, color="firebrick")

# add some
ax.set_ylabel("mean_stall_count_size")
ax.set_title("mean_stall_count_size")
ax.set_xticks(ind + width)
ax.set_xlabel("churn %")
ax.set_xticklabels(("40", "50", "60", "70", "80", "90"))

ax.legend((rects1[0], rects2[0], rects3[0]), ("S1", "S2", "S3"))

plt.savefig('images/mean_stall_count_size.png', bbox_inches='tight')
plt.show()

f1.close()
f2.close()
f3.close()
