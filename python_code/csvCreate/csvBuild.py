#-*- coding: utf-8 -*-
import os
import csv
import chardet
import io
import sys

def PathFunction():
    Path_dir = os.getcwd()
    RealPath_dir = os.listdir( Path_dir )

    return RealPath_dir

def pcmFilePath():
    totalPcmFileList = []
    middleList = []

    RealPath_dir = PathFunction()

    RealPath_dir.remove( "csvBuild.py" )
    RealPath_dir.remove( "spaceRemove.py" )
    RealPath_dir.remove( "imformation.csv" )

    for i in range( len( RealPath_dir )):
        PcmAndTextList = os.listdir( RealPath_dir[ i ] )
        pcmFileList = [ __ for __ in PcmAndTextList if __.endswith( "pcm" )]
        middleList.append( pcmFileList )
    
    for j in range(len(middleList)):
        for x in range(len(middleList[j])):
            totalPcmFileList.append(middleList[j][x])

    return totalPcmFileList

def textFilePath():
    totalmodifyTextFileList = []
    totalTextFileList = []
    AlltotalTextFileList = []

    middlList = []

    modifyTextFileList = []
    textFileList = []

    RealPath_dir = PathFunction()

    RealPath_dir.remove( "csvBuild.py" )
    RealPath_dir.remove( "spaceRemove.py" )
    RealPath_dir.remove( "imformation.csv" )

    for i in range( len( RealPath_dir )):
        PcmAndTextList = os.listdir( RealPath_dir[ i ] )
        AllTextFileList = [ __ for __ in PcmAndTextList if __.endswith( "txt" )]
        AlltotalTextFileList.append( AllTextFileList )
    
    for j in range( len( AlltotalTextFileList )):
        ## AlltotalTextFileList == [ KJEW2CSH1, KR252F002, ... , ]
        middlList = AlltotalTextFileList[ j ]
        for x in range( len( middlList )):
            ## middlList == [ KJEW2CSH1_001.txt, KJEW2CSH1_001_m.txt, ... , ]
            if "_m.txt" in middlList[ x ]:
                modifyTextFileList.append( middlList[ x ] )
                ##modifyTextFileList == [ KJEW2CSH1_001_m.txt, KJEW2CSH1_002_m.txt, ... , ]
            else:
                textFileList.append( middlList[ x ] )
                ##textFileList == [ KJEW2CSH1_001.txt, KJEW2CSH1_002.txt, ... , ]

    totalmodifyTextFileList = modifyTextFileList
    totalTextFileList = textFileList

    return [ totalTextFileList, totalmodifyTextFileList ]

def csvFileCreat():
    rows = ["FileName", "PcmFileName", "Gender", "Ori_textFileName", "Contents", "Modify_textFileName", ""]
    
    with open( "imformation.csv", 'wt' ) as fd:
        csvWrite = csv.writer( fd )
        csvWrite.writerow( rows )

def FileWrite( totalPcmFileList, totalTextFileList, totalmodifyTextFileList ):
    totalcontenstList = []
    totalFileNameList = FileNameCheck( totalPcmFileList )
    totalGenderList = GenderCheck( totalFileNameList )

    for i in range( len( totalPcmFileList )):
        with open( totalFileNameList[i] + "/" + totalTextFileList[i], "r", encoding='utf-8' ) as rd:
            textLine = rd.readline()
            # replaceTextLint = textLine[2:]
            # if "-" in replaceTextLint[0]:
            #     replaceTextLint = replaceTextLint[4:]
            
            textLines = textLine.encode()
            oktext = textLines.decode('utf-8')
            # print(chardet.detect(oktext))

            totalcontenstList.append(oktext)

    with open( "imformation.csv", "a", newline='', encoding='utf-8-sig' ) as fd:
        csvWriter = csv.writer( fd )
        for i in range(len(totalPcmFileList)):
            ##                      ["FileName",           "PcmFileName",        "Gender",        "Ori_textFileName",       "Contents",        "Modify_textFileName", ""]
            csvWriter.writerow( [ totalFileNameList[i], totalPcmFileList[i], totalGenderList[i], totalTextFileList[i], totalcontenstList[i], totalmodifyTextFileList[i], "" ])



def GenderCheck( FileNameList ):
    totalGenderList = []

    for i in range(len(FileNameList)):
        if "KR252F" in FileNameList[i] or "KSEW" in FileNameList[i] :
            totalGenderList.append("Female")
        elif "KJEW" in FileNameList[i]:
            totalGenderList.append("Female")
        else:
            totalGenderList.append("Male")

    return totalGenderList

def FileNameCheck( totalPcmFileList ):
    totalFileNameList = []

    for i in range(len(totalPcmFileList)):
        middleList = totalPcmFileList[i].split("_")
        totalFileNameList.append(middleList[0])

    return totalFileNameList


if __name__ == "__main__":
    csvFileCreat()
    totalPcmFileList = pcmFilePath()
    totalTextFileList, totalmodifyTextFileList = textFilePath()

    FileWrite( totalPcmFileList, totalTextFileList, totalmodifyTextFileList )
