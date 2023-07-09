import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib


engine = pyttsx3.init('sapi5')

voices = engine.getProperty('voices')
print(voices[1].id)
engine.setProperty('voice',voices[1].id)

rate = engine.getProperty('rate')
engine.setProperty('rate',150)

def sendemail(to,content):
    server = smtplib.SMTP('smtp.gmail.com',587)
    server.ehlo()
    server.starttls()
    server.login("sender email","password")
    server.sendmail("sender email",to,content)
    server.close()

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishme():
    time = int(datetime.datetime.now().hour)
    if(time>0 and time<12):
        speak("good morning sir!")
    elif(time>12 and time<15):
        speak("Good afternoon sir!")
    else:
        speak("good evening!")
    speak("hello!")

def takecommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening.........")
        r.pause_threshold = 1
        audio = r.listen(source)
    try:
        query = r.recognize_google(audio,language='en-in')
        print(f"this is user commanded ....{query}")
    except Exception as e:
        print("Please repeat again what you commanded.......")
        return "none"
    return query

email = {}
if __name__=="__main__":
    wishme()
    while True:
        query  = takecommand().lower()
        if 'wikipedia' in query:
            speak("searching on wikipedia.......")
            query = query.replace("wikipedia","")
            result = wikipedia.summary(query,sentences = 5)
            speak(f"According to wikipedia!{result}")

        elif 'open vs code' in query:
            codepath = "C:\\Users\\91877\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
            os.startfile(codepath)

        elif 'open' in query:
            query = query.replace('open','')
            webbrowser.open(f"{query}.com")
        
        elif 'tell me about' in query:
            query = query.replace("tell me about","")
            webbrowser.open(query)
        
        elif 'play movies' in query:
            music_dir = "C:\\Users\\91877\\Downloads\\Telegram Desktop\\movies"
            songs = os.listdir(music_dir)
            print(songs)
            s = os.path.join(music_dir,songs[0])
            os.startfile(s)

        elif 'tell me time' in query:
            time = datetime.datetime.now().strftime("%H:%M:%S")
            speak("sir, the present time is",time)

        elif 'send email' in query:
            try:
                speak("what should i say")
                content = takecommand()
                speak("whom i have to send this to")
                to = takecommand()
                to = email[to]
                sendemail(to,content)
                speak("email sent")
            except:
                speak("sorry i was unable to send this")
        else:
            speak("i am still learning! i can't get your command but i will try to learn it in future")