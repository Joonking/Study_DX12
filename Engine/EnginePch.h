#pragma once

// 각종 include
#include <windows.h>
#include <tchar.h>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
using namespace std;

#include "d3dx12.h"
#include <d3d12.h>
#include <wrl.h>
#include <d3dcompiler.h>
#include <dxgi.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXColors.h>
using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace Microsoft::WRL;

// 각종 lib
#pragma comment(lib, "d3d12")
#pragma comment(lib, "dxgi")
#pragma comment(lib, "dxguid")
#pragma comment(lib, "d3dcompiler")

// 각종 typedef
using int8		= __int8;
using int16		= __int16;
using int32		= __int32;
using int64		= __int64;
using uint8		= unsigned __int8;
using uint16	= unsigned __int16;
using uint32	= unsigned __int32;
using uint64	= unsigned __int64;
using Vec2		= XMFLOAT2;
using Vec3		= XMFLOAT3;
using Vec4		= XMFLOAT4;
using Matrix	= XMMATRIX;

enum
{
	SWAP_CHAIN_BUFFER_COUNT = 2
};


struct WindowInfo  //출력 윈도우 정보
{
	HWND	hwnd;				//출력 윈도우 핸들
	int32		width;				//너비
	int32		height;			//높이
	bool		windowed;		//창 모드 or 전체화면

};

//extern : 아직은 모르겠지만 이런걸 쓸거야
//함수 밖의 전역 범위에 선언되며, 프로그램 전체에서 유효하고 다른 파일에서도 참조 가능
//초기화를 생략하면 0으로 자동 초기화
//정적 데이터영역에 할당
//extern 변수는 편리하지만 남발하면 프로그램을 복잡하게 하고 나중에 유지보수가
//힘들기 때문에 사용을 최소화 하는 것이 바람직함
//class를 붙여서 전방선언을 해줌.
extern unique_ptr<class Engine> GEngine;
