// https://github.com/DK22Pac/directFont/tree/master/directFont

#pragma once
#pragma comment( lib, "d3dx9.lib" )
#include <d3d9.h>
#include <d3dx9.h>

namespace TExtender {
    class CD3DSprite : public ID3DXSprite {
        ID3DXSprite* m_pSprite;
    public:
        CD3DSprite();
        ~CD3DSprite();

        // IUnknown
        STDMETHOD(QueryInterface)(THIS_ REFIID iid, LPVOID* ppv);
        STDMETHOD_(ULONG, AddRef)(THIS);
        STDMETHOD_(ULONG, Release)(THIS);

        // ID3DXSprite
        STDMETHOD(GetDevice)(THIS_ LPDIRECT3DDEVICE9* ppDevice);

        STDMETHOD(GetTransform)(THIS_ D3DXMATRIX* pTransform);
        STDMETHOD(SetTransform)(THIS_ CONST D3DXMATRIX* pTransform);

        STDMETHOD(SetWorldViewRH)(THIS_ CONST D3DXMATRIX* pWorld, CONST D3DXMATRIX* pView);
        STDMETHOD(SetWorldViewLH)(THIS_ CONST D3DXMATRIX* pWorld, CONST D3DXMATRIX* pView);

        STDMETHOD(Begin)(THIS_ DWORD Flags);
        STDMETHOD(Draw)(THIS_ LPDIRECT3DTEXTURE9 pTexture, CONST RECT* pSrcRect, CONST D3DXVECTOR3* pCenter, CONST D3DXVECTOR3* pPosition, D3DCOLOR Color);
        STDMETHOD(Flush)(THIS);
        STDMETHOD(End)(THIS);

        STDMETHOD(OnLostDevice)(THIS);
        STDMETHOD(OnResetDevice)(THIS);
    };
}