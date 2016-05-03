// myinputdevice.h : myinputdevice DLL 的主要標頭檔
//

#pragma once

#include <dinput.h>
#include "initguid.h"

class MyDirectInputDevice8 : public IDirectInputDevice8
{
public:
	MyDirectInputDevice8(LPDIRECTINPUTDEVICE8 ppDID);
	~MyDirectInputDevice8();

	/*** IUnknown methods ***/
	HRESULT WINAPI QueryInterface(REFIID riid, LPVOID *ppvObj);
	ULONG WINAPI AddRef();
	ULONG WINAPI Release();

/*** IDirectInputDevice methods ***/
	HRESULT WINAPI GetCapabilities(LPDIDEVCAPS lpDIDevCaps);
	HRESULT WINAPI EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags);
	HRESULT WINAPI GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph);
	HRESULT WINAPI SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph);
	HRESULT WINAPI Acquire();
	HRESULT WINAPI Unacquire();
	HRESULT WINAPI GetDeviceState(DWORD cbData, LPVOID lpvData);
	HRESULT WINAPI GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
	HRESULT WINAPI SetDataFormat(LPCDIDATAFORMAT lpdf);
	HRESULT WINAPI SetEventNotification(HANDLE hEvent);
	HRESULT WINAPI SetCooperativeLevel(HWND hwnd, DWORD dwFlags);
	HRESULT WINAPI GetObjectInfo(LPDIDEVICEOBJECTINSTANCE pdidoi, DWORD dwObj, DWORD dwHow);
	HRESULT WINAPI GetDeviceInfo(LPDIDEVICEINSTANCE pdidi);
	HRESULT WINAPI RunControlPanel(HWND hwndOwner, DWORD dwFlags);
	HRESULT WINAPI Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
	HRESULT WINAPI CreateEffect(REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
	HRESULT WINAPI EnumEffects(LPDIENUMEFFECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwEffType);
	HRESULT WINAPI GetEffectInfo(LPDIEFFECTINFO pdei, REFGUID rguid);
	HRESULT WINAPI GetForceFeedbackState(LPDWORD pdwOut);
	HRESULT WINAPI SendForceFeedbackCommand(DWORD dwFlags);
	HRESULT WINAPI EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
	HRESULT WINAPI Escape(LPDIEFFESCAPE pesc);
	HRESULT WINAPI Poll();
	HRESULT WINAPI SendDeviceData(DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
	HRESULT WINAPI EnumEffectsInFile(LPCTSTR lpszFileName, LPDIENUMEFFECTSINFILECALLBACK pec, LPVOID pvRef, DWORD dwFlags);
	HRESULT WINAPI WriteEffectToFile(LPCTSTR lpszFileName, DWORD dwEntries, LPDIFILEEFFECT rgDiFileEft, DWORD dwFlags);
	HRESULT WINAPI BuildActionMap(LPDIACTIONFORMAT lpdiaf, LPCTSTR lpszUserName, DWORD dwFlags);
	HRESULT WINAPI SetActionMap(LPDIACTIONFORMAT lpdiActionFormat, LPCTSTR lptszUserName, DWORD dwFlags);
	HRESULT WINAPI GetImageInfo(LPDIDEVICEIMAGEINFOHEADER lpdiDevImageInfoHeader);

private:
	LPDIRECTINPUTDEVICE8 m_pDID;
	size_t iiii;
	byte m_pDataCopy[16];
};
