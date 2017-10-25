#pragma once

#include <math.h>
#include <stdio.h>
/*#include <tchar.h>

#pragma pack(1)
typedef struct __WAVEDESCR
{
	byte riff[4];
	DWORD size;
	BYTE wave[4];

} _WAVEDESCR, *_LPWAVEDESCR;

typedef struct __WAVEFORMAT
{
	BYTE id[4];
	DWORD size;
	SHORT format;
	SHORT channels;
	DWORD sampleRate;
	DWORD byteRate;
	SHORT blockAlign;
	SHORT bitsPerSample;

} _WAVEFORMAT, *_LPWAVEFORMAT;
#pragma pack()

class CWave
{
public:
	CWave(void);
	virtual ~CWave(void);

public:
	// Public methods
	BOOL Load(LPTSTR lpszFilePath);
	BOOL Save(LPTSTR lpszFilePath);	
	LPBYTE GetData()			{return m_lpData;}
	DWORD GetSize()				{return m_dwSize;}
	SHORT GetChannels()			{return m_Format.channels;}
	DWORD GetSampleRate()		{return m_Format.sampleRate;}
	SHORT GetBitsPerSample()	{return m_Format.bitsPerSample;}

private:
	// Private methods
	BOOL Open(SHORT channels, DWORD sampleRate, SHORT bitsPerSample);	
public:
	// Private members
	_WAVEDESCR m_Descriptor;
	_WAVEFORMAT m_Format;
	LPBYTE m_lpData;
	DWORD m_dwSize;
	//HWAVEOUT m_hWaveout;
	WAVEHDR m_WaveHeader;
	BOOL m_bStopped;
	BOOL m_bPaused;
};
 */
