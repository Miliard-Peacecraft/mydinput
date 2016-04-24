// mydinput.cpp : 定義 DLL 的初始化常式。
//

#include "stdafx.h"
#include "mydinput.h"
#include "myinputdevice.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

MyDirectInput8::MyDirectInput8(LPDIRECTINPUT8 ppDI)
	: m_pDI(ppDI)
{
}
MyDirectInput8::~MyDirectInput8()
{
}

/*** IUnknown methods ***/
HRESULT MyDirectInput8::QueryInterface(REFIID riid, LPVOID *ppvObj)
{
	return m_pDI->QueryInterface(riid, ppvObj);
}
ULONG MyDirectInput8::AddRef()
{
	return m_pDI->AddRef();
}
ULONG MyDirectInput8::Release()
{
	ULONG pRef = m_pDI->Release();

	if (pRef == 0)
	{
		delete this;
		return 0;
	}

	return pRef;
}

/*** IDirectInput methods ***/
HRESULT MyDirectInput8::CreateDevice(REFGUID rguid, LPDIRECTINPUTDEVICE8 *lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
	LPDIRECTINPUTDEVICE8 pDID = nullptr;
	HRESULT hr = m_pDI->CreateDevice(rguid, &pDID, pUnkOuter);
	*lplpDirectInputDevice = new MyDirectInputDevice8(pDID);
	return hr;
}
HRESULT MyDirectInput8::EnumDevices(DWORD dwDevType, LPDIENUMDEVICESCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return m_pDI->EnumDevices(dwDevType, lpCallback, pvRef, dwFlags);
}
HRESULT MyDirectInput8::GetDeviceStatus(REFGUID rguidInstance)
{
	return m_pDI->GetDeviceStatus(rguidInstance);
}
HRESULT MyDirectInput8::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return m_pDI->RunControlPanel(hwndOwner, dwFlags);
}
HRESULT MyDirectInput8::Initialize(HINSTANCE hinst, DWORD dwVersion)
{
	return m_pDI->Initialize(hinst, dwVersion);
}
HRESULT MyDirectInput8::FindDevice(REFGUID rguidClass, LPCTSTR ptszName, LPGUID pguidInstance)
{
	return m_pDI->FindDevice(rguidClass, ptszName, pguidInstance);
}
HRESULT MyDirectInput8::EnumDevicesBySemantics(LPCTSTR ptszUserName, LPDIACTIONFORMAT lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCB lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return m_pDI->EnumDevicesBySemantics(ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}
HRESULT MyDirectInput8::ConfigureDevices(LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMS lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
	return m_pDI->ConfigureDevices(lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}

/*** DirectInputCreateA ***/
HRESULT WINAPI DirectInputCreateA(HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTA *ppDI, LPUNKNOWN punkOuter)
{
	LPDIRECTINPUT8 pDI = nullptr;
	HRESULT hr = DirectInput8Create(hinst, DIRECTINPUT_VERSION, IID_IDirectInput8, reinterpret_cast<LPVOID*>(&pDI), punkOuter);
	*ppDI = reinterpret_cast<LPDIRECTINPUTA>(new MyDirectInput8(pDI));
	return hr;
}

