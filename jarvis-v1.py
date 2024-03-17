import speech_recognition as sr
import pyttsx3
import openai
import time



mess_his = [{"role":"system","content":"you are a voice assistant named jarvis keep the number of lines of response less and appealing to listen to and refer to me as sir and if a request (such as return a something) is asked just the request "}]
openai.api_key=''
engine = pyttsx3.init(driverName='sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)
engine.say("HELLO BOSS ...i am your assistant ...jarvis!")
engine.runAndWait()
voice_assistant_name="jarvis"

def takeCommand():
    r=sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        print("Listening...")
        audio=r.listen(source )

    try:
        statement = r.recognize_google(audio, language='en-in').lower()
        return statement
    #    engine.say(statement)
   #     engine.runAndWait()
   #     print(f"user said:{statement}\n")

    except Exception as e:
        return("none")
    return statement

def compute(statement):
    print(statement)
    if voice_assistant_name.lower() in statement and 'are you working' in statement:
        engine.say("Yes boss ... I am working")
        engine.runAndWait()
    elif voice_assistant_name.lower() in statement and 'time' in statement and 'now' in statement:
        t = time.localtime()
        current_time = time.strftime("%H:%M:%S", t)                 
        engine.say(current_time)
        engine.runAndWait()
    elif voice_assistant_name.lower() in statement:
        request = ask_openai(statement)
        if request[-1] == '?':
            print(request)
            engine.say(request)
            engine.runAndWait()
            r=sr.Recognizer()
            with sr.Microphone() as source:
                r.adjust_for_ambient_noise(source)
                audio=r.listen(source)
                statement = r.recognize_google(audio, language='en-in').lower()
            request = ask_openai(statement)
        else:
            pass
        engine.say(request)
        engine.runAndWait()
        print(request)


def ask_openai(question):
    global mess_his
    mess_his.append({"role": "user", "content": question})
    completion = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=mess_his
    )
    gpt_response = completion.choices[0].message.content
    mess_his.append({"role": "assistant", "content": gpt_response})
    return gpt_response


if __name__=='__main__':
    while True:
        statement = takeCommand().lower()
        compute(statement)
