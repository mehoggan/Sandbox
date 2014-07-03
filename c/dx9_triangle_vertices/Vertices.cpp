#include <d3d9.h>
#include <strsafe.h>

LPDIRECT3D9             g_pD3D = NULL; // Pointer to IDirect3D9 interface used to create the D3DDevice
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; // Pointer to the IDirect3DDevice9 interface used to create rendering device
LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL; // Pointer to the IDirect3DVertexBuffer9 interface used to create a buffer to hold vertices

struct CUSTOMVERTEX
{
    FLOAT x, y, z, rhw; // The transformed position for the vertex
    DWORD color;        // The vertex color
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)

HRESULT InitD3D(HWND hWnd)
{
	/*
	 *	If successful, this function returns a pointer to an IDirect3D9 interface
	 *	Global variable: LPDIRECT3D9 g_pD3D = NULL;
	 */
    if((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
        return E_FAIL;
	}
	/*
	 *  typedef struct D3DPRESENT_PARAMETERS {
	 *	UINT                BackBufferWidth;
	 *	UINT                BackBufferHeight;
	 *	D3DFORMAT           BackBufferFormat;
	 *	UINT                BackBufferCount;
	 *	D3DMULTISAMPLE_TYPE MultiSampleType;
	 *	DWORD               MultiSampleQuality;
	 *	D3DSWAPEFFECT       SwapEffect;
	 *	HWND                hDeviceWindow;
	 *	BOOL                Windowed;
	 *	BOOL                EnableAutoDepthStencil;
	 *	D3DFORMAT           AutoDepthStencilFormat;
	 *	DWORD               Flags;
	 *	UINT                FullScreen_RefreshRateInHz;
	 *	UINT                PresentationInterval;
	 *	} D3DPRESENT_PARAMETERS, *LPD3DPRESENT_PARAMETERS;
	 */
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	/*
	 *	Creates a device to represent the display adapter
	 *	LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;
	 */
    if(FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
    {
        return E_FAIL;
    }
    return S_OK;
}

HRESULT InitVB()
{
    CUSTOMVERTEX vertices[] =
    {
        {150.0f,  50.0f, 0.0f, 1.0f, 0xffff0000,}, // x, y, z, rhw, color
        {250.0f, 250.0f, 0.0f, 1.0f, 0xff00ff00,},
        {50.0f, 250.0f, 0.0f, 1.0f, 0xff00ffff,},
    };
    if(FAILED(g_pd3dDevice->CreateVertexBuffer(3 * sizeof( CUSTOMVERTEX ), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_pVB, NULL)))
    {
        return E_FAIL;
    }
    VOID* pVertices;
    if(FAILED(g_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
        return E_FAIL;
	}
    memcpy(pVertices, vertices, sizeof(vertices));
    g_pVB->Unlock();
    return S_OK;
}

VOID Cleanup()
{
    if(g_pVB != NULL)
	{
        g_pVB->Release();
	}
    if(g_pd3dDevice != NULL)
	{
        g_pd3dDevice->Release();
	}
    if(g_pD3D != NULL)
	{
        g_pD3D->Release();
	}
}

VOID Render()
{
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

    if(SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
        g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
        g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
        g_pd3dDevice->EndScene();
    }
    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_DESTROY:
            Cleanup();
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
    WNDCLASSEX wc =
    {
        sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
        GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
        /*L*/"D3D Tutorial", NULL
    };
    RegisterClassEx(&wc);

    HWND hWnd = CreateWindow( /*L*/"D3D Tutorial", /*L*/"D3D Tutorial 02: Vertices",
                              WS_OVERLAPPEDWINDOW, 100, 100, 300, 300,
                              NULL, NULL, wc.hInstance, NULL );

    if(SUCCEEDED(InitD3D(hWnd)))
    {
        if( SUCCEEDED(InitVB()))
        {
            ShowWindow(hWnd, SW_SHOWDEFAULT);
            UpdateWindow(hWnd);
            MSG msg;
            ZeroMemory(&msg, sizeof( msg ));
            while(msg.message != WM_QUIT)
            {
                if(PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
                else
				{
                    Render();
				}
            }
        }
    }

    UnregisterClass( /*L*/"D3D Tutorial", wc.hInstance );
    return 0;
}
