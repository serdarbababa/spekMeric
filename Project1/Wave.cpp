
#include "Wave.h"




CWave::CWave(void)
{
	// Init members
	memset(&m_Descriptor, 0, sizeof(_WAVEDESCR));
	memset(&m_Format, 0, sizeof(_WAVEFORMAT));
	m_lpData = NULL;
	m_dwSize = 0;
	//m_hWaveout = NULL;
	memset(&m_WaveHeader, 0, sizeof(WAVEHDR));
	m_bPaused = false;
	m_bStopped = true;
}

CWave::~CWave(void)
{
	// Close output device
	//Close();
}

BOOL CWave::Open(SHORT channels, DWORD sampleRate, SHORT bitsPerSample)
{
	BOOL bResult = TRUE;

	// Open output device
	SHORT format = WAVE_FORMAT_PCM;
	SHORT blockAlign = channels << 1;
	WAVEFORMATEX wfex;
	wfex.wFormatTag = format;
	wfex.nChannels = channels;
	wfex.nSamplesPerSec = sampleRate;
	wfex.nAvgBytesPerSec = blockAlign * sampleRate;
	wfex.nBlockAlign = blockAlign;
	wfex.wBitsPerSample = bitsPerSample;
	wfex.cbSize = 0;
	/*if (waveOutOpen(&m_hWaveout, WAVE_MAPPER, &wfex, (DWORD_PTR)&CWave::WaveOut_Proc, (DWORD_PTR)this, CALLBACK_FUNCTION) != MMSYSERR_NOERROR)
	{
		m_hWaveout = NULL;
		bResult = FALSE;
	}*/
	m_bPaused = FALSE;
	m_bStopped = TRUE;

	return bResult;
}


BOOL CWave::Load(LPTSTR lpszFilePath)
{
	BOOL bResult = FALSE;

	// Close output device
	//Close();

	// Load .WAV file
	FILE* file = _tfopen(lpszFilePath, _T("rb"));
	if (file != NULL)
	{
		// Read .WAV descriptor
		fread(&m_Descriptor, sizeof(_WAVEDESCR), 1, file);

		// Check for valid .WAV file
		if (strncmp((LPCSTR)m_Descriptor.wave, "WAVE", 4) == 0)
		{
			// Read .WAV format
			fread(&m_Format, sizeof(_WAVEFORMAT), 1, file);

			// Check for valid .WAV file
			if ((strncmp((LPCSTR)m_Format.id, "fmt", 3) == 0) && (m_Format.format == 1))
			{
				// Read next chunk
				BYTE id[4];
				DWORD size;
				fread(id, sizeof(BYTE), 4, file);
				fread(&size, sizeof(DWORD), 1, file);
				DWORD offset = ftell(file);

				// Read .WAV data
				LPBYTE lpTemp = (LPBYTE)malloc(m_Descriptor.size*sizeof(BYTE));
				while (offset < m_Descriptor.size)
				{
					// Check for .WAV data chunk
					if (strncmp((LPCSTR)id, "data", 4) == 0)
					{
						if (m_lpData == NULL)
							m_lpData = (LPBYTE)malloc(size*sizeof(BYTE));
						else
							m_lpData = (LPBYTE)realloc(m_lpData, (m_dwSize+size)*sizeof(BYTE));
						fread(m_lpData+m_dwSize, sizeof(BYTE), size, file);
						m_dwSize += size;
					}
					else
						fread(lpTemp, sizeof(BYTE), size, file);

					// Read next chunk
					fread(id, sizeof(BYTE), 4, file);
					fread(&size, sizeof(DWORD), 1, file);
					offset = ftell(file);
				}
				free(lpTemp);

				// Open output device
				if (!Open(m_Format.channels, m_Format.sampleRate, m_Format.bitsPerSample))
				{
					//m_hWaveout = NULL;
					bResult = FALSE;
				}
				else
					bResult = TRUE;
			}
		}

		// Close .WAV file
		fclose(file);
	}

	return bResult;
}

BOOL CWave::Save(LPTSTR lpszFilePath)
{
	BOOL bResult = FALSE;

	// Save .WAV file
	FILE* file = _tfopen(lpszFilePath, _T("wb"));
	if (file != NULL)
	{
		// Save .WAV descriptor
		m_Descriptor.size = m_dwSize;
		fwrite(&m_Descriptor, sizeof(_WAVEDESCR), 1, file);

		// Save .WAV format
		fwrite(&m_Format, sizeof(_WAVEFORMAT), 1, file);

		// Write .WAV data
		BYTE id[4] = {'d', 'a', 't', 'a'};
		fwrite(id, sizeof(BYTE), 4, file);
		fwrite(&m_dwSize, sizeof(DWORD), 1, file);
		fwrite(m_lpData, sizeof(BYTE), m_dwSize, file);
		bResult = TRUE;

		// Close .WAV file
		fclose(file);
	}

	return bResult;
}