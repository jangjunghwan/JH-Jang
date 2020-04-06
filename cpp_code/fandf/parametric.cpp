#include <iostream>

using namespace std;


void greet(const char* str) {
    cout << str << endl;
}

void test(const char* str) {
    greet(str);
}

int main()
{
    greet("안녕!");

    return 0;
}

#include "ve_class.h"
#include "ve_def.h"


NUAN_ERROR            nErrcode;    /* Error code returned by the ve (vocalizer에 에러 코드 반환)*/
NUAN_U16              nItem = 0, nItem2 = 0, nItem3 = 0;

VPLATFORM_RESOURCES   stResources;

PLATFORM_TCHAR        *szDataInstallPath = NULL;
PLATFORM_TCHAR        szOutputFilename[INPUT_TEXT_MAX_LEN] = OUTPUT_FILE;

int                   nReturnValue;   /* to keep track of the result (결과 추적)*/
char                  *szInputText;

VE_INSTALL            stInstall;
VE_HSPEECH            hSpeech;  /*Voice List(const VE_HSPEECH hTtsCl) same*/
VE_HINSTANCE          hTtsInst;
VE_OUTDEVINFO         stOutDevInfo;
VE_INTEXT             stInText;
VE_PARAM              ttsParam[16];
VE_PRODUCT_VERSION    ttsVersion;

VOUT_FILE_T           stVoutFile;


ve_class::ve_class(){
}

void ve_class::ve_version(){
    nErrcode = ve_ttsGetProductVersion(&ttsVersion);
    if (nErrcode != NUAN_OK){
        qDebug("ve_ttsGetProductVersion failed");
    }
    qDebug("ve_version: %u.%u.%u", ttsVersion.minor, ttsVersion.major, ttsVersion.maint);
}

void ve_class::ve_init(){
    nErrcode = 1;    /* Error code returned by the ve (vocalizer에 에러 코드 반환)*/
    nReturnValue = 0;   /* to keep track of the result (결과 추적)*/
    stInstall = { 0 };
    stResources = { 0 };
    hSpeech = { 0 };
    hTtsInst = { 0 };
    stOutDevInfo = { 0 };
    szInputText = nullptr;
    szDataInstallPath = nullptr;
    stVoutFile = { 0 };
    nItem = 0, nItem2 = 0, nItem3 = 0; /**/

    /*Setting*/
    stInstall.fmtVersion = VE_CURRENT_VERSION;
    stResources.fmtVersion = VPLATFORM_CURRENT_VERSION;
    szDataInstallPath = INSTALL_PATH;
    stResources.apDataInstall = &szDataInstallPath;
    stResources.u16NbrOfDataInstall = 1;
    stVoutFile.sizeOutputBuffer = PCM_BUF_SIZE;
    stVoutFile.pPcmOutputBuffer = vplatform_heap_Malloc(stInstall.hHeap,
        stVoutFile.sizeOutputBuffer);

    /*Get Interfaces (ve, vplatform)*/
    nErrcode = vplatform_GetInterfaces(&stInstall, &stResources);
    if (nErrcode != NUAN_OK){
        qDebug("vplatform_GetInterfaces failed");
    }

    /*pcm file open*/
    nErrcode = vplatform_file_Open(stInstall.hDataClass, stInstall.hHeap,
    szOutputFilename, _T("wb"), &stVoutFile.fOutputPcmFile);
    if (nErrcode != NUAN_OK){
        qDebug("vplatform_file_Open failed");
    }

    /*Text 2 speech Initialize*/
    nErrcode = ve_ttsInitialize(&stInstall, &hSpeech);
    if (nErrcode != NUAN_OK){
        qDebug("ve_ttsInitialize failed");
    }

    /*Text 2 speech Open*/
    nErrcode = ve_ttsOpen(hSpeech, stInstall.hHeap, stInstall.hLog, &hTtsInst);
    if (nErrcode != NUAN_OK){
        qDebug("ve_ttsOpen failed");
    }
}

void ve_class::ve_paramSet(LanguageS hLanguage){

    ttsParam[0].eID = VE_PARAM_LANGUAGE;
    strcpy(ttsParam[0].uValue.szStringValue, hLanguage.LnChar);

    ttsParam[1].eID = VE_PARAM_VOICE;
    strcpy(ttsParam[1].uValue.szStringValue, hLanguage.VoName);

    ttsParam[2].eID = VE_PARAM_TYPE_OF_CHAR;
    ttsParam[2].uValue.usValue = VE_TYPE_OF_CHAR_UTF8;

    nErrcode = ve_ttsSetParamList(hTtsInst, &ttsParam[0], 3);
    if (nErrcode != NUAN_OK){
        qDebug("ve_ttsSetParamList failed");
    }

    stOutDevInfo.pUserData = (void *) &stVoutFile;
    stOutDevInfo.pfOutNotify = vout_Write;

    nErrcode = ve_ttsSetOutDevice(hTtsInst, &stOutDevInfo);
    if (nErrcode != NUAN_OK){
        qDebug("ve_ttsSetoutDevice failed");
    }
}

void ve_class::ve_prossTTS(){
    stInText.eTextFormat = VE_NORM_TEXT;
    szInputText = INPUT_TEXT;
    //szInputText = plResult;
    stInText.szInText = (void *) szInputText;
    stInText.cntTextLength = (NUAN_U32) strlen(szInputText);
}

void ve_class::ve_synthesis(){
    nErrcode = ve_ttsProcessText2Speech(hTtsInst, &stInText);
    if (nErrcode != NUAN_OK){
        qDebug("ve_ttsProcess_tts failed");
    }
}

ve_class::~ve_class(){
    if (hTtsInst.pHandleData != NULL){
        ve_ttsClose(hTtsInst);
    }

    if (hSpeech.pHandleData != NULL){
        ve_ttsUnInitialize(hSpeech);
    }

    if (stVoutFile.pPcmOutputBuffer != NULL){
        vplatform_heap_Free(stInstall.hHeap, stVoutFile.pPcmOutputBuffer);
        stVoutFile.pPcmOutputBuffer = NULL;
    }

    if (stVoutFile.fOutputPcmFile != NULL){
        vplatform_file_Close(stVoutFile.fOutputPcmFile);
        stVoutFile.fOutputPcmFile = NULL;
    }

    vplatform_ReleaseInterfaces(&stInstall);
}

static NUAN_ERROR vout_Write(
     VE_HINSTANCE           hTtsInst,
     void                 * pUserData,
     VE_CALLBACKMSG       * pcbMessage)
{
     VE_OUTDATA*     pTtsOutData = NULL;
     VOUT_FILE_T*    pVoutFile = (VOUT_FILE_T*) pUserData;
     size_t          bytesWritten = 0;
     NUAN_ERROR      ret = NUAN_OK;
     struct stat statbuf;
   //  int second;

     switch (pcbMessage->eMessage)
     {
     case VE_MSG_BEGINPROCESS:  //(1)PCM data creat start
       if (stat("play.pcm", &statbuf) == -1){
           break;
       }
       qDebug("Text-to-speech process has started.\n");
       break;

//     case VE_MSG_ENDPROCESS: //(4)PCM data creat stop
//       qDebug("Text-to-speech process has ended.\
//               Got %u samples. \n", (unsigned int) pVoutFile->cPcmSamples);
//       break;

     case VE_MSG_OUTBUFREQ: //(2) 출력버퍼에 메세지 요청 (새로운 버퍼 요청)
       pTtsOutData = (VE_OUTDATA *)pcbMessage->pParam;
       pTtsOutData->pOutPcmBuf = pVoutFile->pPcmOutputBuffer; //pPcmOutputBuffer: 출력 샘플의 버퍼 할당
       pTtsOutData->cntPcmBufLen = pVoutFile->sizeOutputBuffer; //sizeOutputBuffer: 버퍼의 byte size
       break;

     case VE_MSG_OUTBUFDONE: //(3) 전체 PCM 데이터 버퍼로 준비
       pTtsOutData = (VE_OUTDATA *)pcbMessage->pParam;

       /*
        * cntPcmBufLen: buffer size(pOutPcmbuf의 버퍼 크기)
        * fOutputPcmFile:PCM 파일에 대한 파일 포인터
        */
       if ((pTtsOutData->cntPcmBufLen != 0) && (pVoutFile->fOutputPcmFile != NULL))
       {
         /*vplatform_file_Write: 파일쓰기*/
         bytesWritten = vplatform_file_Write(pTtsOutData->pOutPcmBuf, 1,
           pTtsOutData->cntPcmBufLen, pVoutFile->fOutputPcmFile);
         //qDebug("ve_pOutPcmBuf: %x", pTtsOutData->pOutPcmBuf); //이게 출력버퍼
         if (bytesWritten != pTtsOutData->cntPcmBufLen)
         {
           ret = NUAN_E_FILEWRITEERROR;
           qDebug("Error: failed to save samples to file. Stopping.\n");
         }
         /*cPcmSamples: 총 샘플 수*/
         pVoutFile->cPcmSamples += pTtsOutData->cntPcmBufLen; //cPcmSamples에 cntPcmBufLen만큼 추가
       }
       break;

     default:
       /* other messages are left unhandled. (다른 메세지는 처리되지 않고 남는다.)*/
       break;
     }

     return ret; /* returning an error will cause the ve to stop processing. (error가 반환되면 vocalizer는 멈출 수 있다.)*/
   } /* vout_Write */


