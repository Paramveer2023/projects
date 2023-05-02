from tkinter import *
root = Tk()
root.geometry("600x800")
root.title("CALCULATOR")
def click(event):
    text = event.widget.cget("text")
    print(text)
    if text == "=":
        if scvalue.get().isdigit():
            value = int(scvalue.get())
        else:
            value = eval(screen.get())
        scvalue.set(value)
        screen.update()
    elif text == "C":
        scvalue.set("")
        screen.update()
    else:
        scvalue.set(scvalue.get() + text)
        screen.update()



root.wm_iconbitmap("images.ico")
scvalue = StringVar()
scvalue.set("")
screen = Entry(root,textvariable=scvalue,font="lucida 40 bold")
screen.pack(fill=X,padx=10,pady=10,ipadx=5,ipady=5 )
# FRAME OPEN
def frame(x,y,z):
    f = Frame(root,bg="pink")
    f.pack()
    b = Button(f,text=x,font="lucida 40 bold")
    b.pack(side=LEFT,padx=10,pady=10)
    b.bind("<Button-1>",click)
    b = Button(f,text=y,font="lucida 40 bold")
    b.bind("<Button-1>",click)
    b.pack(side=LEFT,padx=10,pady=10)
    b = Button(f,text=z,font="lucida 40 bold")
    b.bind("<Button-1>",click)
    b.pack(side=LEFT,padx=10,pady=10)
# FRAME CLOSE
frame("7","8","9")
frame("4","5","6")
frame("1","2","3")
frame("+","-","*")
frame("/","%","C")







root.mainloop()