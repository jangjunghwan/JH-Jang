import os
import sys
import glob
import shutil

class PathCtl:
    '''
    # @drif Route setting
    '''
    def __init__(self, realPath):
        '''
        # @brif Get path or get list of subdirectories
        '''
        self.realPath = realPath
        self.pathAddress = "{0}/{1}".format(os.getcwd(), self.realPath)
        self.subDirectoryList = os.listdir( self.realPath )

    def getProcessPath(self):
        '''
        # @brif Get process path
        # @param None
        # @return os.getcwd() Process Path
        '''
        return os.getcwd()

    def getPathDir(self):
        '''
        # @brif Get route list
        # @param None
        # @return self.pathAddress Return path value received from init
        '''
        return self.pathAddress
    
    def getSubDirList(self):
        '''
        # @brif Get subdirectory list
        # @param None
        # @return self.subDirectoryList Directory List
        '''
        return self.subDirectoryList

    def getFileExtension(self, fileNameExtension):
        '''
        # @brif Get list of file extensions
        # @param fileNameExtension Extension Name
        # @param subDirectoryList Sub Directory List
        # @return self.extensionList Extension List
        '''

        self.fileNameExtension = fileNameExtension

        extensionList = [__ for __ in self.subDirectoryList if __.endswith( fileNameExtension )]

        self.extensionList = extensionList

        return self.extensionList

class FolderCtl( PathCtl ):
    '''
    # @drif Folder setting
    '''
    def __init__(self, realPath):
        '''
        # @drif PathCtl Class Inheritance 
        '''
        super().__init__(realPath)
  
    def createFolder(self, createFolderName):
        '''
        # @drif Create Folder
        # @param createFolderName Make Folder Name
        '''
        self.createFolderName = createFolderName

        creatFolderPath = "{0}/{1}".format(self.pathAddress, self.createFolderName)

        if ( os.path.isdir(creatFolderPath) != True ):
            os.mkdir(creatFolderPath)
            print( " |> Create Folder : {}".format(self.createFolderName) )
        else:
            self.deleteFolder(self.createFolderName)
            print( " |> RE Create Folder : {}".format(self.createFolderName) )
            os.mkdir(creatFolderPath)

    def deleteFolder(self, deleteFolderName):
        '''
        # @drif Create Folder
        # @param createFolderName Delete Folder Name
        '''
        self.deleteFolderName = deleteFolderName

        deleteFolderPath = "{0}/{1}".format(self.pathAddress, self.deleteFolderName)

        if (os.path.isdir(deleteFolderPath)):
            shutil.rmtree(deleteFolderPath)
            # os.rmdir(deleteFolderPath)
            print(" |> Delete Folder : {}".format(self.deleteFolderName))
        else:
            print(" |> '{}' Folder Not Found".format(self.deleteFolderName))

class FileCtl(PathCtl):
    '''
    # @drif File Read or Wirte Class
    '''
    def __init__(self, realPath):
        '''
        # @drif PathCtl Class Inheritance 
        '''
        super().__init__(realPath)
        self.realPath = realPath

    def fileRead(self, fileNameExtension):
        '''
        # @drif File read of Extension
        # @param Extension File Name
        # @return fileKeyAndValue(dict)
                * Key = File Name
                * Value = File Result
        '''
        self.fileNameExtension = super().getFileExtension(fileNameExtension)
        fileKeyAndValue = {}

        for fileName in self.fileNameExtension:
            with open( self.realPath + "/" + fileName, 'r', encoding='utf-8') as readFile:
                lines = readFile.readlines()
            for i in range(len(lines)):
                lines[i] = lines[i].strip()
            fileKeyAndValue[fileName] = lines
        
        return fileKeyAndValue

    def fileWirte(self, folderName, fileName, fileResult):
        self.folderName = folderName
        self.fileName = fileName
        self.fileResult = fileResult

        with open( self.realPath + "/" + self.folderName + "/" + self.fileName, 'w', encoding='utf-8' ) as wf:
            wf.write(self.fileResult)

if __name__=='__main__':

    oriPathName = "correct_answer_ok"
    refPathName = "process_answer_ok"
    ori_tmp = "oriTmp"
    ref_tmp = "refTmp"

    #/*
    # * ori file work
    # */
    cPath = PathCtl(oriPathName)
    cFolder = FolderCtl(oriPathName)
    cFile = FileCtl(oriPathName)

    extensionFileList = cPath.getFileExtension("txt")
    cFolder.createFolder(ori_tmp)

    oriKeyAndValue = cFile.fileRead("txt")
    oriFileList = cFile.fileNameExtension

    for i in range(len(oriFileList)):
        oriValue = oriKeyAndValue[oriFileList[i]]
        for j in range(len(oriValue)):
            if (".wav" in oriValue[j]):
                fileName = oriValue[j]
                tmp = fileName.split(".")
                fileName = tmp[0] + ".txt"
                fileValue = oriValue[j+1]
            cFile.fileWirte(ori_tmp, fileName, fileValue)

    
