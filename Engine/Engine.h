#pragma once

#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "RootSignature.h"
#include "Mesh.h"
#include "Shader.h"

class Engine
{
public:
	//클라이언트의 init 에서 엔진의 init 함수를 호출해주면서 윈도우 창과 관련된 정보를 얻어옴.
	void Init(const WindowInfo& info);
	void Render();

public:
	shared_ptr<Device> GetDevice() { return _device; }
	shared_ptr<CommandQueue> GetCmdQueue() { return _cmdQueue; }
	shared_ptr<SwapChain> GetSwapChain() { return _swapChain; }
	shared_ptr<RootSignature> GetRootSignature() { return _rootSignature; }
public:
	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);			//윈도우의 크기를 변경해주는 함수

private:
	// 그려질 화면 크기 관련 정보들 -------------------------------
	WindowInfo		_window;						//클라이언트에서 보내준 정보를 담을 변수 
	D3D12_VIEWPORT	_viewport = {};			
	D3D12_RECT		_scissorRect = {};
	//-----------------------------------------------------------------

	shared_ptr<Device> _device;
	shared_ptr<CommandQueue> _cmdQueue;
	shared_ptr<SwapChain> _swapChain;
	shared_ptr<RootSignature> _rootSignature;
};

