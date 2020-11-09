#-*- coding: utf-8 -*-
import os
import csv
import io
import sys

def Path_dir():

    FolderLists = os.listdir()
    FolderLists.remove("csvBuild.py")
    FolderLists.remove("imformation.csv")
    FolderLists.remove("spaceRemove.py")
    
    return FolderLists

def TextPath_dir( FolderLists ):
    middlList = []
    TotalMiddleList = []
    TotalTextLists = []


    for i in range(len(FolderLists)):
        PcmAndTextLists = os.listdir( FolderLists[i] )
        TextLists = [ __ for __ in PcmAndTextLists if __.endswith( "txt" )]
        middlList.append( TextLists )

    for j in range( len( middlList )):
        for x in range( len( middlList[ j ] )):
            TotalMiddleList.append(middlList[j][x] )

    return TotalMiddleList

def TextDirListMake( TotalMiddleList ):
    folderList = []

    for i in range( len( TotalMiddleList )):
        middlList = TotalMiddleList[i].split("_")
        folderList.append(middlList[0])

    TotalTextDirLists = []

    for j in range(len( folderList )):
        TotalTextDirLists.append( folderList[j] + "/" + TotalMiddleList[j] )

    return TotalTextDirLists


def ReadWrite( TotalTextDirLists ):
    TotalTextLines = []

    for i in range(len( TotalTextDirLists )):
        with open ( TotalTextDirLists[ i ] ) as fd:
            textLines = fd.readline()
            replaceTextLines = textLines[2:]
            if "-" in replaceTextLines[0]:
                replaceTextLines = replaceTextLines[4:]
                TotalTextLines.append( replaceTextLines )
            else:
                TotalTextLines.append( replaceTextLines )

    for j in range(len(TotalTextDirLists)):
        with open( TotalTextDirLists[j], "w" ) as fw:
            fw.write( TotalTextLines[j] )


if __name__ == "__main__":
    FolderLists = Path_dir()
    
    TotalTextLists = TextPath_dir( FolderLists )

    TotalTextDirLists = TextDirListMake( TotalTextLists )

    ReadWrite( TotalTextDirLists )


