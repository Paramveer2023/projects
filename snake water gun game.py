def sps_game():
    import random as ran
    lst = ["stone","paper","scissor"]
    lst_com = []
    lst_human = []
    lst_tie = []
    i = 1
    while i <= 5:
        com = ran.choice(lst)
        human = input("chosse from stone,paper,scissor")
        com = ran.choice(lst)
        print("com chose" ,com)
        if com == "stone" and human == "scissor":
            print("com won")
            lst_com.append("com won")
        elif com == "stone" and human == "paper":
            print("human won")
            lst_human.append("human won")
        elif com == "stone" and human == "stone":
            print("tie")
            lst_tie.append("tie")
        elif com == "paper" and human == "scissor":
            print(" human won")
            lst_human.append("human won")
        elif com == "paper" and human == "stone":
            print("com won")
            lst_com.append("com won")
        elif com == "paper" and human == "paper":
            print("tie")
            lst_tie.append("tie")
        elif com == "scissor" and human == "paper":
            print("com won")
            lst_com.append("com won")
        elif com == "scissor" and human == "stone":
            print("human won")
            lst_human.append("human won")
        elif com == "scissor" and human == "scissor":
            print("tie")
            lst_tie.append("tie")
        print(f"score of human is {len(lst_human)} and score of com is {len(lst_com)}")
        c = 5 - i
        print(f"you are left with only {c} chances")
        i = i+1
    if len(lst_human) > len(lst_com):
        print(f"since score of human is {len(lst_human)} and score of com is {len(lst_com)} so human won")
    elif len(lst_human) < len(lst_com):
        print(f"since score of human is {len(lst_human)} and score of com is {len(lst_com)} so com won")
    else:
        print(f"since score of human is {len(lst_human)} and score of com is {len(lst_com)} so com won")


sps_game()