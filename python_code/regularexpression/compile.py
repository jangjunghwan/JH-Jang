import re
import os

def realDir():
    dir = os.listdir(os.getcwd())
    textdir = [ __ for __ in dir if __.endswith("txt")]

    return textdir

def tagFind( fimeName ):
    garbageText = []
    hangleText = []
    searchCP = re.compile( '[ㄱ-ㅣ가-힣]+' )

    with open ( fimeName, "r", encoding='utf-8') as fd:
        lines = fd.readlines()
    
    for i in range( len( lines )):
        if "<text>" in lines[i]:
            tagLineNum = i

    for i in range( tagLineNum, len(lines) ):
        garbageText.append(lines[i])
    
    for i in range( len( garbageText )):
        a = searchCP.findall(garbageText[i])
        if( a != [] ):
            hangleText.append( " ".join( a ) )

    with open( "modify/"+ fimeName, "w", encoding='utf-8' ) as fd:
        for i in range( len( hangleText )):
            fd.write("<s>"+ hangleText[i]+ "</s>\n")
        

if __name__ == "__main__":
    textdir = realDir()

    for i in textdir:
        tagFind( i )
        