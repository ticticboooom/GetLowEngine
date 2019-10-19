#include "pch.h"
#include "App.h"
#include <winuser.h>
#include <consoleapi2.h>


App::App()
{
}


App::~App()
{
}

int App::Run(HINSTANCE hInstance, int nCmdShow)
{
	int argc;
	LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	LocalFree(argv);

	// Initialize the window class.
	WNDCLASSEX windowClass = { 0 };
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WindowProc;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = L"DXSampleClass";
	RegisterClassEx(&windowClass);

	RECT windowRect = { 0, 0, static_cast<LONG>(1500), static_cast<LONG>(1000) };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	// Create the window and store a handle to it.
	m_hwnd = CreateWindow(
		windowClass.lpszClassName,
		L"Game",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		nullptr,		// We have no parent window.
		nullptr,		// We aren't using menus.
		hInstance,
		NULL);

	// Initialize the sample. OnInit is defined in each child-implementation of DXSample.
	GetDeviceResources();

	ShowWindow(m_hwnd, nCmdShow);

	// Main sample loop.
	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		// Process any messages in the queue.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_KEYDOWN)
			{
				m_main->OnKeyDown(static_cast<UINT8>(msg.wParam));
			}
			if (msg.message == WM_KEYUP)
			{
				m_main->OnKeyUp(static_cast<UINT8>(msg.wParam));
			}
			if (msg.message == WM_SIZE)
			{
				RECT rect;
				GetClientRect(m_hwnd, &rect);
				GetDeviceResources()->SetLogicalSize(
					DirectX::XMFLOAT2(
						float(rect.right - rect.left),
						float(rect.top - rect.bottom)));
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			m_main->Update();
			if (m_main->Render())
			{
				GetDeviceResources()->Present();
			}

		}
	}

	m_main->OnDeviceRemoved();

	// Return this part of the WM_QUIT message to Windows.
	return static_cast<char>(msg.wParam);
}
LRESULT CALLBACK App::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_CREATE:
	{
		// Save the DXSample* passed in to CreateWindow.
		LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));
	}
	return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	// Handle any messages the switch statement didn't.
	return DefWindowProc(hWnd, message, wParam, lParam);
}


std::shared_ptr<DX::DeviceResources> App::GetDeviceResources()
{
	if (m_deviceResources != nullptr && m_deviceResources->IsDeviceRemoved())
	{
		// All references to the existing D3D device must be released before a new device
		// can be created.

		m_deviceResources = nullptr;
		m_main->OnDeviceRemoved();
	}

	if (m_deviceResources == nullptr)
	{
		m_deviceResources = std::make_shared<DX::DeviceResources>();
		m_deviceResources->SetWindow(m_hwnd);
		m_main->CreateRenderers(m_deviceResources);
	}
	return m_deviceResources;
}
