# int amount_serving[PEER_AMOUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

# int contents_wants[PEER_AMOUNT] = {'d', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e'};
# int contents_has[PEER_AMOUNT] =   {'a', 'b', 'c', 'd', 'd', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e'};

# double peer_dying_time[PEER_AMOUNT] = {0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, };

import random, string

peer_amount = 200

five_letters = ['a', 'b', 'c', 'd', 'e']

amount_serving = []
peer_main_tcp = []
contents_wants = []
contents_has = []
dying_time = []
peers_serving = []


for x in range(peer_amount):
    # if peer_amount <= 10:

    print(f"        switch[0].peer_gate++ <--> Channel <--> peer[{x}].gate++;")

    contents_wants.append(random.choice(five_letters))
    tmp = five_letters.copy()
    contents_has.append(random.choice(tmp))

    if random.randint(0,9) >= 7:
        dying_time.append(random.randint(5, 60))

    else:
        dying_time.append(0)
        # continue

    amount_serving.append(0)
    peer_main_tcp.append(-1)

    tmp = '{' 
    for x in range(peer_amount-1):
        tmp += '-1'
        if x == (peer_amount-2):
            continue
        tmp += ', '
    tmp += '}'

    peers_serving.append(tmp)

    # contents_wants.append(random.choice(string.ascii_lowercase))
    # contents_has.append(random.choice(string.ascii_lowercase))
    # dying_time.append(random.randint(5, 60))

print(f"int amount_serving[PEER_AMOUNT] =  {{{(', '.join(str(x) for x in amount_serving))}}};")
print(f"int peers_serving[PEER_AMOUNT][PEER_AMOUNT - 1] = {{{(', '.join(str(x) for x in peers_serving))}}};")
print("\n")
print(f"int contents_wants[PEER_AMOUNT] = {{{str(contents_wants)[1:-1]}}};")
print(f"int contents_has[PEER_AMOUNT] = {{{str(contents_has)[1:-1]}}};")
print("\n")
print(f"double peer_dying_time[PEER_AMOUNT] = {{{(', '.join(str(x) for x in dying_time))}}};")
print(f"int peer_main_tcp[PEER_AMOUNT] = {{{(', '.join(str(x) for x in peer_main_tcp))}}};")
