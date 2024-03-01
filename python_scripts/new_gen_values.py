# int amount_serving[PEER_AMOUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

# int contents_wants[PEER_AMOUNT] = {'d', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e'};
# int contents_has[PEER_AMOUNT] =   {'a', 'b', 'c', 'd', 'd', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e'};

# double peer_dying_time[PEER_AMOUNT] = {0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, };

import random, string

peer_amount = 150

five_letters = ['a', 'b', 'c', 'd', 'e', 'a']

amount_serving = []
peer_main_tcp = []
contents_wants = []
contents_has = []
dying_time = []
peers_serving = []
y = -1
c = peer_amount / 5

for x in range(peer_amount):
    # if peer_amount <= 10:

    # print(f"        switch[0].peer_gate++ <--> Channel <--> peer[{x}].gate++;")

    if (x % c) == 0:
        y += 1
    

    contents_wants.append(five_letters[y])
    contents_has.append(five_letters[y+1])


    amount_serving.append(0)
    peer_main_tcp.append(-1)

    tmp = '{' 
    for x in range(int(c) - 1):
        tmp += '-1'
        if x == (int(c) - 2):
            continue
        tmp += ', '
    tmp += '}'

    peers_serving.append(tmp)

    # contents_wants.append(random.choice(string.ascii_lowercase))
    # contents_has.append(random.choice(string.ascii_lowercase))
    # dying_time.append(random.randint(5, 60))

# if peer_amount == 10:
#     c = 2 ## 50%
#     for x in range(peer_amount):
#         if x == 0:
#             dying_time.append(30)

#         elif x % c == 0:
#             dying_time.append(30)

#         else:
#             dying_time.append(0)

# if peer_amount == 50:
#     count = 4
    
#     for x in range(peer_amount):
#         if x == 0:
#             dying_time.append(30)

#         elif x % count != 0:
#             dying_time.append(30)

#         else:
#             dying_time.append(0)

# if peer_amount == 100:
#     c = 1.5
#     for x in range(peer_amount):
#         if x == 0:
#             dying_time.append(10)

#         elif x % c != 0:
#             dying_time.append(10)

#         else:
#             dying_time.append(0)

# if peer_amount == 400:
#     c = 3
#     for x in range(peer_amount):
#         if x == 0:
#             dying_time.append(0)

#         elif x % c != 0:
#             dying_time.append(random.randint(10,20))

#         else:
#             dying_time.append(0)

time_range = (10, 30)
ta = time_range[0]
tb = time_range[1]

if peer_amount == 300:
    print("#if CHURN == 10")
    c = 10
    for x in range(peer_amount):
        if x % c == 0:
            dying_time.append(random.randint(ta, tb))

        else:
            dying_time.append(0)

    print(f"    double peer_dying_time[PEER_AMOUNT] = {{{(', '.join(str(x) for x in dying_time))}}};")

    dying_time = []

    print("\n#elif CHURN == 20")
    c = 5
    for x in range(peer_amount):
        if x % c == 0:
            dying_time.append(random.randint(ta, tb))

        else:
            dying_time.append(0)

    print(f"    double peer_dying_time[PEER_AMOUNT] = {{{(', '.join(str(x) for x in dying_time))}}};")

    dying_time = []

    print("\n#elif CHURN == 30")
    c = 3
    for x in range(peer_amount):
        if x % c == 0:
            dying_time.append(random.randint(ta, tb))

        else:
            dying_time.append(0)

    print(f"    double peer_dying_time[PEER_AMOUNT] = {{{(', '.join(str(x) for x in dying_time))}}};")

    dying_time = []

    print("\n#elif CHURN == 40")
    c = 5
    for x in range(peer_amount):
        if x % c in [0, 2]:
            dying_time.append(random.randint(ta, tb))

        else:
            dying_time.append(0)
    
    print(f"    double peer_dying_time[PEER_AMOUNT] = {{{(', '.join(str(x) for x in dying_time))}}};")


if peer_amount == 150:
    print("#if CHURN == 10")
    c = 10
    for x in range(peer_amount):
        if x % c == 0:
            dying_time.append(random.randint(ta, tb))

        else:
            dying_time.append(0)

    print(f"    double peer_dying_time[PEER_AMOUNT] = {{{(', '.join(str(x) for x in dying_time))}}};")

    dying_time = []

    print("\n#elif CHURN == 20")
    c = 5
    for x in range(peer_amount):
        if x % c == 0:
            dying_time.append(random.randint(ta, tb))

        else:
            dying_time.append(0)

    print(f"    double peer_dying_time[PEER_AMOUNT] = {{{(', '.join(str(x) for x in dying_time))}}};")

    dying_time = []

    print("\n#elif CHURN == 30")
    c = 3
    for x in range(peer_amount):
        if x % c == 0:
            dying_time.append(random.randint(ta, tb))

        else:
            dying_time.append(0)

    print(f"    double peer_dying_time[PEER_AMOUNT] = {{{(', '.join(str(x) for x in dying_time))}}};")

    dying_time = []

    print("\n#elif CHURN == 40")
    c = 5
    for x in range(peer_amount):
        if x % c in [0, 2]:
            dying_time.append(random.randint(ta, tb))

        else:
            dying_time.append(0)
    
    print(f"    double peer_dying_time[PEER_AMOUNT] = {{{(', '.join(str(x) for x in dying_time))}}};")

print(f"int amount_serving[PEER_AMOUNT] =  {{{(', '.join(str(x) for x in amount_serving))}}};")
print(f"int peers_serving[PEER_AMOUNT][(PEER_AMOUNT / 5) - 1] = {{{(', '.join(str(x) for x in peers_serving))}}};")
print("\n")
print(f"int contents_wants[PEER_AMOUNT] = {{{str(contents_wants)[1:-1]}}};")
print(f"int contents_has[PEER_AMOUNT] = {{{str(contents_has)[1:-1]}}};")
print("\n")
print(f"int peer_main_tcp[PEER_AMOUNT] = {{{(', '.join(str(x) for x in peer_main_tcp))}}};")

# print(dying_time.count(0)/5 - 100)