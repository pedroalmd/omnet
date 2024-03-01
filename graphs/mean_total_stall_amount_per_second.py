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
    data1["40"]["mean_total_stall_amount_per_second"],
    data1["50"]["mean_total_stall_amount_per_second"],
    data1["60"]["mean_total_stall_amount_per_second"],
    data1["70"]["mean_total_stall_amount_per_second"],
    data1["80"]["mean_total_stall_amount_per_second"],
    data1["90"]["mean_total_stall_amount_per_second"],
)
rects1 = ax.bar(ind, setup_1, width, color="royalblue")

setup_2 = (
    data2["40"]["mean_total_stall_amount_per_second"],
    data2["50"]["mean_total_stall_amount_per_second"],
    data2["60"]["mean_total_stall_amount_per_second"],
    data2["70"]["mean_total_stall_amount_per_second"],
    data2["80"]["mean_total_stall_amount_per_second"],
    data2["90"]["mean_total_stall_amount_per_second"],
)
rects2 = ax.bar(ind + width, setup_2, width, color="seagreen")

setup_3 = (
    data3["40"]["mean_total_stall_amount_per_second"],
    data3["50"]["mean_total_stall_amount_per_second"],
    data3["60"]["mean_total_stall_amount_per_second"],
    data3["70"]["mean_total_stall_amount_per_second"],
    data3["80"]["mean_total_stall_amount_per_second"],
    data3["90"]["mean_total_stall_amount_per_second"],
)
rects3 = ax.bar(ind + (width*2), setup_3, width, color="firebrick")

# add some
ax.set_ylabel("mean_total_stall_amount_per_second")
ax.set_title("mean_total_stall_amount_per_second")
ax.set_xticks(ind + width)
ax.set_xlabel("churn %")
ax.set_xticklabels(("40", "50", "60", "70", "80", "90"))

ax.legend((rects1[0], rects2[0], rects3[0]), ("S1", "S2", "S3"))


plt.savefig('images/mean_total_stall_amount_per_second.png', bbox_inches='tight')
plt.show()

f1.close()
f2.close()
f3.close()
