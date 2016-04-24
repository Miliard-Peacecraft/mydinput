// myinputdevice.cpp : 定義 DLL 的初始化常式。
//

#include "stdafx.h"
#include "myinputdevice.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define SLEEP_DURATION 33 // 33 ms

MyDirectInputDevice8::MyDirectInputDevice8(LPDIRECTINPUTDEVICE8 ppDID)
	: m_pDID(ppDID)
{
}
MyDirectInputDevice8::~MyDirectInputDevice8()
{
}

/*** IUnknown methods ***/
HRESULT MyDirectInputDevice8::QueryInterface(REFIID riid, LPVOID *ppvObj)
{
	return m_pDID->QueryInterface(riid, ppvObj);
}
ULONG MyDirectInputDevice8::AddRef()
{
	return m_pDID->AddRef();
}
ULONG MyDirectInputDevice8::Release()
{
	ULONG pRef = m_pDID->Release();

	if (pRef == 0)
	{
		delete this;
		return 0;
	}

	return pRef;
}

/*** IDirectInputDevice methods ***/
HRESULT MyDirectInputDevice8::GetCapabilities(LPDIDEVCAPS lpDIDevCaps)
{
	return m_pDID->GetCapabilities(lpDIDevCaps);
}
HRESULT MyDirectInputDevice8::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return m_pDID->EnumObjects(lpCallback, pvRef, dwFlags);
}
HRESULT MyDirectInputDevice8::GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
	return m_pDID->GetProperty(rguidProp, pdiph);
}
HRESULT MyDirectInputDevice8::SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
	return m_pDID->SetProperty(rguidProp, pdiph);
}
HRESULT MyDirectInputDevice8::Acquire()
{
	return m_pDID->Acquire();
}
HRESULT MyDirectInputDevice8::Unacquire()
{
	return m_pDID->Unacquire();
}
HRESULT MyDirectInputDevice8::GetDeviceState(DWORD cbData, LPVOID lpvData)
{
	Sleep(SLEEP_DURATION);

	if (FAILED(m_pDID->Poll()) || FAILED(m_pDID->Acquire()))
	{
		memset(lpvData, 0, cbData);
	}
	else
	{
		return m_pDID->GetDeviceState(cbData, lpvData);
	}

	return DI_OK;
}
HRESULT MyDirectInputDevice8::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	return m_pDID->GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
}
HRESULT MyDirectInputDevice8::SetDataFormat(LPCDIDATAFORMAT lpdf)
{
	return m_pDID->SetDataFormat(lpdf);
}
HRESULT MyDirectInputDevice8::SetEventNotification(HANDLE hEvent)
{
	return m_pDID->SetEventNotification(hEvent);
}
HRESULT MyDirectInputDevice8::SetCooperativeLevel(HWND hwnd, DWORD dwFlags)
{
	return m_pDID->SetCooperativeLevel(hwnd, dwFlags);
}
HRESULT MyDirectInputDevice8::GetObjectInfo(LPDIDEVICEOBJECTINSTANCE pdidoi, DWORD dwObj, DWORD dwHow)
{
	return m_pDID->GetObjectInfo(pdidoi, dwObj, dwHow);
}
HRESULT MyDirectInputDevice8::GetDeviceInfo(LPDIDEVICEINSTANCE pdidi)
{
	return m_pDID->GetDeviceInfo(pdidi);
}
HRESULT MyDirectInputDevice8::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return m_pDID->RunControlPanel(hwndOwner, dwFlags);
}
HRESULT MyDirectInputDevice8::Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
	return m_pDID->Initialize(hinst, dwVersion, rguid);
}
HRESULT MyDirectInputDevice8::CreateEffect(REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
	return m_pDID->CreateEffect(rguid, lpeff, ppdeff, punkOuter);
}
HRESULT MyDirectInputDevice8::EnumEffects(LPDIENUMEFFECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwEffType)
{
	return m_pDID->EnumEffects(lpCallback, pvRef, dwEffType);
}
HRESULT MyDirectInputDevice8::GetEffectInfo(LPDIEFFECTINFO pdei, REFGUID rguid)
{
	return m_pDID->GetEffectInfo(pdei, rguid);
}
HRESULT MyDirectInputDevice8::GetForceFeedbackState(LPDWORD pdwOut)
{
	return m_pDID->GetForceFeedbackState(pdwOut);
}
HRESULT MyDirectInputDevice8::SendForceFeedbackCommand(DWORD dwFlags)
{
	return m_pDID->SendForceFeedbackCommand(dwFlags);
}
HRESULT MyDirectInputDevice8::EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
	return m_pDID->EnumCreatedEffectObjects(lpCallback, pvRef, fl);
}
HRESULT MyDirectInputDevice8::Escape(LPDIEFFESCAPE pesc)
{
	return m_pDID->Escape(pesc);
}
HRESULT MyDirectInputDevice8::Poll()
{
	return m_pDID->Poll();
}
HRESULT MyDirectInputDevice8::SendDeviceData(DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
	return m_pDID->SendDeviceData(cbObjectData, rgdod, pdwInOut, fl);
}
HRESULT MyDirectInputDevice8::EnumEffectsInFile(LPCTSTR lpszFileName, LPDIENUMEFFECTSINFILECALLBACK pec, LPVOID pvRef, DWORD dwFlags)
{
	return m_pDID->EnumEffectsInFile(lpszFileName, pec, pvRef, dwFlags);
}
HRESULT MyDirectInputDevice8::WriteEffectToFile(LPCTSTR lpszFileName, DWORD dwEntries, LPDIFILEEFFECT rgDiFileEft, DWORD dwFlags)
{
	return m_pDID->WriteEffectToFile(lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}
HRESULT MyDirectInputDevice8::BuildActionMap(LPDIACTIONFORMAT lpdiaf, LPCTSTR lpszUserName, DWORD dwFlags)
{
	return m_pDID->BuildActionMap(lpdiaf, lpszUserName, dwFlags);
}
HRESULT MyDirectInputDevice8::SetActionMap(LPDIACTIONFORMAT lpdiActionFormat, LPCTSTR lptszUserName, DWORD dwFlags)
{
	return m_pDID->SetActionMap(lpdiActionFormat, lptszUserName, dwFlags);
}
HRESULT MyDirectInputDevice8::GetImageInfo(LPDIDEVICEIMAGEINFOHEADER lpdiDevImageInfoHeader)
{
	return m_pDID->GetImageInfo(lpdiDevImageInfoHeader);
}
