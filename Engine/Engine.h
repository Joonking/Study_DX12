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
	// �׷��� ȭ�� ũ�� ����
	WindowInfo		_window;
	D3D12_VIEWPORT	_viewport = {};
	D3D12_RECT		_scissorRect = {};

	//�ʱ�ȭ�� �Ҷ� �ʿ��Ѱ͵� 
	shared_ptr<Device> _device;   //GPU�� ���ҽ��� ��û�Ҷ� ����ϴ� �η»繫�� ��ǥ
	shared_ptr<CommandQueue> _cmdQueue;   //GPU���� ��û�� ������ �ѹ��� �������� 
	shared_ptr<SwapChain> _swapChain; //���۸� 2���� ����� �ϳ��� ȭ�� ��¿�, �ٸ��ϳ��� �ڿ��� �������غ�
};

