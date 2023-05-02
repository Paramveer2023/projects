
from tkinter import *
import os
import tkinter.messagebox as tsmg
from tkinter.filedialog import askopenfilename,asksaveasfile
def new():
    global file
    root.title("Untitled-Notepad")
    TextArea.delete(1.0,END)
def Open():
    global file
    file = askopenfilename(defaultextension=".txt",filetypes=[("All Files","*.*"),("Text Documents","*.txt")])
    if file == "":
        file = None
    else:
        root.title(os.path.basename(file)+" - Notepad")
        TextArea.delete(1.0,END)
        f = open(file,'r')
        TextArea.insert(1.0,f.read())
        f.close()
def save():
    global file
    if file == None:
        file = asksaveasfile(initialfile="Untitled.txt",defaultextension=".txt",filetypes=[("All Files","*.*"),("Text Documents","*.txt")])
        if file == "":
            file = None
        else:
            f = open(file,"w")
            f.write(TextArea.get(1.0,END))
            f.close()

            root.title(os.path.basename(file) + " - Notepad")
    else:
        f = open(file, "w")
        f.write(TextArea.get(1.0, END))
        f.close()
def exit():
    return root.destroy()

def Cut():
    TextArea.event_generate(("<<Cut>>"))

def Copy():
    TextArea.event_generate(("<<Copy>>"))


def Paste():
    TextArea.event_generate(("<<Paste>>"))


def About():
    tsmg.showinfo("Help","You will be helped soon")

root = Tk()
root.title("NOTEPAD")
root.geometry("300x400")

# Add TextArea
TextArea = Text(root,font="lucida 20",padx=20,pady=20,bg="pink")
TextArea.pack(expand=True,fill=BOTH)

file = None

# scrollbar
Scroll = Scrollbar(TextArea)
Scroll.pack(side=RIGHT,fill=Y)
Scroll.config(command=TextArea.yview)
TextArea.config(yscrollcommand=Scroll.set)

# MenuBars
MenuBar = Menu(root)
# file options
FileMenu = Menu(MenuBar,tearoff=0)
FileMenu.add_command(label="New",command=new)
FileMenu.add_command(label="OpenFile",command=Open)
FileMenu.add_command(label="SaveFile",command=save)
FileMenu.add_separator()
FileMenu.add_command(label="Exit",command=exit)
root.config(menu=MenuBar)
MenuBar.add_cascade(label="File",menu=FileMenu)

# edit menu options
EditMenu = Menu(MenuBar,tearoff=0)
EditMenu.add_command(label="Cut",command=Cut)
EditMenu.add_command(label="Copy",command=Copy)
EditMenu.add_command(label="Paste",command=Paste)
MenuBar.add_cascade(label="Edit",menu=EditMenu)

# HelpMenu
HelpMenu = Menu(MenuBar,tearoff=0)
HelpMenu.add_command(label="About Notepad",command=About)

MenuBar.add_cascade(label="Help",menu=HelpMenu)



root.mainloop()