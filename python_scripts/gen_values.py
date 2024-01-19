# int amount_serving[PEER_AMOUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

# int contents_wants[PEER_AMOUNT] = {'d', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e'};
# int contents_has[PEER_AMOUNT] =   {'a', 'b', 'c', 'd', 'd', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e', 'd', 'c', 'd', 'e', 'e'};

# double peer_dying_time[PEER_AMOUNT] = {0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, };

import random, string

peer_amount = 500

five_letters = ['a', 'b', 'c', 'd', 'e']

amount_serving = []
contents_wants = []
contents_has = []
dying_time = []

for x in range(peer_amount):
    # if peer_amount <= 10:

    print(f"        switch[0].peer_gate++ <--> Channel <--> peer[{x}].gate++;")

    contents_wants.append(random.choice(five_letters))
    contents_has.append(random.choice(five_letters))

    if random.randint(0,9) >= 7:
        dying_time.append(random.randint(5, 60))

    else:
        dying_time.append(0)
        # continue

    amount_serving.append(0)

    # contents_wants.append(random.choice(string.ascii_lowercase))
    # contents_has.append(random.choice(string.ascii_lowercase))
    # dying_time.append(random.randint(5, 60))

print(f"int amount_serving[PEER_AMOUNT] =  {{{(', '.join(str(x) for x in amount_serving))}}};")

print(f"int contents_wants[PEER_AMOUNT] = {{{str(contents_wants)[1:-1]}}};")
print(f"int contents_has[PEER_AMOUNT] = {{{str(contents_has)[1:-1]}}};")
print(f"double peer_dying_time[PEER_AMOUNT] = {{{(', '.join(str(x) for x in dying_time))}}};")

