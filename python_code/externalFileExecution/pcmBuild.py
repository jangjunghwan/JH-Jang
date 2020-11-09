import os
import subprocess

def signleStart( PcmName_dir, TxtName_dir ):
    os.system( "<Skip>" +
        " " + PcmName_dir + 
        " > " + TxtName_dir + ".txt")

    TextFile = ("TYPE {0}.txt > {1}_m.txt").format(TxtName_dir, TxtName_dir)
    ReplaceTextFile = TextFile.replace("/","\\")      
    print(ReplaceTextFile)  
    os.system( ReplaceTextFile )


def PathFunction( Path_dir ):
    Path_dir = Path_dir.replace("\\", "/")
    # Path_dir = "D:/5.LGE_TV/jang"
    folder_list = os.listdir( Path_dir )

    if "csvBuild.py" in folder_list:
        folder_list.remove("csvBuild.py")
    else:
        pass
    
    if "imformation.csv" in folder_list:
        folder_list.remove("imformation.csv")
    else:
        pass

    if "spaceRemove.py" in folder_list:
        folder_list.remove("spaceRemove.py")
    else:
        pass

    return folder_list

def FolderList( folder_list, Path_dir ):
    Path_dir = Path_dir.replace("\\", "/")
    PcmFolderFile_dir = []

    for i in folder_list:
    	PcmFolderFile_dir.append( Path_dir + "/" + i )

    return PcmFolderFile_dir

def PcmFileList( PcmFolderFile_dir ):
    pcmfileList_dir = []

    pcmExtension = ".pcm"

    for i in range(len(PcmFolderFile_dir)):
        PcmAndTextList = os.listdir( PcmFolderFile_dir[i] )
        pcmList = [ file for file in PcmAndTextList if file.endswith( pcmExtension ) ]
        for j in range( len( pcmList )):

            pcmfileList_dir.append( PcmFolderFile_dir[i] + "/" + pcmList[j] )

    return pcmfileList_dir

def pcmToText( pcmfile_dir ):

    textfile_dir = []

    for i in pcmfile_dir:
        textfile_dir.append(i.replace( ".pcm", "" ))

    return textfile_dir


if __name__ == "__main__":
    print( "Ex:)---------------------------------------------------" )
    print( " | D:\\5.LGE_TV\jang_test\(KR252F002, KR252F002 , ... ) " )
    print( " | -> DB 폴더 경로를 입력해 주세요: 'D:\\5.LGE_TV\jang_test'" )
    print( "-------------------------------------------------------" )
    Path_dir = input("DB 폴더 경로를 입력해 주세요: ")
    
    folder_list = PathFunction( Path_dir )

    PcmFolderFile_dir = FolderList( folder_list, Path_dir )

    pcmfile_dir = PcmFileList( PcmFolderFile_dir )
    textfile_dir = pcmToText( pcmfile_dir )

    for i in range(len(pcmfile_dir)):
        signleStart(pcmfile_dir[i], textfile_dir[i])

    print("PcmFile_EA : '{0}'EA").format(len(pcmfile_dir))
    print("TextFile_EA: '{0}'EA").format(len(textfile_dir))
    print("-END-")

    os.system("pause")