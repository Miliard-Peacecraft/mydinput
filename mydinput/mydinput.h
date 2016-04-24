// mydinput.h : mydinput DLL 的主要標頭檔
//

#pragma once

#include <dinput.h>
#include "resource.h"		// 主要符號
#include "initguid.h"

class MyDirectInput8 : public IDirectInput8
{
public:
	MyDirectInput8(LPDIRECTINPUT8 ppDI);
	~MyDirectInput8();

	/*** IUnknown methods ***/
	HRESULT WINAPI QueryInterface(REFIID riid, LPVOID *ppvObj);
	ULONG WINAPI AddRef();
	ULONG WINAPI Release();

	/*** IDirectInput methods ***/
	HRESULT WINAPI CreateDevice(REFGUID rguid, LPDIRECTINPUTDEVICE8 *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
	HRESULT WINAPI EnumDevices(DWORD dwDevType, LPDIENUMDEVICESCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags);
	HRESULT WINAPI GetDeviceStatus(REFGUID rguidInstance);
	HRESULT WINAPI RunControlPanel(HWND hwndOwner, DWORD dwFlags);
	HRESULT WINAPI Initialize(HINSTANCE hinst, DWORD dwVersion);
	HRESULT WINAPI FindDevice(REFGUID rguidClass, LPCTSTR ptszName, LPGUID pguidInstance);
	HRESULT WINAPI EnumDevicesBySemantics(LPCTSTR ptszUserName, LPDIACTIONFORMAT lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCB lpCallback, LPVOID pvRef, DWORD dwFlags);
	HRESULT WINAPI ConfigureDevices(LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMS lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

private:
	LPDIRECTINPUT8 m_pDI;
};

/*** DirectInputCreateA ***/
HRESULT WINAPI DirectInputCreateA(HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTA *ppDI, LPUNKNOWN punkOuter);
