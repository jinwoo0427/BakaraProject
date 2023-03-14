#include "Sound.h"
#include "console.h"
#include <mmsyscom.h>
#include <Digitalv.h>
#include "resource.h"
#pragma comment(lib, "winmm.lib")

using namespace std;
//bgm
//열기용
MCI_OPEN_PARMS Openbgm;
//재생용
MCI_PLAY_PARMS Playbgm;

//effect
//열기용
MCI_OPEN_PARMS Openeffect;
//재생용
MCI_PLAY_PARMS Playeffect;
UINT dwID;
UINT dwID2;

void Sound::Playingbgm()
{
	Openbgm.lpstrDeviceType = L"mpegvideo";
	Openbgm.lpstrElementName = TEXT("evolution.mp3");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&Openbgm);
	dwID = Openbgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&Openbgm);
}

void Sound::Playingeffect()
{
	Openeffect.lpstrElementName = L"돈.wav";
	Openeffect.lpstrDeviceType = L"waveaudio";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&Openeffect);
	dwID2 = Openeffect.wDeviceID;
	mciSendCommand(dwID2, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&Openeffect);
	Sleep(500);
	mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, NULL);
}