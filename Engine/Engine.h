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
	//Ŭ���̾�Ʈ�� init ���� ������ init �Լ��� ȣ�����ָ鼭 ������ â�� ���õ� ������ ����.
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

	void ResizeWindow(int32 width, int32 height);			//�������� ũ�⸦ �������ִ� �Լ�

private:
	// �׷��� ȭ�� ũ�� ���� ������ -------------------------------
	WindowInfo		_window;						//Ŭ���̾�Ʈ���� ������ ������ ���� ���� 
	D3D12_VIEWPORT	_viewport = {};			
	D3D12_RECT		_scissorRect = {};
	//-----------------------------------------------------------------

	shared_ptr<Device> _device;
	shared_ptr<CommandQueue> _cmdQueue;
	shared_ptr<SwapChain> _swapChain;
	shared_ptr<RootSignature> _rootSignature;
};

