from  tkinter import *
import tkinter.messagebox as tmsg
root =Tk()
root.geometry("500x300")
def param():
    print("maharaj got it")
def help():
    print("here to help you")
    # tmsg.showinfo("need help","help yourself")
    a = tmsg.askquestion("KBC","kya aap bnoge")
def Rate():
    b = tmsg.askquestion("your experience","mza aaya?")
    if b=="yes":
       msg = "rate us on playstore"
    else:
        msg = "we will fix"
    tmsg.showinfo("experience",msg)
filemenu = Menu(root)

m1 = Menu(filemenu,tearoff=0)
m1.add_command(label="Open",command=param)
m1.add_separator()
m1.add_command(label="Save",command=param)
m1.add_command(label="Save As",command=param)
m1.add_separator()
m1.add_command(label="Rename",command=param)
m1.add_command(label="Copy",command=param)
root.config(menu=filemenu)
filemenu.add_cascade(label="File",menu=m1)

m1 = Menu(filemenu,tearoff=0)
m1.add_command(label="Open",command=param)
m1.add_separator()
m1.add_command(label="Save",command=param)
m1.add_command(label="Save As",command=param)
m1.add_separator()
m1.add_command(label="Rename",command=param)
m1.add_command(label="Copy",command=param)
root.config(menu=filemenu)
filemenu.add_cascade(label="Edit",menu=m1)

m1 = Menu(filemenu,tearoff=0)
m1.add_command(label="Help You",command=help)
m1.add_command(label="Rate Us",command=Rate)
root.config(menu=filemenu)
filemenu.add_cascade(label="Help",menu=m1)





root.mainloop()
