#pragma once

#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"

class Engine
{
public:

	void Init(const WindowInfo& info);
	void Render();

public:
	shared_ptr<Device> GetDevice() { return _device; }
	shared_ptr<CommandQueue> GetCmdQueu() { return _cmdQueue; }
	shared_ptr<SwapChain> GetSwapChain() { return _swapChain; }

public:
	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);

private:
	// 그려질 화면 크기 관련
	WindowInfo		_window;
	D3D12_VIEWPORT	_viewport = {};
	D3D12_RECT		_scissorRect = {};

	//초기화를 할때 필요한것들 
	shared_ptr<Device> _device;   //GPU에 리소스를 요청할때 사용하는 인력사무소 대표
	shared_ptr<CommandQueue> _cmdQueue;   //GPU에게 요청을 보낼때 한번에 보내도록 
	shared_ptr<SwapChain> _swapChain; //버퍼를 2개를 사용해 하나는 화면 출력용, 다른하나는 뒤에서 다음것준비
};

